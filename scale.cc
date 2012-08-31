#include <stdint.h>
#include "skia/SkBitmap.h"
#include "skia/core/SkFlattenable.h"
#include "skia/core/SkPackBits.h"
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
		imgSrc.setConfig(config, srcWidth, srcHeight,
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

void Sk64::setMul(int, int)
{
	assert(0);
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


