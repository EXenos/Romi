#ifndef _MOTOR_H
#define _MOTOR_H

#define L_PWM_PIN 10
#define L_DIR_PIN 16
#define R_PWM_PIN  9
#define R_DIR_PIN 15

// A class to neatly contain commands for the 
// motors, to take care of +/- values, a min/max
// power value, & pin setup.

class motor_c {
  public:

    // This is a function prototype.
    // The actual function is written outside
    // of the class (see below).
    motor_c( );

    void lookLeft();
    void lookRight();
    void turnLeft();
    void turnRight();
    void moveLeftMotorFWD(float l_power);
    void moveRightMotorFWD(float r_power);
    void moveLeftMotorBWD(float l_power);
    void moveRightMotorBWD(float r_power);
   };

// Constructor: when you create an instance
// of this class, your constructor will be
// called automatically.  You can treat it 
// a bit like the main setup().  What needs
// to be setup initially within this class?
motor_c::motor_c(  ) {
  pinMode( L_PWM_PIN, OUTPUT );
  pinMode( L_DIR_PIN, OUTPUT );
  pinMode( R_PWM_PIN, OUTPUT );
  pinMode( R_DIR_PIN, OUTPUT );

  // Set initial direction for l and r
  // Which of these is foward, or backward?
  digitalWrite( L_DIR_PIN, LOW );  //LOW moves both forward
  digitalWrite( R_DIR_PIN, LOW );
}

// You can add your own functions to the class.
// Don't forget to also prototype in the class
// definition above.
//void motor_c::myOwnFunction( float an_argument ) {
//  

void motor_c::lookLeft(){
  turnLeft(); //na gyrisei mexri 90deg aristera
  //lookFWD(); //na gyrisei na koitaei pali mprosta or
  turnRight(); //na gyrisei na koitaei pali mprosta 
}

void motor_c::lookRight(){
  turnRight(); 
  //lookFWD();
  turnLeft();
}

void motor_c::turnLeft(){
  moveLeftMotorBWD(30);
  moveRightMotorFWD(30);
  //mexri na brei grammi, boolean onLine == true 
}

void motor_c::turnRight(){
  moveLeftMotorFWD(30);
  moveRightMotorBWD(30);
  //mexri na brei grammi, boolean onLine == true
}

void motor_c::moveLeftMotorFWD(float l_power){
  digitalWrite( L_DIR_PIN, LOW );   
  analogWrite( L_PWM_PIN, l_power );
}

void motor_c::moveRightMotorFWD(float r_power){
  digitalWrite( R_DIR_PIN, LOW );   
  analogWrite( R_PWM_PIN, r_power );
}

void motor_c::moveRightMotorBWD(float r_power){
  digitalWrite( R_DIR_PIN, HIGH );   
  analogWrite( R_PWM_PIN, r_power );
}

void motor_c::moveLeftMotorBWD(float r_power){
  digitalWrite( R_DIR_PIN, HIGH );   
  analogWrite( R_PWM_PIN, r_power );
}
  
//}

#endif

//  //MOTOR MOVING
//
//  // Adjust power. e.g., increment by 4 on every loop()
//  //l_power = l_power + 4;
//  //r_power = r_power + 4;
//
//  moveRightMotor(10);
//  moveLeftMotor(10);
//
//  // Send power PWM to pins, to motor drivers.
//  analogWrite( L_PWM_PIN, l_power );
//  analogWrite( R_PWM_PIN, r_power );
