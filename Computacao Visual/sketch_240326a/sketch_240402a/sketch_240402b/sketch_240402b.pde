void setup() {
  size(600, 600);
  noLoop();
}

void draw() {
  PImage img = loadImage("Caneca.jpg");
  PImage out = createImage(img.width, img.height, RGB);
  // Filtro na escala de cinza
  for(int y = 0; y < img.height; y++){
    for(int x = 0; x < img.width ; x++) {
      int pos = y*img.width + x;
      int valor =  (int) ((red(img.pixels[pos]) + blue(img.pixels[pos]) + green(img.pixels[pos])) / 3);
      out.pixels[pos] = color(valor); // na posição pos, ele preenche com rgb sendo a mesma cor do valor (quando passa só um valor pro color ele coloca o mesmo)
    }
  }
  
  PImage imgMedia = createImage(img.width, img.height, RGB);
  
  // Filtro Média 4p
  for(int y = 0; y < img.height; y++){
    for(int x = 0; x < img.width ; x++) {
       int pos = y*img.width + x;
       float media = 0;
       int qtd = 0;
       
       if(y != 0) { // Vizinho Acima
         int posV = (y-1)*img.width + x;
         int valor = (int) red(out.pixels[posV]);
         media += valor;
         qtd++;
       }
       if(y != (img.height - 1)) { // Vizinho Abaixo
         int posV = (y+1)*img.width + x;
         int valor = (int) red(out.pixels[posV]);
         media += valor;
         qtd++;
       }
       if(x != 0) { // Vizinhos a esquerda
         int posV = y*img.width + (x-1);
         int valor = (int) red(out.pixels[posV]);
         media += valor;
         qtd++;
       }
       if(x != (img.width - 1)) { // Vizinhos a esquerda
         int posV = y*img.width + (x+1);
         int valor = (int) red(out.pixels[posV]);
         media += valor;
         qtd++;
       }
       media = ((media + red(out.pixels[pos])) /++qtd);
       imgMedia.pixels[pos] = color(media);
    }
  }
  image(imgMedia, 0, 0);
  save("Caneca1.jpg");
}
