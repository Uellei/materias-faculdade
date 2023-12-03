def merge(A, aux, esquerda, meio, direita):
    """
    Combina dois vetores ordenados em um único vetor (também ordenado).
    """
    trocas = 0
    comparacoes = 0

    for k in range(esquerda, direita + 1):
        aux[k] = A[k]

    i = esquerda
    j = meio + 1

    for k in range(esquerda, direita + 1):
        comparacoes += 1
        if i > meio:
            A[k] = aux[j]
            j += 1
        elif j > direita:
            A[k] = aux[i]
            i += 1
        elif aux[j] < aux[i]:
            A[k] = aux[j]
            j += 1
            trocas += 1
        else:
            A[k] = aux[i]
            i += 1
            trocas += 1

    return trocas, comparacoes

def merge_sort(A):
    aux = A.copy()
    esquerda = 0
    direita = len(A) - 1
    trocas, comps = merge_sort_recursive(A, aux, esquerda, direita)
    return trocas, comps

def merge_sort_recursive(A, aux, esquerda, direita):
    if direita <= esquerda:
        return 0, 0

    meio = (esquerda + direita) // 2

    trocas1, comps1 = merge_sort_recursive(A, aux, esquerda, meio)

    trocas2, comps2 = merge_sort_recursive(A, aux, meio + 1, direita)

    trocas3, comps3 = merge(A, aux, esquerda, meio, direita)

    return trocas1 + trocas2 + trocas3, comps1 + comps2 + comps3