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
      out.pixels[pos] = color(valor);
    }
  }
  
  PImage imgMedia = createImage(img.width, img.height, RGB);
  
  // Filtro na escala de cinza
  for(int y = 0; y < img.height; y++){
    for(int x = 0; x < img.width ; x++) {
      int pos = y*img.width + x;
      int jan = 1; // Janela de ordem 1 - 3x3
      float media = 0;
      int qtd = 0;
      
      for (int i = jan*(-1); i <= jan; i++){
        for (int j = jan*(-1); j <= jan; j++) {
          int novoX = x + i;
          int novoY = y + j;
          if( novoX >= 0 && novoX < img.width && novoY >= 0 && novoY < img.height) {
            int posV = novoY * img.width + novoX;
            int valor = (int) red(out.pixels[posV]);
            media += valor;
            qtd++;
          }
        }
      }
      media = media / qtd; 
      imgMedia.pixels[pos] = color(media);
    }
  }

  image(imgMedia, 0, 0);
  save("Caneca1.jpg");
}
