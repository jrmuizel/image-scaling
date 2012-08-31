LDFLAGS=-lstdc++
CXXFLAGS=-ggdb -I. -Iskia/core -Iskia/config


scale: skia/SkBitmap.o skia/SkMallocPixelRef.o skia/Sk64.o skia/SkUnPreMultiply.o skia/SkPixelRef.o scale.o convolver.o image_operations.o

clean:
	rm *.o skia/*.o
