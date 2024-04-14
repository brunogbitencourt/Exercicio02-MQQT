#include <Arduino.h>
#include <WiFi.h>

#include <PubSubClient.h>
#include "Configuracoes.h"
#include "AreaAtuacao.h"




// Criacao das areas de atuacao
AreaAtuacao area01(false, "Area01");
AreaAtuacao area02(false, "Area02");
AreaAtuacao area03(true, "Area03");

void iniciaWifi();  
void initMQTT();
void taskArea(void *pvParameters); 


WiFiClient espClient; // Cria o objeto espClient
PubSubClient MQTT(espClient); // Instancia o Cliente MQTT passando o objeto espClient


void setup() {
    Serial.begin(115200);    
    iniciaWifi(); 
    initMQTT(); // Chamada para inicializar a conexão MQTT

    Serial.println("Iniciando sistema de monitoramento de areas de atuacao");

    xTaskCreate(taskArea, "taskArea01", 4096, &area01, 1, NULL);
    xTaskCreate(taskArea, "taskArea02", 4096, &area02, 1, NULL);
    xTaskCreate(taskArea, "taskArea03", 4096, &area03, 1, NULL);   
}

void loop() {
  // put your main code here, to run repeatedly:
}

void iniciaWifi() {
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
    while (WiFi.status() != WL_CONNECTED)
    {
        vTaskDelay(pdMS_TO_TICKS(500));
        Serial.print(".");
    }
    Serial.println();
    Serial.print("Conectado com sucesso na rede ");
    Serial.print(WIFI_SSID);
    Serial.println("\nIP obtido: ");
    Serial.println(WiFi.localIP());
}

void initMQTT() {
    MQTT.setServer(BROKER_MQTT, BROKER_PORT);   // Informa qual broker e porta deve ser conectado
    if (!MQTT.connected()) {
        // Tentar conectar
        if (MQTT.connect(ID_MQTT)) {
            Serial.println("Conectado ao broker MQTT");
        } else {
            Serial.println("Falha ao conectar ao broker MQTT. Tentando novamente em 5 segundos...");
            // Aguardar 5 segundos antes de tentar novamente
            delay(5000);
            initMQTT(); // Chamada recursiva para tentar reconectar
        }
    }
}

void taskArea(void *pvParameters)
{
    // Cria um objeto Json para armazenar os dados da área de atuação
    AreaAtuacao *area = (AreaAtuacao *)pvParameters;

    while (true)
    {
        // Verifica a conexão WiFi
        if (WiFi.status() != WL_CONNECTED)
        {
            Serial.println("Erro: Não conectado ao WiFi. Tentando reconectar...");
            iniciaWifi(); // Tente reconectar WiFi
            vTaskDelay(pdMS_TO_TICKS(5000)); // Aguarda 5 segundos antes de continuar
            continue; // Retorna ao início do loop para verificar a conexão novamente
        }

        area->atualizaSensores();

        if (MQTT.connected()) {
            StaticJsonDocument<200> doc;
            JsonObject json = doc.to<JsonObject>();
            char output[200]; // Tamanho arbitrário para o buffer de saída
            char areaNome[50]; // Tamanho arbitrário para o buffer de destino

            area->toJsonSensores(json);
            serializeJson(doc, output, sizeof(output));
          
            strcpy(areaNome, area->getAreaID().c_str()); // Copia a área ID para o buffer
            strcat(areaNome, "/sensor");                  // Concatena "/sensor" ao final do buffer

            MQTT.publish(areaNome, output);
            Serial.println("Mensagem Publicada no topico: " + String(areaNome));
            Serial.println("Dados: " + String(output));
            
            doc.clear(); // Limpa o conteúdo do documento JSON
            json = doc.to<JsonObject>(); // Converte o documento para um objeto JSON
            area->toJsonAtuadores(json);
            serializeJson(doc, output, sizeof(output));
            strcpy(areaNome, "");
            strcpy(areaNome, area->getAreaID().c_str()); // Copia a área ID para o buffer
            strcat(areaNome, "/atuador");                // Concatena "/atuador" ao final do buffer

            MQTT.publish(areaNome, output);
            Serial.println("Mensagem Publicada no topico: " + String(areaNome));
            Serial.println("Dados: " + String(output));

            doc.clear(); // Limpa o conteúdo do documento JSON
            json = doc.to<JsonObject>(); // Converte o documento para um objeto JSON
            area->toJsonAlertas(json);
            serializeJson(doc, output, sizeof(output));
            strcpy(areaNome, "");
            strcpy(areaNome, area->getAreaID().c_str()); // Copia a área ID para o buffer
            strcat(areaNome, "/alerta");                 // Concatena "/alerta" ao final do buffer

            MQTT.publish(areaNome, output);
            Serial.println("Mensagem Publicada no topico: " + String(areaNome));
            Serial.println("Dados: " + String(output));
        } else {
            Serial.println("Erro: Não conectado ao servidor MQTT. Tentando reconectar...");
            if (WiFi.status() != WL_CONNECTED); // Tente reconectar WiFi
                iniciaWifi(); // Tente reconectar WiFi
            initMQTT(); // Tente reconectar MQTT
        }

        //Serial.println(area->getAreaID() + " publicou no tópico MQTT");

        MQTT.loop();

        vTaskDelay(pdMS_TO_TICKS(5000));
    }
}



