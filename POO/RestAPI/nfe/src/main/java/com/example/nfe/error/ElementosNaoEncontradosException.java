package com.example.nfe.error;

public class ElementosNaoEncontradosException extends RuntimeException {

    public ElementosNaoEncontradosException(String mensagem) {
        super(mensagem);
    }
}
