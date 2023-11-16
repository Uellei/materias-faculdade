package com.example.nfe.controller;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.DeleteMapping;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.PutMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.ResponseStatus;
import org.springframework.web.bind.annotation.RestController;

import com.example.nfe.error.ChaveDuplicadaException;
import com.example.nfe.error.ChaveNaoEncontradaException;
import com.example.nfe.error.ElementosNaoEncontradosException;
import com.example.nfe.model.NotaFiscal;
import com.example.nfe.service.DadosService;

@RestController
public class Controller {

    @Autowired
    private DadosService dadosService;
    
    @PostMapping("/criar")
    public ResponseEntity<String> receberDados(@RequestBody NotaFiscal[] dados) {
        try {
            String mensagem = dadosService.adicionarNotaFiscal(dados);
            return ResponseEntity.ok(mensagem);
        } catch (IllegalArgumentException e) {
            return ResponseEntity.status(HttpStatus.BAD_REQUEST).body(e.getMessage());
        } catch (ChaveDuplicadaException e) {
            return ResponseEntity.status(HttpStatus.CONFLICT).body(e.getMessage());
        } catch (Exception e) {
            return ResponseEntity.status(HttpStatus.INTERNAL_SERVER_ERROR).body("Erro interno no servidor");
        }
        
    }
    
    @PutMapping("atualizar/{chaveAcesso}")
    public ResponseEntity<String> atualizarDados(@PathVariable String chaveAcesso, @RequestBody NotaFiscal[] novosDados) {
        try {
            dadosService.atualizarDados(chaveAcesso, novosDados);
            return ResponseEntity.ok("Dados Atualizados");
        } catch (ChaveNaoEncontradaException e) {
            return ResponseEntity.status(HttpStatus.NOT_FOUND).body(e.getMessage());
        } catch (Exception e) {
            return ResponseEntity.status(HttpStatus.INTERNAL_SERVER_ERROR).body("Erro interno no servidor");
        }
    }

    @GetMapping("/obter")
    public ResponseEntity<List<NotaFiscal[]>> obterDados() {
        try {
            List<NotaFiscal[]> dados = dadosService.obterTodosOsDados();
            return ResponseEntity.ok(dados);
        } catch (Exception e) {
            return ResponseEntity.status(HttpStatus.INTERNAL_SERVER_ERROR).body(null);
        }
    }

    @GetMapping("/obter/{chaveAcesso}")
    public ResponseEntity<NotaFiscal[]> obterDadosPorChaveAcesso(@PathVariable String chaveAcesso) {
        try {
            NotaFiscal[] dados = dadosService.obterDadosPorChaveAcesso(chaveAcesso);
            return ResponseEntity.ok(dados);
        } catch (ChaveNaoEncontradaException e) {
            NotaFiscal[] errorArray = {new NotaFiscal("error", "Chave de Acesso não encontrada")};
            return ResponseEntity.status(HttpStatus.NOT_FOUND).body(errorArray);
        } catch (IllegalArgumentException e) {
            NotaFiscal[] errorArray = {new NotaFiscal("error", "Campo 'Chave de Acesso' é obrigatório.")};
            return ResponseEntity.status(HttpStatus.INTERNAL_SERVER_ERROR).body(errorArray);
        }
    }

    @DeleteMapping("apagar/{chaveAcesso}")
    public ResponseEntity<String> apagarDados(@PathVariable String chaveAcesso, @RequestBody List<String> elementosParaRemover) {
        if (elementosParaRemover.contains("Chave de Acesso")) {
            return ResponseEntity.status(HttpStatus.BAD_REQUEST).body("Não é possível remover o campo Chave de Acesso");
        }
        try {
            dadosService.removerDados(chaveAcesso, elementosParaRemover);
            return ResponseEntity.ok("Dados Removidos");
        } catch (ElementosNaoEncontradosException e) {
            return ResponseEntity.status(HttpStatus.NOT_FOUND).body(e.getMessage());
        } catch (Exception e) {
            return ResponseEntity.status(HttpStatus.INTERNAL_SERVER_ERROR).body("Erro interno no servidor");
        }
    }

    @DeleteMapping("apagar-nota/{chaveAcesso}")
    public ResponseEntity<String> apagarNotaFiscal(@PathVariable String chaveAcesso) {
        try {
            dadosService.apagarLista(chaveAcesso);
            return ResponseEntity.ok("Nota Fiscal Apagada");
        } catch (ChaveNaoEncontradaException e) {
            return ResponseEntity.status(HttpStatus.NOT_FOUND).body(e.getMessage());
        } catch (Exception e) {
            return ResponseEntity.status(HttpStatus.INTERNAL_SERVER_ERROR).body("Erro interno no servidor");
        }
    }
    
}
