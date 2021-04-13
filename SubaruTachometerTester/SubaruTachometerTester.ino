//Sample using LiquidCrystal library
#include <LiquidCrystal.h>

/*******************************************************

This program will test the LCD panel and the buttons
Mark Bramwell, July 2010

********************************************************/

// select the pins used on the LCD panel
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

// define some values used by the panel and buttons
int lcd_key     = 0;
int adc_key_in  = 0;
#define btnRIGHT  0
#define btnUP     1
#define btnDOWN   2
#define btnLEFT   3
#define btnSELECT 4
#define btnNONE   5

// read the buttons
int read_LCD_buttons()
{
 adc_key_in = analogRead(0);      // read the value from the sensor
 // my buttons when read are centered at these valies: 0, 144, 329, 504, 741
 // we add approx 50 to those values and check to see if we are close
 if (adc_key_in > 1000) return btnNONE; // We make this the 1st option for speed reasons since it will be the most likely result



 if (adc_key_in < 50)   return btnRIGHT;
 if (adc_key_in < 195)  return btnUP;
 if (adc_key_in < 380)  return btnDOWN;
 if (adc_key_in < 555)  return btnLEFT;
 if (adc_key_in < 790)  return btnSELECT;



 return btnNONE;  // when all others fail, return this...
}

int pinLewy = 7;  // 3 dla nano, 7 dla uno
int pinPrawy = 6; // 2 dla nano, 6 dla uno
int opoznienie = 5;  // opoznienie w ms miedzy podaniem stanow enkodera
int liczbaCykliEnkodera = 0;
int blokada = 0;

void setup() {
  pinMode(pinLewy, OUTPUT);
  pinMode(pinPrawy, OUTPUT);
  digitalWrite(pinLewy, HIGH);
  digitalWrite(pinPrawy, HIGH);
  delay(500);  // opoznienie poczatkowe
  obrotyUP(350); // obroty na wejsciu: 200 = prawie 1000 rpm, 350 = prawie 2000 rpm, 450 = 3000 rpm

 lcd.begin(16, 2);              // start the library
 // lcd.setCursor(0,0);
 // lcd.print("Push the buttons"); // print a simple message

  
}

void loop() {


 lcd.setCursor(0,1);            // move cursor to second line "1" and 9 spaces over
 lcd.print(liczbaCykliEnkodera);      // display seconds elapsed since power-up


 // lcd.setCursor(0,1);            // move to the begining of the second line
 lcd_key = read_LCD_buttons();  // read the buttons

 switch (lcd_key)               // depending on which button was pushed, we perform an action
 {
   case btnRIGHT:
     {
     // lcd.print("UP +10");
     czyscNumerek();
     obrotyUP(10);
     liczbaCykliEnkodera=liczbaCykliEnkodera+10;
     break;
     }
   case btnLEFT:
     {
     // lcd.print("DOWN +10");
     czyscNumerek();
     obrotyDOWN(10);
     liczbaCykliEnkodera=liczbaCykliEnkodera-10;
     break;
     }
   case btnUP:
     {
     // lcd.print("UP    ");
     if (blokada == 0) {
        czyscNumerek();
        obrotyUP(1);
        liczbaCykliEnkodera++;
        blokada = 1;
     }
     break;
     }
   case btnDOWN:
     {
     // lcd.print("DOWN  ");
     if (blokada == 0) {
        czyscNumerek();
        obrotyDOWN(1);
        liczbaCykliEnkodera--;
        blokada = 1;
     }
     break;
     }
   case btnSELECT:
     {
     // lcd.print("SELECT");
     break;
     }
     case btnNONE:
     {
     // lcd.print("NONE  ");
     blokada = 0;
     break;
     }
 }
  
}

void czyscNumerek(){
   lcd.setCursor(0,1);            // move cursor to second line "1" and 9 spaces over
    lcd.print("      ");
}

void obrotyUP(int ile){
  int i;
    for (i = 0; i < ile; i++){
        digitalWrite(pinLewy, LOW); //1
        digitalWrite(pinPrawy, HIGH); //0
        delay(opoznienie);
        digitalWrite(pinLewy, LOW); //1
        digitalWrite(pinPrawy, LOW); //1
        delay(opoznienie);
        digitalWrite(pinLewy, HIGH); //0
        digitalWrite(pinPrawy, LOW); //1
        delay(opoznienie);
        digitalWrite(pinLewy, HIGH); //0
        digitalWrite(pinPrawy, HIGH); //0
        delay(opoznienie);
  }
}

void obrotyDOWN(int ile){
  int i;
    for (i = 0; i < ile; i++){
        digitalWrite(pinLewy, HIGH); //0
        digitalWrite(pinPrawy, LOW); //1
        delay(opoznienie);
        digitalWrite(pinLewy, LOW); //1
        digitalWrite(pinPrawy, LOW); //1
        delay(opoznienie);
        digitalWrite(pinLewy, LOW); //1
        digitalWrite(pinPrawy, HIGH); //0
        delay(opoznienie);
        digitalWrite(pinLewy, HIGH); //0
        digitalWrite(pinPrawy, HIGH); //0
        delay(opoznienie);
  }
}
