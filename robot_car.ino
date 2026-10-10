#include <WiFi.h>
#include <WebServer.h>
const char* ssid = "Keerthi";
const char* password = "Keerthiii";
const int IN1 = 26;
const int IN2 = 27;
const int IN3 = 14;
const int IN4 = 12;
WebServer server(80);
void stopCar() {
  digitalWrite(IN1, LOW);  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);  digitalWrite(IN4, LOW);
}
void forward() {
  digitalWrite(IN1, HIGH); digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH); digitalWrite(IN4, LOW);
}
void backward() {
  digitalWrite(IN1, LOW);  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);  digitalWrite(IN4, HIGH);
}
void left() {
  digitalWrite(IN1, LOW);  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH); digitalWrite(IN4, LOW);
}
void right() {
  digitalWrite(IN1, HIGH); digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);  digitalWrite(IN4, HIGH);
}
void handleRoot() {
  String page = "<html><body style='text-align:center;font-family:sans-serif'>";
  page += "<h2>ESP32 Robot Car</h2>";
  page += "<p><a href='/forward'><button style='width:140px;height:60px'>Forward</button></a></p>";
  page += "<p><a href='/left'><button style='width:100px;height:60px'>Left</button></a> ";
  page += "<a href='/stop'><button style='width:100px;height:60px'>Stop</button></a> ";
  page += "<a href='/right'><button style='width:100px;height:60px'>Right</button></a></p>";
  page += "<p><a href='/backward'><button style='width:140px;height:60px'>Back</button></a></p>";
  page += "</body></html>";
  server.send(200, "text/html", page);
}
void setup() {
  Serial.begin(115200);
  pinMode(IN1, OUTPUT); pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT); pinMode(IN4, OUTPUT);
  stopCar();
  WiFi.begin(ssid, password);
  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println();
  Serial.print("Open this IP in your browser: ");
  Serial.println(WiFi.localIP());
  server.on("/", handleRoot);
  server.on("/forward",  []() { forward();  handleRoot(); });
  server.on("/backward", []() { backward(); handleRoot(); });
  server.on("/left",     []() { left();     handleRoot(); });
  server.on("/right",    []() { right();    handleRoot(); });
  server.on("/stop",     []() { stopCar();  handleRoot(); });
  server.begin();
}
void loop() {
  server.handleClient();
}