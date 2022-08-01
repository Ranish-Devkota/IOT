#include<ESP8266WiFi.h>
void setup() {
  pinMode(D4,OUTPUT);
  
  // put your setup code here, to run once:
  Serial.begin(9600);
  WiFi.begin("internet access","CLB39EF9AD");
  while(WiFi.status() != WL_CONNECTED)
  {
    Serial.println("...");
    Serial.print("trying to connect");
    Serial.println("...");
    delay(500);
  }
 if(WiFi.status() == WL_CONNECTED)
 Serial.println("wifi_connected"); 
Serial.println(WiFi.localIP());
}

int i=100;
void loop() {
  // put your main code here, to run repeatedly:
  
  Serial.println(i);
  digitalWrite(D4,HIGH);
  delay(i);
  digitalWrite(D4,LOW);
  delay(i+100);
  i=i+10;
}
