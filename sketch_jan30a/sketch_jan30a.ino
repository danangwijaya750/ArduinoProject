#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>
const char* F_HOST= "smart-traffic-e7625.firebaseio.com";
const char* F_AUTH= "p5dVHb9lWwd7ihvGl2nzHeYcvwRf0VnveZTG6Zxv";
const char* ssid= "coba";
const char* passwd="testes123";

const int U_M =16;
const int U_K =5;
const int U_H =4;
const int B_M =0;
const int B_K =2;
const int B_H =14;
const int S_M =12;
const int S_K =13;
const int S_H =15;

int n = 0;
bool TLstate=false;
bool TLplaysound;
String TLsound;
String TlbUlamp = "", TluUlamp = "", TltUlamp = "", TlsUlamp = "";



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  WiFi.begin(ssid,passwd);
  while(WiFi.status()!=WL_CONNECTED){
    delay(500);
    Serial.print(".");
    }
    Serial.println(WiFi.localIP());
    Firebase.begin(F_HOST,F_AUTH);
    delay(1000);
  
  //timur
  pinMode(U_M,OUTPUT);
  pinMode(U_K,OUTPUT);
  pinMode(U_H,OUTPUT);
  //barat
  pinMode(B_M,OUTPUT);
  pinMode(B_K,OUTPUT);
  pinMode(B_H,OUTPUT);
  //utara
  pinMode(S_M,OUTPUT);
  pinMode(S_K,OUTPUT);
  pinMode(S_H,OUTPUT);


  digitalWrite(U_M,LOW);
  digitalWrite(U_K,LOW);
  digitalWrite(U_H,LOW);

  digitalWrite(B_M,LOW);
  digitalWrite(B_K,LOW);
  digitalWrite(B_H,LOW);
  //utara
  digitalWrite(S_M,LOW);
  digitalWrite(S_K,LOW);
  digitalWrite(S_H,LOW);

}

void loop() {
  // put your main code here, to run repeatedly:
   TLstate = Firebase.getBool("/new-tl/-KlKL87oFYPYGnFJeb5F/-Kw0jLYHwFuK_X2VJskD/TLstate");
  Serial.println(TLstate);
  delay(500);
  if(!TLstate){
    Serial.print("false");
    doEmergency();
    }
  else{
     otomatis();
    }
 

}

 void getLampState(){
    TlbUlamp = Firebase.getString("/new-tl/-KlKL87oFYPYGnFJeb5F/-Kw0jLYHwFuK_X2VJskD/TLpos/TLb/ulamp");
    TluUlamp = Firebase.getString("/new-tl/-KlKL87oFYPYGnFJeb5F/-Kw0jLYHwFuK_X2VJskD/TLpos/TLu/ulamp");
    TlsUlamp = Firebase.getString("/new-tl/-KlKL87oFYPYGnFJeb5F/-Kw0jLYHwFuK_X2VJskD/TLpos/TLs/ulamp");
    TLplaysound = Firebase.getBool("/new-tl/-KlKL87oFYPYGnFJeb5F/-Kw0jLYHwFuK_X2VJskD/TLplaysound");
    }
    void doLampState(){
      //barat
        if (TlbUlamp == "red") {
            digitalWrite (B_H, 0);
            digitalWrite (B_K, 0); 
            digitalWrite (B_M, 1);
        } else if (TlbUlamp == "yellow") {
            digitalWrite (B_H, 0);
            digitalWrite (B_K, 1); 
            digitalWrite (B_M, 0);
        } else {
            digitalWrite (B_H, 1);
            digitalWrite (B_K, 0); 
            digitalWrite (B_M, 0);
        }
      //utara
         if (TluUlamp == "red") {
          digitalWrite (U_H, 0);
          digitalWrite (U_K, 0); 
          digitalWrite (U_M, 1);
        } else if (TluUlamp == "yellow") {
          digitalWrite (U_H, 0);
          digitalWrite (U_K, 1); 
          digitalWrite (U_M, 0);
        } else {
          digitalWrite (U_H, 1);
          digitalWrite (U_K, 0); 
          digitalWrite (U_M, 0);
        }
      //selatan
         if (TlsUlamp == "red") {
          digitalWrite (S_H, 0);
          digitalWrite (S_K, 0); 
          digitalWrite (S_M, 1);
        } else if (TlsUlamp == "yellow") {
          digitalWrite (S_H, 0);
          digitalWrite (S_K, 1); 
          digitalWrite (S_M, 0);
        } else {
          digitalWrite (S_H, 1);
          digitalWrite (S_K, 0); 
          digitalWrite (S_M, 0);
        }
        
      }

void otomatis(){
    UtaraHijau();
  delay(2000);
  BaratHijau();
  delay(2000);
  SelatanHijau();
  delay(2000);
  }

void doEmergency(){

  getLampState();
  doLampState();
  
  }

void UtaraHijau(){
     digitalWrite(S_H,LOW);
    setAllRed();
    delay(1000);
    digitalWrite(U_K,HIGH);
    delay(500);
    digitalWrite(U_K,LOW);
    digitalWrite(B_M,HIGH);
    digitalWrite(S_M,HIGH);
    delay(500);
    digitalWrite(U_H,HIGH);

    digitalWrite(U_M,LOW);
    digitalWrite(B_K,LOW);
    digitalWrite(B_H,LOW);      
    digitalWrite(S_K,LOW);
    digitalWrite(S_H,LOW);
  }

void BaratHijau(){
    digitalWrite(U_H,LOW);  
    setAllRed();
    delay(1000);
    digitalWrite(B_K,HIGH);
    delay(500);
    digitalWrite(B_K,LOW);
    digitalWrite(U_M,HIGH);
    digitalWrite(S_M,HIGH);
    delay(500);
    digitalWrite(B_H,HIGH);
 

    digitalWrite(B_M,LOW);
    digitalWrite(U_K,LOW);
    digitalWrite(U_H,LOW);      
    digitalWrite(S_K,LOW);
    digitalWrite(S_H,LOW);   
  }

  void SelatanHijau(){
    digitalWrite(B_H,LOW);
    setAllRed();
    delay(1000);
    digitalWrite(S_K,HIGH);
    delay(500);
    digitalWrite(S_K,LOW);
    digitalWrite(U_M,HIGH);
    digitalWrite(B_M,HIGH);
    delay(500);
    digitalWrite(S_H,HIGH);

    digitalWrite(S_M,LOW);
    digitalWrite(U_K,LOW);
    digitalWrite(U_H,LOW);      
    digitalWrite(B_K,LOW);
    digitalWrite(B_H,LOW);   
    }

    void setAllRed(){
      digitalWrite(U_M,HIGH);
      digitalWrite(B_M,HIGH);
      digitalWrite(S_M,HIGH);
      }
