/****************************************************************************
 * Project Name:    Interrupt_basic
 * Author:          RUST
 * Filename:        interrupt_basic.c
 * Purpose:         Class Exercise 
 * ------------------------------------------------------------------------
 * Version history:
 * 30-11-15: Initial version
 *
 * =========================================================================
 * Description:
 * Implements a basic interrupt handler for the ATMAL ATMEGA328 microcontroller
 *
 * Pin 2 Input (Button)
 * Pin 3 Input (Button)
 * Pin 13 Output (LED)
 ****************************************************************************/
const byte BUTTON_ON = 2;
const byte BUTTON_OFF = 3;
const byte LED = 13;

void setup() {
  // Setup the output pin containing the LED (pin 13)
  pinMode(LED, OUTPUT);
  
  // Setup the intput pins - the pins are active low
  pinMode(BUTTON_ON, INPUT);  // Set pin 2 (BUTTON_ON) to input direction
  pinMode(BUTTON_OFF, INPUT);  // Set pin 3 (BUTTON_OFF) to input direction
  digitalWrite(BUTTON_ON, HIGH); // Enable resistor to Vcc on pin 2
  digitalWrite(BUTTON_OFF, HIGH); // Enable resistor to Vcc on pin 3

  // Attach interrupt routines to pin two and pin three
  attachInterrupt(digitalPinToInterrupt(BUTTON_ON), turnLEDon, FALLING);
  attachInterrupt(digitalPinToInterrupt(BUTTON_OFF), turnLEDoff, FALLING);
}

// Interrupt routine for BUTTON_ON
void turnLEDon()
{
  digitalWrite(LED, HIGH);
}

// Interrupt routine for BUTTON_OFF
void turnLEDoff()
{
  digitalWrite(LED, LOW);
}

void loop() {
  // Nothing to do here!! (for now)
}
