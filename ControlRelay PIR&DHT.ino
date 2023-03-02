#include<Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

#include <DHT.h>
DHT dht(2,DHT21);

int kipas1=3;
int kipas2=4;
int kipas3=5;
int RelayLampu =6;
int RelayKipas =7;
int PIR =8;

void setup(){
  Serial.begin(9600);
  dht.begin();
  lcd.init(); 
  lcd.backlight();
  pinMode(RelayLampu,OUTPUT);
  pinMode(RelayKipas,OUTPUT);
  pinMode(kipas1,OUTPUT);
  pinMode(kipas2,OUTPUT);
  pinMode(kipas3,OUTPUT);
  pinMode(PIR,INPUT);
}
void loop(){
  int value = digitalRead(PIR);
  if (value == HIGH){
    digitalWrite(RelayLampu,HIGH);
    digitalWrite(RelayKipas,HIGH);
  }
  else {
    digitalWrite(RelayLampu,LOW);
    digitalWrite(RelayKipas,LOW);
  }

  int kelembaban=dht.readHumidity();
  int suhu=dht.readTemperature();
  lcd.setCursor(0,0);
  lcd.print("Temperatur:");
  lcd.setCursor(12,0);
  lcd.print(suhu);
  lcd.setCursor(14,0);
  lcd.print(".C");

  lcd.setCursor(0,1);
  lcd.print("Kipas :");
  lcd.setCursor(8,1);

  if(suhu>=27 && suhu<=30){
    digitalWrite(kipas1,HIGH); 
    digitalWrite(kipas2,LOW); 
    digitalWrite(kipas3,LOW); 
    lcd.print("1 ");}


  else if(suhu>=31 && suhu<=34){
    digitalWrite(kipas1,LOW); 
    digitalWrite(kipas2,HIGH); 
    digitalWrite(kipas3,LOW); 
    lcd.print("2 ");}
  
  else if(suhu>=35){
    digitalWrite(kipas1,LOW); 
    digitalWrite(kipas2,LOW); 
    digitalWrite(kipas3,HIGH); 
    lcd.print("3 ");}
}  

