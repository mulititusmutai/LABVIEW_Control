// Define your pins in an array for easy scaling
const int relayPins[] = {32, 33, 25, 26}; // Add as many as you need
const int numRelays = sizeof(relayPins) / sizeof(relayPins[0]);

void setup() {
  Serial.begin(115200);
  analogReadResolution(12); 
  for(int i = 0; i < numRelays; i++) {
    pinMode(relayPins[i], OUTPUT);
    digitalWrite(relayPins[i], HIGH); // Default OFF for most modules
  }
}

void loop() {
  if (Serial.available() > 0) {
    String packet = Serial.readStringUntil('\n');
    
    // i += 2 skips the comma at indices 1, 3, and 5
    for (int i = 0; i < packet.length(); i += 2) {
        int relayIndex = i / 2; // Converts 0,2,4,6 back to 0,1,2,3
        if (relayIndex < 4) {
            digitalWrite(relayPins[relayIndex], (packet[i] == '1') ? LOW : HIGH);
        }
    }
    Serial.println(packet);
}
}