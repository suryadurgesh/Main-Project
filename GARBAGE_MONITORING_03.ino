 #include <LiquidCrystal.h>
#define MQ2pin 0
// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 13, en = 12, d4 = 11, d5 = 10, d6 = 9, d7 = 8;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

String i;
String num="6302772060";
const int trigPin = 7;
const int echoPin = 6;
// defines variables
long duration;

{
sensorValue = analogRead(MQ2pin);  
lcd.begin(16, 2);
lcd.setCursor(0, 0);
lcd.print("GARBAGE");
lcd.setCursor(0, 1);
lcd.print("MONITORING");
delay(2000);
lcd.clear();
pinMode(5, OUTPUT);
pinMode(trigPin, OUTPUT); 
pinMode(echoPin, INPUT); 
Serial.begin(9600);
}     
void loop()
{ 

digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance = duration * 0.034 / 2;
Serial.print("Distance: ");
Serial.println(distance);
lcd.setCursor(0, 0);
lcd.print("Distance: :");
lcd.println(distance);
delay(2000);
lcd.clear();

 if 
  (distance<= 5)
  {
        digitalWrite(5,HIGH);
        delay(1000);
        lcd.setCursor(0, 0);
        lcd.println("GARBAGE FULL :");
        delay(2000);
        lcd.clear();
        Serial.println("AT\r");
        delay(500); 
        Serial.println("AT+CMGF=1\r");
        delay(500);
        Serial.print("AT+CMGS=\"");
       Serial.print(num);
        Serial.println("\"\r");
        delay(500);
        Serial.println("GARBAGE FULL ");
        delay(1000);
        Serial.println("\"\r");
        Serial.print("GO TO NEXT GARBAGE");
        delay(1000);
        Serial.println((char)26);
         Serial.println((int)0-9);
        delay(1000);
        Serial.println("message sent");
        delay(3000);           
  }
  else
  {  
    digitalWrite(5,LOW);
          
}

  sensorValue = analogRead(MQ2pin); 
  Serial.print("SMELLING: ");
  Serial.println(sensorValue);
  delay(2000);
  lcd.clear();
  lcd.setCursor(0, 0);
   lcd.print("SMELLING :");
   lcd.print(sensorValue);
    delay(2000);
    lcd.clear();
  if 
    (sensorValue>=200)
  {
    
    digitalWrite(5, HIGH);
   delay(2000);
  }
  else
  {
    digitalWrite(5, LOW);
    
}
}
