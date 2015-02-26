int motorPin = D4;
// int ledPin = D7;
int potPin = A0;

String thisID = Spark.deviceID();
boolean myTurn = true;
int maxPosn = 4000;
int minPosn = 3000;

// To debug using LED flashing on pin D7, uncomment
// the lines above and below.
// two blinks for a publish
// four blinks for a subscription event recieved

void setup() {
    Spark.subscribe("pulled", remoteRopePulled);
    pinMode(motorPin, OUTPUT);
//    pinMode(ledPin, OUTPUT);
    moveSliderTo(maxPosn);
}

void loop() {
    int newLocalPosition = analogRead(potPin);
    if (newLocalPosition <  minPosn && myTurn) {
        Spark.publish("pulled", thisID);
//        flash(2);
        myTurn = false;
        //delay(2000);
    }
}

void remoteRopePulled(const char *event, const char *data)
{
//    flash(4);
    String dataS = String(data);
    if (dataS.indexOf(thisID) == -1) // ignore messages from yourself
    {
        moveSliderTo(maxPosn);
        myTurn = true;
    }
}

void moveSliderTo(int newPosition) {
    while (analogRead(potPin) < newPosition) {
        digitalWrite(motorPin, HIGH);
    };
    digitalWrite(motorPin, LOW);
}


// void flash(int n) {
//     for (int i = 0; i < n; i++) {
//         digitalWrite(ledPin, HIGH);
//         delay(300);
//         digitalWrite(ledPin, LOW);
//         delay(300);
//     }
// }
