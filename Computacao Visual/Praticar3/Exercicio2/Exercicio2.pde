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

      if (y < x) {
        img.pixels[pos] = color(150, 0, 100);
      } else {
        img.pixels[pos] = color(0, 0, 0);
      }
    }
  }
  image(img, 0, 0);
}
