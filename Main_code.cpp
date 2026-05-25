#include <Servo.h>
#include <MFRC522.h>
#include <SPI.h>
#include <LiquidCrystal_I2C.h>
int buzzer =2;
int servopin=3;
int rstpin=9;
int sspin=10;
byte lock;
String valid_id1="62 3D DD 51";
String valid_id2="B8 51 FA 12";
int delay1=200;
int delay2=1500;
MFRC522 rfid(sspin,rstpin);
LiquidCrystal_I2C lcd(0x27,16,2);
Servo servo;
void setup()
{
SPI.begin(); 
Serial.begin(9600);
lcd.init();
lcd.backlight();
servo.attach(servopin);
//servo.write(70);
rfid.PCD_Init();
pinMode(buzzer,OUTPUT);
}
void loop()
{
lcd.setCursor(4,0);
lcd.print("Welcome!");
lcd.setCursor(0,1);
if(lock==1)
{
lcd.print("Scan to unlock door...");
}
else if(lock==0)
{
lcd.print("Scan to lock door...");
}
delay(delay2);
lcd.clear();
if(!rfid.PICC_IsNewCardPresent())
{
return;
}
if(!rfid.PICC_ReadCardSerial())
{
return;
}
String UID="";
for(int i=0;i<rfid.uid.size;i++)
{
UID.concat(String(rfid.uid.uidByte[i]< 0x10 ? " 
0":" "));
UID.concat(String(rfid.uid.uidByte[i],HEX));
delay(300);
}
UID.toUpperCase();
if((UID.substring(1)==valid_id1||UID.substring(1)==
valid_id2) && lock==0)
{
digitalWrite(buzzer,HIGH);
delay(50);
digitalWrite(buzzer,LOW);
delay(100);
servo.write(50);
lcd.setCursor(0,0);
lcd.print("Valid Card...");
lcd.setCursor(0,1);
lcd.print("Door Locked..");
delay(1500);
lcd.clear();
lock=1;
}
else
if((UID.substring(1)==valid_id1||UID.substring(1)==va
lid_id2) && lock==1)
{
digitalWrite(buzzer,HIGH);
delay(50);
digitalWrite(buzzer,LOW);
delay(100);
servo.write(110);
lcd.setCursor(0,0);
lcd.print("Valid Card...");
lcd.setCursor(0,1);
lcd.print("Door Unlocked...");
delay(1500);
lcd.clear();
lock=0;
}
else
{
digitalWrite(buzzer,HIGH);
delay(120);
digitalWrite(buzzer,LOW);
delay(120);
digitalWrite(buzzer,HIGH);
delay(120);
digitalWrite(buzzer,LOW);
delay(120);
lcd.setCursor(0,0);
lcd.print("Invalid Card!!!");
lcd.setCursor(0,1);
lcd.print("Access Denied!!");
delay(delay2);
lcd.clear();
}
}