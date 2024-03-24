## 1. Baseado na lista de valores abaixo, faça UMA iteração do algoritmo de ordenação QuickSort, utilizando como pivô o último dígito do seu RA. Entende-se como uma iteração o momento em que ocorre a divisão do vetor em duas partes, dada a posição correta do pivô.  

<img src="https://upload.wikimedia.org/wikipedia/commons/9/9c/Quicksort-example.gif">

## 2. Considere o algoritmo que implementa o seguinte processo: uma coleção desordenada de elementos é dividida em duas metades e cada metade é utilizada como argumento para a reaplicação recursiva do procedimento. Os resultados das duas reaplicações são, então, combinados pela intercalação dos elementos de ambas, resultando em uma coleção ordenada. Qual é a complexidade desse algoritmo?  
#### Merge Sort - `O(n log n)`

## 3. As técnicas de projeto de algoritmos são essenciais para que os desenvolvedores possam implementar software de qualidade. Essas técnicas descrevem os princípios que devem ser adotados para se projetar soluções algoritmicas para um dado problema. Entre as principais técnicas, destacam-se os projetos de algoritmos por tentativa e erro, divisão e conquista, programação dinâmica e algoritmos gulosos. Nesse contexto, faça o que se pede nos itens a seguir.
### a) Descreva o que caracteriza o projeto de algoritmos por divisão e conquista.
##### `Resposta:` O projeto de algoritmos por divisão e conquista é uma técnica que aborda a resolução de problemas complexos dividindo-os em subproblemas menores e resolvendo cada subproblema de forma independente

### b) Apresente uma situação de uso da técnica de projeto de algoritmos por divisão e conquista.
##### `Resposta:` Um exemplo prático de uso da técnica de divisão e conquista é o algoritmo Merge Sort para ordenação de listas. Na etapa de "divisão", a lista é dividida em duas partes iguais. Cada parte é, então, ordenada recursivamente, representando a fase de "conquista". Por fim, as duas partes ordenadas são mescladas (combinadas) para produzir a lista globalmente ordenada.

## 4. 
### I. O método guloso encontra o menor número de moedas para o valor de entrada, considerando as moedas do país.
#### `Verdadeiro:` O algoritmo guloso seleciona a melhor escolha local em cada etapa, visando otimizar a solução global. No contexto de encontrar o menor número de moedas para um valor específico, um algoritmo guloso pode selecionar a maior moeda possível a cada passo, o que muitas vezes leva a uma solução ótima em termos de quantidade mínima de moedas.

### II. Métodos gulosos sempre encontram a solução ótima global.
#### `Falso:` Embora métodos gulosos sejam eficazes em muitos casos, não há garantia de que sempre levem à solução ótima global. A escolha da "melhor opção local" em cada etapa pode não ser a melhor escolha para o problema como um todo. Existem problemas para os quais algoritmos gulosos não produzem a solução mais eficiente ou ótima.

Um exemplo clássico é o "Problema da Mochila Fracionária", onde um algoritmo guloso pode não produzir a solução ótima. Portanto, embora os métodos gulosos sejam poderosos em muitos cenários, é importante avaliar caso a caso e verificar se a estratégia gulosa leva à solução ótima global.

## 5. Alguns tipos de banco de dados e certas ferramentas de desenvolvimento de software atualmente utilizam o paradigma da orientação a objetos. Assinale a afirmação correta quanto aos fundamentos da tecnologia de orientação a objetos.
#### A) As classes são instâncias dos objetos que elas próprias definem.
#### `B) O conceito de herança torna possível que uma classe "herde" em sua definição, variáveis (dados) e métodos (código) de outra classe já existente.`
#### C) A interface é um recurso da orientação a objeto utilizado em Java que define ações que não devem ser obrigatoriamente executadas, mas que cada classe pode executar de forma igual.
#### D) O conceito de polimorfismo possibilita que um objeto seja declarado como pertencendo a mais de uma classe simultaneamente.
#### E) O conceito de encapsulamento prevê que os objetos sejam montados a partir de cápsulas especiais que permitem o acesso aos seus dados por qualquer entidade externa.

### Explicação:
A herança é um dos princípios fundamentais da orientação a objetos, permitindo que uma classe (chamada de classe derivada ou subclasse) herde características (variáveis e métodos) de outra classe (chamada de classe base ou superclasse).
As demais afirmações (A, C, D e E) contêm conceitos que não são precisos ou são incorretos em relação aos fundamentos da orientação a objetos.

## 6. O encapsulamento é um mecanismo da programação orientada a objetos no qual os membros de uma classe (atributos e métodos) constituem uma caixa preta. O nível de visibilidade dos membros pode ser definido pelos modificadores de visibilidade "privado", "público" e "protegido". Com relação ao comportamento gerado pelos modificadores de visibilidade, assinale a opção correta.
#### (A) Um atributo privado pode ser acessado pelos métodos privados da própria classe e pelos métodos protegidos das suas classes descendentes.
#### (B) Um atributo privado pode ser acessado pelos métodos públicos da própria classe e pelos métodos públicos das suas classes descendentes.'
#### (C) Um membro público é visível na classe à qual ele pertence, mas não é visível nas suas classes descendentes.
#### (D) Um método protegido não pode acessar os atributos privados e declarados na própria classe.
#### `(E) Um membro protegido é visível na classe à qual pertence e em suas classes descendentes`.

### Explicação:

(A) Um atributo privado pode ser acessado pelos métodos privados da própria classe e pelos métodos protegidos das suas classes descendentes.

Correção: Um atributo privado só pode ser acessado pelos métodos privados da própria classe, não pelos métodos protegidos das classes descendentes.
(B) Um atributo privado pode ser acessado pelos métodos públicos da própria classe e pelos métodos públicos das suas classes descendentes.

Correção: Um atributo privado só pode ser acessado pelos métodos privados da própria classe, não pelos métodos públicos das classes descendentes.
(C) Um membro público é visível na classe à qual ele pertence, mas não é visível nas suas classes descendentes.

Correção: Um membro público é visível tanto na classe à qual pertence quanto em suas classes descendentes.
(D) Um método protegido não pode acessar os atributos privados e declarados na própria classe.

Correção: Um método protegido pode acessar os atributos protegidos da própria classe, mas não os atributos privados.
(E) Um membro protegido é visível na classe à qual pertence e em suas classes descendentes.

Correção: Correta. Um membro protegido é visível na classe à qual pertence e nas suas classes descendentes.