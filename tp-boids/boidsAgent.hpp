#pragma once

// We will need to "talk about" what's defined
// in boidsTorus.hpp in this boidsAgent.hpp file,
// so we include boidsTorus.hpp.
#include <boidsTorus.hpp>

namespace boids {

  namespace kinds {
    // This is a way to define numbers (like macros) known at
    // compiling time.
    constexpr unsigned int bird = 0; // boids::kinds::bird <=> 0 in the code.
    constexpr unsigned int nb   = 1; // boids::kinds::nb is the number of kinds we will have.
  }
  
  struct agent {
    unsigned int kind;     // Tells what kind of agent it is.
    torus::pose location;  // This is where it is and how it is oriented.
    double velocity;       // This is the motion speed of the agent.

    agent(unsigned int kind, const torus::pose& location, double velocity)
      : kind(kind), location(location), velocity(velocity) {}
  };
}
