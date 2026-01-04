#include <LiquidCrystal.h>
#include <Keypad.h>
LiquidCrystal lcd(8, 9, 10, 11, 12, 13);  // LCD pin connections
const byte pushbutton = 0;
const byte ledPin = 5;
const byte ledPin2 = 6;
const int fanPin = 7;
const int tempPin = A0;
const String password = "1214";  // Change as needed
String inputPassword = "";
const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = 
{ {'7', '8', '9', '/'},
  {'4', '5', '6', '*'},
  {'1', '2', '3', '-'},
  {'C', '0', '=', '+'}  };
byte rowPins[ROWS] = {A1, A2, A3, A4};
byte colPins[COLS] = {4, 3, 2, 1};
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);
void setup() 
{ lcd.begin(20, 4);
  lcd.setCursor(3, 0);
  lcd.print("Enter Password:");
  pinMode(fanPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(tempPin, INPUT);
  pinMode(pushbutton, INPUT);
  digitalWrite(fanPin, LOW);  // Fan OFF initially
  digitalWrite(ledPin, LOW);  // LED OFF initially
  digitalWrite(ledPin2, LOW); // LED OFF initially
  }
void loop() 
{  char key = keypad.getKey();
  if (key) {
    if (key == 'C') {  // Clear input
      inputPassword = "";  // Reset password
      lcd.setCursor(0, 1);
      lcd.print("                    "); } 
    else if (key == '=') {  
      if (inputPassword == password) {
        lcd.setCursor(0, 0);
        lcd.print("                    ");  // Clear enter password
        lcd.setCursor(0, 1);
        lcd.print("                    ");  // Clear password
        lcd.setCursor(3, 1);
        lcd.print("ACCESS GRANTED!");
        delay(800);  
        lcd.setCursor(3, 1);
        lcd.print("                  ");  // Clear Access Granted message
        unsigned long startTime = millis();  // Start the timer
        unsigned long lastUpdate = millis();
        int hours = 0, minutes = 0, seconds = 0;
        while (true) {
          unsigned long currentTime = millis();
          if (currentTime - lastUpdate >= 1000) {
            lastUpdate += 1000;
            seconds++;
            if (seconds == 60) {
              seconds = 0;
              minutes++;    }
            if (minutes == 60) {
              minutes = 0;
              hours++;  }
            lcd.setCursor(3, 0);
            lcd.print("LENGTH OF STAY");
            lcd.setCursor(4, 1);
            lcd.print(hours < 10 ? "0" : "");  // Add leading zero
            lcd.print(hours);
            lcd.print(" : ");
            lcd.print(minutes < 10 ? "0" : "");  // Add leading zero
            lcd.print(minutes);
            lcd.print(" : ");
            lcd.print(seconds < 10 ? "0" : "");  // Add leading zero
            lcd.print(seconds);
            lcd.setCursor(1, 2);
            lcd.print("=================="); // Display divider }
          int tempValue = analogRead(tempPin);
          int check = digitalRead(pushbutton);
          if (check == 1) {
            digitalWrite(fanPin, HIGH);  
            digitalWrite(ledPin, HIGH);   
            digitalWrite(ledPin2, HIGH); 
            float temperature = (tempValue * 5.0 / 1023.0) * 100;
            lcd.setCursor(1, 3);
            lcd.print("TEMPERATURE: ");
            lcd.print(temperature, 1);  // Display with 1 decimal place
            lcd.write(223);  // ascii for degree symbol
            lcd.print("C");  }
          else { 
            digitalWrite(fanPin, LOW);  
            digitalWrite(ledPin, LOW);   
            digitalWrite(ledPin2, LOW);   }}
            }
  }          else {
        lcd.setCursor(3, 2);
        lcd.print("WRONG PASSWORD!");
        delay(1000);    }
      inputPassword = "";  
      lcd.setCursor(3, 2);
      lcd.print("                    ");  } 
    else {
      if (inputPassword.length() < 4) {
        inputPassword += key;
        lcd.setCursor(0, 1);
        String maskedPassword = "";
        for (int i = 0; i < inputPassword.length(); i++) {
          maskedPassword += "*";   } 
        lcd.print(maskedPassword + " ");    }}}}