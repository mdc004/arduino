int temp= 30;
void setup() {
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(11,OUTPUT);

}

void loop() {
  for(int i=2; i<11; i++){
    digitalWrite(i,HIGH);
    delay(temp);
    digitalWrite(i,LOW);
  }
  tone(11,9000);
  
}
