```java
void setup() {
  size(400, 400);
}

void draw() {
  background(220);
  
  // Base
  fill(255, 204, 0); // A função fill é usada para definir a cor de preenchimento das formas seguintes.
  rect(100, 200, 200, 200); // Desenha um retângulo que representa a base da cada. Sintaxe "rect(x, y, width, height)" e é preenchida com a cor definida anteriormente
  
  // Teto
  fill(255);
  triangle(100, 200, 300, 200, 200, 100); // Desenha um triângulo, as coordenadas fornecidas são os vértices do triângulo "(x1, y1)", "(x2, y2)", "(x3, y3)" 
  
  // Porta
  fill(150, 75, 0);
  rect(180, 300, 40, 100); 
  
  // Janelas
  fill(0, 0, 255); // Azul para as janelas
  rect(130, 230, 40, 40); // Janela esquerda
  rect(230, 230, 40, 40); // Janela direita
}
```