# Arduino-Joystick-Weather-Clock

Forked from rydepier's excellent work - updated in 2020:

* BMP180 is now hard to find - I bought a BMP280 which offers the same functions, but had to make use of a different library, and change some of the library calls to match.
* In my hardware construction, the OLED display ended up "upside-down". A single call to the u8g library rotates the display through 180 degrees. Could easily be modified for other rotations.
* All other modules seem to be readily available - I used a DS1307 for the RTC.
* Code structure has been modified to build on Arduino 1.8.10
* A few test programs have been added to this folder, including an i2c scanner, as my BMP280 is at 0x76, and the modules default to 0x77.

---

This project was updated in Feb. 2017 to include a Humidity Sensor.

This clock has 22 screens selected using a joystick. Everything from weather forecast to moon phase on OLED screen. The project requires an Arduino Mega, a real time clock (DS1307), a pressure sensor (BMP180), a Humidity Sensor (DHT 11), an active buzzer, an SD Card and a joystick with switch. Data is shown on 22 screens, selected using the joystick and an Anlo Clock, Digital Clock, Alarm and Timer are included.

The main code contains connection details for the various sensors. There is a RTC setting sketch and some simple instructions in a sketch. The full project is shown on my blog at  https://rydepier.wordpress.com/2015/07/30/joystick-weather-clock-using-oled-display/ . The moon phase calculator will work for any date after 1972, but in this sketch it is used to calculate the date of the last full moon, then display a simple graphic and description for the moon phase today. The Calendar displays the current date and a one month calendar in standard format.

Pressure and temperature are plotted over a 24 hour period with 3 days worth of data stored and each 24 hour period can be displayed. Data is saved to an SD Card, which is then is loaded when the Arduino is powered up. The buzzer is used to show the presence of an SD Card and that the backup data being loaded.

The SD Card can be removed to read the data, but when the card is removed it becomes un-mounted and will not remount when it is replaced. Press the Arduino Reset when the card is returned, this will remount the card and upload the stored data. If this is not done the data will not be written to the data files.
