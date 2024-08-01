#include "webserver.h"

const uint16_t kIrLed = 4;  // ESP8266 GPIO pin to use. Recommended: 4 (D2).

IRsend irsend(kIrLed);  // Set the GPIO to be used to sending the message.


WebServer::WebServer(const int port, const uint64_t acCommandOn, const uint64_t acCommandOff)
  : server(port), powerOn(acCommandOn), powerOff(acCommandOff) {
  irsend.begin();
}

void WebServer::begin() {
  server.on("/", HTTP_GET, std::bind(&WebServer::handleRoot, this));
  server.on("/on", HTTP_GET, std::bind(&WebServer::handleOn, this));
  server.on("/off", HTTP_GET, std::bind(&WebServer::handleOff, this));
  server.onNotFound(std::bind(&WebServer::handleRoot, this));
  server.begin();
}

void WebServer::handleClient() {
  server.handleClient();
}

void WebServer::handleRoot() {
  server.send(200, "text/html", index_html);
}

void WebServer::handleOn() {
  Serial.println("LIGANDO AR CONDICIONADO...");
  irsend.sendCOOLIX(powerOn);
  server.send(200, "text/html", index_html);
}

void WebServer::handleOff() {
  Serial.println("DESLIGANDO AR CONDICIONADO...");
  irsend.sendCOOLIX(powerOff);
  server.send(200, "text/html", index_html);
}
