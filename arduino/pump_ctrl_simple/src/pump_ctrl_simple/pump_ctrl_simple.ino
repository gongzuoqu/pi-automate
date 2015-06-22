/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */
 
// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int DELAY = 10000 ;

int PUMP1 = 0x02 ;
int PUMP2 = 0x03 ;
int PUMP3 = 0x04 ;
int PUMP4 = 0x05 ;
int PUMP5 = 0x06 ;
int PUMP6 = 0x07 ;
int PUMP7 = 0x08 ;
int PUMP8 = 0x09 ;
int PUMP9 = 0x0A ;
int PUMP10 = 0x10 ;

int nbr_of_relay = 9 ;
int relay_pins[9] = {PUMP3,PUMP2,PUMP1,PUMP4,PUMP5,PUMP6,PUMP9,PUMP8,PUMP7} ;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  for(int i=0;i<nbr_of_relay;i++)
  {
    pinMode(relay_pins[i], OUTPUT) ;
  }
}

void loop()
{
  for(int i=0;i<nbr_of_relay;i++)
  {
      digitalWrite(relay_pins[i], HIGH); 
      delay(DELAY);
      digitalWrite(relay_pins[i], LOW); 
  }
}




