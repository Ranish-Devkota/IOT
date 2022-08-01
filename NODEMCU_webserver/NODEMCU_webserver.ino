#include<ESP8266WiFi.h>
#define led D7


WiFiClient client;
WiFiServer server(80); 

 
void setup() {
  // put your setup code here, to run once:
  pinMode(led,OUTPUT);
  
  Serial.begin(9600);
  WiFi.begin("IOEPC Robotics", "robotics123");
//  while (WiFi.status() != WL_CONNECTED)
//  {
//    Serial.println("....");
//    Serial.println("trying to connect");
//    Serial.println("....");
//    delay(500);
//  }
  if( WiFi.status() == WL_CONNECTED)
  Serial.println("wifi_connected");
  Serial.println(WiFi.localIP());
  server.begin();

}

void loop() {
  // put your main code here, to run repeatedly:
//  if(server.available()>=0)
//  {
//    client=server.available();
//    String req = client.readStringUntil('\n');
//    Serial.println(req);
//    req.trim();
//    
//    if(req=="GET /ledon HTTP/1.1")
//    {
//      Serial.println("LED111 on");
//      digitalWrite(led,LOW);
//    }
//    if(req=="GET /ledoff HTTP/1.1")
//    {
//      Serial.println("LED111 off");
//      digitalWrite(led,HIGH);
//    }
//  }

  Serial.println("LED222 on");
  digitalWrite(led,HIGH);
  delay(1000);
  Serial.println("LED222 off");
  digitalWrite(led,LOW);
  delay(1000);
}
