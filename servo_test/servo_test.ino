#include <Servo.h>

Servo myservo;  // create servo object to control a servo

const int CENTER = 78; // Straight ahead
const int LOWER_LIMIT = CENTER - 22; // Rightmost
const int UPPER_LIMIT = CENTER + 22; // Leftmost
const int SERVO_DELAY = 4; // Fastest possible speed, don't reduce
int pos = 0;    // variable to store the servo position

void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object

  myservo.write(LOWER_LIMIT);
}

// Go from left to right and from right to left as fast as possible
void loop() {
  for (pos = LOWER_LIMIT; pos <= UPPER_LIMIT; pos++) {
    myservo.write(pos);
    delay(SERVO_DELAY);
  }

  for (pos = UPPER_LIMIT; pos >= LOWER_LIMIT; pos--) {
    myservo.write(pos);
    delay(SERVO_DELAY);
  }
}
