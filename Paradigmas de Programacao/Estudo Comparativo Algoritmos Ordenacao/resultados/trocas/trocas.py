import numpy as np
import matplotlib.pyplot as plt
import os

# Dados
caso_melhor_1000 = [0,0,999,0,5044,511,0]
caso_melhor_10000 = [0,0,9999,0,69008,5904,0]
caso_melhor_100000 = [0,0,99999,0,853904,65535,0]

caso_pior_1000 = [499500,499500,500499,500,4932,509,4700]
caso_pior_10000 = [49995000,49995000,50004999,5000,64608,5910,62560]
caso_pior_100000 = [4999950000,4999950000,5000049999,50000,815024,50862,844560]

caso_aleatorio_1000 = [251055,251055,252054,995,8715,566,7527]
caso_aleatorio_10000 = [25108678,25108678,25118677,9990,120399,5708,142084]
caso_aleatorio_100000 = [2500873064,2500873064,2500973063,99992,1536495,57137,3003856]

# Dicionário para facilitar o loop
dados = {
    "Melhor Caso": [caso_melhor_1000, caso_melhor_10000, caso_melhor_100000],
    "Pior Caso": [caso_pior_1000, caso_pior_10000, caso_pior_100000],
    "Caso Aleatório": [caso_aleatorio_1000, caso_aleatorio_10000, caso_aleatorio_100000]
}

bar_width = 0.25

# Loop sobre os casos
for caso, valores in dados.items():
    plt.figure(figsize=(10, 5))

    for i, conjunto in enumerate(valores):
        r = np.arange(len(conjunto))
        r = [x + bar_width * i for x in r]
        plt.bar(r, conjunto, width=bar_width, label=f"Caso {10 ** (i + 3)}")

    plt.xlabel("Algoritmos")
    plt.xticks([r + bar_width for r in range(len(caso_melhor_1000))],
               ["Bubble Sort", "Improved Bubble Sort", "Insertion Sort", "Merge Sort", "Quick Sort", "Selection Sort",
                "Shell Sort"], rotation=10, ha='right')
    plt.ylabel("Trocas")
    plt.yscale('log')
    plt.title(f"Representação das Trocas no {caso} dos algoritmos")
    plt.legend()
    
    path = 'resultados/trocas'
    os.makedirs(path, exist_ok=True)  # Cria a pasta se não existir
    plt.savefig(os.path.join(path, f'{caso.lower().replace(" ", "_")}_grafico.png'))
    
    # plt.show()
