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
      //int valor =  (int) ((red(img.pixels[pos]) + blue(img.pixels[pos]) + green(img.pixels[pos])) / 3);
      int valor = (int) blue(img.pixels[pos]);
      out.pixels[pos] = color(valor); // na posição pos, ele preenche com rgb sendo a mesma cor do valor (quando passa só um valor pro color ele coloca o mesmo)
    }
  }
  // Como o objetivo era destacar a caneca, deixar cinza com a cor do azul, deixa ela mais destacada, visto que a caneca tem um tom de azul.
  image(out, 0, 0);
  save("CanecaGreyBlue.jpg");
}
