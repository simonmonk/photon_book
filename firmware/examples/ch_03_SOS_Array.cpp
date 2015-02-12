int durations[] = {200, 200, 200, 600, 600, 600, 200, 200, 200};
int gaps[] =      {200, 200, 600, 200, 200, 600, 200, 200, 600};

void setup() {
    RGB.control(true);
}

void loop() {
    for (int i = 0; i < 9; i++) {
        flash(durations[i], gaps[i]);
    }
    
    delay(2000); // delay before repeat
}

void flash(int duration, int gap) {
    RGB.color(255, 255, 255);
    delay(duration);
    RGB.color(0, 0, 0);
    delay(gap);
}