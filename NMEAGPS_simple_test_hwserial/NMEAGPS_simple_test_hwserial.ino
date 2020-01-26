//  Pick a serial port for the GPS

// BEST choice is a HardwareSerial port:
//    Use Serial1 on a Mega, Leo or Due board
//    You could use Serial on any board by connecting the GPS TX pin
//       to the Arduino RX pin 0 (disconnect when uploading over USB).
#define gpsPort Serial1

// 2nd best:
//#include <AltSoftSerial.h>
//AltSoftSerial gpsPort; // must be on specific pins (8 & 9 for an UNO)

// 3rd best: must be baud rate 9600, 19200 or 38400
//#include <NeoSWSerial.h>
//NeoSWSerial gpsPort(4, 3);

// Worst: SoftwareSerial NOT RECOMMENDED
//---------------------

#include <NMEAGPS.h>
NMEAGPS gps;  // This does all the grunt work with the NMEA data

void setup()
{
  Serial.begin(9600);
  gpsPort.begin(9600);
  Serial.println( F("GPS Start") );//Just show to the monitor that the sketch has started
}

void loop()
{
  //Parse any characters coming from the GPS
  while (gps.available( gpsPort ))
  {
    //  Get the latest info from the gps object which it
    //      derived from the data sent by the GPS unit.
    //  This happesn exactly once per second.
    gps_fix fix = gps.read();

    if(fix.valid.location)
    {
      Serial.println( F("Satellite Count:") );
      Serial.println(fix.satellites);
      Serial.println( F("Latitude:") );
      Serial.println(fix.latitude(), 6);
      Serial.println( F("Longitude:") );
      Serial.println(fix.longitude(), 6);
      Serial.println( F("Speed MPH:") );
      Serial.println(fix.speed_mph());
      Serial.println( F("Altitude Feet:") );
      Serial.println(fix.altitude() * 3.28084 ); // feet
      Serial.println( F("Year:") );
      Serial.println(fix.dateTime.year);
      Serial.println( F("Month:") );
      Serial.println(fix.dateTime.month);
      Serial.println( F("Day:") );
      Serial.println(fix.dateTime.day);
      
      Serial.println();
    } else {
      Serial.print( '.' );
    }
  }
}
