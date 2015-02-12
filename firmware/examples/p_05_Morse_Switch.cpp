String message = "sos sos sos sos sos";

int ledPin = D7;
int switchPin = D3;

int dot = 100;
int dash = dot * 3;

String letters[] = {
  ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..",    // A-I
  ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.",  // J-R
  "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."          // S-Z
};

void setup() {
    pinMode(ledPin, OUTPUT);
    pinMode(switchPin, INPUT_PULLUP);
}

void loop() {
    if (digitalRead(switchPin) == LOW) {
        flashMessage(message);
    }
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
    digitalWrite(ledPin, HIGH);
    delay(duration);
    digitalWrite(ledPin, LOW);
}
