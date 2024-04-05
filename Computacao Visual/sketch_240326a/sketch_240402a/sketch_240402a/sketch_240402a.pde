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
      //int valor = (int) blue(img.pixels[pos]);
      out.pixels[pos] = color(valor); // na posição pos, ele preenche com rgb sendo a mesma cor do valor (quando passa só um valor pro color ele coloca o mesmo)
    }
  }
  // Filtro de brilho
  int brilho = 100;
  for(int y = 0; y < img.height; y++){
    for(int x = 0; x < img.width ; x++) {
      int pos = y*img.width + x;
      int valor = (int) red(out.pixels[pos]);
      valor += brilho;
      if(valor > 255) valor = 255;
      out.pixels[pos] = color(valor);
    }
  }
  
  // Filtro de limiarização
  int limiar = 200;
  for(int y = 0; y < img.height; y++){
    for(int x = 0; x < img.width ; x++) {
      int pos = y*img.width + x;
      int valor = (int) red(out.pixels[pos]);
      if (valor > limiar) valor = 255;
      else valor = 0;
      if(y < 100) valor = 0;
      if(y > 545) valor = 0;
      out.pixels[pos] = color(valor);
    }
  }
  image(out, 0, 0);
  save("CanecaBrilhoLimiar.jpg");
}
