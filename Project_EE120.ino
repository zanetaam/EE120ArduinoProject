#include <hcsr04.h>

#include <LiquidCrystal.h>

#define TRIG_PIN 10
#define ECHO_PIN 7
HCSR04 hcsr04(TRIG_PIN, ECHO_PIN, 20, 4000);
// Library for LCD Screen
#include <LiquidCrystal.h>

const int motorPin1  = 9;
const int motorPin2  = 13;


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
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  { Serial.begin(9600); }
  if ( hcsr04.distanceInMillimeters() < 15)
  {
    lcd.noDisplay();
    digitalWrite(LED, LOW);
    delay(20000);
    digitalWrite(motorPin1, LOW);
     
    
     
  }
  else
  {
    digitalWrite(LED, HIGH); //Turn red LED on  
  delay (1);
   digitalWrite(motorPin1, HIGH);
  // Turning on the screnlight
  pinMode(backLight, OUTPUT); 

  // start of line 1
  lcd.begin(16, 2);
  
  lcd.print("Have a gr8 day!");

  // start of line 2 
  lcd.setCursor(5, 7);
  
  lcd.print("-Z&N :)");

  
}
}
void loop() 

{
 // screen is still on during loop
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
    digitalWrite(motorPin1, LOW);
    delay(2000);
  }
 }
