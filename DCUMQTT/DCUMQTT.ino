#include "DBC_SL3_18072023_teste3.h"
#include <LiquidCrystal.h>
#include <WiFi.h> 
#include <PubSubClient.h> 
#include <ArduinoJson.h>
#include <ArduinoJson.hpp>

// inicializar a biblioteca associando qualquer pino de interface LCD necessário
// com o número do pino arduino está ligado a
//const int rs = 10, en = 17, d4 = 12, d5 = 13, d6 = 14, d7 = 15;

//Configuração LCD(pinos de Data trocar) Consultar Documentação
//LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

CAN_device_t CAN_cfg;

// Definição de RPM's para cada troca de marcha
#define troca1marchamax 11500
#define troca2marchamax 11500
#define troca3marchamax 11200
#define troca4marchamax 11000
#define troca5marchamax 10900

//Definição dos dados para conectar no wifi e no mqtt
#define TOPICO_SUBSCRIBE "FSAELive/IC/MauaRacing/Telemetry/rx"   
#define ID_MQTT  "fa12e506-eff6-4b91-b824-db3a5d25bada"     
#define USER_MQTT "public"
#define PASSWORD_MQTT "public"

const char* SSID = "Esp32"; 
const char* PASSWORD = "12345678"; 

const char* BROKER_MQTT = "mqtt.maua.br"; 
int BROKER_PORT = 1883;
WiFiClient espClient;
PubSubClient MQTT(espClient);
  
void wifi(void);
void verificaConexoes(void);

int rx_Received = 0;

//Led acionados da shift lights
int led1_shift =16;
int led2_shift = 17;
int led3_shift= 18;
int led4_shift = 20;


float vBat;
int Engine_RPM;
float GPS_Speed;
int Gear;

float Eng_Oil_Pres;
float Engine_Temp;
float Air_Temp_Inlet;
float ECU_Temp;

int Brake_Pressure_Front;
int Brake_Pressure_Rear;
float manifold_Pres;
float Fuel_Pres;

float ETC_1;
float ETC_2;
float ETC_3;
float SDL_Temp;

float Lambda_1;
float G_Force_Lat;
float G_Force_Long;
float G_Force_Vert;

float Throttle_Pos;
float Fuel_Used;
int Beacon;
float GPS_Altitude;

float GPS_Latitude;
float GPS_Longitude;

const uint8_t taskCoreZero = 0;
const uint8_t taskCoreOne = 1;

static void maincode(void *pvParameters);
static void ReadVariables(void *pvParameters);

void printarGear();
void shiftlights();
void printRPM();

void setup(){
    Serial.begin(115200);
    Serial.println("Conectando-se ao WIFI: ");
    Serial.println(SSID);
    wifi();
    MQTT.setServer(BROKER_MQTT, BROKER_PORT); 
    // Configuração do LCD
    //lcd.begin(16,2);
    //lcd.setCursor(0, 0);


    //Configuração dos LED´s da Shift Lights
    pinMode(led1_shift,OUTPUT);
    pinMode(led2_shift,OUTPUT);
    pinMode(led3_shift,OUTPUT);
    pinMode(led4_shift,OUTPUT);

    //Configuração dos pinos de Rede CAN
    CAN_cfg.tx_pin_id = GPIO_NUM_4;
    CAN_cfg.rx_pin_id = GPIO_NUM_5;
    CAN_cfg.speed = CAN_SPEED_1000KBPS;
    CAN_cfg.rx_queue = xQueueCreate(10,sizeof(CAN_frame_t));

    //initialize CAN
    CAN_init();
    delay(200);
    Serial.println("CAN foi");
    delay(100);
    xTaskCreatePinnedToCore(ReadVariables, "Atualiza as variaveis do codigo", 4096, NULL, 1, NULL, taskCoreOne);
    delay(100);
    xTaskCreatePinnedToCore(maincode, "Codigo Principal", 4096, NULL, 1, NULL, taskCoreZero);
    delay(100);

}

void wifi(void) {
    if (WiFi.status() == WL_CONNECTED)
        return;
    WiFi.begin(SSID, PASSWORD);
    while (WiFi.status() != WL_CONNECTED) {
        delay(100);
        Serial.print(".");
    }
    Serial.println();
    Serial.print("Conectado com sucesso na rede ");
    Serial.print(SSID);
    Serial.println("IP obtido: ");
    Serial.println(WiFi.localIP());
} 

void reconnect_mqtt(void) {
    while (!MQTT.connected()) {
        Serial.print("* Tentando se conectar ao Broker MQTT: ");
        Serial.println(BROKER_MQTT);
        if (MQTT.connect(ID_MQTT, USER_MQTT, PASSWORD_MQTT)) 
        {
            Serial.println("Conectado com sucesso ao broker MQTT!");
        } 
        else
        {
            Serial.println("Falha ao reconectar no broker.");
        }
    }
}

void enviaMQTT(char* msg){
  MQTT.publish(TOPICO_SUBSCRIBE, msg);
}

void verificaConexoes(void){
    wifi(); 
    if (!MQTT.connected()) 
        reconnect_mqtt(); 
} 

//Printar o Sinal do Gear(Marcha) para o Display LCD
void printarGear(){
  //lcd.setCursor(0,0);
  //lcd.print("Marcha: ");
  //lcd.print(Gear);
  
}


//Controle da ShiftLights
void shiftlights(){
// Cada If aciona a shift lights em determinados valores
  if (Gear == 1){
    digitalWrite(led1_shift,LOW);
    digitalWrite(led2_shift,LOW);
    digitalWrite(led3_shift,LOW);
    digitalWrite(led4_shift,LOW);
    if(Engine_RPM <= troca1marchamax/4){
      digitalWrite(led1_shift,HIGH);
    }
    if((Engine_RPM <= troca1marchamax/3) && (Engine_RPM > troca1marchamax/4)){
      digitalWrite(led1_shift,HIGH);
    }
    if((Engine_RPM <= troca1marchamax/2) && (Engine_RPM > troca1marchamax/3)){
      digitalWrite(led1_shift,HIGH);
    }
    if((Engine_RPM <= troca1marchamax)&& (Engine_RPM > troca1marchamax/2)){
      digitalWrite(led1_shift,HIGH);
    }
  }
  if (Gear == 2){
    
    digitalWrite(led1_shift,LOW);
    digitalWrite(led2_shift,LOW);
    digitalWrite(led3_shift,LOW);
    digitalWrite(led4_shift,LOW);
    if(Engine_RPM <= troca2marchamax/4){
      digitalWrite(led1_shift,HIGH);
    }
    if((Engine_RPM <= troca2marchamax/4) && (Engine_RPM > troca2marchamax/4)){
      digitalWrite(led2_shift,HIGH);
    }
    if((Engine_RPM <= troca2marchamax/2) && (Engine_RPM > troca2marchamax/3)){
      digitalWrite(led3_shift,HIGH);
    }
    if((Engine_RPM <= troca2marchamax) && (Engine_RPM > troca2marchamax/2)){
      digitalWrite(led4_shift,HIGH);
    }
  }
  if (Gear == 3){
    
    digitalWrite(led1_shift,LOW);
    digitalWrite(led2_shift,LOW);
    digitalWrite(led3_shift,LOW);
    digitalWrite(led4_shift,LOW);
    if(Engine_RPM <= troca3marchamax/4){
      digitalWrite(led1_shift,HIGH);
    }
    if((Engine_RPM <= troca3marchamax/3) && (Engine_RPM > troca3marchamax/4)){
      digitalWrite(led2_shift,HIGH);
    }
    if((Engine_RPM <= troca3marchamax/2) && (Engine_RPM > troca3marchamax/3)){
      digitalWrite(led3_shift,HIGH);
    }
    if((Engine_RPM <= troca3marchamax)  && (Engine_RPM > troca3marchamax/2)){
      digitalWrite(led4_shift,HIGH);
    }
  }
  if (Gear == 4){
    
    digitalWrite(led1_shift,LOW);
    digitalWrite(led2_shift,LOW);
    digitalWrite(led3_shift,LOW);
    digitalWrite(led4_shift,LOW);
    if(Engine_RPM == troca4marchamax/4){
      digitalWrite(led1_shift,HIGH);
    }
    if((Engine_RPM <= troca4marchamax/3) && (Engine_RPM > troca4marchamax/4)){
      digitalWrite(led2_shift,HIGH);
    }
    if((Engine_RPM <= troca4marchamax/2) && (Engine_RPM > troca4marchamax/3)){
      digitalWrite(led3_shift,HIGH);
    }
    if((Engine_RPM <= troca4marchamax) && (Engine_RPM > troca4marchamax/2)){
      digitalWrite(led4_shift,HIGH);
    }
  }
  if (Gear == 5){
    
    digitalWrite(led1_shift,LOW);
    digitalWrite(led2_shift,LOW);
    digitalWrite(led3_shift,LOW);
    digitalWrite(led4_shift,LOW);
    if(Engine_RPM <= troca5marchamax/4){
      digitalWrite(led1_shift,HIGH);
    }
    if((Engine_RPM <= troca5marchamax/3)  && (Engine_RPM > troca5marchamax/4)){
      digitalWrite(led1_shift,HIGH);
    }
    if((Engine_RPM <= troca5marchamax/2)  && (Engine_RPM > troca5marchamax/3)){
      digitalWrite(led1_shift,HIGH);
    }
    if((Engine_RPM <= troca5marchamax) && (Engine_RPM > troca5marchamax/2)){
      digitalWrite(led1_shift,HIGH);
    }
  }
  else{
    
    digitalWrite(led1_shift,HIGH);
    digitalWrite(led2_shift,HIGH);
    digitalWrite(led3_shift,HIGH);
    digitalWrite(led4_shift,HIGH);
  }

}

void printRPM(){
  //lcd.setCursor(0,1);
  //lcd.print(GPS_Speed);
}

void maincode(void *pvParameters) { 

    TickType_t myLastUnblock = xTaskGetTickCount();
    while(1){
        /*Serial.println(vBat);
        Serial.println(" V_Bateria\t");
        Serial.println(Engine_RPM);
        Serial.println(" RPM\t");
        Serial.println(GPS_Speed);
        Serial.println(" GPS speed\t");
        Serial.println(Gear);
        Serial.println(" Gear\t");
        Serial.println(Eng_Oil_Pres);
        Serial.println(" Oil Pres\t");
        Serial.println(Engine_Temp);
        Serial.println(" Eng Temp\t");
        Serial.println(Air_Temp_Inlet);
        Serial.println(" Temp Inlet\t");
        Serial.println(ECU_Temp);
        Serial.println(" ECU temp\t");
        Serial.println(Brake_Pressure_Front);
        Serial.println(" Pres Front\t");
        Serial.println(Brake_Pressure_Rear);
        Serial.println(" Pres Rear\t");
        Serial.println(manifold_Pres);
        Serial.println(" Pres manifold\t");
        Serial.println(Fuel_Pres);
        Serial.println(" Fuel Pres\t");
        Serial.println(ETC_1);
        Serial.println(" ETC 1\t");
        Serial.println(ETC_2);
        Serial.println(" ETC 2\t");
        Serial.println(ETC_3);
        Serial.println(" ETC 3\t");
        Serial.println(SDL_Temp);
        Serial.println(" SDL temp\t");
        Serial.println(Lambda_1);
        Serial.println(" LA\t");
        Serial.println(G_Force_Lat);
        Serial.println(" G Lat\t");
        Serial.println(G_Force_Long);
        Serial.println(" G Long\t");
        Serial.println(G_Force_Vert);
        Serial.println(" G vert\t");
        Serial.println(Throttle_Pos);
        Serial.println(" % TH\t");
        Serial.println(Fuel_Used);
        Serial.println(" Fuel Used\t");
        Serial.println(Beacon);
        Serial.println(" Beacon\t");
        Serial.println(GPS_Altitude);
        Serial.println(" GPS altitude\t");
        Serial.println(GPS_Latitude);
        Serial.println(" GPS Lat\t");
        Serial.println(GPS_Longitude);
        Serial.println(" GPS Long\t");*/
        shiftlights();
        printarGear();
        printRPM();
        verificaConexoes();
        MQTT.loop();
        }
        vTaskDelayUntil(&myLastUnblock, 5000 / portTICK_RATE_MS);

}

void ReadVariables(void *pvParameters){

    PDO1_DCU_Data PDO1_DCU_Data;
    PDO1_DCU_Val PDO1_DCU_Val;
    PDO2_DCU_Data PDO2_DCU_Data;
    PDO2_DCU_Val PDO2_DCU_Val;
    PDO3_DCU_Data PDO3_DCU_Data;
    PDO3_DCU_Val PDO3_DCU_Val;
    PDO4_DCU_Data PDO4_DCU_Data;
    PDO4_DCU_Val PDO4_DCU_Val;
    PDO5_DCU_Data PDO5_DCU_Data;
    PDO5_DCU_Val PDO5_DCU_Val;
    PDO6_DCU_Data PDO6_DCU_Data;
    PDO6_DCU_Val PDO6_DCU_Val;
    PDO7_DCU_Data PDO7_DCU_Data;
    PDO7_DCU_Val PDO7_DCU_Val;

    TickType_t myLastUnblock = xTaskGetTickCount();
    CAN_frame_t PDO1_DCU;
    CAN_frame_t PDO2_DCU;
    CAN_frame_t PDO3_DCU;
    CAN_frame_t PDO4_DCU;
    CAN_frame_t PDO5_DCU;
    CAN_frame_t PDO6_DCU;
    CAN_frame_t PDO7_DCU;
    while(1){
        if(xQueueReceive(CAN_cfg.rx_queue, &PDO1_DCU, 3 * portTICK_PERIOD_MS) == pdTRUE) rx_Received = 1;
        else rx_Received = 0;


        if(rx_Received && PDO1_DCU.MsgID == 0x1F0){
            PDO1_DCU_Data.PDO1_DCU_7 = PDO1_DCU.data.u8[0];
            PDO1_DCU_Data.PDO1_DCU_6 = PDO1_DCU.data.u8[1];
            PDO1_DCU_Data.PDO1_DCU_5 = PDO1_DCU.data.u8[2];
            PDO1_DCU_Data.PDO1_DCU_4 = PDO1_DCU.data.u8[3];
            PDO1_DCU_Data.PDO1_DCU_3 = PDO1_DCU.data.u8[4];
            PDO1_DCU_Data.PDO1_DCU_2 = PDO1_DCU.data.u8[5];
            PDO1_DCU_Data.PDO1_DCU_1 = PDO1_DCU.data.u8[6];
            PDO1_DCU_Data.PDO1_DCU_0 = PDO1_DCU.data.u8[7];
            atualizaRX_PDO1_DCU(&PDO1_DCU_Val, &PDO1_DCU_Data);

            vBat = (PDO1_DCU_Val.Bat_Volts_SDL_Val*0.01);
            Engine_RPM = (PDO1_DCU_Val.Engine_RPM_Val*6);
            GPS_Speed = (PDO1_DCU_Val.GPS_Speed_Val*0.1);
            Gear = (PDO1_DCU_Val.Gear_Val);
            
            DynamicJsonBuffer Jbuffer;
            JsonObject& root = Jbuffer.createObject();
            JsonObject& fields = root.createNestedObject("fields");
            fields["sld3_battery_voltage"] = vBat;
            fields["engine_rpm"] = Engine_RPM;
            fields["gps_speed"] = GPS_Speed;
            fields["gear"] = Gear;
            root["name"]="pd01_dcu";
            root["timestamp"]= 1713288706239;
            
            char JSONmessageBuffer[100];
            root.printTo(JSONmessageBuffer, sizeof(JSONmessageBuffer));
            enviaMQTT(JSONmessageBuffer);
            
        }
        if (rx_Received && PDO2_DCU.MsgID == 0x1F1){

          PDO2_DCU_Data.PDO2_DCU_7 = PDO2_DCU.data.u8[0];
          PDO2_DCU_Data.PDO2_DCU_6 = PDO2_DCU.data.u8[1];
          PDO2_DCU_Data.PDO2_DCU_5 = PDO2_DCU.data.u8[2];
          PDO2_DCU_Data.PDO2_DCU_4 = PDO2_DCU.data.u8[3];
          PDO2_DCU_Data.PDO2_DCU_3 = PDO2_DCU.data.u8[4];
          PDO2_DCU_Data.PDO2_DCU_2 = PDO2_DCU.data.u8[5];
          PDO2_DCU_Data.PDO2_DCU_1 = PDO2_DCU.data.u8[6];
          PDO2_DCU_Data.PDO2_DCU_0 = PDO2_DCU.data.u8[7];
          atualizaRX_PDO2_DCU(&PDO2_DCU_Val, &PDO2_DCU_Data);

          Eng_Oil_Pres = (PDO2_DCU_Val.Eng_Oil_Pres_Val*0.1 - 3276.7);
          Engine_Temp = (PDO2_DCU_Val.Engine_Temp_Val*0.1);
          Air_Temp_Inlet = (PDO2_DCU_Val.Air_Temp_Inlet_Val*0.1);
          ECU_Temp = (PDO2_DCU_Val.ECU_Temp_Val*0.1);
          
          DynamicJsonBuffer Jbuffer1;
          JsonObject& root1 = Jbuffer1.createObject();
          JsonObject& fields1 = root1.createNestedObject("fields");
          fields1["engine_oil_pressure"] = Eng_Oil_Pres;
          fields1["engine_temperature"] = Engine_Temp;
          fields1["engine_intake_air_temperature"] = Air_Temp_Inlet;
          fields1["engine_ecu_temperature"] = ECU_Temp;
          root1["name"]="pd02_dcu";
          root1["timestamp"]= 1713288706239;
            
          char JSONmessageBuffer1[100];
          root1.printTo(JSONmessageBuffer1, sizeof(JSONmessageBuffer1));
          enviaMQTT(JSONmessageBuffer1);
        }
        if (rx_Received && PDO3_DCU.MsgID == 0x1F2){

          PDO3_DCU_Data.PDO3_DCU_7 = PDO3_DCU.data.u8[0];
          PDO3_DCU_Data.PDO3_DCU_6 = PDO3_DCU.data.u8[1];
          PDO3_DCU_Data.PDO3_DCU_5 = PDO3_DCU.data.u8[2];
          PDO3_DCU_Data.PDO3_DCU_4 = PDO3_DCU.data.u8[3];
          PDO3_DCU_Data.PDO3_DCU_3 = PDO3_DCU.data.u8[4];
          PDO3_DCU_Data.PDO3_DCU_2 = PDO3_DCU.data.u8[5];
          PDO3_DCU_Data.PDO3_DCU_1 = PDO3_DCU.data.u8[6];
          PDO3_DCU_Data.PDO3_DCU_0 = PDO3_DCU.data.u8[7];
          atualizaRX_PDO3_DCU(&PDO3_DCU_Val, &PDO3_DCU_Data);

          Brake_Pressure_Front = (PDO3_DCU_Val.Brake_Pressure_Front_Val);
          Brake_Pressure_Rear = (PDO3_DCU_Val.Brake_Pressure_Rear_Val);
          manifold_Pres = (PDO3_DCU_Val.manifold_Pres_Val*0.1 - 3276.7);
          Fuel_Pres = (PDO3_DCU_Val.Fuel_Pres_Val*0.1);

          DynamicJsonBuffer Jbuffer2;
          JsonObject& root2 = Jbuffer2.createObject();
          JsonObject& fields2 = root2.createNestedObject("fields");
          fields2["brake_pressure_front"] = Brake_Pressure_Front;
          fields2["brake_pressure_rear"] = Brake_Pressure_Rear;
          fields2["manifold_air_pressure"] = manifold_Pres;
          fields2["fuel_pressure"] = Fuel_Pres;
          root2["name"]="pd03_dcu";
          root2["timestamp"]= 1713288706239;
            
          char JSONmessageBuffer2[100];
          root2.printTo(JSONmessageBuffer2, sizeof(JSONmessageBuffer2));
          enviaMQTT(JSONmessageBuffer2);

        }
        if (rx_Received && PDO4_DCU.MsgID == 0x1F3){

          PDO4_DCU_Data.PDO4_DCU_7 = PDO4_DCU.data.u8[0];
          PDO4_DCU_Data.PDO4_DCU_6 = PDO4_DCU.data.u8[1];
          PDO4_DCU_Data.PDO4_DCU_5 = PDO4_DCU.data.u8[2];
          PDO4_DCU_Data.PDO4_DCU_4 = PDO4_DCU.data.u8[3];
          PDO4_DCU_Data.PDO4_DCU_3 = PDO4_DCU.data.u8[4];
          PDO4_DCU_Data.PDO4_DCU_2 = PDO4_DCU.data.u8[5];
          PDO4_DCU_Data.PDO4_DCU_1 = PDO4_DCU.data.u8[6];
          PDO4_DCU_Data.PDO4_DCU_0 = PDO4_DCU.data.u8[7];
          atualizaRX_PDO4_DCU(&PDO4_DCU_Val, &PDO4_DCU_Data);

          ETC_1 = (PDO4_DCU_Val.Exhaust_Temperature_Cylinder_1_Val*0.1);
          ETC_2 = (PDO4_DCU_Val.Exhaust_Temperature_Cylinder_2_Val*0.1);
          ETC_3 = (PDO4_DCU_Val.Exhaust_Temperature_Cylinder_3_Val*0.1);
          SDL_Temp = (PDO4_DCU_Val.SDL_Temp_Val*0.1);

          DynamicJsonBuffer Jbuffer3;
          JsonObject& root3 = Jbuffer3.createObject();
          JsonObject& fields3 = root3.createNestedObject("fields");
          fields3["exhaus_temperature_cylinder_1"] = ETC_1;
          fields3["exhaus_temperature_cylinder_2"] = ETC_2;
          fields3["exhaus_temperature_cylinder_3"] = ETC_3;
          fields3["sdl3_temperature"] = SDL_Temp;
          root3["name"]="pd04_dcu";
          root3["timestamp"]= 1713288706239;
            
          char JSONmessageBuffer3[100];
          root3.printTo(JSONmessageBuffer3, sizeof(JSONmessageBuffer3));
          enviaMQTT(JSONmessageBuffer3);
        }
        if (rx_Received && PDO5_DCU.MsgID == 0x1F4){

            PDO5_DCU_Data.PDO5_DCU_7 = PDO5_DCU.data.u8[0];
            PDO5_DCU_Data.PDO5_DCU_6 = PDO5_DCU.data.u8[1];
            PDO5_DCU_Data.PDO5_DCU_5 = PDO5_DCU.data.u8[2];
            PDO5_DCU_Data.PDO5_DCU_4 = PDO5_DCU.data.u8[3];
            PDO5_DCU_Data.PDO5_DCU_3 = PDO5_DCU.data.u8[4];
            PDO5_DCU_Data.PDO5_DCU_2 = PDO5_DCU.data.u8[5];
            PDO5_DCU_Data.PDO5_DCU_1 = PDO5_DCU.data.u8[6];
            PDO5_DCU_Data.PDO5_DCU_0 = PDO5_DCU.data.u8[7];
            atualizaRX_PDO5_DCU(&PDO5_DCU_Val, &PDO5_DCU_Data);

            Lambda_1 = (PDO5_DCU_Val.Lambda_1_Val*0.001);
            G_Force_Lat = (PDO5_DCU_Val.G_Force_Lat_Val*0.01 - 327.67);
            G_Force_Long = (PDO5_DCU_Val.G_Force_Long_Val*0.01 - 327.67);
            G_Force_Vert = (PDO5_DCU_Val.G_Force_Vert_Val*0.01 - 327.67);

            DynamicJsonBuffer Jbuffer4;
            JsonObject& root4 = Jbuffer4.createObject();
            JsonObject& fields4 = root4.createNestedObject("fields");
            fields4["lambda_1"] = Lambda_1;
            fields4["acc_x"] = G_Force_Lat;
            fields4["acc_y"] = G_Force_Long;
            fields4["acc_z"] = G_Force_Vert;
            root4["name"]="pd05_dcu";
            root4["timestamp"]= 1713288706239;
              
            char JSONmessageBuffer4[100];
            root4.printTo(JSONmessageBuffer4, sizeof(JSONmessageBuffer4));
            enviaMQTT(JSONmessageBuffer4);
      
        }
        if (rx_Received && PDO6_DCU.MsgID == 0x1F5){

            PDO6_DCU_Data.PDO6_DCU_7 = PDO6_DCU.data.u8[0];
            PDO6_DCU_Data.PDO6_DCU_6 = PDO6_DCU.data.u8[1];
            PDO6_DCU_Data.PDO6_DCU_5 = PDO6_DCU.data.u8[2];
            PDO6_DCU_Data.PDO6_DCU_4 = PDO6_DCU.data.u8[3];
            PDO6_DCU_Data.PDO6_DCU_3 = PDO6_DCU.data.u8[4];
            PDO6_DCU_Data.PDO6_DCU_2 = PDO6_DCU.data.u8[5];
            PDO6_DCU_Data.PDO6_DCU_1 = PDO6_DCU.data.u8[6];
            PDO6_DCU_Data.PDO6_DCU_0 = PDO6_DCU.data.u8[7];
            atualizaRX_PDO6_DCU(&PDO6_DCU_Val, &PDO6_DCU_Data);

            Throttle_Pos = (PDO6_DCU_Val.Throttle_Pos_Val*0.1);
            Fuel_Used = (PDO6_DCU_Val.Fuel_Used_Val*0.01);
            Beacon = (PDO6_DCU_Val.Beacon_Val);
            GPS_Altitude = (PDO6_DCU_Val.GPS_Altitude_Val*0.1);
            
            DynamicJsonBuffer Jbuffer5;
            JsonObject& root5 = Jbuffer5.createObject();
            JsonObject& fields5 = root5.createNestedObject("fields");
            fields5["throttle_position"] = Throttle_Pos;
            fields5["fuel_used"] = Fuel_Used;
            fields5["beacon"] = Beacon;
            fields5["gps_altitude"] = GPS_Altitude;
            root5["name"]="pd06_dcu";
            root5["timestamp"]= 1713288706239;
              
            char JSONmessageBuffer5[100];
            root5.printTo(JSONmessageBuffer5, sizeof(JSONmessageBuffer5));
            enviaMQTT(JSONmessageBuffer5);
        }
        if (rx_Received && PDO7_DCU.MsgID == 0x1F6)
        {
            PDO7_DCU_Data.PDO7_DCU_7 = PDO7_DCU.data.u8[0];
            PDO7_DCU_Data.PDO7_DCU_6 = PDO7_DCU.data.u8[1];
            PDO7_DCU_Data.PDO7_DCU_5 = PDO7_DCU.data.u8[2];
            PDO7_DCU_Data.PDO7_DCU_4 = PDO7_DCU.data.u8[3];
            PDO7_DCU_Data.PDO7_DCU_3 = PDO7_DCU.data.u8[4];
            PDO7_DCU_Data.PDO7_DCU_2 = PDO7_DCU.data.u8[5];
            PDO7_DCU_Data.PDO7_DCU_1 = PDO7_DCU.data.u8[6];
            PDO7_DCU_Data.PDO7_DCU_0 = PDO7_DCU.data.u8[7];
            atualizaRX_PDO7_DCU(&PDO7_DCU_Val, &PDO7_DCU_Data);

            GPS_Latitude = (PDO7_DCU_Val.GPS_Latitude_Val*0.0000001);
            GPS_Longitude = (PDO7_DCU_Val.GPS_Longitude_Val*0.0000001);

            DynamicJsonBuffer Jbuffer6;
            JsonObject& root6 = Jbuffer6.createObject();
            JsonObject& fields6 = root6.createNestedObject("fields");
            fields6["gps_latitude"] = GPS_Latitude;
            fields6["gps_longitude"] = GPS_Longitude;
            root6["name"]="pd07_dcu";
            root6["timestamp"]= 1713288706239;
              
            char JSONmessageBuffer6[100];
            root6.printTo(JSONmessageBuffer6, sizeof(JSONmessageBuffer6));
            enviaMQTT(JSONmessageBuffer6);
        }
        
        vTaskDelayUntil(&myLastUnblock, 20 / portTICK_RATE_MS);
}}

void taskUpdateLCD(void *pvParameters) {
    while (1) {
        // Limpa o conteúdo anterior do LCD
        //lcd.clear();

        // Mostra os dados no LCD
        //lcd.setCursor(0, 0);
        //lcd.print("MARCHA: ");
        //lcd.print(Gear);

        // Adicione mais linhas para mostrar outros dados conforme necessário

        // Aguarde um curto período de tempo para evitar atualizações muito rápidas
        vTaskDelay(500 / portTICK_PERIOD_MS);
    }
}

void loop(){

}