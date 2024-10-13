/*Example code for testing the Cytron Technologies 10A Rev 2.0 Motor Driver
 *The code uses only two pins, one for the motor direction (Pin 9) 
 * and one for the motor speed (pin 9). The speed is set using PWM. 
 * This code is meant to be run on the Arduino Uno hardware. 
 */


//Pins used to control direction and speed of the motor. Speed pin should be a pwm pin.
#define MD1 50
#define MD2 51
#define MS1 2
#define MS2 3


void setup() {
  //Declaration for the pins used, both should be outputs.
  pinMode(MD1, OUTPUT);
  pinMode(MD2, OUTPUT);
  pinMode(MS1, OUTPUT);
  pinMode(MS2, OUTPUT);
}

void loop() {
  digitalWrite(MD1, LOW);
  digitalWrite(MD2, LOW);
  analogWrite(MS1, 128);
  analogWrite(MS2, 128);
}
