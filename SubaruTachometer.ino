void setup() {
  pinMode(3, OUTPUT);
  pinMode(2, OUTPUT);
  digitalWrite(3, HIGH);
  digitalWrite(2, HIGH);
  delay(500);
  obrotyUP(350); // 200 = prawie 1000 rpm 450 = 3000 rpm
}

void loop() {
}

void obrotyUP(int ile){
  int i;
    for (i = 0; i < ile; i++){
        digitalWrite(3, LOW); //1
        digitalWrite(2, HIGH); //0
        delay(5);
        digitalWrite(3, LOW); //1
        digitalWrite(2, LOW); //1
        delay(5);
        digitalWrite(3, HIGH); //0
        digitalWrite(2, LOW); //1
        delay(5);
        digitalWrite(3, HIGH); //0
        digitalWrite(2, HIGH); //0
        delay(5);
  }
}

void obrotyDOWN(int ile){
  int i;
    for (i = 0; i < ile; i++){
        digitalWrite(3, HIGH); //0
        digitalWrite(2, LOW); //1
        delay(10);
        digitalWrite(3, LOW); //1
        digitalWrite(2, LOW); //1
        delay(10);
        digitalWrite(3, LOW); //1
        digitalWrite(2, HIGH); //0
        delay(10);
        digitalWrite(3, HIGH); //0
        digitalWrite(2, HIGH); //0
        delay(10);
  }
}
