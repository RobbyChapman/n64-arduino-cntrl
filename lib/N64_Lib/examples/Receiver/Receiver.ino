#include <ICSC.h>
#include <crc_table.h>
#include <N64.h>
#include <N64_DTO.h>
#include <SoftwareSerial.h>

ICSC icsc(Serial, 'B');
SoftwareSerial xbee(3, 4);

static void handlePacket(unsigned char src, char command, unsigned char len, char *data);

void setup() 
{
  Serial.begin(9600);
  icsc.begin();
  icsc.registerCommand('C', &handlePacket);
  //xbee.begin(115200);
}

void loop() 
{
  icsc.process();
}

static void handlePacket(unsigned char src, char command, unsigned char len, char *data)
{
  N64_DTO *controller = (N64_DTO *)data;
  /* For debug use */
  xbee.print("Y Joystick::");
  xbee.println(controller->y, DEC);
  xbee.print("X Joystick::");
  xbee.println(controller->x, DEC);  
}
