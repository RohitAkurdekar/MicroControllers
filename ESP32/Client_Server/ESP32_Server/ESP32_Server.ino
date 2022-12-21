/******************************************************************************************
* @name   : ESP32 Server
* @date   : 21/dec/2022
* @Author : Rohit Akurdekar.
* @tested : OK
* @brief  : Connect ESP32 to home Router.
            Create a server on ESP32 and communicate with client. 
* @note   : Change SSID,PASSWORD and IP address according to your network.
******************************************************************************************/



//////////////////////////////////////////////////////////////////////////////////
// Please use Your Mobile HotSpot to Test This Program                          //
// Also Note that CDAC Network has Jammers that Block the HOTSPOT of your Mobile//
//Client and Server Must be Connected to same HotSpot//
////////////////////////////////////////////////
#include <WiFi.h>


#define SSID "YourSSID"
#define PASSWORD "YourPassword"


String  ClientRequest;
//Below IP Address Will be Used by Client to Connect to this Server
//IPAddress is in CSV format

IPAddress staticIP316_10(192,168,100,21);
//Below is the IP Address of the Mobile Gateway
IPAddress gateway316_10(192,168,100,1);
IPAddress subnet316_10(255,255,255,0);

WiFiServer server(80);        // Set server port to 80

WiFiClient client;

String myresultat;



// --------------- Read Incoming Request() -------------------------------------
String ReadIncomingRequest()
{
  while(client.available()) 
  {
    ClientRequest = (client.readStringUntil('\r'));           // Read till end of line.
    if ((ClientRequest.indexOf("HTTP/1.1")>0) && (ClientRequest.indexOf("/favicon.ico")<0))
    {
      myresultat = ClientRequest;
    }
  }
  return myresultat;
}

// ------------------------- setup() ----------------------------------------------
void setup()
{
  ClientRequest = "";

  Serial.begin(115200);

  WiFi.disconnect();
  delay(3000);
  Serial.println("START");
  WiFi.begin(SSID,PASSWORD);
  while ((!(WiFi.status() == WL_CONNECTED)))
  {
    delay(300);
    Serial.print("..");
  }
  Serial.println("Connected");
  WiFi.config(staticIP316_10, gateway316_10, subnet316_10);
  Serial.println("Your IP is");
  Serial.println((WiFi.localIP()));
  server.begin();

}

// --------------------------- loop() ------------------------------------------
void loop()
{

  client = server.available();
  
  if (!client) { return; }
  
  while(!client.available()){  delay(1); }
  
  ClientRequest = (ReadIncomingRequest());
  
  client.flush();
  
  Serial.println("HTTP Request From");
  Serial.println((client.remoteIP()));
  Serial.println("Original request");
  Serial.println(ClientRequest);
  
  ClientRequest.remove(0, 5);
  ClientRequest.remove(ClientRequest.length()-9,9);
  
  Serial.println("Request after Clear");
  Serial.println(ClientRequest);

}

/*********************  OUTPUT  *****************************************



configsip: 0, SPIWP:0xee
clk_drv:0x00,q_drv:0x00,d_drv:0x00,cs0_drv:0x00,hd_drv:0x00,wp_drv:0x00
mode:DIO, clock div:1
load:0x3fff0030,len:1344
load:0x40078000,len:13864
load:0x40080400,len:3608
entry 0x400805f0


START
....Connected
Your IP is
192.168.100.21
HTTP Request From
192.168.100.104
Original request
GET /yes HTTP/1.1
Request after Clear
yes
HTTP Request From
192.168.100.104
Original request
GET /yes HTTP/1.1
Request after Clear
yes

*/