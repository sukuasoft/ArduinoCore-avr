all:
	avr-g++ main.cpp Servo/Servo.cpp cores/arduino/wiring.c cores/arduino/wiring_analog.c cores/arduino/wiring_digital.c cores/arduino/WMath.cpp -mmcu=atmega328p -DF_CPU=16000000UL -Os -o main.elf