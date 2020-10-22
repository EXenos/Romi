/*
       @@@@@@@@@@@&*           %@@@@@%       @@@@@@@@@    @@@@@@@@@  @@@@@@@@
       @@@@@@@@@@@@@@@     #@@@@@@@@@@@@    @@@@@@@@@@   @@@@@@@@@* @@@@@@@@@
       @@@@@@   @@@@@@   /@@@@@%  .@@@@@@    @@@/@@@@@ @@@@@@@@@@    @@@@@@
      &@@@@@##&@@@@@@   @@@@@@(   @@@@@@@   @@@,.@@@@@@@@,.@@@@@    @@@@@@
      @@@@@@@@@@@@@    &@@@@@@    @@@@@@   @@@@  @@@@@@@  @@@@@    (@@@@@
     @@@@@@  @@@@@@*   @@@@@@    @@@@@@   .@@@   @@@@@#  @@@@@@    @@@@@&
   @@@@@@@@   @@@@@@%  .@@@@@@@@@@@@@    @@@@@%  @@@@  @@@@@@@@  @@@@@@@@
  %@@@@@@@&   @@@@@@     #@@@@@@@@      @@@@@@   @@@   @@@@@@@/ @@@@@@@@%
  Provided by Paul O'Dowd Oct 2020
*/


// The following files should all appear in
// tabs above.  They are incomplete and match
// up to exercie labsheets provided.
#include "lineSensor.h"
#include "encoders.h"
#include "kinematics.h"
#include "motor.h"
#include "pid.h"

float l_power = 30;   //with floats works the same
float r_power= 30;
//lineSensor_c lineSensor;    //object typou lineSensor_c
motor_c motor;       //object typou motor_c
int pin;


// Setup, only runs once when the power
// is turned on.  However, if your Romi
// gets reset, it will run again.
void setup() {

  // Start up the serial port.
  Serial.begin(9600);

  // Delay to connect properly.
  delay(1000);

  // Print a debug, so we can see a reset on monitor.
  Serial.println("***RESET***");

  //object pointer of the class lineSensor_c
//  lineSensor=new lineSensor_c(pin);
  //object of the class motor_c
//  motor=new motor_c();
  setupEncoder0();      //right motor
  setupEncoder1();      //left motor
  motor.lookLeft();
  motor.lookRight();
  motor.turnLeft();
  motor.turnRight();
  motor.moveLeftMotorFWD(l_power);
  motor.moveRightMotorFWD(r_power);
  motor.moveLeftMotorBWD(l_power);
  motor.moveRightMotorBWD(r_power);
  
} // end of setup()


// The main loop of execution.  This loop()
// function is automatically called every
// time it finishes.  You should try to write
// your code to take advantage of this looping
// behaviour.  
void loop() {
  
  Serial.println(" loop ");
  delay(20);

//    //to get the results 
//    int *p; //pointer p
//
//    p = lineSensor->readSensorValues();
//    //*(p+0) periexomeno left
//    //*(p+1) periexomeno centre 
//    //*(p+2) periexomeno right
//
//    Serial.print(*(p+0));  //print tis times
//    Serial.print(*(p+1));
//    Serial.print(*(p+2));

      //delay(50);

  if(count_e0<2000 && count_e1<2000){    
  //ROMI MOVING

  // Adjust power. e.g., increment by 4 on every loop()
  //l_power = l_power + 4;
  //r_power = r_power + 4;

  motor.moveRightMotorFWD(r_power);
  motor.moveLeftMotorFWD(l_power);

  // Send power PWM to pins, to motor drivers.
  analogWrite( L_PWM_PIN, l_power );
  analogWrite( R_PWM_PIN, r_power );

  // Brief pause
  delay(250);

  Serial.println(count_e1);
  Serial.println(count_e0);
  }else{
    analogWrite( L_PWM_PIN, 0 );
    analogWrite( R_PWM_PIN, 0 );
  }
  delay(500); 
} // end of loop()
