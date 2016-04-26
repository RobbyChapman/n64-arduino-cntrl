#include <crc_table.h>
#include <N64.h>
#include <N64_DTO.h>
#include <SoftwareSerial.h>

SoftwareSerial mySerial(3, 4); // RX, TX
N64 n64(2);

void setup() {
  
  mySerial.begin(9600);
  n64.begin(115200); 
}

void loop() {

  N64_DTO controller = n64.read();
  delay(200);
  mySerial.write((const char *)&controller, sizeof(N64_DTO));
}
