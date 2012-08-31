CC=/Users/ehsanakhgari/moz/emscripten/emcc
CXXFLAGS=-I. -Iskia/core -Iskia/config

%.o: %.cpp
	$(CC) $(CPPFLAGS) $(CXXFLAGS) -c $^ -o $@

%.o: %.cc
	$(CC) $(CPPFLAGS) $(CXXFLAGS) -c $^ -o $@

scale.js: skia/SkBitmap.o skia/SkMallocPixelRef.o skia/Sk64.o skia/SkUnPreMultiply.o skia/SkPixelRef.o scale.o convolver.o image_operations.o
	$(CC) $(LDFLAGS) $^ -o scale.bc
	$(CC) -o scale.js scale.bc

clean:
	rm *.bc skia/*.o *.o
