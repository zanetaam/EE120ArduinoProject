

// Library for LCD Screen
#include <LiquidCrystal.h>

// LCD pins connected to Arduino Board accordingly i.e RS on LCD screen goes to pin 12 on arduino board) 
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2; 

// defining LCD screen with inputs
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// Defining the LED which is connected to pin 6 
#define LED 6

// Defining backLight which is the display output of the LCD which is connected to pin 8 on the arduino board
int backLight = 8; // pin 13 will control the backlight


void setup() 
{
  // Turning on the screnlight
  pinMode(backLight, OUTPUT); 

  // start of line 1
  lcd.begin(16, 2);
  
  lcd.print("Have a gr8 day!");

  // start of line 2 
  lcd.setCursor(5, 7);
  
  lcd.print("-Zaneta :)");
}

void loop() 

{
 // screen is till on during loop
 digitalWrite(backLight, OUTPUT);
 
  // setting the counter up 
  lcd.setCursor(0, 16);
  
  // print the number of seconds since reset:
  lcd.print(millis() / 1000);
  
 
// if the timer is less than 10 seconds the LED remains on
if (((millis() / 1000) < 10))
{
  digitalWrite(LED, HIGH); //Turn red LED on  
  delay (1);
}

// else if the timer is equal to 10 seconds the LED shuts off 
 else ((millis() / 1000) == 10 );
 { 
  digitalWrite(LED, LOW); //Turn red LED off    
  delay (1);//Leave off for redOffTime
}

// once the timer reaches 10 seconds the display has no text to go along with the LED timing 
if (((millis() / 1000) == 10))
  {
    lcd.noDisplay();
  }
 }
