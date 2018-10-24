#include <crc_table.h>
#include <N64.h>
#include <N64_DTO.h>
#include <ICSC.h>
#include <SoftwareSerial.h>

SoftwareSerial mySerial(3, 4); // RX, TX
N64 n64(2);
ICSC icsc(Serial, 'A');

void setup() {
  
  mySerial.begin(9600);
  icsc.begin();
  n64.begin(); 
}

void loop() {

  N64_DTO controller = n64.read();
  delay(200);
  mySerial.write((const char *)&controller, sizeof(N64_DTO));
}
