## 1 Pintar de forma alternada as colunas
```java
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
```
## 2
```java
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
```
## 3
```java
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
```

## 4
```java
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
```