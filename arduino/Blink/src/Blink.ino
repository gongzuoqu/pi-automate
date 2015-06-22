/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */
 
// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int led = 13;
int outsideLed = 12;
int buttonPin = 2 ;
boolean toggle = false ;
int blinkDelay = 200 ;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  Serial.begin(9600);
  pinMode(led, OUTPUT); 
  pinMode(outsideLed, OUTPUT); 
  pinMode(buttonPin, INPUT); 
  Serial.print("System Initialized \n");
}

// the loop routine runs over and over again forever:
void loop()
{
  checkKeyPressed() ;
  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
  
  if (toggle==true)
    switchOn() ;
  else
    switchOff() ;
  
  delay(blinkDelay);               // wait for a second
  
  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  delay(blinkDelay);               // wait for a second
}

void checkKeyPressed()
{
// read the state of the pushbutton value:
  int buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  if (buttonState == HIGH)
  {
    Serial.print("key pressed \n");   
    if (toggle==true)
    {
      toggle = false ;
      Serial.print("set to off \n");   
    }
    else
    {
      toggle = true ;
      Serial.print("set to on \n");   
    }
  }
}
  
void switchOn()
{
  digitalWrite(outsideLed, HIGH);
}

void switchOff()
{
  digitalWrite(outsideLed, LOW);
}

