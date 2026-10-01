#pragma once

// System files have no error, so it is a good idea to include them
// before yours. If you forget to close a brace in yours, and include
// a file system after, the syntax error may appear in the system file,
// which is confusing...

#include <iomanip>   // for formatting.
#include <fstream>   // for files
#include <iostream>  // for string streams

#include <array> 
#include <vector>

#include <algorithm> // for std::fill

// We will need to "talk about" what's defined
// in these file... do not care about recursive
// includes that can be redundant... The directive
// #opragma once does the jobs.

#include <boidsTorus.hpp>
#include <boidsAgent.hpp>

namespace boids {

  // This is a color
  using rgb = std::array<unsigned char, 3>; // 3 bytes, red, blue and green component, each in [0, 255].
  // using pour définir un type (au lieu d'écrirstd::array of ecrit rgb)
  struct simulator {
    unsigned int ppm_rank;                            // The frame number.
    rgb background_color;
    std::vector<rgb> img_buffer;                      // Memory for storing pixels.
    std::vector<agent> agents;                        // The simulated agents.
    std::array<rgb, boids::kinds::nb> color_of_kind;  // color_of_kind[bird] contains the color of a bird.

    simulator()
      : ppm_rank(0),
	background_color({255, 255, 255}), // white
	img_buffer(),
	agents(),
	color_of_kind({
	  {255, 0, 0}  // birds are red.
	})
    {
    }

    void to_ppm(unsigned int image_side) {
      // Nota: the img_buffer is not reallocated at each call to
      // to_ppm, so we save time. Resizing to a size the vector
      // already has takes no time.
      img_buffer.resize(image_side * image_side); // We (re)allocate enough memory space for the image.
      std::fill(img_buffer.begin(),
		img_buffer.end(),
		background_color); // We paint everything in white.

      // More will have to be done here

      std::ostringstream filename;
      filename << "frame-"
	       << std::setw(6) << std::setfill('0') << ppm_rank++ // e.g. 000231
	       << ".ppm";
      std::ofstream ppm_file {filename.str()}; // We open the file for writing (ofstream)

      ppm_file << "P6\n"                                  // This is the tag for binary 24bit ppm images.
	       << image_side << ' ' << image_side << '\n' // We tell the width and height of our image.
	       << "255\n";                                // This is required by the ppm format.

      char* buffer = (char*)(std::data(img_buffer));
      // This is the adress of the bunch of bytes containing the
      // image. The next "write" function expects it as a char*.
      ppm_file.write(buffer, img_buffer.size() * 3);

      // This enables to print filenames always on the same line.
      std::cout << filename.str() << "\r" << std::flush;

      // The file is automatically closed here when ppm_file us unstacked from the scope.
    }
  };
}
