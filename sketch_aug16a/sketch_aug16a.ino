#define led 5
#define button 3

bool state = HIGH;
void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
  pinMode(button, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  state = digitalRead(button);
  digitalWrite(led, state);
}
