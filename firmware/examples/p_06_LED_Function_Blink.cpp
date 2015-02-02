int ledPin = D7;

boolean blinking = false;

void setup() {
    pinMode(ledPin, OUTPUT);
    Spark.function("led", ledSwitcher);
}

void loop() {
    if (blinking) {
        digitalWrite(ledPin, HIGH);
        delay(200);
        digitalWrite(ledPin, LOW);
        delay(200);
    }
}

int ledSwitcher(String command) {
    if (command.equalsIgnoreCase("on")) {
        blinking = true;
        return 1;
    }
    else if (command.equalsIgnoreCase("off")) {
        blinking = false;
        return 1;
    }
    return -1;
}

// To test with curl
// curl https://api.spark.io/v1/devices/<deviceid>/led -d access_token=<accesstoken> -d params=on