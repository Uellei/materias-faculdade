import numpy as np
import matplotlib.pyplot as plt
import os

# Dados
caso_melhor_1000 = [0.000148, 0.000000, 0.000000, 0.044666, 0.003000, 0.000000, 0.001997]
caso_melhor_10000 = [0.002868, 0.002000, 0.015610, 3.490626, 0.038720, 0.026803, 0.020783]
caso_melhor_100000 = [0.015613, 0.018635, 0.017608, 350.605896, 0.371218, 0.135475, 0.199464]

caso_pior_1000 = [0.135850, 0.105333, 0.056365, 0.037971, 0.000000, 0.000000, 0.003183]
caso_pior_10000 = [14.524436, 10.220217, 7.100101, 3.485587, 0.031389, 0.022721, 0.031401]
caso_pior_100000 = [1517.986380, 1060.692025, 735.382452, 355.041196, 0.369500, 0.184648, 0.342152]

caso_aleatorio_1000 = [0.112583, 0.066319, 0.044201, 0.031184, 0.015625, 0.001008, 0.001994]
caso_aleatorio_10000 = [11.479670, 7.489761, 3.543427, 3.441242, 0.037905, 0.016601, 0.042134]
caso_aleatorio_100000 = [1217.637489, 782.997709, 363.683738, 356.897012, 0.417782, 0.184452, 0.801743]

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
    plt.ylabel("Tempo de Execução")
    plt.yscale('log')
    plt.title(f"Representação do Tempo de Execução no {caso} dos algoritmos")
    plt.legend()
    
    path = 'resultados/tempo'
    os.makedirs(path, exist_ok=True)  # Cria a pasta se não existir
    plt.savefig(os.path.join(path, f'{caso.lower().replace(" ", "_")}_grafico.png'))
    
    # plt.show()
