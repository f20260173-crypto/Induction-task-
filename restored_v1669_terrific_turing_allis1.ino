// C++ code
//
#include <LiquidCrystal_I2C.h>

int Dist = 0;

int Time_in_danger = 0;

int Anchor = 0;

LiquidCrystal_I2C lcd_1(32, 16, 2);

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

void setup()
{
  lcd_1.init();
  pinMode(8, INPUT);
  pinMode(A0, INPUT);

  // Confiuging th lcd display
  // Turning on the back light
  lcd_1.backlight();
}

void loop()
{
  // Only running this block when the anchor is
  // dropped
  while (digitalRead(8) == 1) {
    // Displaying the state
    lcd_1.setCursor(0, 0);
    lcd_1.print("State:");
    // Displaying  “Anchored”
    lcd_1.setCursor(0, 1);
    lcd_1.print("Anchored ");
    delay(500); // Wait for 500 millisecond(s)
    lcd_1.clear();
  }
  // Block for the open sea
  while ((0.01723 * readUltrasonicDistance(7, 6) >= 100 && analogRead(A0) >= 512) && digitalRead(8) != 1) {
    // Displaying the state
    lcd_1.setCursor(0, 0);
    lcd_1.print("State:");
    // Displaying  “open sea”
    lcd_1.setCursor(0, 1);
    lcd_1.print("Open sea");
    // Resetting the time in Charybdis and storm
    Time_in_danger = 0;
    delay(200); // Wait for 200 millisecond(s)
    lcd_1.clear();
  }
  // For Charybdis
  while (digitalRead(8) != 1 && (1 < 5 && 0.01723 * readUltrasonicDistance(7, 6) < 100)) {
    // Displaying the state
    lcd_1.setCursor(0, 0);
    lcd_1.print("State:");
    // Displaying  “Charybdis”
    lcd_1.setCursor(0, 1);
    lcd_1.print("Charybdis ");
    // Counting time in Charybdis
    Time_in_danger = (Time_in_danger + 1);
    delay(1000); // Wait for 1000 millisecond(s)
    lcd_1.clear();
  }
  // For storm
  while (digitalRead(8) != 1 && (Time_in_danger < 5 && analogRead(A0) < 512)) {
    // Displaying the state
    lcd_1.setCursor(0, 0);
    lcd_1.print("State:");
    // Displaying  “storm”
    lcd_1.setCursor(0, 1);
    lcd_1.print("Storm");
    // Counting time in storm
    Time_in_danger = (Time_in_danger + 1);
    delay(1000); // Wait for 1000 millisecond(s)
    lcd_1.clear();
  }
  // For wrecked
  while (1 >= 5 || Time_in_danger >= 5) {
    lcd_1.setCursor(0, 0);
    lcd_1.print("State:");
    lcd_1.setCursor(0, 1);
    lcd_1.print("WRECKED ");
    delay(1000); // Wait for 1000 millisecond(s)
  }
}