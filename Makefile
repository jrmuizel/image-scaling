EMCC=/Users/jrmuizel/src/emscripten/emcc
CC=/Users/jrmuizel/src/emscripten/emcc
CXXFLAGS=-I. -Iskia/core -Iskia/config -fno-exceptions
LDLIBS=-lstdc++

%.o: %.cpp
	$(CC) $(CPPFLAGS) $(CXXFLAGS) -c $^ -o $@

%.o: %.cc
	$(CC) $(CPPFLAGS) $(CXXFLAGS) -c $^ -o $@

scale: skia/SkBitmap.o skia/SkMallocPixelRef.o skia/Sk64.o skia/SkUnPreMultiply.o skia/SkPixelRef.o scale.o convolver.o image_operations.o

scale.js: skia/SkBitmap.o skia/SkMallocPixelRef.o skia/Sk64.o skia/SkUnPreMultiply.o skia/SkPixelRef.o scale.o convolver.o image_operations.o
	$(EMCC) $(LDFLAGS) $^ -o scale.bc
	$(EMCC) -o scale.js scale.bc -s TOTAL_MEMORY=100000000 -O2 -s DISABLE_EXCEPTION_CATCHING=1 -s EXPORTED_FUNCTIONS="['_malloc','_Scale']"

clean:
	rm *.bc skia/*.o *.o
