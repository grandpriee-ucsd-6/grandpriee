#include <Servo.h> 
//#include <Arduino.h>

#define LEN 128
#define SI 3
#define CLK 4
#define MAX(x,y) x>y?x:y
#define MIN(x,y) x>y?y:x
#define MEDIAN(x,y,z) MIN((MAX(x,y)),z)
#define Kp 0.9
#define Ki 0.5
#define Kd 0.125
#define SERVOMID 78


using namespace std;

int * cameraData = new int[LEN];
int servoPin = 9;
int motorPin = 8;
int degree = 0;
Servo serv;

void linescan();
int * median_filter(int * raw);
int * gradient_filter(int * raw);
double pid(int mid);
int * edges(int * nums);

unsigned long lastTime = millis();
double prevError;

void setup() {
  Serial.begin(9600);
  pinMode(motorPin, OUTPUT);
  pinMode(SI,OUTPUT);
  pinMode(CLK,OUTPUT);
  pinMode(A0,INPUT);
  serv.attach(servoPin);
}

void loop() {

   linescan();
//   for(int i = 0; i < 128; i++){
//    Serial.print(cameraData[i]);
//    Serial.print(", ");
//  }
//   Serial.println("");
  int * medianArr = median_filter(cameraData);
  int * modifiedArr = gradient_filter(medianArr);
  int * edge = edges(modifiedArr);


  
  int maxin = edge[0];
  int minin = edge[1];
  int mid = (maxin + minin)/2;
  double out = pid(mid);

  int turnAngle = (0.3 * out) + SERVOMID;

  Serial.print(mid);
  Serial.print(' ');
  Serial.print(out);
  Serial.print(' ');
  Serial.print(turnAngle);
  Serial.println();

  serv.write(turnAngle);
  delay(4);

  delete(edge);
  delete(medianArr);
  delete(modifiedArr);
   
//  Serial.print(maxin);
//  Serial.print(", ");
//  Serial.print(minin);
//  Serial.print("array:");
  
  //serv.write(turnAngle);
  // vdelay(4);
//   delete(edge);
//   delete(medianArr);
//   delete(modifiedArr);
//   free(cameraData);
//   cameraData = new int[LEN];
}
