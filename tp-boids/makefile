help:
	@echo
	@echo
	@echo "This makefile helps for compiling and testing"
	@echo
	@echo "Usage:"
	@echo
	@echo "make movie-001.mp4  <-- makes and displays the movie for test-001"
	@echo "make movie-001.bin  <-- compiles test-001"
	@echo
	@echo "make clean  <-- cleans binaries and .ppm files"
	@echo

VIDEO_VIEWER = totem

BOIDS_HEADERS = $(wildcard boid*.hpp)

.PHONY: clean
clean:
	rm -f *.ppm *.bin

# This builds an executable as test-001.bin, from test-001.cpp
test-%.bin : test-%.cpp $(BOIDS_HEADERS)
	g++ -o $@ -I. -std=c++20 $<

# This builds up the movies
# - first we remove eventual existing ppm frames
# - then we run test-%.bin (i.e. $<)
# - we remove eventual existing movie-%.mp4 (i.e. $@)
# - then we gather the frames into a movie using ffmpeg.
# - and last, we use our viewer to play the movie.
movie-%.mp4 : test-%.bin
	rm -f frame-*.ppm
	./$<
	rm -f $@
	ffmpeg -i frame-%06d.ppm -b:v 1M $@
	$(VIDEO_VIEWER) $@
