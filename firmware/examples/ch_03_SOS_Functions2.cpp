void setup() {
    RGB.control(true);
}

void loop() {
    flashS();
    flashO();
    flashS();
    
    delay(2000); // delay before repeat
}

void flash(int duration, int gap) {
    RGB.color(255, 255, 255);
    delay(duration);
    RGB.color(0, 0, 0);
    delay(gap);
}

void flashS() {
    flash(200, 200);
    flash(200, 200);
    flash(200, 600);
}

void flashO() {
    flash(600, 200);
    flash(600, 200);
    flash(600, 600);
}