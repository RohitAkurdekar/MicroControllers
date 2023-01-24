/********************************************************************************************
 * Name:- WiFi connect
 * Date:- 24/Jan/2023
 * Developer:- Rohit Akurdekar
 * Brief:- Connect you WiFi with network.
 * Note:- Verify libraries and change Network credentials
*********************************************************************************************/

//---------------------------------- Libraries inclusion -----------------------------------
#include <WiFi.h>
#include <esp_wifi.h>

//---------------------------------- CONSTANTS ---------------------------------------------

// Your WiFi credentials
const char* SSID     = "<Your_SSID>";       
const char* PASSWORD = "<Your_PASSWORD>";     // Keep password as an empty string for an OPEN network.

// Change according to your MAC Address.
uint8_t MAC_Address[] = {0xCC, 0x50, 0xE3, 0xAB, 0xB5, 0x74};   //CC:50:E3:AB:B5:74

//---------------------------------- Function declaration -----------------------------------
bool isWiFiBegin();  

//---------------------------------- Setup Function -----------------------------------------

void setup() {

  Serial.begin(115200);
  delay(10);

  isWiFiBegin();  
  
}

//---------------------------------- Loop Function -----------------------------------
void loop() {
  // put your main code here, to run repeatedly:
  
}

//---------------------------------- isWiFiBegin Function -----------------------------------
//  Connect to WiFi network
//-------------------------------------------------------------------------------------------
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