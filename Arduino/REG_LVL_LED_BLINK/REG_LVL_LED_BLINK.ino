/*
  AVR-GCC- Arduino compiler

  Arduino compiler ignores non useful loops or statements for code optimization.

*/

void setup() {
  // put your setup code here, to run once:
  DDRB = 32;
}

void loop() {
  // put your main code here, to run repeatedly:
  PORTB = 32;   // LED turn ON

  // Delay()
  for(long int i=0;i<1000000; i++)
  {
    PORTB=32;
  }

  PORTB = 0;    // LED turn OFF

  // Delay()
  for(long int i=0;i<1000000; i++)
  {
    PORTB=0;
  }
}
