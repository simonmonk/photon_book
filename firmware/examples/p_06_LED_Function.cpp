int ledPin = D7;

void setup() {
    pinMode(ledPin, OUTPUT);
    Spark.function("led", ledSwitcher);
}

void loop() {
}

int ledSwitcher(String command) {
    if (command.equalsIgnoreCase("on")) {
        digitalWrite(ledPin, HIGH);
        return 1;
    }
    else if (command.equalsIgnoreCase("off")) {
        digitalWrite(ledPin, LOW);
        return 1;
    }
    return -1;
}

// To test with curl
// curl https://api.spark.io/v1/devices/<deviceid>/led -d access_token=<accesstoken> -d params=on