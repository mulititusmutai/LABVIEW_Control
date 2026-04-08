#include <ArduinoJson.h>

// Define your Relay Pins (Update these to your actual ESP32 GPIOs)
const int relay1 = 16;
const int relay2 = 17;
const int relay3 = 18;
const int relay4 = 19;
const int relay5 = 21;


void setup() {
  Serial.begin(115200);
  
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  pinMode(relay3, OUTPUT);
  pinMode(relay4, OUTPUT);
  pinMode(relay5, OUTPUT);
  
  Serial.println("ESP32 Ready for JSON...");
}

void loop() {
  if (Serial.available() > 0) {
    // 1. Read the JSON string sent from LabVIEW
    String input = Serial.readStringUntil('\n');

    // 2. Create a dynamic document (V7 Magic - No size needed!)
    JsonDocument doc;

    // 3. Deserialize (Parse) the string
    DeserializationError error = deserializeJson(doc, input);

    // 4. If the JSON is valid, update the relays
    if (!error) {
      // Access keys directly by the names you gave them in LabVIEW
      digitalWrite(relay1, doc["SV1"].as<int>());
      digitalWrite(relay2, doc["SV2"].as<int>());
      digitalWrite(relay3, doc["SV3"].as<int>());
      digitalWrite(relay4, doc["SV4"].as<int>());
      digitalWrite(relay5, doc["SV5"].as<int>());

      // Send a confirmation back to the LabVIEW "Confirmation" indicator
      Serial.println("RECEIVED");
    } else {
      Serial.println("ERROR");
    }
  }
}