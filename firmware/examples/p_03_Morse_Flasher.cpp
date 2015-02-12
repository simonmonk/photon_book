String message = "My Photon speaks Morse";

int dot = 200;
int dash = dot * 3;

String letters[] = {
  ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..",    // A-I
  ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.",  // J-R
  "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."          // S-Z
};

void setup() {
    RGB.control(true);
}

void loop() {
    flashMessage(message);
    delay(5000); // delay before repeat
}

void flashMessage(String message) {
    for (int i = 0; i < message.length(); i++) {
        char letter = message.charAt(i);
        flashLetter(letter);
    }
}

void flashLetter(char letter)
{
    if (letter >= 'a' && letter <= 'z') {
        flashDotsAndDashes(letters[letter - 'a']);
    }
    else if (letter >= 'A' && letter <= 'Z') {
        flashDotsAndDashes(letters[letter - 'A']);
    }
    else if (letter == ' ') {
        delay(dot * 7); // gap between words
    }
}

void flashDotsAndDashes(String dotsAndDashes) {
    for (int i = 0; i < dotsAndDashes.length(); i++) {
        char dotOrDash = dotsAndDashes.charAt(i);
        if (dotOrDash == '.') {
            flash(dot);
        }
        else {
            flash(dash);
        }
        delay(dot); // gap between dots and dashes of a letter
    }
    delay(dash - dot); // gap between letters of a word
}

void flash(int duration) {
    RGB.color(255, 255, 255);
    delay(duration);
    RGB.color(0, 0, 0);
}
