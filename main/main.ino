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
int validate(int width, int * width_array, int loop_count, int sum); // new validate function

unsigned long lastTime = millis();
double prevError;
int loop_count = 0;
int width_array[512]; //record the width of line we've detected;
int sum_width = 0;
int last_angle;
int flag_back_track = 0; // =1 if car is getting back to track

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
  int turnAngle = SERVOMID;

  /*updated*/
  int width = maxin - minin;
  int ret = validate(width, width_array, loop_count,sum_width);
  if(!ret){
    if(!flag_back_track){
      flag_back_track = 1;
      turnAngle = -last_angle; //out of track,try to reverse t
    }
    else{
      turnAngle = last_angle; // not yet back to track, keep turnnig
    }
  }
  else if(ret == 2){
    turnAngle = SERVOMID; //detect wider line than usual, keep going straight;
  }
  else{
  if(loop_count < 512){
      width_array[loop_count] = width;
      sum_width += width;
  }
  flag_back_track = 0;
  int mid = (maxin + minin)/2;
  double out = pid(mid);

  turnAngle = (0.3 * out) + SERVOMID;
  }
  /*
  Serial.print(mid);
  Serial.print(' ');
  Serial.print(out);
  Serial.print(' ');
  Serial.print(turnAngle);
  Serial.println();*/
  
  /*end of update*/
  serv.write(turnAngle);
  delay(4);

  delete(edge);
  delete(medianArr);
  delete(modifiedArr);
  loop_count ++;
}
