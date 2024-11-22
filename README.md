# GSEDGE

Monitor de Energia Limpa com ESP32 e MQTT
Este projeto utiliza um ESP32 para simular a medição de energia limpa gerada por painéis solares e enviar os dados para um broker MQTT. Ele foi desenvolvido como parte de um trabalho acadêmico e tem como objetivo demonstrar o uso de microcontroladores e comunicação MQTT para aplicações em IoT (Internet das Coisas).

📝 Descrição
O projeto mede (ou simula) a energia gerada por uma fonte renovável, como painéis solares, e envia os dados para um servidor MQTT configurado. Esses dados podem ser monitorados por ferramentas como o MQTT Explorer ou integrados a sistemas de visualização de dados, como o Node-RED.

Recursos principais:
Conexão Wi-Fi para envio dos dados.
Comunicação via protocolo MQTT.
Publicação de dados em tópicos MQTT configuráveis.
Simulação de valores de geração de energia.

📋 Requisitos do Projeto

Hardware:
ESP32: microcontrolador principal do projeto.
Fonte de alimentação: cabo USB para alimentar o ESP32.
(Opcional) Sensores de corrente ou tensão, caso deseje medições reais.
Software:
Arduino IDE (versão 1.8.19 ou superior).
Bibliotecas:
WiFi.h (padrão no ESP32).
PubSubClient (para comunicação MQTT).
Broker MQTT:
Você pode usar qualquer servidor MQTT público ou privado. Para este projeto, recomendamos o uso do HiveMQ Public Broker:

Endereço do broker: broker.hivemq.com
Porta: 1883 (sem TLS)
