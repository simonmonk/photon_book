void setup() {
    RGB.control(true);
}

void loop() {
    RGB.color(255, 0, 0);
    delay(2000);
    RGB.color(0, 255, 0);
    delay(2000);
    RGB.color(0, 0, 255);
    delay(2000);
}