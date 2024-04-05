void setup() {
  size(600, 600);
  noLoop();
  background(255);
}

void draw() {
  PImage img = loadImage("contraste.jpg");
  int [] nk = new int[256];
  float [] pk = new float[256];
  float [] sk = new float[256];
  int [] nsk = new int[256];
  float somatorio = 0;
  
  for(int i = 0;i< 256;i++){
    nk[i] = 0; // Esta inicializando todas as posições com 0
  }
  
    for(int y = 0; y < img.height; y++){
    for(int x = 0; x < img.width; x++) {
      int pos = y*img.width + x;
      int valor = int(red(img.pixels[pos]));
      nk[valor]++;
    }
  }
  
  for(int i = 0; i< 256; i++){
    pk[i] = (float) nk[i] / (img.width * img.height);
  }
  for(int i = 0; i< 256; i++){
    somatorio += pk[i];
    sk[i] = somatorio;
  }
  for(int i = 0; i < 256; i++) {
    nsk[i] = int(sk[i] * 255 + 0.5);
  }
  
  PImage img2 = createImage(img.width, img.height, RGB);
  for(int y = 0; y < img2.height; y++){
    for(int x = 0; x < img2.width; x++) {
      int pos = y*img.width + x;
      int valor = nsk[int(red(img.pixels[pos]))];
      img2.pixels[pos] = color(valor);
    }
  }
  image(img2, 0, 0);
  
}
