#include <crc_table.h>
#include <N64.h>
#include <N64_DTO.h>
#include <ICSC.h>

N64 n64(2);
ICSC icsc(Serial, 'A');

void setup() {
  
  Serial.begin(9600);
  icsc.begin();
  n64.begin(); 
}

void loop() {

  N64_DTO controller = n64.read();
  delay(200);
  icsc.send('B', 'C', sizeof(N64_DTO), (char *)&controller);
}
