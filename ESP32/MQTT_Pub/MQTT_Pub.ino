/********************************************************************************************
 * Name:- MQTT Publisher
 * Date:- 24/Jan/2023
 * Developer:- Rohit Akurdekar
 * Brief:- MQTT publisher functions.
     * Connect to Network
     * Connect to MQTT broker'
     * Publish message over MQTT
 * Note:- Verify libraries and change Network credentials.
*********************************************************************************************/

#include"MQTT_Header.h"


// ----------------- SETUP -----------------------------
void setup() 
{
  Serial.begin(115200);
  isWiFiBegin();
  client.setServer(MQTT_BROKER, 1883);      // Connect to MQTT broker
  client.setCallback(subscribe);

  pinMode(LED, OUTPUT);         // set LED as output
}

// ------------------------- LOOP -----------------------------------
void loop() 
{
  if (!client.connected()) 
  {
    reconnect();
  }
  client.loop();

    String message = "Enter your message here...";

  long now = millis();
  if (now - lastMsg > 5000) 
  {
    lastMsg = now;
    
    client.publish(TOPIC, message.c_str());

  }

// ----------------- Print received message -------------------------------
    if(isRxdMsg)
    {
        Serial.print("Received message: ");
        Serial.println(RxdMsg);
        isRxdMsg = false;
    }

}
