def insertion_sort(arr):
    n = len(arr)
    swaps = 0
    comparisons = 0
      
    if n <= 1:
        return swaps, comparisons  
 
    for i in range(1, n):  
        key = arr[i]  
        j = i - 1
        while j >= 0 and key < arr[j]:  
            arr[j + 1] = arr[j]  
            swaps += 1
            comparisons += 1
            j -= 1
        arr[j + 1] = key  
        swaps += 1

    return swaps, comparisons
