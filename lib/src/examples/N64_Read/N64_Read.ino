#include <N64.h>

N64 n64(2);

void setup() {
  n64.begin(1);
}

void loop() {
  n64.read();
}
