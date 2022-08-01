#include<ESP8266WiFi.h>
#define led D4

WiFiClient client;
WiFiServer server(80); 

 
void setup() {
  // put your setup code here, to run once:
  pinMode(led,OUTPUT);
  Serial.begin(9600);
  WiFi.softAP("NODEMCU","123456789");
  Serial.println("wifi started");
  Serial.println(WiFi.softAPIP());
//  Serial.println(WiFi.monitor());
  server.begin();

}

void loop() {
  // put your main code here, to run repeatedly:
client = server.available();
if(client ==1)
{
  String req = client.readStringUntil('\n');
  Serial.println(req);
  req.trim();
  if(req=="GET /ledon HTTP/1.1")
  {
    digitalWrite(led,LOW);
  }
  if(req=="GET /ledoff HTTP/1.1")
  {
    digitalWrite(led,HIGH);
  }


}
}
