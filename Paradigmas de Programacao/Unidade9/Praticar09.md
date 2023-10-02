# Análise de Algoritmos - Lista de Exercício

## 1. Busca Sequencial e Busca Binária
Assumindo que a lista possui chaves que podem ocorrer múltiplas vezes na lista. Retorna uma lista com todas as posições onde a chave foi encontrada. Se a chave não for encontrada na lista, retorna uma lista vazia.

### Busca Sequencial
```py
def busca_sequencial(lista, chave):
    posicoes = []
    for i in range(len(lista)):
        if lista[i] == chave:
            posicoes.append(i)
    return posicoes
```

### Busca Binária
```py
def pesquisa_binaria_multipla(lista, item):
    posicoes = []
    esquerda, direita = 0, len(lista) - 1
    while esquerda <= direita:
        meio = (esquerda + direita) // 2
        if lista[meio] == item:
            posicoes.append(meio)
            esquerda_temp = meio - 1
            while esquerda_temp >= 0 and lista[esquerda_temp] == item:
                posicoes.append(esquerda_temp)
                esquerda_temp -= 1
            direita_temp = meio + 1
            while direita_temp < len(lista) and lista[direita_temp] == item:
                posicoes.append(direita_temp)
                direita_temp += 1
            return posicoes
        elif lista[meio] > item:
            direita = meio - 1
        else:  # lista[meio] < item
            esquerda = meio + 1
    return []
```