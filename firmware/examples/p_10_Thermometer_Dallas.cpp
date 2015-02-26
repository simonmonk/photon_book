#include "OneWire/OneWire.h"
#include "spark-dallas-temperature/spark-dallas-temperature.h"

double tempC = 0.0;
double tempF = 0.0;

int tempSensorPin = D2;

OneWire oneWire(tempSensorPin);
DallasTemperature sensors(&oneWire);

void setup() {
    sensors.begin();
    Spark.variable("tempc", &tempC, DOUBLE);
    Spark.variable("tempf", &tempF, DOUBLE);
}

void loop() {
  sensors.requestTemperatures();
  tempC = sensors.getTempCByIndex(0);
  tempF = tempC * 9.0 / 5.0 + 32.0;
}


// https://api.spark.io/v1/devices/54ff72066672524860351167/tempc?access_token=cb8b348000e9d0ea9e354990bbd39ccbfb57b30e
