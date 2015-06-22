/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */
 
// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int nbr_of_relay = 10 ;
int relay_pins[10] = {0x2,0x3,0x4,0x5,0x6,0x7,0x8,0x9,0xa,0x10} ;
int DELAY = 1000 ;
//int relay_pins[5] = {15,14,16,10,0x09} ;
int button_pins[5] = {2,3,4,5,6} ;
int relay_state[5] = {0, 0, 0, 0, 0};

// last 2 relay are for pump and drain
int relay_pump = nbr_of_relay - 1 ;
int relay_drain = relay_pump - 1 ;

int nbrOfRelayMuxPin = 4 ;
int nbrOfRelay = 10 ;
int relayActivationPin=0x6 ;

int relayMuxPin[4]={0x4,0x5,0x7,0x8} ;
int relayActive[10][4] = { {LOW,LOW,LOW,HIGH}, 
                        {LOW,LOW,HIGH,LOW}, 
                        {LOW,LOW,HIGH,HIGH}, 
                        {LOW,HIGH,LOW,LOW}, 
                        {LOW,HIGH,LOW,HIGH}, 
                        {LOW,HIGH, HIGH,LOW}, 
                        {LOW,HIGH, HIGH,HIGH}, 
                        {HIGH, LOW,LOW,LOW}, 
                        {HIGH, LOW,LOW,HIGH}, 
                        {HIGH, LOW,HIGH,LOW}} ;

void activateRelay(int relay)
{
  digitalWrite(relayActivationPin, LOW) ;
   for(int i=0;i<nbrOfRelayMuxPin;i++)
   {
     int state = relayActive[relay][i] ;
     digitalWrite(relayMuxPin[i], state); 
   }
  digitalWrite(relayActivationPin, HIGH) ;
}

// the setup routine runs once when you press reset:
void setup() {                
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  for(int i=0;i<nbrOfRelayMuxPin;i++)
  {
    pinMode(relayMuxPin[i], OUTPUT) ;
    digitalWrite(relayMuxPin[i], LOW);
  }
  
  pinMode(relayActivationPin, OUTPUT) ;
  digitalWrite(relayActivationPin, LOW);
}

void loop()
{
  for(int i=0;i<nbr_of_relay;i++)
  {
    activateRelay(i) ;
    delay(5000) ;
    
//      digitalWrite(relay_pins[i], HIGH); 
//      delay(5000);
//      digitalWrite(relay_pins[i], LOW); 
//    if (relay_state[i]==0)
//    {
//      digitalWrite(relay_pins[i], HIGH); 
//      relay_state[i]=1 ;
//    }
//    else
//    {
//      digitalWrite(relay_pins[i], LOW); 
//      relay_state[i]=0 ;
//    }
//    delay(500);
  }
}


void closeDrain()
{
  digitalWrite(relay_pins[relay_drain], HIGH);   // turn the LED on (HIGH is the voltage level)
}

void openDrain()
{
  digitalWrite(relay_pins[relay_drain], LOW);   // turn the LED on (HIGH is the voltage level)
}

void openValve(int i)
{
  // close the drain and open a valve
  closeDrain() ;
  digitalWrite(relay_pins[i], LOW);   // turn the LED on (HIGH is the voltage level)
  relay_state[i]=1 ;
}

void closeValve(int i)
{
  // open the drain and close the valve
  openDrain() ;
  digitalWrite(relay_pins[i], HIGH);   // turn the LED on (HIGH is the voltage level)
  relay_state[i]=0 ;
}

// open the drain and start the pump
void startPump()
{
  // open the drain
  openDrain() ;
  // start the pump
  digitalWrite(relay_pins[relay_pump], HIGH);   // turn the LED on (HIGH is the voltage level)
  relay_state[relay_pump]=1 ;

}

// open the drain and start the pump
void stopPump()
{
  // close the drain
  closeDrain() ;
  //stop the pump
  digitalWrite(relay_pins[relay_pump], LOW);   // turn the LED on (HIGH is the voltage level)
  relay_state[relay_pump]=0 ;
}

void closeAllValves()
{
  for(int i=0;i<(nbr_of_relay-2);i++)
  {
    closeValve(i) ;
  }
}

// the loop routine runs over and over again forever:
/*
void loop() {
  
  for(int i=0;i<nbr_of_relay;i++)
  {
    int buttonState = digitalRead(button_pins[i]);
    if (buttonState == HIGH)
    {
      if (i==relay_pump)
      {
        if (relay_state[i]==0)
          startPump() ;
         else
         {
          stopPump() ;
          closeAllValves() ;
         }
         delay(1000); 
         continue ;
      }
      
      if (relay_state[i]==0)
      {
         openValve(i) ;
      }
       else
      {
         closeValve(i) ;
      } 
      delay(1000);               // wait for a second
    }
  }
}
*/


