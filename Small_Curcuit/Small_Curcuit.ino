#define b1 49
#define b2 48
#define r1 47
#define r2 46
#define MD1 50
#define MD2 51
#define MS1 2
#define MS2 3

bool state = HIGH;
bool state2 = HIGH;

void setup() {
  // put your setup code here, to run once:
  pinMode(MD1, OUTPUT);
  pinMode(MD2, OUTPUT);
  pinMode(MS1, OUTPUT);
  pinMode(MS2, OUTPUT);
  pinMode(b1, INPUT);
  pinMode(b2, INPUT);
  pinMode(r1, OUTPUT);
  pinMode(r2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  state = digitalRead(b1);
  state2 = digitalRead(b2);
  if(state && state2){
    digitalWrite(r1, HIGH);
    digitalWrite(r2, HIGH);
    }
  else if(state){
    digitalWrite(r1, HIGH);
    digitalWrite(r2, LOW);
  }
  else if(state2){
    digitalWrite(r1, LOW);
    digitalWrite(r2, HIGH);
    }
  else{
    digitalWrite(r1, LOW);
    digitalWrite(r2, LOW);
    }
  digitalWrite(MD1, HIGH);
  digitalWrite(MD2, HIGH);
  analogWrite(MS1, 255);
  analogWrite(MS2, 255);
}
