void linescan() {
  digitalWrite(CLK, LOW);
  digitalWrite(SI, HIGH);
  digitalWrite(CLK, HIGH);
  digitalWrite(SI, LOW);
  digitalWrite(CLK, LOW);

  for(int i = 0; i < 128; i++){
    digitalWrite(CLK, HIGH);
    digitalWrite(CLK, LOW);
  }
  delayMicroseconds(4000);
  digitalWrite(SI,HIGH);
  digitalWrite(CLK, HIGH);
  digitalWrite(SI, LOW);
  digitalWrite(CLK, LOW);

  for(int i = 0; i < 128; i++){
    delayMicroseconds(2000);
    cameraData[i] = analogRead(A0);
    digitalWrite(CLK, HIGH);
    digitalWrite(CLK, LOW);
  } 
}
