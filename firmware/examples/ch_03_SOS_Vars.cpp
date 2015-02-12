int dot = 100;
int dash = dot * 3;

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
    flash(dot, dot);
    flash(dot, dot);
    flash(dot, dash);
}

void flashO() {
    flash(dash, dot);
    flash(dash, dot);
    flash(dash, dash);
}