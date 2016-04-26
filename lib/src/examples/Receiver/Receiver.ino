#include <crc_table.h>
#include <N64.h>
#include <N64_DTO.h>
#include <SoftwareSerial.h>

N64_DTO controller;
SoftwareSerial xbee(3, 4);

void setup() {
  
  Serial.begin(115200);
  xbee.begin(9600);
}

void loop() {
  
  while (xbee.available() > 0) {
    xbee.readBytes((char *)&controller, sizeof(N64_DTO));
    /* For debug use */
    Serial.print("Y Joystick::");
    Serial.println(controller.y, DEC);
    Serial.print("X Joystick::");
    Serial.println(controller.x, DEC);
  }
}
