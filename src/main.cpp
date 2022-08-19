#include <Arduino.h>
#include <WiFi.h>
#include <ESPmDNS.h>

#include "secret.h"
const char *ssid = WIFI_SSID;      // Defined in secret.h
const char *password = WIFI_PASS;  // Defined in secret.h

void setup()
{
  WiFi.disconnect();
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
      delay(1000);

  // This next line is the one that seems to be required for mDNS to work, but means
  // that WiFi and Bluetooth coexistence are not possible 
  // WiFi.setSleep(false);

  MDNS.begin("testhost");
  MDNS.addService("_testservice", "_tcp", 80);
}

void loop() {delay(200);}
