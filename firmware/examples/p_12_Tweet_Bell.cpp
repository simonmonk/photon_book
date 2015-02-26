int relayPins[] = {D0, D1, D2, D3};

void setup() {
    for (int i = 0; i < 4; i++) {
        pinMode(relayPins[i], OUTPUT);
    }
    Spark.function("relaycontrol", relaySwitcher);
}

void loop() {
}

int relaySwitcher(String command) {
    // "11", "10", "1P 1000" - P for pulse duration in millis
    int relayNumber = command.charAt(0) - '0';
    char action = command.charAt(1);
    if (action == '1') {
        digitalWrite(relayPins[relayNumber-1], HIGH);
    }
    else if (action == '0') {
        digitalWrite(relayPins[relayNumber-1], LOW);
    }
    else if (action == 'P' || action == 'p') {
        int duration = command.substring(3).toInt();
        digitalWrite(relayPins[relayNumber-1], HIGH);
        delay(duration);
        digitalWrite(relayPins[relayNumber-1], LOW);
    }
    return 1;
}

// To test with curl
// curl https://api.spark.io/v1/devices/<deviceid>/relaycontrol -d access_token=<accesstoken> -d params=1P-1000
// curl https://api.spark.io/v1/devices/54ff6d066678574934420567/relaycontrol -d access_token=cb8b348000e9d0ea9e354990bbd39ccbfb57b30e -d params=1P-1000