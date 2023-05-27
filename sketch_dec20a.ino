/*
 * Created by ArduinoGetStarted.comw
 *
 * This example code is in the public domain
 *
 * Tutorial page: https://arduinogetstarted.com/tutorials/arduino-joystick
 */
#include<Mouse.h>
#include<Keyboard.h>

#define VRX_MOUSE_PIN  A0 // Arduino pin connected to VRX pin from mouse
#define VRY_MOUSE_PIN  A1 // Arduino pin connected to VRY pin from mouse

#define VRX_KBOARD_PIN  A3 // Arduino pin connected to VRX pin from keyboarda
#define VRY_KBOARD_PIN  A4 // Arduino pin connected to VRY pin from keyboard

#define PIN_0 2
#define PIN_1 3
#define PIN_2 4
#define PIN_3 5

#define PIN_4 9

const int sensitivity = 500;
int xMouse_Value, xMouse_Zero, xKBoard_Value, xKBoard_Zero; //  X axis
int yMouse_Value, yMouse_Zero, yKBoard_Value, yKBoard_Zero; //  Y axis

int btnState_0, btnState_1, btnState_2, btnState_3;

int btnState_4;

void setup() {
  
  pinMode(VRX_MOUSE_PIN, INPUT);
  pinMode(VRY_MOUSE_PIN, INPUT);
  pinMode(VRX_KBOARD_PIN, INPUT);
  pinMode(VRY_KBOARD_PIN, INPUT);

  pinMode(PIN_0,INPUT);
  pinMode(PIN_1,INPUT);
  pinMode(PIN_2,INPUT);
  pinMode(PIN_3,INPUT);

  pinMode(PIN_4,INPUT);

  digitalWrite(PIN_0,HIGH);
  digitalWrite(PIN_1,HIGH);
  digitalWrite(PIN_2,HIGH);
  digitalWrite(PIN_3,HIGH);
  
  digitalWrite(PIN_4,HIGH);
  delay(1000);
  
  xMouse_Zero = analogRead(VRX_MOUSE_PIN);
  yMouse_Zero = analogRead(VRY_MOUSE_PIN);
  xKBoard_Zero = analogRead(VRX_KBOARD_PIN);
  yKBoard_Zero = analogRead(VRY_KBOARD_PIN);
  
  Mouse.begin();
  Keyboard.begin();
}

//Camera Control
void Mouse_Control()
{
  // read analog X and Y analog values
  xMouse_Value = analogRead(VRX_MOUSE_PIN) - xMouse_Zero;
  yMouse_Value = analogRead(VRY_MOUSE_PIN) - yMouse_Zero;

  if(xMouse_Value != 0)
  {
    Mouse.move(xMouse_Value/sensitivity , 0 , 0);
  }
  if(yMouse_Value != 0)
  {
    Mouse.move(0, yMouse_Value/sensitivity , 0);
  }
}

void KeyBoard_Control()
{
  // read analog X and Y analog values
  xKBoard_Value =analogRead(VRX_KBOARD_PIN) - xKBoard_Zero;
  yKBoard_Value = analogRead(VRY_KBOARD_PIN) - yKBoard_Zero;

  // state of buttons
  btnState_0 =  digitalRead(PIN_0);
  btnState_1 =  digitalRead(PIN_1);
  btnState_2 =  digitalRead(PIN_2);
  btnState_3 =  digitalRead(PIN_3);

  btnState_4 = digitalRead(PIN_4);
  
   if(btnState_0 == LOW)
  {
    Keyboard.press('j');
    //Keyboard.releaseAll();
  }
  if(btnState_1 == LOW)
  {
    Keyboard.press('i');
    //Keyboard.releaseAll();
  }
  if(btnState_2 == LOW)
  {
    Keyboard.press('k');
    //Keyboard.releaseAll();
  }
  if(btnState_3 == LOW)
  {
    Keyboard.press('l');
    //Keyboard.releaseAll();
  }
  if(btnState_4 == LOW)
  {
    Keyboard.press(' ');
    //Keyboard.releaseAll();
  }

  if(xKBoard_Value/100 > 0)
  {
    Keyboard.press('a');
    delay(200);
    //Keyboard.releaseAll();
    
  }
  
  if(xKBoard_Value/100 < 0)
  {
    Keyboard.press('d');
    delay(200);
  }
  
  if(yKBoard_Value/100 > 0)
  {
    Keyboard.press('w');
    delay(200);
    //Keyboard.releaseAll();
    
    
  }
  if(yKBoard_Value/100 < 0)
  {
    Keyboard.press('s');
    delay(200);
    //Keyboard.releaseAll();
    
  }
  Keyboard.releaseAll();
  
}
void loop() {
  
  
  Mouse_Control();
  KeyBoard_Control();

  /*
  Serial.println("KBoard = ");
  Serial.println(yKBoard_Zero);
  Serial.println("Mouse = ");
  Serial.println(yMouse_Value);
  */
  
}
