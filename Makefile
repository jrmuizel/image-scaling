CC=/Users/jrmuizel/src/emscripten/emcc
CXXFLAGS=-I. -Iskia/core -Iskia/config

%.o: %.cpp
	$(CC) $(CPPFLAGS) $(CXXFLAGS) -c $^ -o $@

%.o: %.cc
	$(CC) $(CPPFLAGS) $(CXXFLAGS) -c $^ -o $@

scale.js: skia/SkBitmap.o skia/SkMallocPixelRef.o skia/Sk64.o skia/SkUnPreMultiply.o skia/SkPixelRef.o scale.o convolver.o image_operations.o
	$(CC) $(LDFLAGS) $^ -o scale.bc
	$(CC) -o scale.js scale.bc -s TOTAL_MEMORY=100000000 -O2

clean:
	rm *.bc skia/*.o *.o
