void setup() {
    RGB.control(true);
}

void loop() {
    // flash S
    // dot
    RGB.color(255, 255, 255);
    delay(200);
    RGB.color(0, 0, 0);
    delay(200);
    // dot
    RGB.color(255, 255, 255);
    delay(200);
    RGB.color(0, 0, 0);
    delay(200);
    // dot
    RGB.color(255, 255, 255);
    delay(200);
    RGB.color(0, 0, 0);
    delay(600);
    // end of S
    // flash O
    // dash
    RGB.color(255, 255, 255);
    delay(600);
    RGB.color(0, 0, 0);
    delay(200);
    // dash
    RGB.color(255, 255, 255);
    delay(600);
    RGB.color(0, 0, 0);
    delay(200);
    // dash
    RGB.color(255, 255, 255);
    delay(600);
    RGB.color(0, 0, 0);
    delay(600);
    // end of O
    // flash S
    // dot
    RGB.color(255, 255, 255);
    delay(200);
    RGB.color(0, 0, 0);
    delay(200);
    // dot
    RGB.color(255, 255, 255);
    delay(200);
    RGB.color(0, 0, 0);
    delay(200);
    // dot
    RGB.color(255, 255, 255);
    delay(200);
    RGB.color(0, 0, 0);
    delay(600);
    // end of S
    
    delay(2000); // delay before repeat
}