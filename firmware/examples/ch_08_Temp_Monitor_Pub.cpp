#include "spark-dallas-temperature/spark-dallas-temperature.h"
#include "OneWire/OneWire.h"

int tempSensorPin = D2;
OneWire oneWire(tempSensorPin);
DallasTemperature sensors(&oneWire);

boolean toohot = false;

void setup() {
    sensors.begin();
}

void loop() {
  sensors.requestTemperatures();
  float tempC = sensors.getTempCByIndex(0);
  float tempF = tempC * 9.0 / 5.0 + 32.0;
  if (tempF > 80.0 && toohot == false) {
      Spark.publish("toohot");
      toohot = true;
  }
  if (tempF < 78.0 && toohot == true) {
      Spark.publish("tempnormal");
      toohot = false;
  }
}