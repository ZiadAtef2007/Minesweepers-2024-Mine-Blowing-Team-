//Libraries:
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include<stdio.h>
//----------------

//defines:
#define dir1 34 
#define speed1 6

#define dir2 35
#define speed2 3
 
#define dir3 36
#define speed3 4

#define dir4 37
#define speed4 5

#define dir_step 12
#define speed_step 13

#define Magnet 46

#define Siren 47

#define Sensor 31
//----------------

//Structure of the messege
struct msg{
  char dir;
  char stepper;
  char magnet;
  };
typedef struct msg msg;
msg R_msg;
//------------------------


bool state1=HIGH;
bool state2=HIGH;


//NRF24 radio signal:
RF24 radio(9, 10); // CE, CSN
const byte address[6] = "00001";
//-------------------


void setup() {
  // put your setup code here, to run once:
  pinMode(dir1,OUTPUT);
  pinMode(speed1, OUTPUT);
  
  pinMode(dir2,OUTPUT);
  pinMode(speed2,OUTPUT);

  pinMode(dir3,OUTPUT);
  pinMode(speed3,OUTPUT);

  pinMode(dir4, OUTPUT);
  pinMode(speed3,OUTPUT);

  pinMode(speed_step, OUTPUT);
  pinMode(dir_step, OUTPUT);

  pinMode(Magnet, OUTPUT);

  pinMode(Siren, OUTPUT);

  pinMode(Sensor, INPUT);
  
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MAX, 1);
  radio.setDataRate(RF24_250KBPS);
  radio.startListening();
  

}
void loop() {
  // put your main code here, to run repeatedly:

  
   if (radio.available()) {
      char text = 'X';
      radio.read(&R_msg, sizeof(R_msg));
      Serial.print("DIR = ");
      Serial.print(R_msg.dir);
      Serial.print("    ");
      Serial.print("STEPPER = ");
      Serial.print(R_msg.stepper);
      Serial.print("    ");
      Serial.print("Magnet = ");
      Serial.println(R_msg.magnet);
    



    
//     DC MOTORS //
    if(R_msg.dir=='F'){
      //  Cytron motor driver dir, pwm
      digitalWrite(dir1, HIGH);
      analogWrite(speed1, 255);

      digitalWrite(dir2, HIGH);
      analogWrite(speed2, 255);

      digitalWrite(dir3, HIGH);
      
      analogWrite(speed3, 255);

      digitalWrite(dir4, HIGH);
      analogWrite(speed4, 255);

      Serial.println("Forward");
    }
    else if(R_msg.dir=='B'){
      digitalWrite(dir1, LOW);
      analogWrite(speed1, 255);

      digitalWrite(dir2, LOW);
      analogWrite(speed2, 255);

      digitalWrite(dir3, LOW);
      analogWrite(speed3, 255);

      digitalWrite(dir4, LOW);
      analogWrite(speed4, 255);

      Serial.println("Back");
    }
    else if(R_msg.dir=='R'){
      digitalWrite(dir1, HIGH);
      analogWrite(speed1, 255);

      digitalWrite(dir2, HIGH);
      analogWrite(speed2, 255);

      digitalWrite(dir3, LOW);
      analogWrite(speed3, 255);

      digitalWrite(dir4, LOW);
      analogWrite(speed4, 255);

      Serial.println("Right");
    }
    else if(R_msg.dir=='L'){
      digitalWrite(dir1, LOW);
      analogWrite(speed1, 255);

      digitalWrite(dir2, LOW);
      analogWrite(speed2, 255);

      digitalWrite(dir3, HIGH);
      analogWrite(speed3, 255);

      digitalWrite(dir4, HIGH);
      analogWrite(speed4, 255);
      Serial.println("Left");
    }
   else{
      analogWrite(speed1, 0);
      analogWrite(speed2, 0);
      analogWrite(speed3, 0);
      analogWrite(speed4, 0);
      Serial.println("STOP");
    }
    // DC MOTORS END //




    float t = micros();
    Serial.println(t);
    




   // MAGNET //
    if (R_msg.magnet == '0'){
      digitalWrite(Magnet, LOW);
      }
    else if (R_msg.magnet == '1'){
      digitalWrite(Magnet, HIGH);
      }
    else{}
   // MAGNET END //
   }



  // Sensor //
  if(digitalRead(Sensor) == HIGH){
    digitalWrite(Siren, HIGH);
    }
  else {
    digitalWrite(Siren, LOW);
    }
  // Sensor End//



   // STEPPER MOTOR //
    if (R_msg.stepper=='U'){ //clockwise
      digitalWrite(dir_step, LOW);
      analogWrite(speed_step, 32);
//      delayMicroseconds(140);
//      digitalWrite(speed_step, LOW);
//      delayMicroseconds(140); 
    }
    if (R_msg.stepper=='D'){ // Anti-clockwise
      digitalWrite(dir_step, HIGH);
      analogWrite(speed_step, 32);
//      delayMicroseconds(40);
//      digitalWrite(speed_step, LOW);
//      delayMicroseconds(40);
    }
    if(R_msg.stepper=='S'){
      digitalWrite(speed_step, LOW);
      }
    // STEPPER MOTOR END //
}
