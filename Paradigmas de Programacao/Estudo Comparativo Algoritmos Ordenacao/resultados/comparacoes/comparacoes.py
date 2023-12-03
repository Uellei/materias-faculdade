import numpy as np
import matplotlib.pyplot as plt
import os

# Dados
caso_melhor_1000 = [999,999,0,499500,9976,2939,8006]
caso_melhor_10000 = [9999,9999,0,49995000,133616,54613,120005]
caso_melhor_100000 = [99999,99999,0,4999950000,1668928,615031,1500006]

caso_pior_1000 = [999000,499500,499500,499500,9976,3509,12706]
caso_pior_10000 = [99990000,49995000,49995000,49995000,133616,50831,182565]
caso_pior_100000 = [9999900000,4999950000,4999950000,4999950000,1668928,680665,2344566]

caso_aleatorio_1000 = [962037,498834,251055,499500,9976,4704,15533]
caso_aleatorio_10000 = [97290270,49958685,25108678,49995000,133616,49984,262089]
caso_aleatorio_100000 = [9983400165,4999936470,2500873064,4999950000,1668928,817422,4503862]

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
    plt.ylabel("Comparações")
    plt.yscale('log')
    plt.title(f"Representação das Comparações no {caso} dos algoritmos")
    plt.legend()
    
    path = 'resultados/comparacoes'
    os.makedirs(path, exist_ok=True)  # Cria a pasta se não existir
    plt.savefig(os.path.join(path, f'{caso.lower().replace(" ", "_")}_grafico.png'))
    
    # plt.show()
