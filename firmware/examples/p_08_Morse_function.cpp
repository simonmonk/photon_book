String message = "";

int ledPin = D7;
int buzzerPin = D1;
int dot = 100;
int dash = dot * 3;
boolean flashing = false; 

String letters[] = {
  ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..",    // A-I
  ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.",  // J-R
  "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."          // S-Z
};

void setup() {
    pinMode(ledPin, OUTPUT);
    pinMode(buzzerPin, OUTPUT);
    Spark.function("morse", startFlashing);
}

void loop() {
    if (flashing) {
        flashMessage(message);
        flashing = false;
    }
}

int startFlashing(String param) {
    if (param.length() <= 63) {
        message = param;
        flashing = true;
        return 1;
    }
    else {
        return -1; // message too long
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
    tone(buzzerPin, 1000);
    delay(duration);
    noTone(buzzerPin);
    digitalWrite(ledPin, LOW);
}

// curl https://api.spark.io/v1/devices/55ff6b065075555322151487/morse -d access_token=cb8b348000e9d0ea9e354990bbd39ccbfb57b30e -d params=ABCD
