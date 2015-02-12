void setup() {
    RGB.control(true);
}

void loop() {
    RGB.color(255, 255, 255);
    delay(500);
    RGB.color(0, 0, 0);
    delay(500);
}