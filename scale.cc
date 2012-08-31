#include <stdint.h>
#include "skia/SkBitmap.h"
#include "skia/core/SkFlattenable.h"
#include "skia/core/SkPackBits.h"
#include "skia/core/SkString.h"
#include "image_operations.h"
#include <assert.h>
static bool
Scale(uint8_t *src, int srcWidth, int srcHeight, uint8_t* dst, int dstWidth, int dstHeight)
{

	SkBitmap::Config config;
	bool opaque;


		uint8_t* srcData;
		uint32_t srcDataLength;
		// Source frame data is locked/unlocked on the main thread.

		uint8_t* dstData;
		uint32_t dstDataLength;

		SkBitmap imgSrc;
		imgSrc.setConfig(SkBitmap::kARGB_8888_Config, srcWidth, srcHeight,
				 srcWidth*4);
		imgSrc.setPixels(srcData);
		imgSrc.setIsOpaque(opaque);

		// This returns an SkBitmap backed by dstData; since it wrote to dstData,
		// we don't need to look at that SkBitmap.
		skia::ImageOperations::Resize(imgSrc, skia::ImageOperations::RESIZE_BEST,
					      dstWidth, dstHeight, dstData);

}
void
sk_throw()
{
}

SkString::SkString()
{};

SkString::~SkString()
{};

void
SkPackBits::Unpack8(unsigned char*, unsigned long, unsigned long, unsigned char const*)
{
	assert(0);
}

/*
SkFlattenable::SkFlattenable()
{
	assert(0);
}*/
int8_t SkToS8(long x)
{
    SkASSERT((int8_t)x == x);
    return (int8_t)x;
}

uint8_t SkToU8(size_t x)
{
    SkASSERT((uint8_t)x == x);
    return (uint8_t)x;
}

int16_t SkToS16(long x)
{
    SkASSERT((int16_t)x == x);
    return (int16_t)x;
}

uint16_t SkToU16(size_t x)
{
    SkASSERT((uint16_t)x == x);
    return (uint16_t)x;
}

int32_t SkToS32(long x)
{
    SkASSERT((int32_t)x == x);
    return (int32_t)x;
}

uint32_t SkToU32(size_t x)
{
    SkASSERT((uint32_t)x == x);
    return (uint32_t)x;
}


int SkCLZ_portable(unsigned int)
{
	assert(0);
}

#include <stdlib.h>
int main()
{
	uint8_t *src = (uint8_t*)malloc(100*100*4);
	uint8_t *dst = (uint8_t*)malloc(25*25*4);
	Scale(src, 100, 100, dst, 25, 25);

}


