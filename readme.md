# AIR Remote Control

## Informações Importantes

- Para o ESP8266 que está recebendo o sinal do controle conectar o pino de sinal ao GPIO14 (D5 para nodemcu)
- Para o ESP8266 que está transmitindo o sinal do controle conectar o pino positivo do led ir ao GPIO4 (D2 para nodemcu)

## Pré requisitos

- Ter a IDE do [Arduino](https://www.arduino.cc/en/software) instalada na máquina
- Adicionar a url `https://arduino.esp8266.com/stable/package_esp8266com_index.json` ao gerenciador de placas da sua IDE
- Instalar a biblioteca [IRremoteESP8266](https://www.arduino.cc/reference/en/libraries/irremoteesp8266/) na IDE
