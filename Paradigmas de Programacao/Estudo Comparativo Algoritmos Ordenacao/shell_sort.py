def shell_sort(arr):
    n = len(arr)
    trocas = 0
    comps = 0
    intervalo = n // 2
    while intervalo > 0:
        for i in range(intervalo, n):
            valor = arr[i]
            j = i
            comps += 1
            while j >= intervalo and arr[j - intervalo] > valor:
                arr[j] = arr[j - intervalo]
                j -= intervalo
                trocas += 1
                comps += 1
            arr[j] = valor
        intervalo //= 2

    return trocas, comps