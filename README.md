# MLX90395 Magnetometer for Hyperfine Field Characterization
## Description
This project includes an Arduino .INO for making basic measurements from MLX903985 magnetometer (based off of the [Adafruit Driver](https://github.com/adafruit/Adafruit_MLX90395/tree/master) example code) and python script to log data from the Arduino via the serial connection.

## Installing Dependencies
Use the included **package installer in the Arduino IDE** to install the following:
- [Adafruit_BusIO](https://github.com/adafruit/Adafruit_BusIO)
- [Adafruit_Sensor](https://github.com/adafruit/Adafruit_Sensor)

Download the .zip file and install from .zip for the following (and possibly the above depending on version):
- [Adafruit_MLX90395](https://github.com/adafruit/Adafruit_MLX90395)

For reading the serial output from the Arduino using Python, install PySerial using:
- `pip install pyserial`