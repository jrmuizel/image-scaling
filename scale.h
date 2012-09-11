#include <stdint.h>

class Scaler {
public:
Scaler() {};
bool
Scale(uint8_t *src, int srcWidth, int srcHeight, uint8_t* dst, int dstWidth, int dstHeight);
};

