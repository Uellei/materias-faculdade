import time

def fibonacci_recursivo(n):
    if n <= 1:
        return n
    else:
        return fibonacci_recursivo(n-1) + fibonacci_recursivo(n-2)

def fibonacci_memoization(n, memo={}):
    if n <= 1:
        return n
    elif n not in memo:
        memo[n] = fibonacci_memoization(n-1, memo) + fibonacci_memoization(n-2, memo)
    return memo[n]

n = 17

start_time = time.time()
result1 = fibonacci_recursivo(n)
end_time = time.time()
print(f"Fibonacci sem memoização para n={n}: {result1}")
print(f"Tempo de execução sem memoização: {end_time - start_time:.6f} segundos")

start_time = time.time()
result2 = fibonacci_memoization(n)
end_time = time.time()
print(f"Fibonacci com memoização para n={n}: {result2}")
print(f"Tempo de execução com memoização: {end_time - start_time:.6f} segundos")
