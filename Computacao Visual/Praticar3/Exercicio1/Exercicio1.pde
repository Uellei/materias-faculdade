void setup() {
  noLoop();
  size(500, 500);
}

void draw() {
  PImage img;
  img = createImage(500, 500, RGB);

  for (int x = 0; x < img.width; x++) {
    
    for (int y = 0; y < img.height; y++) {
      
      int pos = y * img.width + x;

      if (x % 11 < 6) {
        img.pixels[pos] = color(0, 0, 0);
      } else {
        img.pixels[pos] = color(255, 255, 255);
      }
    }
  }
  image(img, 0, 0);
}
