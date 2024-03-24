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

      if (y < img.width - x) {
        img.pixels[pos] = color(255, 100, 0);
      } else {
        img.pixels[pos] = color(204, 204, 204);
      }
    }
  }
  image(img, 0, 0);
}
