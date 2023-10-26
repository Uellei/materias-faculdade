# Ordenação e Busca - Lista de Exercícios
## 1. Refaça as funções de busca sequencial e busca binária assumindo que a lista possui chaves que podem ocorrer múltiplas vezes na lista. Neste caso, você deve retornar uma lista com todas as posições onde a chave foi encontrada. Se a chave não for encontrada na lista, retornar uma lista vazia.
### Busca Sequencial
```py
def busca_sequencial(lista, chave):
    posicoes = []
    for i in range(len(lista)):
        if lista[i] == chave:
            posicoes.append(i)
    return posicoes
```
### Busca Binária
```py
def pesquisa_binaria_multipla(lista, item):
    posicoes = []
    esquerda, direita = 0, len(lista) - 1
    while esquerda <= direita:
        meio = (esquerda + direita) // 2
        if lista[meio] == item:
            posicoes.append(meio)
            esquerda_temp = meio - 1
            while esquerda_temp >= 0 and lista[esquerda_temp] == item:
                posicoes.append(esquerda_temp)
                esquerda_temp -= 1
            direita_temp = meio + 1
            while direita_temp < len(lista) and lista[direita_temp] == item:
                posicoes.append(direita_temp)
                direita_temp += 1
            return posicoes
        elif lista[meio] > item:
            direita = meio - 1
        else:
            esquerda = meio + 1
    return []
```
## 2. Faça um teste de mesa com cada método de ordenação estudado até o momento, utilizando as seguintes sequências de dados de entrada:
### `a) C1 = {5,7,2,5,6}`
### Bubble Sort
- Primeira Passagem:
    - `(`5 7`)` 2 5 6: 5 < 7 então não troca
    - 5 `(`7 2`)` 5 6 : 7 > 2 então troca: `5,2,7,5,6`
    - 5 2 `(`7 5`)` 6: 7 > 5 então troca: `5,2,5,7,6`
    - 5 2 5 `(`7 6`)`: 7 > 6 então troca: `5,2,5,6,7`
- Segunda Passagem:
    - `(`5 2`)` 5 6 7: 5 > 2 então troca: `2,5,5,6,7`
    - 2 `(`5 5`)` 6 7 : 5 = 5 então não troca: `2,5,5,6,7`
    - 2 5 `(`5 6`)` 7: 5 < 6 então não troca: `2,5,5,6,7`
    - 2 5 5 `(`6 7`)`: 6 < 7 então não troca: `2,5,5,6,7`
- Terceira Passagem:
    - Nehuma troca ocorre, sequência já ordenada
- Quarta Passagem:
    - Nehuma troca ocorre, sequência já ordenada

### Insertion Sort
- Primeira Iteração:
    - 7 > 5 então está no lugar certo
- Segunda Iteração:
    - 2 < 7, move o 7 para a direita: `5,2,7,5,6`
    - 2 < 5, move o 5 para a direita: `2,5,7,5,6`
- Terceira Iteração:
    - 5 < 7, move o 7 para a direita: `2,5,5,7,6`
    - 5 = 5, não há movimento.
- Quarta Iteração:
    - 6 < 7, move o 7 para a direita: `2,5,5,6,7`
    - 6 > 5, não há movimento, array ordenado.

### Selection Sort
- Primeira Iteração:
    - Menor elemento é o 2, troca o 5 e o 2 de posição
    - Troca: `2,7,5,5,6`
- Segunda Iteração:
    - Segundo menor elemento é o 5, troca o 7 e o 5 de lugar
    - Troca: `2,5,7,5,6`
- Terceira Iteração:
    - Terceiro menor elemento é o 5, troca o 7 e o 5 de lugar
    - Troca: `2,5,5,7,6`
- Quarta Iteração:
    - Quarto menor elemento é o 6, troca o 7 e o 6 de lugar
    - Troca: `2,5,5,6,7`

### `C2 = {30,20,10,0, −10}`
### Bubble Sorte
- Primeira Iteração:
    - `(`30, 20`)`,10,0,-10: 30 > 20, então troca: `20,30,10,0,-10`
    - 20,`(`30,10`)`,0,-10: 30 > 10, então troca: `20,10,30,0,-10`
    - 20,10,`(`30,0`)`,-10: 30 > 0, então troca: `20,10,0,30,-10`
    - 20,10,0,`(`30,-10`)`: 30 > -10, então troca: `20,10,0,-10,30`
- Segunda Iteração:
    - `(`20,10`)`,0,-10,30: 20 > 10, então troca: `10,20,0,-10,30`
    - 10,`(`20,0`)`,-10,-30: 20 > 0, então troca: `10,0,20,-10,30`
    - 10,0,`(`20,-10`)`,30: 20 > -10, então troca: `10,0,-10,20,30`
- Terceira Iteração:
    - `(`10,0`)`,-10,20,30: 10 > 0, então troca: `0,10,-10,20,30`
    - 0,`(`10,-10`)`,20,30: 10 > -10, então troca: `0,-10,10,20,30`
    - 0,-10,`(`10,20`)`,30: 10 < 20, então não troca: `0,-10,-10,20,30`
- Quarta Iteração:
    - `(`0,-10`)`,10,20,30: 0 > -10, então troca: `-10,0,10,20,30`
    - -10,`(`0,10`)`,20,30: 0 < 10, então não troca: `-10,0,10,20,30`

### Insertion Sort
- Primeira Iteração:
    - 20 < 30, move o 30 para a direita: `20,30,10,0,-10`
- Segunda Iteração:
    - 10 < 30, move o 30 para a direita: `20,10,30,0,-10`
    - 10 < 20. move o 20 para a direita: `10,20,30,0,-10`
- Terceira Iteração:
    - 0 < 30, move o 30 para a direita
    - 0 < 20, move o 20 para a direita
    - 0 < 10, move o 10 para a direita: `0,10,20,30,-10`
- Quarta Iteração:
    - -10 < 30, move o 30 para a direita
    - -10 < 20, move o 20 para a direita
    - -10 < 10, move o 10 para a direita
    - -10 < 0, move o 0 para a direita: `-10,0,10,20,30`

### Selection Sort
- Primeira Iteração:
    - Menor elemento é o -10, troca 30 e o -10 de lugar
    - Troca: `-10,20,10,0,30`
- Segunda Iteração:
    - Segundo menor elemento é o 0, troca o 20 e o 0 de lugar
    - Troca: `-10,0,10,20,30`
- Terceira Iteração:
    - Terceiro menor elemento é o 10, já esta no lugar e não troca
- Quarta Iteração:
    - Quarto menor elemento é o 20, já esta no lugar e não troca

## c) `C3 = {2,4,6,8,10}`
### Bubble Sort
- Primeira Iteração:
    - `(`2,4`)`6,8,10: 2 < 4, então não troca: `2,4,6,8,10`
    - 2,`(`4,6`)`,8,10: 4 < 6, então não troca: `2,4,6,8,10`
    - 2,4,`(`6,8`)`,10: 6 < 8, então não troca: `2,4,6,8,10`
    - 2,4,6,`(`8,10`)`: 8 < 10, então não troca: `2,4,6,8,10`
- Segunda Iteração:
    -  Nehuma troca ocorre, sequência já ordenada

### Insertion Sort
- Primeira Iteração:
    - 4 > 2, não troca
- Segunda Iteração:
    - 6 < 4, não troca
    - 6 < 2, não troca
- Terceira Iteração:
    - 8 < 6, não troca
    - 8 < 4, não troca
    - 8 < 2, não troca
- Quarta Iteração:
    - 10 < 8, não troca
    - 10 < 6, não troca
    - 10 < 4, não troca
    - 10 < 2, não troca

### Selection Sort
- Primeira Iteração:
    - Menor elemento é o 2, já está no lugar certo e não troca
- Segunda Iteração:
    - Segundo menor elemento é o 4, já está no lugar certo e não troca
- Terceira Iteração:
    - Terceiro menor elemento é o 6, já está no lugar certo e não troca
- Quarta Iteração:
    - Quarto menor elemento é o 8, já está no lugar certo e não troca

## 3. O método insert sort, a cada passo, o menor elemento é procurado para que seja inserido na sequência já ordenada. Essa procura pode ser realizada sequencialmente ou por busca binária. Analise o desempenho de ambas as abordagens.
### Busca Sequencial: 
- `Melhor Caso:` O melhor caso ocorre quando a lista já está ordenada. Nesse caso, a busca sequencial é muito eficiente, pois o algoritmo precisa apenas comparar cada elemento com o seu predecessor na sequência ordenada. A complexidade de tempo é `O(N)` no melhor caso.
- `Pior Caso:` O pior caso ocorre quando a lista está em ordem inversa, e o algoritmo precisa percorrer toda a sequência ordenada para inserir cada elemento. A complexidade de tempo é `O(N²)` no pior caso.
### Busca Binária:
- `Melhor Caso:` O melhor caso ocorre quando a lista está quase completamente ordenada. A busca binária ajuda a encontrar a posição correta de inserção de forma mais eficiente do que a busca sequencial. Nesse cenário, o algoritmo tem um desempenho muito próximo do melhor caso, e a complexidade de tempo `O(log n)`.
- `Pior Caso:` A busca binária não melhora o pior caso em que a lista está em ordem inversa. O algoritmo ainda precisa percorrer toda a sequência ordenada para inserir cada elemento. A complexidade de tempo continua sendo O(n²)

## 4. Pesquise sobre o que significa dizer que um algoritmo de ordenação é estável. Dos algoritmos estudados quais deles são estáveis? Utilize o C1 do exercício 2 para justificar a sua resposta. 
Um algoritmo de ordenação é considerado "estável" quando ele preserva a ordem relativa de elementos chaves iguais(ou seja, elementos que têm o mesmo valor de classificação) após a ordenação. Isso signifca que, se dois elementos A e B têm chaves iguais e a aparece antes de B na lista original, após a ordenação, A ainda aparecerá antes de B na lista ordenada.
- `Bubble Sort`: É um algoritmo estável.
Exemplo: `C1 = {5,7,2,5,6}`
Nesse exemplo quando ele encontrar o `(`5,5`)` por ter o mesmo valor, ele não os trocará, mantendo assim a ordem relativa.
- `Insertion Sort`: É um algoritmo estável, pois, durante a inserção de elementos na lista ordenada, ele mantém a ordem relativa dos elementos com chaves iguais.
Exemplo: `C1 = {5,7,2,5,6}`
Nesse exemplo, quando ele for empurrar os elementos para a direita para inserir, quando ele tentar pegar o segundo "5" ele vai inserir a direita do outro "5" e vai manter a ordem relativa.
- `Selection Sort`: Não é estável.
Exemplo: `C1 = {5,7,2,5,6}`
Nesse exemplo, ele mantém a ordem, mas se o 2 estivesse no lugar do 6, ele não preservaria a ordem relativa e os "5" estariam em ordem relativa diferentes da lista original.

## 5. Desconsidere o conhecimento da função sqrt na linguagem C. Uma forma dese obter a raiz quadrada de um número qualquer x seria através de busca binária. Assuma que a raiz quadrada de x está entre 0 e x (Se o número for negativo, retorne 0). Para sabermos se um palpite y é a raiz quadrada de x, basta testar se y*y é próximo o suficiente de x ou, em outras palavras, se o módulo da diferença entre eles está dentro de uma tolerância definida. Caso contrário, podemos restringir a busca entre 0 e y ou entre y e x. Escreva a função abaixo que implemente este algoritmo, considerando 10-6 como tolerância para o cálculo do resultado.
```py
def raiz(x):
    if x < 0:
        return 0.0

    left, right = 0.0, x
    epsilon = 1e-6 

    while right - left > epsilon:
        mid = (left + right) / 2
        square = mid * mid

        if square > x:
            right = mid
        else:
            left = mid

    return (left + right) / 2
```