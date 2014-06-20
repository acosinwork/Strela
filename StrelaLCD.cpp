
/* StrelaLCD.cpp
 * Strela library 
 *
 *
 */

#include <avr/io.h>
#include "Stream.h"

#include <Arduino.h>
#include <Wire.h> 

#include <Strela.h>
//#include <Strela.cpp>

#include <LiquidCrystal_I2C.h>

#define GPLCD_TWI_ADDR   0x21
/*
//from Strela.h
//LCx вид (для LiquidCrystal_I2C.h)
#define LC_ADDR    LCD_TWI_ADDR

#define LC4 0
#define LC5 1
#define LC6 2
#define LC7 3
#define LCEN 4
#define LCRW 5
#define LCRS 6
*/

//                    addr, en,rw,rs,d4,d5,d6,d7,bl,blpol

namespace {

bool lcdIsInit = false;

void _lcdInit()
{
    STRELA_INIT_CHECK;
    
    LiquidCrystal_I2C LCD(LC_ADDR, LCEN, LCRW, LCRS, LC4, LC5, LC6, LC7);

    lcdInit = true;
}

    
}



/*
void  //uPinMode(uint8_t pin, uint8_t mode)
{
}


#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define GPLCD_TWI_ADDR   0x21

// =======================================================================

//                    addr, en,rw,rs,d4,d5,d6,d7,bl,blpol
LiquidCrystal_I2C lcd(0x21, 4, 5, 6, 0, 1, 2, 3);

char txtMsg[16];
byte txtCounter;
void setup()
{
  pinMode(12, OUTPUT);

  Wire.begin();
  lcd.begin(8, 2);
  Serial1.begin(9600);

  for (byte i = 0; i < 16; ++i)
  {
    txtMsg[i] = ' ';
  }

}

void loop()
{

  while (Serial1.available() > 0) {
    char inChar = Serial1.read();

    if ((inChar == '\n') || (txtCounter >= 16))
    {
      while (Serial1.available() > 0)
        Serial1.read();

      printStringLCD();
    }
    else
    {
      txtMsg[txtCounter] = inChar;
      ++txtCounter;
    }
  }
}

void printStringLCD()
{
  lcd.clear();
  lcd.home();

  for (byte i = 0; i < 8; ++i)
  {
    lcd.print(txtMsg[i]);
  }

  lcd.setCursor(0, 1);

  for (byte i = 8; i < 16; ++i)
  {
    lcd.print(txtMsg[i]);
  }

  for (byte i = 0; i < 16; ++i)
  {
    txtMsg[i] = ' ';
  }
  txtCounter = 0;

  tone(12, 2000, 50);

}
*/
