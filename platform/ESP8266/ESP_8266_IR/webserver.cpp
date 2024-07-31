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

String WebServer::showHTML() {
  String html = "<!DOCTYPE html>\n";
  html += "<html lang=\"pt-BR\">\n";
  html += "  <head>\n";
  html += "    <meta charset=\"UTF-8\" />\n";
  html += "    <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\" />\n";
  html += "    <title>IOT LAB</title>\n";
  html += "    <link rel=\"icon\" href=\"https://softexlabs.com.br/static/images/SOFTLABS.svg\" type =\"image/x-icon\" />\n";
  html += "    <style>\n";
  html += "      * {\n";
  html += "        margin: 0;\n";
  html += "        padding: 0;\n";
  html += "        box-sizing: border-box;\n";
  html += "      }\n";
  html += "      body {\n";
  html += "        font-family: Poppins, sans-serif;\n";
  html += "        background-color: #f9fafd;\n";
  html += "      }\n";
  html += "      header {\n";
  html += "        width: 100%;\n";
  html += "        display: flex;\n";
  html += "        justify-content: center;\n";
  html += "        align-items: center;\n";
  html += "      }\n";
  html += "      img {\n";
  html += "        width: 10rem;\n";
  html += "        height: auto;\n";
  html += "      }\n";
  html += "      h1 {\n";
  html += "        font-size: 2.5rem;\n";
  html += "      }\n";
  html += "      ul {\n";
  html += "        width: 20%;\n";
  html += "        list-style-type: none;\n";
  html += "      }\n";
  html += "      li {\n";
  html += "        width: 100%;\n";
  html += "        margin: 1rem 0;\n";
  html += "        padding: 1rem;\n";
  html += "        background-color: #0170b9;\n";
  html += "        border-radius: 10px;\n";
  html += "        color: #ffffff;\n";
  html += "        font-weight: bold;\n";
  html += "        display: flex;\n";
  html += "        justify-content: center;\n";
  html += "      }\n";
  html += "      a {\n";
  html += "        text-decoration: none;\n";
  html += "        color: #ffffff;\n";
  html += "        font-size: 1rem;\n";
  html += "      }\n";
  html += "      main {\n";
  html += "        width: 100%;\n";
  html += "        min-height: 75vh;\n";
  html += "        display: flex;\n";
  html += "        justify-content: center;\n";
  html += "        align-items: center;\n";
  html += "      }\n";
  html += "      footer {\n";
  html += "        width: 100%;\n";
  html += "        display: flex;\n";
  html += "        flex-direction: column;\n";
  html += "        justify-content: center;\n";
  html += "        align-items: center;\n";
  html += "        gap: 1rem;\n";
  html += "      }\n";
  html += "      .footer-img {\n";
  html += "        width: 10rem;\n";
  html += "        padding: 0 2rem;\n";
  html += "      }\n";
  html += "      span {\n";
  html += "        font-size: .8rem;\n";
  html += "      }\n";
  html += "      @media (max-width: 768px) {\n";
  html += "        ul {\n";
  html += "          width: 80%;\n";
  html += "        }\n";
  html += "        header {\n";
  html += "          flex-direction: column;\n";
  html += "          justify-content: center;\n";
  html += "          align-items: center;\n";
  html += "        }\n";
  html += "        h1 {\n";
  html += "         font-size: 1rem;\n";
  html += "         margin-top: 1rem;\n";
  html += "        }\n";
  html += "        .footer-img {\n";
  html += "          width: 6rem;\n";
  html += "        }\n";
  html += "        span {\n";
  html += "          font-size: .3rem;\n";
  html += "        }\n";
  html += "      }\n";
  html += "    </style>\n";
  html += "    <script>\n";
  html += "    </script>\n";
  html += "  </head>\n";
  html += "  <body>\n";
  html += "    <header>\n";
  html += "      <img src=\"https://softexlabs.com.br/static/images/SOFTLABS.svg\" alt=\"Logo SOFTEX Labs\" />\n";
  html += "      <h1>IOT LAB</h1>\n";
  html += "    </header>\n";
  html += "    <main>\n";
  html += "      <ul>\n";
  html += "        <li><a href=\"/on\">LIGAR</a></li>\n";
  html += "        <li><a href=\"/off\">DESLIGAR</a></li>\n";
  html += "      </ul>\n";
  html += "    </main>\n";
  html += "    <footer>\n";
  html += "      <div>\n";
  html += "        <img class=\"footer-img\" src=\"https://softexlabs.com.br/static/images/softexPE.svg\" alt=\"Logo SOFTEX\" />\n";
  html += "      </div>\n";
  html += "      <span>&copy; 2024 IOT LAB. Todos os direitos reservados.</span>\n";
  html += "    </footer>\n";
  html += "  </body>\n";
  html += "</html>\n";

  return html;
}

void WebServer::handleRoot() {
  server.send(200, "text/html", showHTML());
}

void WebServer::handleOn() {
  Serial.println("LIGANDO AR CONDICIONADO...");
  irsend.sendCOOLIX(powerOn);
  server.send(200, "text/html", showHTML());
}

void WebServer::handleOff() {
  Serial.println("DESLIGANDO AR CONDICIONADO...");
  irsend.sendCOOLIX(powerOff);
  server.send(200, "text/html", showHTML());
}
