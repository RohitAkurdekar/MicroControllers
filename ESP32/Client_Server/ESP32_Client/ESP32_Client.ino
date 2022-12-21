/******************************************************************************************
* @name   : ESP32 Client
* @date   : 21/dec/2022
* @Author : Rohit Akurdekar.
* @tested : OK
* @brief  : Connect ESP32 to home Router.
            Configure an ESP32 as a  client and communicate with a server. 
* @note   : Change SSID,PASSWORD and IP address according to your network.
******************************************************************************************/

//////////////////////////////////////////////////////////////////////////////////
// Please use Your Mobile HotSpot to Test This Program                          //
// Also Note that CDAC Network has Jammers that Block the HOTSPOT of your Mobile//
//////////////////////////////////////////////////////////////////////////////////

#include <WiFi.h>

WiFiClient client;

#define SSID "yourSSID"
#define PASSWORD "yourPASSWORD"

#define SERVER_IP "yourServerIP"        // Change this according to IP assigned to ESP32_SERVER.

String myurl = "/";
void setup()
{
  Serial.begin(115200);

  WiFi.disconnect();    // Disconnect if not connected
  delay(3000);
  Serial.println("START");

  WiFi.begin(SSID,PASSWORD);  // Connect to AP
  while ((!(WiFi.status() == WL_CONNECTED))){
    delay(300);
    Serial.print("..");

  }
  Serial.println("Connected to HotSpot");
  Serial.println("Your IP is");               // print IP address of ESP32
  Serial.println((WiFi.localIP()));
  Serial.println("Note the IP Address and Find the Network IP");
  Serial.println("Configure the same Network IP in Server");
}


void loop()
{

  if (client.connect(SERVER_IP, 80))          // Checks whether ESP client is connected to ESP Server
	{ 
	  Serial.println("OK :Connected To Server");
	  Serial.println("Sending Data to Server");
    myurl += "yes";
    client.print(String("GET ") + myurl + " HTTP/1.1\r\n" +
              "Host: " + SERVER_IP + "\r\n" +     
              "Connection: close\r\n\r\n");
    myurl="/";
  }
	else 
	{
		Serial.println("NOK : Unable Connect Server");
	}
	
  delay(1000);
    
}

/*********************  OUTPUT  *****************************************
load:0x40080400,len:3608
entry 0x400805f0
START
....Connected to HotSpot
Your IP is
192.168.100.104
Note the IP Address and Find the Network IP
Configure the same Network IP in Server
OK :Connected To Server
Sending Data to Server
OK :Connected To Server
Sending Data to Server

*/