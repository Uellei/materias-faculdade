package com.example.nfe.service;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Iterator;
import java.util.List;

import org.springframework.stereotype.Service;

import com.example.nfe.error.ChaveDuplicadaException;
import com.example.nfe.error.ChaveNaoEncontradaException;
import com.example.nfe.error.ElementosNaoEncontradosException;
import com.example.nfe.model.NotaFiscal;

@Service
public class DadosService {
    private List<NotaFiscal[]> listaDeDados = new ArrayList<>();

    // ADICIONAR NOTA FISCAL
    public String adicionarNotaFiscal(NotaFiscal[] dados) {
        String chaveAcesso = extrairChaveAcesso(dados);
        if (chaveAcesso != null && !chaveAcessoJaExiste(chaveAcesso)) {
            if (chaveAcesso.isEmpty()) {
                throw new IllegalArgumentException("Campo 'Chave de Acesso' é obrigatório.");
            }
            listaDeDados.add(dados);
        } else if (chaveAcessoJaExiste(chaveAcesso))
            throw new ChaveDuplicadaException("Chave de Acesso já existente. Não foi possível adicionar os dados!");
        return "Nota Fiscal adicionados com sucesso!";
    }

    // OBTER NOTAS FISCAIS
    public List<NotaFiscal[]> obterTodosOsDados() {
        return listaDeDados;
    }

        
    private String extrairChaveAcesso(NotaFiscal[] dados) {
        for (NotaFiscal dado : dados) {
            if ("Chave de Acesso".equals(dado.getName())) {
                String chaveAcesso = dado.getValue();
                if (chaveAcesso != null && !chaveAcesso.trim().isEmpty()) {
                    return chaveAcesso;
                } else {
                    throw new IllegalArgumentException("Campo 'Chave de Acesso' não pode ser nulo ou vazio.");
                }
            }
        }
        throw new IllegalArgumentException("Campo 'Chave de Acesso' é obrigatório.");
    }

    // RETORNAR DADOS DA NOTA FISCAL COM CHAVE DE ACESSO ESPECÍFICA
    public NotaFiscal[] obterDadosPorChaveAcesso(String chaveAcesso) {
        for (NotaFiscal[] dadosArray : listaDeDados) {
            for (NotaFiscal dado : dadosArray) {
                if ("Chave de Acesso".equals(dado.getName()) && chaveAcesso.equals(dado.getValue())) {
                    return dadosArray;
                }
            }
        }
        throw new ChaveNaoEncontradaException("Chave de Acesso não encontrada");
    }

    // ATUALIZAR DADOS ESPECIFICOS DE UMA NOTA OU CRIAR OS DADOS
    public String atualizarDados(String chaveAcesso, NotaFiscal[] novosDados) {
        for (int i = 0; i < listaDeDados.size(); i++) {
            NotaFiscal[] dadosArray = listaDeDados.get(i);
            for (NotaFiscal item : dadosArray) {
                if ("Chave de Acesso".equals(item.getName()) && chaveAcesso.equals(item.getValue())) {
                    for (NotaFiscal novoDado : novosDados) {
                        boolean dadoExistente = false;
                        for (NotaFiscal dados : dadosArray) {
                            if (novoDado.getName().equals(dados.getName())) {
                                dados.setValue(novoDado.getValue());
                                dadoExistente = true;
                                break;
                            }
                        }
                        if (!dadoExistente) {
                            NotaFiscal[] novoArray = Arrays.copyOf(dadosArray, dadosArray.length + 1);
                            novoArray[novoArray.length - 1] = new NotaFiscal(novoDado.getName(), novoDado.getValue());
                            listaDeDados.set(i, novoArray);
                        }
                    }
                    return "Dados Atualizados ou Adicionados";
                }
            }
        }
        throw new ChaveNaoEncontradaException("Chave de Acesso não encontrada");
    }
    
    

    // APAGAR DADOS ESPECÍFICOS DE UMA NOTA
    public String removerDados(String chaveAcesso, List<String> elementosParaRemover) {
        for (Iterator<NotaFiscal[]> iterator = listaDeDados.iterator(); iterator.hasNext();) {
            NotaFiscal[] dadosArray = iterator.next();
            List<NotaFiscal> novaLista = new ArrayList<>();
            for (NotaFiscal item : dadosArray) {
                // Garante que o campo "Chave de Acesso" não será removido
                if ("Chave de Acesso".equals(item.getName()) && chaveAcesso.equals(item.getValue())) {
                    novaLista.add(item);  // Adiciona o campo "Chave de Acesso" à nova lista
                } else if (!elementosParaRemover.contains(item.getName())) {
                    novaLista.add(item);
                }
            }
            if (!novaLista.isEmpty()) {
                listaDeDados.set(listaDeDados.indexOf(dadosArray), novaLista.toArray(new NotaFiscal[0]));
            } else {
                iterator.remove();
            }
        }
    
        if (listaDeDados.isEmpty()) {
            throw new ElementosNaoEncontradosException("Elementos não encontrados");
        }
    
        return "Dados Removidos";
    }

    // APAGAR NOTA FISCAL
    public String apagarLista(String chaveAcesso) {
        boolean apagar = listaDeDados.removeIf(dadosArray -> Arrays.stream(dadosArray)
                .anyMatch(item -> "Chave de Acesso".equals(item.getName()) && chaveAcesso.equals(item.getValue())));
        if (!apagar) {
            throw new ChaveNaoEncontradaException("Chave de Acesso não encontrada");
        }
        return "Lista Removida";
    }

    // CONFERIR SE UMA NOTA COM CHAVE DE ACESSO ESPECIFICA JA EXISTE
    private boolean chaveAcessoJaExiste(String chaveAcesso) {
        for (NotaFiscal[] dadosArray : listaDeDados) {
            for (NotaFiscal dado : dadosArray) {
                if ("Chave de Acesso".equals(dado.getName()) && chaveAcesso.equals(dado.getValue())) {
                    return true;
                }
            }
        }
        return false;
    }
}
