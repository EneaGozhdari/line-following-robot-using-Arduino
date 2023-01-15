#include <AFMotor.h>

#include <QTRSensors.h> 
  
AF_DCMotor motor1(1, MOTOR12_1KHZ ); //create motor #1 using M1 dalje on Motor Drive Shield, set to 1kHz PWM frequency
AF_DCMotor motor2(2, MOTOR12_1KHZ ); //create motor #2 using M2 dalje on Motor Drive Shield, set to 1kHz PWM frequency
  
#define KP 2 //experiment to determine this, start by something small that just makes your bot follow the line at a slow speed
#define KD 5 //experiment to determine this, slowly increase the speeds and adjust this value. ( Note: Kp < Kd) 
#define M1_minumum_speed 150  //minimum I shperjtesise per Motorin 1
#define M2_minumum_speed 150  //minimum I shpejtesise per Motorin 2
#define M1_maksimum_speed 250 //maimumi I shpejesise per Motorin 1
#define M2_maksimum_speed 250 //maximum I shpejtesise per Motorin 2
#define MIDDLE_SENSOR 4       //numri I sensorit te mesem te perdorur
#define NUM_SENSORS 5         //numri I sensoreve te perdour
#define TIMEOUT 2500          //prêt 2500 milisekonda per sensorin dales qe te shkoj LOW EMITTER_PIN 2         //emitterPin eshte pini I Arduinos qe kontrollon nese LED-et IR jane te ON ose OFF . Emitteri kontrollohet nga pini dixhital 2.
#define DEBUG 0

//sensoret nga 0 ne 5 jane te lidhur perkatesisht me hyrjet analoge te arduinos nga 0 ne 5 respektivisht
QTRSensorsRC qtrrc((unsigned charë]) { A4,A3,A2,A1,A0} ,NUM_SENSORS, TIMEOUT, EMITTER_PIN);
  
unsigned int sensorValuesëNUM_SENSORS];
  
void setup()
{
delay(1500);
manual_calibration();
set_motors(0,0);
}
  
int lastError = 0;
int last_proportional = 0;
int integral = 0;
  
void loop()
{
unsigned int sensorsë5];
int position = qtrrc.readLine(sensors); //kalibrohet duke e kaluar persiper rruges te caktuar , referohu libraries QTR Sensors ne Arduino Libraries per me shume detaje ne pozicionimin e tij.
int error = position - 2000;
  
int motorSpeed = KP * error + KD * (error - lastError);
lastError = error;
  
int leftMotorSpeed = M1_minumum_speed + motorSpeed;
int rightMotorSpeed = M2_minumum_speed - motorSpeed;
  
// vendosim shpejtesine e motorrit duke perdoru dy variablat e perdorura me siper
set_motors(leftMotorSpeed, rightMotorSpeed);
}
  
void set_motors(int motor1speed, int motor2speed)
{
if (motor1speed > M1_maksimum_speed ) motor1speed = M1_maximum_speed;
if (motor2speed > M2_maksimum_speed ) motor2speed = M2_maximum_speed;
if (motor1speed < 0) motor1speed = 0; 
if (motor2speed < 0) motor2speed = 0; 
motor1.setSpeed(motor1speed); 
motor2.setSpeed(motor2speed);
motor1.run(FORWARD); 
motor2.run(FORWARD);
}

//duhet kalibruar nje fare kohe duke kaluar sensoret smbi vije ose mund te perdorim auto kalibrim te grupit te sensoreve
void manual_calibration() {
  
int i;
for (i = 0; i < 250; i++)
{
qtrrc.calibrate(QTR_EMITTERS_ON);
delay(20);
}
  
if (DEBUG) {
Serial.begin(9600);
for (int i = 0; i < NUM_SENSORS; i++)
{
Serial.print(qtrrc.calibratedMinimumOnëi]);
Serial.print(' ');
}
Serial.println();
  
for (int i = 0; i < NUM_SENSORS; i++)
{
Serial.print(qtrrc.calibratedMaximumOnëi]);
Serial.print(' ');
}
Serial.println();
Serial.println();
}
}
