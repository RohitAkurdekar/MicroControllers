#define PIN_LED 2
#define PIN_BUTTON 0
#define DEBOUNCE_DELAY 300

bool currentLEDState = true;
unsigned long lastDebounceTime = 0;


void setup() {
    // put your setup code here, to run once:
  pinMode(PIN_LED,OUTPUT);
  pinMode(PIN_BUTTON,INPUT);
  Serial.begin(115200);
  Serial.println("setup complete");
}

void loop() {
  // put your main code here, to run repeatedly:
  int reading = digitalRead(PIN_BUTTON);
  unsigned long currentTime = millis();

  if((reading == LOW) && ((currentTime - lastDebounceTime)> DEBOUNCE_DELAY))
  {
    lastDebounceTime = currentTime;
    currentLEDState = !currentLEDState;

    Serial.print("Changing LED state to: ");
    Serial.println(currentLEDState);

    digitalWrite(PIN_LED, currentLEDState);    
  }
}