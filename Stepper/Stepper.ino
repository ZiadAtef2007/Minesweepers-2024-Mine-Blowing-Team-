#define dirPin 2
#define stepPin 3

char motion;

void setup() {
Serial.begin(9600);

pinMode(stepPin, OUTPUT);// rotate

pinMode(dirPin, OUTPUT);// direction

}

void loop() {

motion = 'u';

  if (motion=='d'){
    // say what you got:
    digitalWrite(dirPin, HIGH);

    digitalWrite(stepPin, HIGH);

    delayMicroseconds(100);

    digitalWrite(stepPin, LOW);

    delayMicroseconds(100);
  }
  else if (motion=='u'){
    // read the incoming byte:
//    motion = Serial.read();

    // say what you got:
    digitalWrite(dirPin, LOW);

    digitalWrite(stepPin, HIGH);

    delayMicroseconds(100);

    digitalWrite(stepPin, LOW);

    delayMicroseconds(100);
    
  }
  else{
        digitalWrite(stepPin, LOW);
    }
    
}
 
