/**
* Created by robert.chapman on 4/21/16.
*/

#include "N64_DTO.h"

class N64 {
  public:
    N64(int pin);
    void begin(int baud);
    N64_DTO read();
};
