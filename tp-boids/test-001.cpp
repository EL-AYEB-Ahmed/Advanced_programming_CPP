#include <iostream>
#include <iterator> // for back_inserter
#include <complex>
#include <numbers>

#include <boids.hpp>

#define NB_FRAMES  100
#define IMAGE_SIDE 800

using namespace std::complex_literals;

int main(int argc, char* argv[]) {

  boids::simulator sim {};

  // Let us add agents
  
  auto out = std::back_inserter(sim.agents);
  *(out++) = boids::agent(boids::kinds::bird,
			  {.position = .2 + .3i, .orientation = std::polar(1., 0.)},
			  1.0); // velocity of 1.
  
  *(out++) = boids::agent(boids::kinds::bird,
			  {.position = .6 + .7i, .orientation = std::polar(1., 0.)},
			  1.0); // velocity of 1.

  // We make a movie then.
  
  for(unsigned int i = 0; i < NB_FRAMES; ++i)
    sim.to_ppm(IMAGE_SIDE);
  std::cout << std::endl;

  return 0;
}
