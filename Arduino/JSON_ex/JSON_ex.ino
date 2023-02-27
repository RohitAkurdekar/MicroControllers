
#include <ArduinoJson.h>

DynamicJsonDocument doc1(1024);
DynamicJsonDocument doc2(1024);

// String pub_data = "{\"GATEWAY_ID\":1301,\"Device1\": {\"DEVICE_ID\":BMP280_1,\"temperature\":31.24,\"pressure\":94150.06,\"altitude\":615.26},\"Device2\":{\"DEVICE_ID\":POT_1,\"value\":441.00}}"

String JSON_str;

void setup() {
  // put your setup code here, to run once:

  Serial.begin(115200);

  doc1["Gateway_id"] = "1302";
  doc1["Device1"]["Sensor_id"] = "BME280_1";
  doc1["Device1"]["value"] = 290;
  
  serializeJson(doc1,JSON_str);     // JSON stringify | JSON dumps

  /*
    Above line creates a string with JSON format as shown below:

    {"Gateway_id":"1302","Device1":{"Sensor_id":"BME280_1","value":290}}    
  */
  Serial.println("JSON_str: " + JSON_str);

  deserializeJson(doc2, JSON_str);      // JSON parse | JSON loads

  Serial.print("Gateway_ID: ");
  String gateway_id = doc2["Gateway_id"];
  Serial.println(gateway_id);
  
  Serial.print("Sensor_id: ");
  String sensor_id = doc2["Device1"]["Sensor_id"];
  Serial.println(sensor_id);
  
  Serial.print("Value: ");
  int value = doc2["Device1"]["value"];
  Serial.println(value);

}

void loop() {
  // put your main code here, to run repeatedly:

}
