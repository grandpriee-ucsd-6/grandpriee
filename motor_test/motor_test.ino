#define H_OUT 3
#define L_OUT 5

void setup() {
  pinMode(H_OUT, OUTPUT);
  pinMode(L_OUT, OUTPUT);

  analogWrite(L_OUT, 0);
  analogWrite(H_OUT, 30);
}

void loop() {
//
//  analogWrite(L_OUT, 0);
//
//  for (int i = 21; i < 32; i++) {
//
//    analogWrite(H_OUT, i);
//
//    delay(500);
//
//  }
//
//  analogWrite(H_OUT, 0);
//
//  analogWrite(L_OUT, 255);
//
//  delay(5000);
}
