
#include "cores/arduino/Arduino.h"
#include "Servo/Servo.h"


// Declared weak in Arduino.h to allow user redefinitions.
int atexit(void (* /*func*/ )()) { return 0; }

// Weak empty variant initialization function.
// May be redefined by variant files.
void initVariant() __attribute__((weak));
void initVariant() { }

void setupUSB() __attribute__((weak));
void setupUSB() { }

int main(void)
{
	//init();

	initVariant();

#if defined(USBCON)
	USBDevice.attach();
#endif
	
	//setup();
    Servo servo;

    servo.attach(5);

    
	for (;;) {
		  // Para o servo
  servo.write(90);  // Envia o sinal neutro, servo para

  _delay_ms(2000); // Aguarda 2 segundos

  // Faz o servo girar para frente
  servo.write(0);  // Gira em uma direção
  _delay_ms(2000);       // Aguarda 2 segundos

  // Faz o servo girar para trás
  servo.write(180); // Gira na direção oposta
  _delay_ms(2000);      
		if (serialEventRun) serialEventRun();
	}
        
	return 0;
}

