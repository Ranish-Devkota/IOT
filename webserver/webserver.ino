#include<ESP8266WiFi.h>
#include<ESP8266WebServer>
#define led D4


WiFiClient client;
WebServer server(80); 

 
void setup() {
  // put your setup code here, to run once:
  pinMode(led,OUTPUT);
  
  Serial.begin(9600);
  WiFi.begin("IOEPC Robotics", "robotics123");
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.println("....");
    Serial.println("trying to connect");
    Serial.println("....");
    delay(500);
  }
  if( WiFi.status() == WL_CONNECTED)
  Serial.println("wifi_connected");
  Serial.println(WiFi.localIP());
  server.begin();

}

void loop() {
  // put your main code here, to run repeatedly:
  if(server.available()>=0)
  {
    client=server.available();
    String req = client.readStringUntil('\n');
    Serial.println(req);
    req.trim();
    
    if(req=="GET /ledon HTTP/1.1")
    {
      Serial.println("LED111 on");
      digitalWrite(led,HIGH);
    }
    if(req=="GET /ledoff HTTP/1.1")
    {
      Serial.println("LED111 off");
      digitalWrite(led,LOW);
    }

    
//    if(req=="GET /led2on HTTP/1.1")
//    {
//      Serial.println("LED222 on");
//      digitalWrite(led2,HIGH);
//    }
//    if(req=="GET /led2off HTTP/1.1")
//    {
//      Serial.println("LED222 off");
//      digitalWrite(led2,LOW);
//    }
  }
}
