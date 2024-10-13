#define button1 3
#define button2 4
#define motor1 8
#define motor2 9
#define Speed A5
#define en 10

bool state = HIGH;
bool state2 = HIGH;
int V; 
void setup() {
  // put your setup code here, to run once:
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(motor1, OUTPUT);
  pinMode(motor2, OUTPUT);
  pinMode(Speed, OUTPUT);
  pinMode(en, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  state = digitalRead(button1);
  state2 = digitalRead(button2);
  V = analogRead(en);
  V = map(V, 0, 1023, 0, 255);
  analogWrite(Speed, V);
  if(state && state2){
    digitalWrite(motor1, LOW);
    digitalWrite(motor2, LOW);
    }
  else if(state){
    digitalWrite(motor1, HIGH);
    digitalWrite(motor2, LOW);
  }
  else if(state2){
    digitalWrite(motor1, LOW);
    digitalWrite(motor2, HIGH);
    }
  else{
    digitalWrite(motor1, LOW);
    digitalWrite(motor2, LOW);
    }
}
