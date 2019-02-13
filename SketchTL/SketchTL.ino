#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>
const char* F_HOST= "smart-traffic-e7625.firebaseio.com";
const char* F_AUTH= "p5dVHb9lWwd7ihvGl2nzHeYcvwRf0VnveZTG6Zxv";
const char* ssid= "UGM_HOTSPOT (copy)";
const char* passwd="amienganteng";

const int T_M =16;
const int T_K =5;
const int T_H =4;
const int U_M =0;
const int U_K =2;
const int U_H =14;
const int B_M =12;
const int B_K =13;
const int B_H =15;
const int S_M =1;
const int S_K =3;
const int S_H =9;

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
  pinMode(T_M,OUTPUT);
  pinMode(T_K,OUTPUT);
  pinMode(T_H,OUTPUT);
  //utara
  pinMode(U_M,OUTPUT);
  pinMode(U_K,OUTPUT);
  pinMode(U_H,OUTPUT);
  //barat
  pinMode(B_M,OUTPUT);
  pinMode(B_K,OUTPUT);
  pinMode(B_H,OUTPUT);
  //selatan
  pinMode(S_M,OUTPUT);
  pinMode(S_K,OUTPUT);
  pinMode(S_H,OUTPUT);
}


void loop() {
 TLstate = Firebase.getBool("/new-tl/-KlKL87oFYPYGnFJeb5F/-Kw0jLYHwFuK_X2VJskD/TLstate");
  Serial.println(TLstate);
  delay(500);
  if(TLstate==false){
    doEmergency();
    }
  else{
    otomatis();
    }

}


  void doEmergency(){
    getLampState();  
    doLampState();
  }
  void getLampState(){
    TlbUlamp = Firebase.getString("/new-tl/-KlKL87oFYPYGnFJeb5F/-Kw0jLYHwFuK_X2VJskD/TLpos/TLb/ulamp");
    TltUlamp = Firebase.getString("/new-tl/-KlKL87oFYPYGnFJeb5F/-Kw0jLYHwFuK_X2VJskD/TLpos/TLt/ulamp");
    TluUlamp = Firebase.getString("/new-tl/-KlKL87oFYPYGnFJeb5F/-Kw0jLYHwFuK_X2VJskD/TLpos/TLu/ulamp");
    TlsUlamp = Firebase.getString("/new-tl/-KlKL87oFYPYGnFJeb5F/-Kw0jLYHwFuK_X2VJskD/TLpos/TLs/ulamp");
    TLplaysound = Firebase.getBool("/new-tl/-KlKL87oFYPYGnFJeb5F/-Kw0jLYHwFuK_X2VJskD/TLplaysound");
    }

    void doLampState(){
      //utara
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
      //timur
         if (TltUlamp == "red") {
             digitalWrite (T_H, 0);
             digitalWrite (T_K, 0); 
             digitalWrite (T_M, 1);
        } else if (TltUlamp == "yellow") {
             digitalWrite (T_H, 0);
             digitalWrite (T_K, 1); 
             digitalWrite (T_M, 0);
        } else {
             digitalWrite (T_H, 1);
             digitalWrite (T_K, 0); 
             digitalWrite (T_M, 0);
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
  digitalWrite(S_K, LOW);
  digitalWrite(T_H, HIGH);
  digitalWrite(U_M, HIGH);
  digitalWrite(B_M, HIGH);
  digitalWrite(S_M, HIGH);
  digitalWrite(T_M, LOW);
  digitalWrite(S_H, LOW);
  delay (5000);
  digitalWrite(T_H, LOW);
  digitalWrite(T_K, HIGH);
  delay (750);
  digitalWrite(T_K, LOW);
  digitalWrite(T_M, HIGH);
  digitalWrite(U_H, HIGH);
  digitalWrite(B_M, HIGH);
  digitalWrite(S_M, HIGH);
  digitalWrite(U_M, LOW);
  digitalWrite(T_H, LOW);
  delay (5000);
  digitalWrite(U_H, LOW);
  digitalWrite(U_K, HIGH);
  delay (750);
  digitalWrite(U_K, LOW);
  digitalWrite(T_M, HIGH);
  digitalWrite(U_M, HIGH);
  digitalWrite(B_H, HIGH);
  digitalWrite(S_M, HIGH);
  digitalWrite(B_M, LOW);
  digitalWrite(U_H, LOW);
  delay (5000);
  digitalWrite(B_H, LOW);
  digitalWrite(B_K, HIGH);
  delay (750);
  digitalWrite(B_K, LOW);
  digitalWrite(T_M, HIGH);
  digitalWrite(U_M, HIGH);
  digitalWrite(B_M, HIGH);
  digitalWrite(S_H, HIGH);
  digitalWrite(S_M, LOW);
  digitalWrite(B_H, LOW);
  delay (5000);
  digitalWrite(S_H, LOW);
  digitalWrite(S_K, HIGH);
  delay (750);
  }
