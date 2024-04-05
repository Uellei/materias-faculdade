# Modelo PEAS (Performacce, Environment, Actuatores, Sensors)
É uma estrutura conceitual usada para descrever sistemas inteligentes, como agentes de inteligência artificial. Cada letra representa um aspecto importante do sistema e ajuda a entender como o agente funciona em seu ambiente.

## 1. Performance (Desempenho):
- A medida de desempenho define os critérios pelos quais o sucesso do agente é avaliado. No caso de um carro autônomo, a medida de desempenho pode incluir:
    - Viagem segura e rápida.
    - Condução sem violações às leis de trânsito.
    - Conforto para os passageiros.
    - Maximização dos lucros, no caso de um serviço de táxi autônomo.

## 2. Environment (Ambiente):
- O ambiente refere-se ao contexto no qual o agente opera e interage. No caso de um carro autônomo, o ambiente inclui:
    - Ruas e estradas.
    - Outros veículos.
    - Pedestres.
    - Clientes(se o carro for usado para transporte de passageiros ou entregas).

## 3. Actuatores (Atuadores):
- Os atuadores são os dispositivos ou mecanismos que permitem que o agente aja sobre o ambiente. No caso do carro autônomo, os atuadores podem incluir:
    - Direção.
    - Acelerador.
    - Freio.
    - Embreagem(se o carro for equipado com transmissão manual).
    - Marcha(se aplicável).
    - Seta.
    - Buzina.

## 4. Sensors (Sensores)
- Os sensores são os dispositivos que permitem que o agente perceba e compreenda seu ambiente. No caso do carro autônomo, os sensores podem incluir:
    - Câmeras para visão.
    - Sonar ou sensores de proximidade para detecção de obstáculos.
    - Velocímetro para medir a velocidade.
    - GPS para navegação.
    - Acelerômetro para medir a aceleração do veículo.
    - Sensores do motor para monitorar o desempenho do veículo.
    - Teclado ou microfone para interações com os passageiros ou para entrada de comandos adicionais.

O modelo PEAS fornece uma estrutura clara para entender os componentes essenciais de um agente inteligente, como um carro autônomo, e como esses componentes interagem para alcançar os objetivos definidos pela medida de desempenho.

# Exemplo: Jogo Wumpus

## 1. Performance
- A medida de desempenho pode ser definida em termos de sucesso do jogador em encontrar o tesouro e retornar em segurança à entrada da caverna, evitando ser capturado pelo Wumpus ou cair em armadilhas.
- Desempenho também pode ser medido pela eficiência do jogador em explorar a caverna, minimizando o número de movimentos e ações desnecessárias.

## 2. Environment
- A caverna composta por salar interconectadas, onde cada sala pode conter o tesouro, o Wumpus, buracos e outras pistas.
- O ambiente é dinâmico, pois o jogador pode se mover de uma sala para outra e descobrir informações novas ao longo do jogo.

## 3. Actuators
- Os atuadores no jogo Wumpus podem se incluir:
    - Movimentação do jogador de uma sala para outra.
    - Disparo de uma flecha(para atacar o Wumpus).
    - Ação de coletar o tesouro.

## 4. Sensores
- Os sensores no jogo Wumpus podem incluir:
    - Informações sobre as adjacências da sala(por exemplo, se há correntes de ar indicando a presença de um buraco próximo).
    - Presença do Wumpus ou do tesouro em salar adjacentes.
    - Vibrações(indicando que o Wumpus está proximo).
    - Cheiro(indicando que o Wumpus está em uma sala adjacente).
    - Informações sobre o estado do jogo(por exemplo, se o jogador encontrou o tesouro, foi capturado pelo Wumpus ou caiu em um buraco)