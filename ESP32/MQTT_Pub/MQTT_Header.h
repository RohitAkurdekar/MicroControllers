/********************************************************************************************
 * Name:- MQTT Header
 * Date:- 24/Jan/2023
 * Developer:- Rohit Akurdekar
 * Brief:- MQTT publisher functions.
     * Connect to Network
     * Connect to MQTT broker'
     * Publish message over MQTT
 * Note:- Verify libraries and change Network credentials.
*********************************************************************************************/


#ifndef MQTT_HEADER_H
#define MQTT_HEADER_H

//---------------------------------- Libraries inclusion -----------------------------------
#include <WiFi.h>
#include <esp_wifi.h>

#include <PubSubClient.h>           // ESP MQTT library

//---------------------------------- CONSTANTS ---------------------------------------------

// Your WiFi credentials
#define SSID     "<Your_SSID>"       
#define PASSWORD "<Your_PASSWORD>"     // Keep password as an empty string for an OPEN network.

// Change according to your MAC Address.
uint8_t MAC_Address[] = {0xCC, 0x50, 0xE3, 0xAB, 0xB5, 0x74};   //CC:50:E3:AB:B5:74                                    

// Add your MQTT Broker IP address, 
#define MQTT_BROKER  "YOUR_MQTT_BROKER_IP_ADDRESS"

#define TOPIC  "akurdekar/rohit"

// #define WIFI_MODE WIFI_MODE_STA


#define LED  2                // LED Pin

WiFiClient espClient;
PubSubClient client(espClient);


// --------------------------- variables -----------------------------
long lastMsg = 0;
char msg[50];
int value = 0;
bool isRxdMsg = false;
String RxdMsg;


//---------------------------------- Function declaration -----------------------------------

/********************************************************************************
 * @name    : bool isWiFiBegin()
 * @param   : None
 * @returns : WiFi connection status
 * @date    : 26 Jan 2023
 * @brief   : Connect to a WiFi network.
 * @note    : Change MAC address and WIFI credentials according to your network.
 * @test    : tested ok
********************************************************************************/
bool isWiFiBegin()
{

  WiFi.mode(WIFI_MODE_STA);
  
  esp_wifi_set_mac(WIFI_IF_STA, &MAC_Address[0]);   // Function used to configure MAC address

  Serial.print("MAC address of device: ");  
  Serial.println(WiFi.macAddress());                  // Print MAC address
  
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(SSID);

  
  WiFi.begin(SSID, PASSWORD);   // Password is optional

  while (WiFi.status() != WL_CONNECTED) {           // Verify connection
    delay(500);
    Serial.print(".");                            // Wait until not connected
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());                  // Print IP address

  return true;
}

/********************************************************************************
 * @name    : void subscribe()
 * @param   : char* topic, byte* message, unsigned int length
 * @returns : None
 * @date    : 26 Jan 2023
 * @brief   : Subscribe to a MQTT topic
 * @note    : Check TOPIC and logic
 * @test    : tested ok
********************************************************************************/
void subscribe(char* topic, byte* message, unsigned int length) 
{
  String messageTemp;
  
  for (int i = 0; i < length; i++) 
  {
    // Serial.print((char)message[i]);
    messageTemp += (char)message[i];
  }
  Serial.println();

    RxdMsg = messageTemp;
    isRxdMsg = true;
//   return messageTemp;
}


/********************************************************************************
 * @name    : void reconnect()
 * @param   : None
 * @returns : None
 * @date    : 26 Jan 2023
 * @brief   : Recconect to MQTT broker 
 * @note    : 
 * @test    : tested ok
********************************************************************************/
void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) 
  {
    Serial.print("Attempting MQTT connection...");
    // Attempt to connect
    if (client.connect("ESP8266Client")) 
    {
      Serial.println("connected");
      // Subscribe
      client.subscribe(TOPIC);
    }
    else 
    {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}
// ------------------------------- EoF ------------------------------------------

#endif