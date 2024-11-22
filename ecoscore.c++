#include <WiFi.h>
#include <PubSubClient.h>


const char* ssid = "seu_id";          
const char* password = "sua_senha"; 


const char* mqtt_server = "broker.hivemq.com"; 
const int mqtt_port = 1883;                   
const char* mqtt_topic = "casa/energia";      


WiFiClient espClient;
PubSubClient client(espClient);

void setup() {
  Serial.begin(115200);

  
  WiFi.begin(ssid, password);
  Serial.print("Conectando ao Wi-Fi...");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWi-Fi conectado!");
  Serial.print("Endereço IP: ");
  Serial.println(WiFi.localIP());

  
  client.setServer(mqtt_server, mqtt_port);
}

void reconnect() {
  
  while (!client.connected()) {
    Serial.print("Conectando ao broker MQTT...");
    if (client.connect("ESP32Client")) { 
      Serial.println("Conectado ao MQTT!");
    } else {
      Serial.print("Falha ao conectar. Código: ");
      Serial.print(client.state());
      Serial.println(". Tentando novamente em 5 segundos...");
      delay(5000);
    }
  }
}

void loop() {
  
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  
  float energiaProduzida = random(50, 150) / 10.0; 

  
  String mensagem = String(energiaProduzida);
  client.publish(mqtt_topic, mensagem.c_str());

  
  Serial.print("Energia enviada: ");
  Serial.println(mensagem);

  delay(5000); 
}