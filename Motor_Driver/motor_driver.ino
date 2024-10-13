#define motor1_1 11
#define motor1_2  12
#define motor2_1 13
#define motor2_2 8
#define speed1 9
#define speed2 10
#define control A5
#define VRX_PIN  A0
#define VRY_PIN  A1


bool state1=HIGH;
bool state2=HIGH;


int x = 0;
int y = 0;
int V=230;


void setup() {
  // put your setup code here, to run once:
  pinMode(motor1_1,OUTPUT);
  pinMode(motor1_2, OUTPUT);
  pinMode(motor2_1,OUTPUT);
  pinMode(motor2_2, OUTPUT);
  pinMode(speed1, OUTPUT);
  pinMode(speed2,OUTPUT);
//  Serial.begin(9600) ;

}
void loop() {
  // put your main code here, to run repeatedly:
   analogWrite(speed1, V);
   analogWrite(speed2, V);
   x = analogRead(VRX_PIN);
   y = analogRead(VRY_PIN);
//   Serial.print("x = ");
//   Serial.print(x);
//   Serial.print("y = ");
//   Serial.println(y);
//   delay(200);

   if(x >= 500 && x <= 525 && y >= 500 && y <= 525){
        digitalWrite(motor1_1, LOW);
        digitalWrite(motor1_2, LOW);
        digitalWrite(motor2_1, LOW);
        digitalWrite(motor2_2, LOW);
    }
   else if(x > 525){
        digitalWrite(motor1_1, HIGH);
        digitalWrite(motor1_2, LOW);
        digitalWrite(motor2_1, LOW);
        digitalWrite(motor2_2, HIGH);
    }
   else if(x < 500){
        digitalWrite(motor1_1, LOW);
        digitalWrite(motor1_2, HIGH);
        digitalWrite(motor2_1, HIGH);
        digitalWrite(motor2_2, LOW);
    }
     else if(y > 525){
      digitalWrite(motor1_1, HIGH);
      digitalWrite(motor1_2, LOW);
      digitalWrite(motor2_1, HIGH);
      digitalWrite(motor2_2, LOW);
    }
   else if(y < 500){
      digitalWrite(motor1_1, LOW);
      digitalWrite(motor1_2, HIGH);
      digitalWrite(motor2_1, LOW);
      digitalWrite(motor2_2, HIGH);
    }
   else{
       
    }
}
