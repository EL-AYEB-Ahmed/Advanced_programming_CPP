#include <iostream>
#include <iterator> // for back_inserter
#include <complex>
#include <numbers>

#include <boids.hpp>

#define NB_FRAMES  1000
#define IMAGE_SIDE 800
#define DT 5e-3

using namespace std::complex_literals;

int main(int argc, char* argv[]) {

  boids::simulator sim {};

  // Let us add agents
  
  auto out = std::back_inserter(sim.agents);
  *(out++) = boids::agent(boids::kinds::bird,
			  {.position = .2 + .3i, .orientation = std::polar(1., std::numbers::pi / 3)},
			  1.0); // velocity of 1.
  
  *(out++) = boids::agent(boids::kinds::bird,
			  {.position = .6 + .7i, .orientation = std::polar(1., 0.)},
			  1.0); // velocity of 1.

  // For now, our agents cannot move ! we need to provide the function
  // they have to use for moving.
  for(auto& a : sim.agents) a.virtual_move_ptr = boids::behaviors::move::by_default;

  // We make a movie then.
  
  for(unsigned int i = 0; i < NB_FRAMES; ++i) {
    sim.timestep(DT); 
    sim.to_ppm(IMAGE_SIDE);
  }
  std::cout << std::endl;

  return 0;
}
