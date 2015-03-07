void setup() {
    Serial.begin(9600);
}

void loop() {
    if (Serial.available()) {
        char ch = Serial.read();
        if (ch == '?') {
            Serial.print("Hello millis()=");
            Serial.println(millis());
        }
    }
}