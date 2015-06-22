/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */
#include <Wire.h>

#define I2C_SLAVE_ADDRESS 0x04
int number = 0 ;
int nbrOfPin = 4 ;
int addressPin[4]={0x4,0x5,0x7,0x8} ;
int channelPinArray[16][4] = { 
                        {LOW,LOW,LOW,LOW}, 
                        {LOW,LOW,LOW,HIGH}, 
                        {LOW,LOW,HIGH,LOW}, 
                        {LOW,LOW,HIGH,HIGH}, 
                        {LOW,HIGH,LOW,LOW}, 
                        {LOW,HIGH,LOW,HIGH}, 
                        {LOW,HIGH, HIGH,LOW}, 
                        {LOW,HIGH, HIGH,HIGH}, 
                        {HIGH, LOW,LOW,LOW}, 
                        {HIGH, LOW,LOW,HIGH}, 
                        {HIGH, LOW,HIGH,LOW},
                        {HIGH, LOW,HIGH,HIGH},
                        {HIGH, HIGH,LOW,LOW},
                        {HIGH, HIGH,LOW,HIGH},
                        {HIGH, HIGH,HIGH,LOW},
                        {HIGH, HIGH,HIGH,HIGH},
                      } ;


// the setup routine runs once when you press reset:
void setup()
{                
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  
  // init the pin
  Serial.println("init of the address pin");
  for(int i=0;i<nbrOfPin;i++)
  {
    pinMode(addressPin[i], OUTPUT) ;
  }
  
  // init i2c
  Serial.println("init of i2c");
  Wire.begin(I2C_SLAVE_ADDRESS);

  // define callbacks for i2c communication
  Wire.onReceive(receiveData);
  Wire.onRequest(sendData);
  
  for(int i=0;i<16;i++)
  {
    Serial.print("activate channel:");
    Serial.println(i);
    activateADChannel(i) ;
    delay(1000) ;
  }
}

// callback for received data
void receiveData(int byteCount)
{
  while(Wire.available())
  {
    number = Wire.read();
    Serial.print("data received: ");
    Serial.println(number);
  
    if (number <16)
    {
      activateADChannel(number) ;      
    }
  }
}


// callback for sending data
void sendData()
{
  Wire.write(number);
}

void activateADChannel(int channel)
{
   for(int i=0;i<nbrOfPin;i++)
   {
     int state = channelPinArray[channel][i] ;
     digitalWrite(addressPin[i], state); 
   }
}

void loop()
{
  Serial.println("main loop");
  delay(1000);
}



