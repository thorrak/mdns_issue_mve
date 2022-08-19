#include <Arduino.h>
#include <WiFi.h>
#include <ESPmDNS.h>

#include "secret.h"
const char *ssid = WIFI_SSID;      // Defined in secret.h
const char *password = WIFI_PASS;  // Defined in secret.h

void setup()
{
  Serial.begin(115200);
  Serial.println();
  Serial.flush();
  Serial.println("Starting test");

  WiFi.disconnect();
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.print("Establishing connection to WiFi..");
  while (WiFi.status() != WL_CONNECTED)
  {
      delay(1000);
      Serial.print(F("."));
  }

  // This next line is the one that seems to be required for mDNS to work, but means
  // that WiFi and Bluetooth coexistence are not possible 
  WiFi.setSleep(false);

  Serial.println();
  Serial.print("Connected, IP address: ");
  Serial.println(WiFi.localIP().toString());

  if (!MDNS.begin("testhost")) {
    Serial.println("Error setting up MDNS responder.");
  } else {
      MDNS.addService("_testservice", "_tcp", 80);
  }
  Serial.println("mDNS Initialized");
}

void loop()
{
  delay(200);
}