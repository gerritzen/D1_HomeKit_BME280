# esp8266-homekit-tempsensor
This is a native HomeKit temperature and humidity sensor with D1 mini ESP8266 and BME280 sensor.

## Hardware
The following hardware is required:
```
- D1 mini (ESP8266)
- Temperature and humidity sensor (BME280)
```

Connection:
D1 mini -> DS18B20
```
3V3 -> VCC (red)
GND -> GND (black)
D1 -> SDA (yellow)
D2 -> SCL (green)
```
![alt text](https://github.com/gerritzen/D1_HomeKit_BME280/blob/main/Schema.png?raw=true)

## Development
This sketch is for following development environment
```
Arduino
```

Following libraries are required
```
https://github.com/Mixiaoxiao/Arduino-HomeKit-ESP8266
https://github.com/adafruit/Adafruit_Sensor
https://github.com/adafruit/Adafruit_BME280_Library
```

## Setup
Setup my_accessory.c:
```
.password = "123-55-222". // Homekit Code
```

Setup wifi_info.h
```
const char *ssid = "xxx"; // SETUP Wlan ssid
const char *password = "xxx"; // SETUP Wlan password
```

## Upload to device
Following files needs to be uploaded to the ESP8266 (D1 mini)
```
D1_HomeKit_BME280.ino
my_accessory.c
wifi_info.h
```

## Add device to Homekit
The device can be added to homekit like every other homekit device.
