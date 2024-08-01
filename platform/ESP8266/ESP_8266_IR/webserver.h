#ifndef WEBSERVER_H
#define WEBSERVER_H

#include <ESP8266WebServer.h>
#include <IRremoteESP8266.h>
#include <IRsend.h>
#include "index_html.h"

class WebServer
{
public:
    WebServer(const int port, const uint64_t acCommandOn, const uint64_t acCommandOff);
    void begin();
    void handleClient();

private:
    ESP8266WebServer server;
    void handleRoot();
    void handleOn();
    void handleOff();
    uint64_t powerOn;
    uint64_t powerOff;
};

#endif
