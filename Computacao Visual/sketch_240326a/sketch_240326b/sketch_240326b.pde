void setup() {
  size(600, 600);
  noLoop();
  background(255);
}

void draw() {
  PImage imgEntrada = loadImage("Lena.jpg");
  PImage imgSaida = createImage(imgEntrada.width, imgEntrada.height, RGB);
  int brilho = -90;
  
  for(int y = 0; y < imgEntrada.height; y++){
    for(int x = 0; x < imgEntrada.width; x++) {
      int pos = y*imgEntrada.width + x;
      int valor = int(red(imgEntrada.pixels[pos]));
      valor += brilho;
      if(valor > 255) valor = 255;
      else if(valor < 0) valor = 0;
      imgSaida.pixels[pos] = color(valor);
    }
  }
  image(imgSaida, 0, 0);
}
