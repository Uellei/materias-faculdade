```java
void setup() {
  size(400, 400);
}

void draw() {
  background(135, 206, 250); // Define o céu como azul claro
  // Montanhas
  fill(181, 230, 29);
  noStroke(); // Remove o traço
  for(int x = 0; x < 6; x++) {
    ellipse(20 + (x * 80), 110, 100, 100);
  }
  fill(255, 255, 0);
  ellipse(10, 10, 80, 80);

  // Desenha quatro casas
  desenharCasa(0, color(0, 162, 232)); // Casa 1
  desenharCasa(100, color(158, 1, 1)); // Casa 2
  desenharCasa(200, color(227, 215, 0)); // Casa 3
  desenharCasa(300, color(207, 103, 32)); // Casa 4
  
  // Rua
  fill(100);
  rect(0, 210, width, height - 320);
  line(0, 250, 30, 250);
  line(100, 250, 60, 250);
  line(170, 250, 130, 250);
  line(240, 250, 200, 250);
  line(310, 250, 270, 250);
  line(380, 250, 340, 250);
  
  // Lago
  fill(135, 206, 250);
  quad(0, 290, width/2, 290, width/1.3, height, 0, height);
  
  // Peixes
  desenharPeixe(50, 330, 0, 162, 232);
  desenharPeixe(100, 360, 0, 162, 232);
  desenharPeixe(150, 310, 0, 162, 232);
  desenharPeixe(240, 380, 0, 162, 232);

  // Grama
  fill(181, 230, 29);
  quad(width/2, 290, width, 290, height, height, width/1.3, height);
}

void desenharCasa(int x, color cor) {
  // Base
  stroke(0);
  fill(cor);
  rect(x, 130, 100, 80); // x, y, width, height
  
  // Telhado
  fill(33, 22, 16);
  triangle(x, 130, x + 50, 90, x + 100, 130);
  
  // Porta
  fill(102, 51, 0);
  rect(x + 40, 180, 20, 30);
  
  // Janela    
  fill(255); // Branco
  rect(x + 10, 150, 20, 20); // Janela 1
  rect(x + 70, 150, 20, 20); // Janela 2
  // Desenha os mini quadrados da cruz na janela
  line(x + 10, 160, x + 30, 160); // Linha horizontal
  line((x + 10) + (20 / 2), 150, (x + 10) + (20 / 2), 150 + 20); // Linha vertical
  
  line(x + 70, 160, x + 90, 160); // Linha horizontal
  line((x + 70) + (20 / 2), 150, (x + 70) + (20 / 2), 150 + 20); // Linha vertical
  
  // Fechadura
  fill(0); // Preto
  ellipse(x + 55, 195, 2, 2); // Desenha a fechadura redonda
}

void desenharPeixe(float x, float y, int r, int g, int b) {
  // Corpo do peixe
  fill(r, g, b);
  ellipse(x, y, 30, 20);
  
  // Cauda do peixe
  triangle(x - 15, y, x - 30, y - 10, x - 30, y + 10);
  
  // Olho do peixe
  fill(255);
  ellipse(x + 10, y, 5, 5);
}
```