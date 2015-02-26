int relayPin = D0;

void setup() {
    pinMode(relayPin, OUTPUT);
    Spark.subscribe("toohot", soundAlarm);
    Spark.subscribe("tempnormal", cancelAlarm);
}

void loop() {
}

void soundAlarm(const char *event, const char *data) {
    digitalWrite(relayPin, HIGH);
}

void cancelAlarm(const char *event, const char *data) {
    digitalWrite(relayPin, LOW);
}