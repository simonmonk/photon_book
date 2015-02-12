int relayPins[] = {D0, D1, D2, D3};

void setup() {
    for (int i = 0; i < 4; i++) {
        pinMode(relayPins[i], OUTPUT);
    }
    Spark.function("relay", relaySwitcher);
}

void loop() {
}

int relaySwitcher(String command) {
    if (command.length() != 2) return -1;
    int relayNumber = command.charAt(0) - '0';
    int state = command.charAt(1) - '0';
    digitalWrite(relayPins[relayNumber-1], state);
    return 1;
}

// To test with curl
// curl https://api.spark.io/v1/devices/<deviceid>/relay -d access_token=<accesstoken> -d params=11