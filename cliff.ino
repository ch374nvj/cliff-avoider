#define IR1 2
#define IR2 15
#define EN1 13
#define EN2 12
#define IN1 5
#define IN2 18
#define IN3 19
#define IN4 21
#define SPEED 72

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  pinMode(IR1, INPUT);
  pinMode(IR2, INPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  ledcSetup(0, 1000, 8);

  ledcAttachPin(EN1, 0);
  ledcAttachPin(EN2, 1);

  delay(3000);
}

void forward() {
  ledcWrite(0, SPEED);
  ledcWrite(1, SPEED+5);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void stop() {
  ledcWrite(0, SPEED+5);
  ledcWrite(1, SPEED+2);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  delay(500);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  delay(400);
}


void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(IR1) == HIGH || digitalRead(IR2) == HIGH) {
    Serial.println("STOP");
    stop();
  }
  else {
    Serial.println("Fwd");
    forward();
  }
}
