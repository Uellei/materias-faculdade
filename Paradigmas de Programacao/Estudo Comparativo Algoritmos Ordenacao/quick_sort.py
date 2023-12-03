def quick_sort(A):
    comps, trocas = quicksort_helper(A, 0, len(A) - 1)
    return trocas, comps

def quicksort_helper(A, esquerda, direita):
    trocas = 0
    comps = 0
    if esquerda < direita:
        indice_pivo, comps_partition = particao(A, esquerda, direita)
        trocas += 1
        comps += comps_partition
        comps_left, trocas_left = quicksort_helper(A, esquerda, indice_pivo - 1)
        comps_right, trocas_right = quicksort_helper(A, indice_pivo + 1, direita)
        comps += comps_left + comps_right
        trocas += trocas_left + trocas_right

    return comps, trocas

def particao(A, esquerda, direita):
    meio = (esquerda + direita) // 2
    if A[meio] < A[esquerda]:
        A[meio], A[esquerda] = A[esquerda], A[meio]
    if A[direita] < A[esquerda]:
        A[direita], A[esquerda] = A[esquerda], A[direita]
    if A[direita] < A[meio]:
        A[direita], A[meio] = A[meio], A[direita]
        
    A[meio], A[direita - 1] = A[direita - 1], A[meio]
    pivo = A[direita - 1]
    i = esquerda
    j = direita - 1
    
    while True:
        i += 1
        while A[i] < pivo:
            i += 1
            
        j -= 1
        while A[j] > pivo:
            j -= 1

        if i < j:
            A[i], A[j] = A[j], A[i]
        else:
            break

    A[i], A[direita - 1] = A[direita - 1], A[i]
    
    return i, j - esquerda + 1
