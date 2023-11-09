// Estação Metereológica - Versao 2S/2023

// Credenciais do Blynk 
// #define BLYNK_TEMPLATE_ID "TMPL22QlKLyBo"
// #define BLYNK_TEMPLATE_NAME "Teste Projeto"
// #define BLYNK_AUTH_TOKEN "Q0MoTK2eWkS_XBW7CA0sroR3phDFanAe"

#define BLYNK_TEMPLATE_ID "TMPL20gaZ65Qd"
#define BLYNK_TEMPLATE_NAME "Quickstart Template"
#define BLYNK_AUTH_TOKEN "gcuf_P8WSOh52CVVklo6G8aO_nyAEjzB"

#define BLYNK_PRINT Serial
char auth[] = BLYNK_AUTH_TOKEN;

// Inclui bibliotecas
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include <Wire.h>
#include <Adafruit_BMP280.h>
#include <BH1750.h>
#include <DHT.h>
#include <AS5600.h>

//Configuracao do Wi-Fi
//#define WIFI_SSID           "FARMBOT"    
//#define WIFI_PASS           "Farm#Uni2018"
//#define WIFI_SSID         "Darth Vader"    
//#define WIFI_PASS         "bololeta11"
#define WIFI_SSID         "Thepeter"    
#define WIFI_PASS         "brenogabriel"

//Define do pino do ESP para o sensor DHT11 (Umidade)
#define DHT_DATA_PIN 32
#define DHTTYPE DHT11
DHT dht(DHT_DATA_PIN, DHTTYPE);

// Define o pino do encoder (Velocidade)
#define EncPIN 35

// Sensor de pressao e temperatura
Adafruit_BMP280 bmp;

// Sensor de luminosidade
BH1750 lightMeter;

// Sensor de direcao do vento (Efeito Hall)
AS5600 as5600; 

// Define os objetos timer para acionar as interrupções
BlynkTimer  timer_leituras; // Define o intervalo entre leituras
BlynkTimer  timer_encoder; // Define intervalo para ler contador

// Define a variável para armazenar o intervalo de amostragem (em milisegundos)
int int_encoder = 2000; // Faz a totalizacao dos pulsos a cada 2 segundos

// Define as variáveis para armazenar os valores lidos
int umidade_media = 0;
int luminosidade_media = 0;
int pressao = 0;
float temperatura_media = 0.0;
int velocidade = 0;
int rotacao = 0;
float direcao = 0;

// Strings que contém o texto indicativo de direção
String get_direcao(float direcao) {
  char *direcoes[] = {"N", "NE", "L", "SE", "S", "SO", "O", "NO"};
  int num_direcoes = sizeof(direcoes) / sizeof(direcoes[0]);
  double setor = 360.0 / num_direcoes;
  int index = int((direcao + setor / 2) / setor) % num_direcoes;
  return direcoes[index];
}

// Variável para ler o status do encoder
bool enc_st = LOW;
bool enc_ant = LOW;

// Variável para armazenar a contagem de pulsos
int cont = 0;

// TESTANDO
#include <HTTPClient.h>
HTTPClient http;

#include <ArduinoJson.h>

template <typename T>
void send_sensor_data_to_server(const String& key, T value) {
  DynamicJsonDocument jsonDocument(256);

  jsonDocument[key] = value;

  String json_str;
  serializeJson(jsonDocument, json_str);

  String url = "http://192.168.233.141:5000/dados";
  String response;

  http.begin(url);
  http.addHeader("Content-Type", "application/json");

  int httpCode = http.POST(json_str);
  Serial.println(json_str);

  if (httpCode > 0) {
    response = http.getString();
    Serial.println("Resposta do servidor:");
    Serial.println(response);
  } else {
    Serial.print("Falha na solicitação HTTP. Código de status: ");
    Serial.println(httpCode);
  }
  http.end();
}

// FIM TESTE

void setup() {
  Serial.begin(115200); // Inicia a comunicação serial com uma taxa de transmissão de 115200 bps (bits por segundo).
  Wire.begin(); // Inicia a comunicação I2C. O I2C é um barramento de comunicação que permite que dispositivos se comuniquem entre si. Neste caso, provavelmente é usado para se comunicar com sensores I2C, como o BMP280 e o BH1750.

  // Configura o pino do encoder como entrada
  pinMode(EncPIN, INPUT); // Este pino é provavelmente usado para ler os pulsos do encoder. A configuração como entrada permite que o Arduino leia o estado lógico no pino, que muda conforme o encoder gira.
  // Configura a interrupção para ser acionada a cada intervalo de amostragem
  timer_leituras.setInterval(1000, run_leitura_temperatura);
  timer_leituras.setInterval(10000, run_leitura_media_temperatura);
  timer_leituras.setInterval(10000, run_leitura_umidade);
  timer_leituras.setInterval(60000, run_leitura_media_umidade);
  timer_leituras.setInterval(10000, run_leitura_luminosidade);
  timer_leituras.setInterval(60000, run_leitura_media_luminosidade);
  timer_leituras.setInterval(10000, run_leitura_pressao);  
  timer_leituras.setInterval(120000, run_leitura_media_pressao);
  timer_leituras.setInterval(5000, run_leitura_direcao);  
  timer_leituras.setInterval(5000, run_leitura_rotacao);

  timer_encoder.setInterval(int_encoder, conta_pulsos); // Essas linhas configuram os temporizadores Blynk. timer_leituras é usado para agendar a função RunLeituras para ser executada a cada int_leituras milissegundos. timer_encoder agendará a função conta_pulsos para ser executada a cada int_encoder milissegundos. Isso permite que você execute essas funções em intervalos regulares.

  // Set WIFI module to STA mode
  WiFi.mode(WIFI_STA); // sta linha define o módulo Wi-Fi do ESP32 para o modo estação (STA). No modo STA, o ESP32 se conecta a uma rede Wi-Fi existente como um cliente.

  Serial.printf("[WIFI] Connecting to %s ", WIFI_SSID);  

  // Tenta conectar ao Wi-Fi e repete tentativa a cada 5 segundos
  while (WiFi.status() != WL_CONNECTED) {
    WiFi.begin(WIFI_SSID, WIFI_PASS);
    // Serial.print(".");
    delay(5000);
  }

  // Inicia DHT11
  dht.begin(); // Umidade

  // Inicia BH1750
  lightMeter.begin(); // Luminosidade

  // Inicia BMP280
  bmp.begin(0x76); // Pressão

  // Inicia AS5600
  as5600.begin(4);  //  Direção do Vento
  as5600.setDirection(AS5600_CLOCK_WISE);  // default, just be explicit.

  // Mensagem de conexão do Blynk
  Blynk.begin(auth,WIFI_SSID,WIFI_PASS); // Esta chamada estabelece a conexão com o servidor Blynk, permitindo o envio e recebimento de dados entre o Arduino e o aplicativo Blynk.
}

void loop() {
  // Executa as tarefas programadas pelo timer
  timer_leituras.run();
  timer_encoder.run();
  // São chamadas para verificar se é hora de executar as funções RunLeituras e conta_pulsos, respectivamente, com base nos temporizadores configurados anteriormente.
  Blynk.run(); // Usado para permitir que o serviço Blynk execute suas tarefas e atualize as informações no aplicativo Blynk.

  // Realiza a contagem de pulsos 
  enc_st = digitalRead(EncPIN);
  if (enc_st == HIGH && enc_ant == LOW) {
    cont++;
    enc_ant = HIGH;
  }
  if (enc_st == LOW && enc_ant == HIGH) {
    enc_ant = LOW;
  }
}

template <typename T>
void add_to_samples(T value, T array[], int& current_index, int max_size) {
  array[current_index] = value;
  current_index = (current_index + 1) % max_size;
}

// template <typename T>
// T calcula_media(T array[], int size) {
//   T peso_total = 0;
//   T media_ponderada = 0;

//   for(int i = 0;i < size;i++) {
//     T peso = static_cast<T>(i) + static_cast<T>(0.5);
//     Serial.print("Peso: ");
//     Serial.println(peso);
//     media_ponderada += array[i] * peso;
//     Serial.print("Media Ponderada: ");
//     Serial.println(media_ponderada);
//     peso_total += peso;
//     Serial.println(peso_total);
//   }
//   media_ponderada /= peso_total;
//   return media_ponderada;
// }

template <typename T>
T calcula_media_exponencial(T array[], int size, float alpha) {
  T media_exponencial = array[0];
  for(int i = 1; i < size; i++) {
    media_exponencial = alpha * array[i] + (1 - alpha) * media_exponencial;
  }
  return media_exponencial;
}

// TEMPERATURA
int index_temp = 0;
float array_temp[10];
void run_leitura_temperatura() {
  float temp = bmp.readTemperature(); // Leitura da temperatura
  add_to_samples(temp, array_temp, index_temp, 10);
}
float temp_ant = 0.0;
bool temperatura_acima_limite = false;
bool envio_limite = true;
bool primeiro_temp_envio = true;
void run_leitura_media_temperatura() {
  temperatura_media = calcula_media_exponencial(array_temp, 10,0.8);
  float diferenca = fabs(temperatura_media - temp_ant);
  if (temperatura_media >= 35.0 && envio_limite) {
    temperatura_acima_limite = true;
  } else if(temperatura_media < 35 && temperatura_media > 34.5){  
    envio_limite = true;
  }
  if (temperatura_acima_limite || diferenca >= 0.5 || primeiro_temp_envio) {
    Blynk.virtualWrite(V0, temperatura_media); // Envie a média para o Blynk
    send_sensor_data_to_server("Temperatura", temperatura_media);
    temp_ant = temperatura_media;
    temperatura_acima_limite = false;
    envio_limite = false;
    primeiro_temp_envio = false;
  }
}

// UMIDADE
float array_umid[10];
int index_umid = 0;
void run_leitura_umidade() {
  float umidade = dht.readHumidity();
  add_to_samples(umidade, array_umid, index_umid, 10);
}

int umidade_ant = 0.0;
bool primeiro_umid_envio = true;
void run_leitura_media_umidade() {
  umidade_media = calcula_media_exponencial(array_umid, 10, 0.7);
  float mudanca_percentual = fabs(umidade_ant - umidade_media) / umidade_ant * 100.0;

  if (primeiro_umid_envio || mudanca_percentual >= 5.0) {
    Blynk.virtualWrite(V1, umidade_media);
    send_sensor_data_to_server("Umidade", umidade_media);
    umidade_ant = umidade_media;
    primeiro_umid_envio = false;
  }
}

// LUMINOSIDADE
float array_lx[6];
int index_lx = 0;
void run_leitura_luminosidade() {
  float lx = lightMeter.readLightLevel();
  Serial.println(lx);
  add_to_samples(lx, array_lx, index_lx, 10);
}

float luminosidade_ant = 0.0;
bool primeiro_lx_envio = true;
void run_leitura_media_luminosidade() {
  luminosidade_media = calcula_media_exponencial(array_lx, 6, 0.5);
  float diferenca_percentual = fabs((luminosidade_media - luminosidade_ant) / luminosidade_ant * 100.0);

  if (diferenca_percentual >= 10.0 || primeiro_lx_envio) {
    Blynk.virtualWrite(V2, luminosidade_media);
    send_sensor_data_to_server("Luminosidade", luminosidade_media);
    luminosidade_ant = luminosidade_media;
    primeiro_lx_envio = false;
  }
}

// PRESSÃO
int array_press[12];
int index_press = 0;
void run_leitura_pressao() {
  pressao = bmp.readPressure() / 100;
  Serial.println(pressao);
  add_to_samples(pressao, array_press, index_press, 12);
}

float pressao_ant = 0.0;
bool primeiro_press_envio = true;
void run_leitura_media_pressao() {
  float pressao_media = calcula_media_exponencial(array_press, 12, 0.7);
  if ((fabs(((pressao_media - pressao_ant) / pressao_ant) * 100) >= 5.0) || primeiro_press_envio) {
    Blynk.virtualWrite(V3, pressao_media);
    send_sensor_data_to_server("Pressao", pressao_media);
    pressao_ant = pressao_media;
    primeiro_lx_envio = false;
  }
}

// DIREÇÃO
int direcao_ant = 0;
void run_leitura_direcao() {
  direcao = int(abs((as5600.rawAngle()*360/4095)));
  if(direcao != direcao_ant) {
    Blynk.virtualWrite(V4, direcao);
    String teste = get_direcao(direcao);
    Serial.println(teste);
    send_sensor_data_to_server("Direcao", direcao);
    direcao_ant = direcao;
  } 
}

// ROTAÇÃO
int rotacao_ant = 0;
void run_leitura_rotacao() {
  if(rotacao_ant != rotacao){
    Blynk.virtualWrite(V5, rotacao);
    send_sensor_data_to_server("Rotacao", rotacao);
    rotacao = rotacao_ant;
  }
  
}

// Rotina para integralizar os pulsos e converter para rpm
void conta_pulsos() {
  rotacao = ((cont * 6) ) * 1000.00 / int_encoder;
  cont = 0; // REFAZER PARA NAO REPETIR VALOR REPETIDO
}