#include <Arduino.h>
#include <arduino_homekit_server.h>    // https://github.com/Mixiaoxiao/Arduino-HomeKit-ESP8266
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

#include "wifi_info.h"

#define LOG_D(fmt, ...)   printf_P(PSTR(fmt "\n") , ##__VA_ARGS__);

Adafruit_BME280 bme;

void setup() {
  Wire.pins(D1, D2); //new SDA SCL pins
  Serial.begin(115200);
  unsigned status = bme.begin(0x76, &Wire);
  if (!status) {
    Serial.println("Could not find BME280 sensor!");
    for(;;) delay(100);
  }

  wifi_connect(); // in wifi_info.h
  
  // homekit_storage_reset(); // to remove the previous HomeKit pairing storage when you first run this new HomeKit example
  
  my_homekit_setup();
}

void loop() {
  my_homekit_loop();
  delay(10);
}

//==============================
// Homekit setup and loop
//==============================

// access your homekit characteristics defined in my_accessory.c
extern "C" homekit_server_config_t config;
extern "C" homekit_characteristic_t cha_current_temperature;
extern "C" homekit_characteristic_t cha_humidity;

static uint32_t next_heap_millis = 0;
static uint32_t next_report_millis = 0;

void my_homekit_setup() {
  arduino_homekit_setup(&config);
}

void my_homekit_loop() {
  arduino_homekit_loop();
  const uint32_t t = millis();
  if (t > next_report_millis) {
    // report sensor values every 60 seconds
    next_report_millis = t + 60 * 1000;
    my_homekit_report();
  }
  if (t > next_heap_millis) {
    // show heap info every 5 seconds
    next_heap_millis = t + 5 * 1000;
    LOG_D("Free heap: %d, HomeKit clients: %d",
        ESP.getFreeHeap(), arduino_homekit_connected_clients_count());

  }
}

void my_homekit_report() {
  // Get Temperature
  float temperature_value = bme.readTemperature();
  float humidity_value = bme.readHumidity();

  cha_current_temperature.value.float_value = temperature_value;
  cha_humidity.value.float_value = humidity_value;
  LOG_D("Current temperature: %.1f", temperature_value);
  LOG_D("Current humidity: %.1f\%", humidity_value);
  homekit_characteristic_notify(&cha_current_temperature, cha_current_temperature.value);
  homekit_characteristic_notify(&cha_humidity, cha_humidity.value);
}

