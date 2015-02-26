int reading = 0;
double volts = 0.0;
int analogPin = A0;

void setup() {
    Spark.variable("analog", &reading, INT);
    Spark.variable("volts", &volts, DOUBLE);
}

void loop() {
  reading = analogRead(analogPin);
  volts = reading * 3.3 / 4096.0;
}


// https://api.spark.io/v1/devices/54ff72066672524860351167/analog?access_token=cb8b348000e9d0ea9e354990bbd39ccbfb57b30e
// https://api.spark.io/v1/devices/54ff72066672524860351167/volts?access_token=cb8b348000e9d0ea9e354990bbd39ccbfb57b30e