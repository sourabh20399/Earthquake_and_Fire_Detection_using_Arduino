#include<LiquidCrystal.h>
#include<SoftwareSerial.h>
#define DEBUG true

//LCD pin configuration---------------------------------------------
LiquidCrystal lcd(10, 11, 4, 5, 6, 7);

//Pin configuration for Tilt Sensor------------------------------------------
const int xpin = A2;
const int ypin = A1;
const int zpin = A0;
int x;
int y;
int z;

//Pin configuration for Motor---------------------------------------------------
const int mpin1 = ;
const int mpin2 = ;
int m1;
int m2;

//Pin configuration for LDR-----------------------------------------------
const int ldrPin =;
int ldr = 0;

//Pin configuration for Buzzer-------------------------------------------
const int buzzPin =;
int buzzState = 0;

//Pin configuration for Wifi Module----------------------------------------
SoftwareSerial esp8266(8, 9);

//Pin configuration for Reset Button------------------------------
const int resetPin =;
int reset = 0;

int earthquake = 0;
int fire = 0;


void setup() {
  pinMode(A2, INPUT);
  pinMode(A1, INPUT);
  pinMode(A0, INPUT);
  pinMode(A2, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(A2, INPUT);
  pinMode(A2, OUTPUT);
  pinMode(A2, INPUT);

  Serial.begin(9600);
  esp8266.begin(9600);
  lcd.begin(16, 2);

  sendData("AT+RST\r\n", 2000, DEBUG);
  delay(3000);
  sendData("AT+CWMODE=2\r\n", 1000, DEBUG);
  delay(1000);
  sendData("AT+CIPMODE=0\r\n", 1000, DEBUG);
  delay(1000);
  sendData("AT+CIPMUX=1\r\n", 1000, DEBUG);
  delay(1000);
  sendData("AT+CIFSR\r\n", 1000, DEBUG);
  delay(1000);
  sendData("AT+CIPSERVER=1,81\r\n", 1000, DEBUG);
  delay(2000);

  lcd.print("Hazard Detection");
  lcd.setCursor(5, 1);
  lcd.print("System");
  delay(2000);
}

void loop() {
  lcd.clear();

  //Earthquake Detection System----------------------------------------
  x = analogRead(xpin);
  y = analogRead(ypin);
  z = analogRead(zpin);
  Serial.print("X:");
  Serial.print(x);
  Serial.print("|");
  Serial.print("Y:");
  Serial.print(y);
  Serial.print("|");
  Serial.print("Z:");
  Serial.print(z);
  Serial.print("|");
  delay(1000);

  if (x >? ? || y >? ? || z >? ? )
  {
    earthquake = HIGH;
  }
  if (x <? ? || y <? ? || z <? ? )
  {
    earthquake = HIGH;
  }
  if (x = ?? && y = ?? && z = ?? )
  {
    earthquake = LOW;
  }

  if (earthquake == HIGH)
  {
    lcd.print("!!DANGER!!")
    lcd.setCursor(0, 1);
    lcd.print("EARTHQUAKE");
    Serial.println("!!DANGER!! Earthquake Detected");
    buzzState = HIGH;
    sendData("AT+CIPSEND=0,30\r\n", 1000, DEBUG);
    delay(100);
    sendData("!!DANGER!! Earthquake Detected", 1000, DEBUG);
    delay(500);
  }
  if (earthquake == LOW)
  {
    lcd.clear();
    buzzState = LOW;
  }

  //Fire Detection System-----------------------------------------------
  ldr = analogRead(ldrPin);
  Serial.println("ldr:");
  Serial.print(ldr);
  delay(1000);


  if (ldr >? ? )
  {
    fire = HIGH;
  }
  if (ldr <? ? )
  {
    fire = LOW;
  }

  if (fire == HIGH)
  {
    lcd.print("!!DANGER!!")
    lcd.setCursor(0, 1);
    lcd.print("FIRE");
    Serial.println("!!DANGER!! Fire Detected");
    buzzState = HIGH;
    sendData("AT+CIPSEND=0,24\r\n", 1000, DEBUG);
    delay(100);
    sendData("!!DANGER!! Fire Detected", 1000, DEBUG);
    delay(500);
    m1 = LOW;
    m2 = HIGH;
    digitalWrite(mpin1, m1);
    digitalWrite(mpin2, m2);
  }
  if (fire == LOW)
  {
    lcd.clear();
    buzzState = LOW;
    m1 = LOW;
    m2 = LOW;
    digitalWrite(mpin1, m1);
    digitalWrite(mpin2, m2);
  }


  //Buzzer-----------------------------------------------
  if (buzzState == HIGH)
  {
    tone(buzzPin, 250, 1000);
    delay(500);
    noTone(buzzPin);
    delay(200);
  }

  //Wifi Contorl--------------------------------------------------
  while (esp8266.available())  //check if any data received in rx(Pin 0) pin from ESP8266-----
  {
    if (esp8266.find("$"))
    {
      char c = esp8266.read();
      if (c == 's')
      {
        buzzState = LOW;
        earthquake = LOW;
        fire = LOW;
        m1 = LOW;
        m2 = LOW;
        lcd.clear();
        c = 0;
      }
    }
  }

}


//Fuction Block of sendData-----------------------------------------------------
String sendData(String command, const int timeout, boolean debug)
{

  String response = "";
  esp8266.print(command); // send the read character to the esp8266
  long int time = millis();
  while ( (time + timeout) > millis())
  {
    while (esp8266.available())
    {
      // The esp has data so display its output to the serial window
      char c = esp8266.read(); // read the next character.
      response += c;
    }
  }

  return response;
}
