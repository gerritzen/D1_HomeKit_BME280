# D1\_HomeKit\_BME280
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

![Connection](/drawing.png)

## Development
This sketch is for following development environment

```
Arduino
```

The following libraries are required

```
https://github.com/Mixiaoxiao/Arduino-HomeKit-ESP8266
https://github.com/adafruit/Adafruit_Sensor
https://github.com/adafruit/Adafruit_BME280_Library
```

## Setup
Setup `my_accessory.c`:

```
.password = "123-55-222". // Homekit Code
```

Setup `wifi_info.h`:

```
const char *ssid = "xxx"; // SETUP Wlan ssid
const char *password = "xxx"; // SETUP Wlan password
```

## Upload to device
The following files need to be uploaded to the ESP8266 (D1 mini)

```
D1_HomeKit_BME280.ino
my_accessory.c
wifi_info.h
```

Use these settings:

| Name               | Setting                                 |
|--------------------|-----------------------------------------|
| Board              | "LOLIN(WEMOS) D1 mini (clone)"          |
| Upload Speed:      | "921600"                                |
| CPU Frequency:     | "80 MHz"                                |
| Flash Size:        | "4MB(FS:2MB OTA:~1019KB)"               |
| Flash Mode:        | "DOUT (compatible)"                     |
| Flash Frequency:   | "40MHz"                                 |
| Debug port:        | "Disabled"                              |
| Debug Level:       | "None"                                  |
| lwIP Variant:      | "v2 Lower Memory"                       |
| VTables:           | "Flash"                                 |
| C++ Exceptions:    | "Disabled (new aborts on oom)           |
| Stack Protection:  | "Disabled"                              |
| Erase Flash:       | "Only Sketch"                           |
| SSL Support:       | "All SSL ciphers (most compatible)"     |
| MMU:               | "32KB cache + 32KB IRAM (balanced)"     |
| Non-32-Bit Access: | "Use pgm\_read macros for IRAM/PROGMEM" |
| Port:              | "/dev/USB0"                             |


## Add device to Homekit
The device can be added to homekit like every other homekit device.
