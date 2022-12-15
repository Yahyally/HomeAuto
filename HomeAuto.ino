#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
#include <SoftwareSerial.h>
SoftwareSerial SIM900A(10,11);//tx,rx

int green=2;//IN1 relay 4
int white=3;//IN2 relay 2
int blue=4;//IN3
int red=5;//IN4 relay 1

void setup()
{
lcd.init(); 
lcd.backlight();
pinMode(white,OUTPUT);
pinMode(red,OUTPUT);
pinMode(blue,OUTPUT);
pinMode(green,OUTPUT);
  lcd.setCursor(0, 0);
  lcd.print("   Welcome to      ");
  lcd.setCursor(0, 1);
  lcd.print("Home Automation");
  delay(2000);
  
SIM900A.begin(115200); // GSM Module Baud rate – communication speed
Serial.begin(115200); // Baud rate of Serial Monitor in the IDE app
delay(100);
SIM900A.println("AT+CMGF=1"); //Text Mode initialisation
delay(1000);
SIM900A.println("AT+CNMI=2,2,0,0,0"); // Receiving Mode Enabled
delay(1000);
SIM900A.println("AT+CMGDA=\r");
  delay(1000);
  Serial.println("Waiting For Message");
}

void loop()
{
int i=0;
char data[200]="";
char ch;
while(1){
  if(SIM900A.available())
  {
   while(SIM900A.available()<=0);
   //Serial.println("Hi");
   ch=SIM900A.read();
   if(ch==' ')
   break;
   data[i]=data[i]+ch;
   i++;
 }
  }
Serial.println(data);
 if(strstr(data,"whOFF"))
 {
  Serial.println("White Is OFF");
  digitalWrite(white,HIGH);
  SIM900A.println("AT+CMGF=1"); //Sets the GSM Module in Text Mode
delay(1000); // Delay of 1000 milli seconds or 1 second
SIM900A.println("AT+CMGS=\"+255654833057\"\r"); // Replace x with mobile number +91
delay(1000);
SIM900A.println("White Is OFF");// The SMS text you want to send
delay(100);
SIM900A.println((char)26);// ASCII code of CTRL+Z
delay(1000);
lcd.clear();
lcd.setCursor(0, 0);
 lcd.print("Wh =OFF");
 
 }
 if(strstr(data,"whON"))
 {
  Serial.println("White Is ON");
  digitalWrite(white,LOW);
  SIM900A.println("AT+CMGF=1"); //Sets the GSM Module in Text Mode
delay(1000); // Delay of 1000 milli seconds or 1 second
SIM900A.println("AT+CMGS=\"+255654833057\"\r"); // Replace x with mobile number +91
delay(1000);
SIM900A.println("White Is ON");// The SMS text you want to send
delay(100);
SIM900A.println((char)26);// ASCII code of CTRL+Z
delay(1000);
lcd.clear();
lcd.setCursor(0, 0);
 lcd.print("Wh =ON");
 }
  Serial.println(data);
 if(strstr(data,"reOFF"))
 {
  Serial.println("Red Is OFF");
  digitalWrite( red,HIGH);
  SIM900A.println("AT+CMGF=1"); //Sets the GSM Module in Text Mode
delay(1000); // Delay of 1000 milli seconds or 1 second
SIM900A.println("AT+CMGS=\"+255654833057\"\r"); // Replace x with mobile number +91
delay(1000);
SIM900A.println("Red Is OFF");// The SMS text you want to send
delay(100);
SIM900A.println((char)26);// ASCII code of CTRL+Z
delay(1000);
lcd.clear();
lcd.setCursor(9, 0);
 lcd.print("Re =OFF");
 
 }
 if(strstr(data,"reON"))
 {
  Serial.println("Red Is ON");
  digitalWrite( red,LOW);
  SIM900A.println("AT+CMGF=1"); //Sets the GSM Module in Text Mode
delay(1000); // Delay of 1000 milli seconds or 1 second
SIM900A.println("AT+CMGS=\"+255654833057\"\r"); // Replace x with mobile number +91
delay(1000);
SIM900A.println("Red Is ON");// The SMS text you want to send
delay(100);
SIM900A.println((char)26);// ASCII code of CTRL+Z
delay(1000);
lcd.clear();
lcd.setCursor(9, 0);
 lcd.print("Re =ON");

 }
 Serial.println(data);
 if(strstr(data,"blOFF"))
 {
  Serial.println("Relay 3 OFF");
  digitalWrite(blue,HIGH);
  SIM900A.println("AT+CMGF=1"); //Sets the GSM Module in Text Mode
delay(1000); // Delay of 1000 milli seconds or 1 second
SIM900A.println("AT+CMGS=\"+255654833057\"\r"); // Replace x with mobile number +91
delay(1000);
SIM900A.println("Blue Is OFF");// The SMS text you want to send
delay(100);
SIM900A.println((char)26);// ASCII code of CTRL+Z
delay(1000);
lcd.clear();
lcd.setCursor(0, 1);
lcd.print("Bl =OFF");

 }
 if(strstr(data,"blON"))
 {
  Serial.println("Relay 3 ON");
  digitalWrite(blue,LOW);
  SIM900A.println("AT+CMGF=1"); //Sets the GSM Module in Text Mode
delay(1000); // Delay of 1000 milli seconds or 1 second
SIM900A.println("AT+CMGS=\"+255654833057\"\r"); // Replace x with mobile number +91
delay(1000);
SIM900A.println("Blue Is ON");// The SMS text you want to send
delay(100);
SIM900A.println((char)26);// ASCII code of CTRL+Z
delay(1000);
lcd.clear();
lcd.setCursor(0, 1);
 lcd.print("Bl =ON");
  
 }
  Serial.println(data);
 if(strstr(data,"grOFF"))
 {
  Serial.println("Green Is OFF");
  digitalWrite( green,HIGH);
  SIM900A.println("AT+CMGF=1"); //Sets the GSM Module in Text Mode
delay(1000); // Delay of 1000 milli seconds or 1 second
SIM900A.println("AT+CMGS=\"+255654833057\"\r"); // Replace x with mobile number +91
delay(1000);
SIM900A.println("Green Is OFF");// The SMS text you want to send
delay(100);
SIM900A.println((char)26);// ASCII code of CTRL+Z
delay(1000);
lcd.clear();
lcd.setCursor(9, 1);
 lcd.print("Gr =OFF");
 }
 if(strstr(data,"grON"))
 {
  Serial.println("Green Is ON");
  digitalWrite( green,LOW);
SIM900A.println("AT+CMGF=1"); //Sets the GSM Module in Text Mode
delay(1000); // Delay of 1000 milli seconds or 1 second
SIM900A.println("AT+CMGS=\"+255654833057\"\r"); // Replace x with mobile number +91
delay(1000);
SIM900A.println("Green Is ON");// The SMS text you want to send
delay(100);
SIM900A.println((char)26);// ASCII code of CTRL+Z
delay(1000);
lcd.clear();
lcd.setCursor(0, 0);
 lcd.print("Gr =ON");

 } 
 if(strstr(data,"ALLON"))
 {
  Serial.println("All Relay ON");
  digitalWrite( green,LOW);
  digitalWrite(blue,LOW);
  digitalWrite(white,LOW);
  digitalWrite(red,LOW);
  SIM900A.println("AT+CMGF=1"); //Sets the GSM Module in Text Mode
delay(1000); // Delay of 1000 milli seconds or 1 second
SIM900A.println("AT+CMGS=\"+255654833057\"\r"); // Replace x with mobile number +91
delay(1000);
SIM900A.println("All are ON");// The SMS text you want to send
delay(100);
SIM900A.println((char)26);// ASCII code of CTRL+Z
delay(1000);
lcd.clear();
lcd.setCursor(0, 0);
 lcd.print("Wh =ON");
 lcd.setCursor(9, 0);
 lcd.print("Re =ON");
 lcd.setCursor(9, 1);
 lcd.print("Gr =ON");
 lcd.setCursor(0, 1);
 lcd.print("Bl =ON");
 
 } 
  if(strstr(data,"ALLOFF"))
 {
  Serial.println("All Relay OFF");
  digitalWrite( green,HIGH);
  digitalWrite(blue,HIGH);
  digitalWrite(white,HIGH);
  digitalWrite(red,HIGH);
  SIM900A.println("AT+CMGF=1"); //Sets the GSM Module in Text Mode
delay(1000); // Delay of 1000 milli seconds or 1 second
SIM900A.println("AT+CMGS=\"+255654833057\"\r"); // Replace x with mobile number +91
delay(1000);
SIM900A.println("All are OFF");// The SMS text you want to send
delay(100);
SIM900A.println((char)26);// ASCII code of CTRL+Z
lcd.clear();
lcd.setCursor(0, 0);
 lcd.print("Wh =OFF");
 lcd.setCursor(9, 0);
 lcd.print("Re =OFF");
 lcd.setCursor(9, 1);
 lcd.print("Gr =OFF");
 lcd.setCursor(0, 1);
 lcd.print("Bl =OFF");

delay(1000);
 }
}
