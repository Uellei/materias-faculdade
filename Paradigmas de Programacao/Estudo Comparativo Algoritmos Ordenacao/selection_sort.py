def selection_sort(array):
    trocas = 0
    comparacoes = 0
    size = len(array)
    for ind in range(size):
        min_index = ind
        for j in range(ind + 1, size):
            comparacoes += 1
            if array[j] < array[min_index]:
                min_index = j
        if min_index != ind:
            trocas += 1
            array[ind], array[min_index] = array[min_index], array[ind]

    return trocas, comparacoes
