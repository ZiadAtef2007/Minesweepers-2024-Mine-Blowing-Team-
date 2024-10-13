#define dirPin 7
#define stepPin 6

char X;

void setup() {

pinMode(stepPin, OUTPUT);// rotate

pinMode(dirPin, OUTPUT);// direction


Serial.begin(9600);

//digitalWrite(dirPin, HIGH);

} void loop() {

digitalWrite(dirPin, LOW);
analogWrite(stepPin, 128);


//if(Serial.available()){
//X = Serial.read();
//Serial.println(X);
//if( X == 'S'){
//  digitalWrite(dirPin, LOW);
//
//  digitalWrite(stepPin, LOW);
//  }
//if( X == 'U'){
//  digitalWrite(dirPin, LOW);
//
//  analogWrite(stepPin, 128);
//}
//
//if( X == 'D'){
//  digitalWrite(dirPin, HIGH);
//
//  analogWrite(stepPin, 128);
//
//}
//}
}
