# Introdução à Computação Gráfica
## 1 Introdução
Área que estuda a geração, manipulação e análise de imagens, através do computador. Se dedica ao estudo e desenvolvimento de técnias e aloritmos para a geração (síntese) de imagens através do computador.

### 1.2 Aplicação

Uma área de aplicação da CG que tem crescido muito nos últimos anos é a visualização. Inicialmente, surgiu a visualização científica, que visava o desenvolvimento de representações gráficas para grandes volumes de dados gerados. Hoje, existem visualização volumétrica, trata de como gerar representações para dados volumétricos, tais como dados meteorológicos, oceanográficos e médicos, e a visualização de informações, uma área que visa auxiliar na análise de dados financeiros, mineração de dados, estudos do mercado ou de gerenciamento de redes de computadores.

### 1.3 Hardware Gráfico
Os dispositivos gráficos podem ser classificados quanto à finalidade em dispositivos de entrada, saída, ou de entrada e saída, e quanto ao formato dos dados em dispositivos matriciais ou vetoriais.
- Matriciais são aqueles cujos dados são capturados e/ou exibidos na forma de matrizes, ou seja, um conjunto de `pixels`. O digitalizador e scanner são exemplos de matriciais de entrada. Pode-se dizer que a grande maioria dos dispositivos de saída são matriciais, tais como impressoras, stereo glasses, caves, e monitores de vídeo.
- Vetoriais: Equipamentos através dos quais se pode coletar e/ou exibir dados de forma isolada, associados a uma posição do plano/espaço. Entre os de entrada destacam-se o mouse, o digitalizador espacial, a luva eletrônica e os dispositivos para rastreamento. O exemplo mais comum de dispositivo de saída é o plotador gráfico.
- Dispositivos de entrada e saída: São aqueles onde há captura de informação e exibição/resposta ao usuário. Por exemplo, dispositivos de resposta tátil, ou seja, que permitem a captura de movimentos e geram sensações de tato e força. Outro exemplo é o monitor touch.

### 1.4 Áreas Relacionadas
Há duas áreas que têm uma relação bastante próxima com a CG: `Processamento de Imagens (PI)` e `Visão Computacional`.
- PI: Estudo e pequisa de técnicas para realizar a manipulação de imagens, tais como ajustes de cor, brilho, contraste ou aplicação de filtros, entre outras.
- Visão Computacional: Análise de imagens, buscando obter a especificação dos seus componentes para identificação dos modelos geométricos que a compõem. Uma aplicação de técnicas de Visão Computacional é o reconhecimento automático de impressões digitais.

## 2 Modelagem Geométrica
Modelagem consiste em todo o processo de descrever um modelo, objeto ou cena, de forma que se possa desenhá-lo. Modelagem engloba dois tópoicos de estudo: `formas de representação dos objetos` que se preocupa com a forma(estrutura dos objetos) como os modelos são armazenados; e `técnicas de modelagem dos objetos`, que trata das técnicas interativas(e também das interfaces) que podem ser usadas para criar um modelo de objeto.

### 2.1 Representação
É possível enumerar quatro formas de representação, de acordo com a importância e frequência de utilização: (1) malha de polígonos; (2) superfícies paramétricas; (3) Geometria Sólida Construtiva (CSG); (4) enumeração de ocupação espacial.
- 1 e 4 consistem numa aproximação da forma do objeto que está sendo modelado.
- 2 e 3 são representações exatas.
- 1 e 2 representam apenas a superfície do objeto.
- 3 e 4 representam o volume inteiro.

A forma mais comum de representar modelos 3D é através de uma `manha de polígonos`. Define-se um conjunto de vértices no espaço(geometria) e como esses vértices devem ser ligados para formarem polígonos fechados, chamados de face(topologia), que podem ser triângulos ou quadrados.

### 2.2 Instanciamento de Primitivas
O sistema de modelagem define um conjunto de objetos primitivos 3D que são relevantes para a área de aplicação. Podem ser representandos, por exemplo, por malhas de polígonos ou superfícies paramétricas. Depois, estes objetos podem ser parametrizados, tanto em termos de transformações geométricas, como em outras propriedades, e agrupados. Igual uma figura de uma mesa redonda formada pelo instanciamento de três cilindros, com diferentes alturas e raios.

### 2.3 Varredura Rotacional e Translacional
Útil para a construção de objetos 3D que possuam algum tipo de simetria. Um objeto é gerado pelo arrastar de uma curva ou superfície(chamada geradora ou geratriz), que determina sua forma, ao longo de uma trajetória(diretriz). Os dois tipos mais comuns são: `Varredura Rotacional(ou sweep)`, quando a trajetória é um círculo ao redor de um dos eixos; e `Varredura Translacional(extrusão)`, quando a trajetória é uma linha. Conforme a geratriz vai sendo arrastada, os pontos se conectam e formam uma malha de polígonos.

### 2.4 Superfícies Paramétricas
São usadas quando se necessita trabalhar com superfícies suaves na modelagem de objetos de forma livre. Uma representação muito utilizada são os patches paramétricos bicúbicos, que permitem calcular as coordenadas de todos os pontos que formam uma superfície curva através da definjição de 16 pontos de controle e da utilização de três equações, uma para x, uma para y e uma para z. Cada equação possui duas variáveis(ou parâmetros) e termos para todo domínio dos parâmetros até o seu cubo.
Patch é uma superfície na qual cada um dos pontos que a formam devem ser processados. Inicialmente devem ser definidos 16 pontos 3D, chamados pontos de controle. Quatro destes pontos que determinam a forma do patch pertencem aos seus cantos. A partir da especificação dos pontos de controle, são usadas três funções para calcular os valores intermediários que, simplificadamente, são resultantes de uma interpolação. Através de parâmetros passados para as funções, é possível determinar a quantidade de valores intermediários calculados. Além disso, sempre que um ponto de controle é alterado, os pontos que formam a superfície devem ser gerados novamente.