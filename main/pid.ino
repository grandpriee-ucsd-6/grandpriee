double pid(int mid) {
  unsigned long currTime = millis();
  double dt = double(currTime - lastTime);
  double error = mid - 63;
  double derror = (error - prevError)/dt;
  double ierror = (error + prevError)/dt;
  double output = Kp * error + Kd * derror + Ki * ierror;

  prevError = error;
  lastTime = currTime;

  return output;
}
