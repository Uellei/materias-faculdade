def busca_sequencial(lista, chave):
    posicoes = []
    for i in range(len(lista)):
        if lista[i] == chave:
            posicoes.append(i)
    return posicoes

lista = [1,2,3,3,4,4,5,5,6]
print(busca_sequencial(lista, 3))