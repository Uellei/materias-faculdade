void setup() {
  size(400, 400);
}

void draw() {
  PImage img = loadImage("");
  int somatorio = 0;
  float media;
  
  for(int y = 0; y < img.height; y++) {
    for(int x = 0; x < img.width ; x++) {
      int pos = y*img.width + x;
      somatorio += int(red(img.pixels[pos]));
    }
  }
  media = somatorio / (img.width * img.height);
  println("A media é igual a: " + media);
}
