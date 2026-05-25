#include <SPI.h>
#include <MFRC522.h>
int rst_pin=9;
int ss_pin =10;
MFRC522 mfrc522(ss_pin,rst_pin); 
void setup()
{
Serial.begin(9600);
while (!Serial);
SPI.begin();
mfrc522.PCD_Init(); // Initialising the RFID Reader
delay(10);
Serial.println(F("Scan the RFID card to see the 
Unique ID..."));
}
void loop() {
if ( ! mfrc522.PICC_IsNewCardPresent()) // Checks 
if the scanned card is a new card or not
{
return;
}
if ( ! mfrc522.PICC_ReadCardSerial()) // Checks if 
the scanned card ID is readable or not
{
return;
}
mfrc522.PICC_DumpToSerial(&(mfrc522.uid));
}