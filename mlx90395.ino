#include "Adafruit_MLX90395.h"

#define OPTIMAL_OSR MLX90395_OSR_8         // optimal OSR: 8 {1, 2, 4, 8}
#define OPTIMAL_RESOLUTION MLX90395_RES_19 // optimal resolution: 19 {16, 17, 18, 19}
#define OPTIMAL_GAIN_SELECTION 7           // optimal gainSel: 7 {0-15}

Adafruit_MLX90395 sensor = Adafruit_MLX90395();
void setup(void)
{
  Serial.begin(115200); // ensure baud in the Serial monitor is set to the same value

  // Wait for serial on USB platforms
  while (!Serial) {
      delay(10);
  }

  Serial.println("Starting Adafruit MLX90395 Demo");
  
  // Hardware I2C mode, can pass in address & alt Wire
  if (! sensor.begin_I2C()) {
    Serial.println("No sensor found ... check your wiring?");
    while (1) { delay(10); }
  }
  
  Serial.print("Found a MLX90395 sensor with unique id 0x");
  Serial.print(sensor.uniqueID[0], HEX);
  Serial.print(sensor.uniqueID[1], HEX);
  Serial.println(sensor.uniqueID[2], HEX);

  // Set and print OSR
  sensor.setOSR(OPTIMAL_OSR);
  Serial.print("OSR set to: ");
  switch (sensor.getOSR()) {
    case MLX90395_OSR_1: Serial.println("1 x"); break;
    case MLX90395_OSR_2: Serial.println("2 x"); break;
    case MLX90395_OSR_4: Serial.println("4 x"); break;
    case MLX90395_OSR_8: Serial.println("8 x"); break;
  }
  
  // Set and print Resolution
  sensor.setResolution(OPTIMAL_RESOLUTION);
  Serial.print("Resolution: ");
  switch (sensor.getResolution()) {
    case MLX90395_RES_16: Serial.println("16b"); break;
    case MLX90395_RES_17: Serial.println("17b"); break;
    case MLX90395_RES_18: Serial.println("18b"); break;
    case MLX90395_RES_19: Serial.println("19b"); break;
  }
  
  // Set and print Gain Selection
  sensor.setGain(OPTIMAL_GAIN_SELECTION);
  Serial.print("Gain: "); Serial.println(sensor.getGain());
}

void loop(void) {
  /* Get a new sensor event, normalized to uTesla */
  sensors_event_t event; 
  sensor.getEvent(&event);
  /* Display the results (magnetic field is measured in uTesla) */
  Serial.print("X: "); Serial.print(event.magnetic.x);
  Serial.print(" \tY: "); Serial.print(event.magnetic.y); 
  Serial.print(" \tZ: "); Serial.print(event.magnetic.z); 
  Serial.println(" uTesla ");

  delay(500);
}
