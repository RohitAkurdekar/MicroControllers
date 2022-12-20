/*
  DDR- Data Direction Register.
  8 bit variable and then calc which bit is set or not.
  If bit in DDRxN is  set, then it is configured in OUTPUT mode.
  If bit in DDRxN is !set, then it is configured in INPUT  mode.

  
*/

#define LED_BUILTIN 2


void setup() {
  // put your setup code here, to run once:

  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(115200);
  Serial.println("Setup complete");
}


void loop() {
  // put your main code here, to run repeatedly:
Serial.println("led on");
digitalWrite(LED_BUILTIN, HIGH);
delay(500);
Serial.println("led off");
digitalWrite(LED_BUILTIN, LOW );
delay(500);

}
