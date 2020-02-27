//----------------------------------------------------------------------
// Author: Antonio Bogallo
// Sketch para 4 interruptores que actuan como pulsadores
//-----------------------------------------------------------------------

#include <Joystick.h>

Joystick_ Joystick(JOYSTICK_DEFAULT_REPORT_ID,JOYSTICK_TYPE_GAMEPAD,
  4, 0,                  // Button Count, Hat Switch Count ---- result = 4 buttons
  false, false, false,     //no X,no Y and no Z Axis
  false, false, false,   // No Rx, Ry, or Rz
  false, false,          // No rudder or throttle
  false, false, false);  // No accelerator, brake, or steering

void setup() {
  // Initialize Switches Pins
  pinMode(5, INPUT_PULLUP);
  pinMode(4,INPUT_PULLUP);
  pinMode(3,INPUT_PULLUP);
  pinMode(2,INPUT_PULLUP);

  // Inicializa Joystick Library
  Joystick.begin();
}

// Ultimo estado de los switches
int lastButtonState[4] = {0,0,0,0};

void loop() {
  
  for (int index = 0; index < 4;index++){   // Bucle para ir comprobando los estados de lo switches

     int currentButtonState = !digitalRead(index + 2);
     if(currentButtonState != lastButtonState[index])
     {
      switch(index){

         case 0:  //Switch 1
              Joystick.pressButton(0);
              delay(150);
              Joystick.releaseButton(0);
              break;

         case 1:  //Switch 2
              Joystick.pressButton(1);
              delay(150);
              Joystick.releaseButton(1);
              break;
              
         case 2:  //Switch 3
              Joystick.pressButton(2);
              delay(150);
              Joystick.releaseButton(2);
              break;

         case 3:  //Switch 4
              Joystick.pressButton(4);
              delay(150);
              Joystick.releaseButton(4);
              break;
      }
       lastButtonState[index] = currentButtonState;
     }
  }
delay(10);
}
