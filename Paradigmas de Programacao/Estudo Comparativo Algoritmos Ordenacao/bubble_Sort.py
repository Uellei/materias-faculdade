# Bubble sort

def bubble_sort(arr):
    n = len(arr)
    swaps = 0
    comparacoes = 0
    ordenado = False

    while not ordenado:
        ordenado = True
        for i in range(n - 1):
            comparacoes += 1
            if arr[i] > arr[i + 1]:
                arr[i], arr[i + 1] = arr[i + 1], arr[i]
                swaps += 1
                ordenado = False

    return swaps, comparacoes
