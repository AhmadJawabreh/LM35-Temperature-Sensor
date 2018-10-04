/*        
 *         Palestine Polytechnic University
 *  College of Information Technology and Computer Engineering 
 *       Department of Computer Systems Engineering 
 *                  Embedded systems
 *         Prepared by: Ahmad Jawabreh & Enas Jawabreh
 *              Supervisor: Dr.Ayman Wazwaz
 *                        Oct 2018                   
*/
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
double Temperature_in_Fahrenheit = 0;
double Temperature_in_Celsius = 0;
double Vout_one = A0;
double Vout_two = A1;
double Vfinal = 0;
void setup() {
  pinMode(Vout_one,INPUT);
  pinMode(Vout_two,INPUT);
  lcd.begin(16, 2);
  lcd.setCursor(0,0);
  lcd.print("C:");
  lcd.setCursor(0,1);
  lcd.print("F:");
}

void loop() {
   //calculate the diffreient between voltage one and two.
   Vfinal = analogRead(Vout_one) - analogRead(Vout_two); 
   //calculate the Temperature in Celsius.
   Temperature_in_Celsius    = floor((Vfinal * 500)/1023); 
   //calculate the Temperature in Fahrenheit.
   Temperature_in_Fahrenheit = (Temperature_in_Celsius * 1.8)+32; 
   //print the Temperature in Celsius on the LCD.
   lcd.setCursor(3,0);
   lcd.print(Temperature_in_Celsius);
   //print the Temperature in Celsius on the LCD.
   lcd.setCursor(3,1);
   lcd.print(Temperature_in_Fahrenheit);
   delay(100);
}
