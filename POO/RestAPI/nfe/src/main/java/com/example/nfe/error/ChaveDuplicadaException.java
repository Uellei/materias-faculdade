package com.example.nfe.error;

public class ChaveDuplicadaException extends RuntimeException{
    public ChaveDuplicadaException(String mensagem) {
        super(mensagem);
    }
}
