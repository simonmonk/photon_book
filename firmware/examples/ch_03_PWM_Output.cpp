int ledPin = A5;
int switchPin = D3;

int brightness = 0;

void setup() {
    pinMode(A5, OUTPUT);
    pinMode(switchPin, INPUT_PULLUP);
}

void loop() {
    if (digitalRead(switchPin) == LOW) {
        brightness += 25;
        if (brightness > 255) {
            brightness = 0;
        }
        analogWrite(ledPin, brightness);
        delay(200);
    }
}