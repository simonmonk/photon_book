// https://api.spark.io/v1/devices/54ff72066672524860351167/analog?access_token=cb8b348000e9d0ea9e354990bbd39ccbfb57b30e

int reading = 0;
int analogPin = A0;

void setup() {
    Spark.variable("analog", &reading, INT);
}

void loop() {
  reading = analogRead(analogPin);
}
