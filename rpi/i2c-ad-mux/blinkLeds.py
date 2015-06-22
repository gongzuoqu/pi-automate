import smbus
import time
# for RPI version 1, use bus = smbus.SMBus(0)
bus = smbus.SMBus(1)

# This is the address we setup in the Arduino Program
address = 0x04

def writeNumber(value):
	bus.write_byte(address, value)
	return -1

def readNumber():
	number = bus.read_byte(address)
	return number

#lets's fire up a few leds ...
while(1):
	for i in range(16):
		print "will send:", i
		writeNumber(i)
		time.sleep(1)
