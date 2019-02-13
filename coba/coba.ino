#include <ESP8266WiFi.h>
const char* ssid="@wifi.indomie";
const char* passwd="11235813";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  WiFi.begin(ssid,passwd);
  while(WiFi.status()!=WL_CONNECTED){
    delay(500);
    Serial.print(".");
    }
    Serial.println(WiFi.localIP());
    delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:
  
}
