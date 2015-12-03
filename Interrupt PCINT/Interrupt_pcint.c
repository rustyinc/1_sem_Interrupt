const byte LED = 13;
const byte BUTTON = 8;

/* Interrupt setup for D8 - D13 */
ISR (PCINT0_vect) 
{
  digitalWrite(LED, !digitalRead(LED));
}

/* Interrupt setup for A0 - A5 */
ISR (PCINT1_vect) 
{
}

/* Interrupt setup for D0 - D7 */
ISR (PCINT2_vect) 
{
}

void pciSetup (byte pin)
{
  *digitalPinToPCMSK(pin) |= bit (digitalPinToPCMSKbit(pin));  // enable pin
  PCIFR  |= bit (digitalPinToPCICRbit(pin)); // clear any outstanding interrupt
  PCICR  |= bit (digitalPinToPCICRbit(pin)); // enable interrupt for the group
}

void setup() 
{
  pinMode (LED, OUTPUT);
  pinMode (BUTTON, INPUT);
  digitalWrite (BUTTON, HIGH);
      
  pciSetup(BUTTON);
}

void loop() {
}

