package com.example.nfe.error;

public class ChaveNaoEncontradaException extends RuntimeException {

    public ChaveNaoEncontradaException(String mensagem) {
        super(mensagem);
    }
}