int key=0, num;
int buzzer=2;
void setup() {
    Serial.begin(9600);
    pinMode(2, OUTPUT); //buzzer
    pinMode(3, OUTPUT); //led vero 
    pinMode(4, OUTPUT); //led falso 
    pinMode(5, OUTPUT); //led 1 
    pinMode(6, OUTPUT); //led 2
    pinMode(7, OUTPUT); //led 3 
    pinMode(8, OUTPUT); //led 4 
    pinMode(9, OUTPUT); //bottone 1
    pinMode(10, OUTPUT); //bottone 2
    pinMode(11, OUTPUT); //bottone 3
    pinMode(12, OUTPUT); //bottone 4

}

void loop() {
    digitalWrite(3,HIGH);
    digitalWrite(4,HIGH);
    digitalWrite(5,HIGH);
    digitalWrite(6,HIGH);
    digitalWrite(7,HIGH);
    digitalWrite(8,HIGH);
    delay(1000);
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
    digitalWrite(6,LOW);
    digitalWrite(7,LOW);
    digitalWrite(8,LOW);
    delay(500);
    key=0;
    num = 0;
    num = (int)random(1, 5);
    Serial.println(num+4);
    for(int i=0; i<100; i++){
      Serial.println(num+4);
      num = (int)random(1, 5);
    }
    digitalWrite(num+4,HIGH);
    delay(0.9);
    digitalWrite(num+4,LOW);
    do{
        if(digitalRead(9)==HIGH)key = 9;
            else if (digitalRead(10)==HIGH)key = 10;
                else if (digitalRead(11)==HIGH)key = 11;
                    else if (digitalRead(12)==HIGH)key = 12;
    }
    while(key==0);
    key -=8;
    if(key == num){  
      digitalWrite(3,HIGH);
      
tone(buzzer, 510 ,100);  
delay ( 450);  
tone(buzzer, 380 ,100);  
delay ( 400);  
tone(buzzer, 320 ,100);  
delay ( 500);  
tone(buzzer, 440 ,100);  
delay ( 300);  
tone(buzzer, 480 ,80);  
delay ( 330);  
tone(buzzer, 450 ,100);  
delay ( 150);  
tone(buzzer, 430 ,100);  
delay ( 300);  
tone(buzzer, 380 ,100);  
delay ( 200);  
tone(buzzer, 660 ,80);  
delay ( 200);  
tone(buzzer, 760 ,50);  
delay ( 150);  
tone(buzzer, 860 ,100);  
delay ( 300);  
tone(buzzer, 700 ,80);  
delay ( 150);  
tone(buzzer, 760 ,50);  
delay ( 350);  
tone(buzzer, 660 ,80);  
delay ( 300);  
tone(buzzer, 520 ,80);  
delay ( 150);  
tone(buzzer, 580 ,80);  
delay ( 150);  
tone(buzzer, 480 ,80);  
delay ( 500);  
  
tone(buzzer, 510 ,100);  
delay ( 450);  
tone(buzzer, 380 ,100);  
delay ( 400);  
tone(buzzer, 320 ,100);  
delay ( 500);  
tone(buzzer, 440 ,100);  
delay ( 300);  
tone(buzzer, 480 ,80);  
delay ( 330);  
tone(buzzer, 450 ,100);  
delay ( 150);  
tone(buzzer, 430 ,100);  
delay ( 300);  
tone(buzzer, 380 ,100);  
delay ( 200);  
tone(buzzer, 660 ,80);  
delay ( 200);  
tone(buzzer, 760 ,50);  
delay ( 150);  
tone(buzzer, 860 ,100);  
delay ( 300);  
tone(buzzer, 700 ,80);  
delay ( 150);  
tone(buzzer, 760 ,50);  
delay ( 350);  
tone(buzzer, 660 ,80);  
delay ( 300);  
tone(buzzer, 520 ,80);  
delay ( 150);  
tone(buzzer, 580 ,80);  
delay ( 150);  
tone(buzzer, 480 ,80);  
delay ( 500);  
  
tone(buzzer, 500 ,100);  
delay ( 300);  
  
tone(buzzer, 760 ,100);  
delay ( 100);  
tone(buzzer, 720 ,100);  
delay ( 150);  
tone(buzzer, 680 ,100);  
delay ( 150);  
tone(buzzer, 620 ,150);  
delay ( 300);  
  
tone(buzzer, 650 ,150);  
delay ( 300);  
tone(buzzer, 380 ,100);  
delay ( 150);  
tone(buzzer, 430 ,100);  
delay ( 150);  
  
tone(buzzer, 500 ,100);  
delay ( 300);  
tone(buzzer, 430 ,100);  
delay ( 150);  
tone(buzzer, 500 ,100);  
delay ( 100);  
tone(buzzer, 570 ,100);  
delay ( 220);  
  
tone(buzzer, 500 ,100);  
delay ( 300);  
  
tone(buzzer, 760 ,100);  
delay ( 100);  
tone(buzzer, 720 ,100);  
delay ( 150);  
tone(buzzer, 680 ,100);  
delay ( 150);  
tone(buzzer, 620 ,150);  
delay ( 300);  
  
tone(buzzer, 650 ,200);  
delay ( 300);  
  
tone(buzzer, 1020 ,80);  
delay ( 300);  
tone(buzzer, 1020 ,80);  
delay ( 150);  
tone(buzzer, 1020 ,80);  
delay ( 300);  
  
tone(buzzer, 380 ,100);  
delay ( 300);  
tone(buzzer, 500 ,100);  
delay ( 300);  
  
tone(buzzer, 760 ,100);  
delay ( 100);  
tone(buzzer, 720 ,100);  
delay ( 150);  
tone(buzzer, 680 ,100);  
delay ( 150);  
tone(buzzer, 620 ,150);  
delay ( 300);  
  
tone(buzzer, 650 ,150);  
delay ( 300);  
tone(buzzer, 380 ,100);  
delay ( 150);  
tone(buzzer, 430 ,100);  
delay ( 150);  
  
tone(buzzer, 500 ,100);  
delay ( 300);  
tone(buzzer, 430 ,100);  
delay ( 150);  
tone(buzzer, 500 ,100);  
delay ( 100);  
tone(buzzer, 570 ,100);  
delay ( 420);  
  
tone(buzzer, 585 ,100);  
delay ( 450); 
digitalWrite(3,LOW); 
    }
    else{
        digitalWrite(4,HIGH);
        tone(2,500,1000);
        delay(1000);
        noTone(2);
        digitalWrite(4,LOW);
    }
    delay(1000);
    digitalWrite(3,HIGH);
    digitalWrite(4,HIGH);
    digitalWrite(5,HIGH);
    digitalWrite(6,HIGH);
    digitalWrite(7,HIGH);
    digitalWrite(8,HIGH);
    delay(1000);
}
