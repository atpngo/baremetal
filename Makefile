default:
	avr-gcc -Os -DF_CPU=16000000UL -mmcu=atmega328p main.cpp Serial.cpp -o main.bin
	avr-objcopy -O ihex -R .eeprom main.bin main.hex
.PHONY: deploy
deploy:
	avrdude -F -V -c arduino -p ATMEGA328P -P /dev/ttyUSB0 -b 115200 -U flash:w:main.hex
