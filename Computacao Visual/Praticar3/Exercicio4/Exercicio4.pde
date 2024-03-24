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

      if (y < x && x < 251) {
        img.pixels[pos] = color(0, 100, 150);
      } else if (y < img.width - x && x > 250){
        img.pixels[pos] = color(0, 100, 150);
      } else {
        img.pixels[pos] = color(0,0, 0);
      }
    }
  }
  image(img, 0, 0);
}
