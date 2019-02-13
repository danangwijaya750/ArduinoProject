const int T_M =16;
const int T_K =5;
const int T_H =4;

void setup() {
  // put your setup code here, to run once:
//timur
  pinMode(T_M,OUTPUT);
  pinMode(T_K,OUTPUT);
  pinMode(T_H,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:digitalWrite(S_K, LOW);
  digitalWrite(T_H, HIGH);
  digitalWrite(T_M, LOW);
  delay (5000);
  digitalWrite(T_H, LOW);
  digitalWrite(T_K, HIGH);
  delay (750);
  digitalWrite(T_K, LOW);
  digitalWrite(T_M, HIGH);
  digitalWrite(T_H, LOW);
  delay (5000);
  delay (750);
  digitalWrite(T_M, HIGH);
  delay (5000);
  delay (750);
  digitalWrite(T_M, HIGH);
  delay (5000);
  delay (750);
}
