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

# Exemplo de uso:
lista = [1, 2, 2, 3, 4, 4, 4, 5, 6]
item = 4
print(pesquisa_binaria_multipla(lista, item))
