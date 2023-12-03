from selection_sort import selection_sort
from merge_sort import merge_sort
from quick_sort import quick_sort
from shell_sort import shell_sort
from bubble_Sort import bubble_sort
from improved_bubble_Sort import improved_bubble_sort
from insertion_Sort import insertion_sort


import random
import time
import pandas as pd

random.seed(42)

casos_medios = {
    1000: random.sample(range(1, 1000 + 1), 1000),
    10000: random.sample(range(1, 10000 + 1), 10000),
    100000: random.sample(range(1, 100000 + 1), 100000),
}

def generate_fixed_data(size, case):
    if case == 'melhor':
        return list(range(1, size + 1))
    elif case == 'pior':
        return list(range(size, 0, -1))
    else:
        return casos_medios.get(size, [])

algorithms = [bubble_sort, improved_bubble_sort, insertion_sort, selection_sort, merge_sort, quick_sort, shell_sort]
cases = ['melhor','pior','aleatorio']
sizes = [1000, 10000, 100000]

data_dict = {
    'Algoritmo': [],
    'Caso': [],
    'Tamanho': [],
    'Trocas': [],
    'Comparações': [],
    'Tempo de Execução': []
}

for algorithm in algorithms:
    for case in cases:
        for size in sizes:
            data = generate_fixed_data(size, case)

            start_time = time.time()
            trocas, comps = algorithm(data.copy())
            end_time = time.time()

            data_dict['Algoritmo'].append(algorithm.__name__)
            data_dict['Caso'].append(case.capitalize())
            data_dict['Tamanho'].append(size)
            data_dict['Trocas'].append(trocas)
            data_dict['Comparações'].append(comps)
            data_dict['Tempo de Execução'].append(end_time - start_time)

pd.set_option('display.max_columns', None)
pd.set_option('display.max_rows', None)
pd.set_option('display.width', None)

df = pd.DataFrame(data_dict)
print(df)

excel_filename = 'result.xlsx'
df.to_excel(excel_filename, index=False)
print(f'Dados salvos em {excel_filename}')