#include <WiFi.h>
#include <WebServer.h>
#include <ESP32Servo.h>

// بيانات شبكة الـ ESP32
const char* ssid = "ESP32-Servo";
const char* password = "12345678";

// منافذ التوصيل
const int SERVO_PIN = 27;
const int YELLOW_LED_PIN = 26;
const int RED_LED_PIN = 25;

Servo myServo;
WebServer server(80);

String getHTMLPage() {
  String html = R"rawliteral(
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<meta name="viewport" content="width=device-width, initial-scale=1">
<title>ESP32 Servo Control</title>
<style>
body{
font-family:Arial;
text-align:center;
background:#f2f2f2;
margin-top:60px;
}
button{
width:220px;
height:70px;
font-size:24px;
margin:15px;
border:none;
border-radius:12px;
color:white;
cursor:pointer;
}
.open{
background:#28a745;
}
.close{
background:#dc3545;
}
</style>
</head>
<body>

<h1>ESP32 Servo Control</h1>

<form action="/open">
<button class="open">Open</button>
</form>

<form action="/close">
<button class="close">Close</button>
</form>

</body>
</html>
)rawliteral";

  return html;
}

void handleRoot() {
  server.send(200, "text/html", getHTMLPage());
}

void handleOpen() {
  myServo.write(90);

  digitalWrite(YELLOW_LED_PIN, HIGH);
  digitalWrite(RED_LED_PIN, LOW);

  server.send(200, "text/html", getHTMLPage());
}

void handleClose() {
  myServo.write(0);

  digitalWrite(YELLOW_LED_PIN, LOW);
  digitalWrite(RED_LED_PIN, HIGH);

  server.send(200, "text/html", getHTMLPage());
}

void setup() {

  Serial.begin(115200);

  pinMode(YELLOW_LED_PIN, OUTPUT);
  pinMode(RED_LED_PIN, OUTPUT);

  myServo.attach(SERVO_PIN);
  myServo.write(0);

  digitalWrite(RED_LED_PIN, HIGH);
  digitalWrite(YELLOW_LED_PIN, LOW);

  // إنشاء شبكة WiFi
  WiFi.softAP(ssid, password);

  Serial.println();
  Serial.println("WiFi Access Point Started");
  Serial.print("SSID: ");
  Serial.println(ssid);

  Serial.print("IP Address: ");
  Serial.println(WiFi.softAPIP());

  server.on("/", handleRoot);
  server.on("/open", handleOpen);
  server.on("/close", handleClose);

  server.begin();
}

void loop() {
  server.handleClient();
}