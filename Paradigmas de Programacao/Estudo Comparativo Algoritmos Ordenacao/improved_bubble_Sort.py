#Improved bubble sort

def improved_bubble_sort(arr):
    n = len(arr)
    swaps = 0
    comparacoes = 0

    for i in range(n):
        trocas_realizadas = False

        for j in range(0, n-i-1):
            comparacoes += 1
            if arr[j] > arr[j+1]:
                arr[j], arr[j+1] = arr[j+1], arr[j]
                swaps += 1
                trocas_realizadas = True

        if not trocas_realizadas:
            break

    return swaps, comparacoes

