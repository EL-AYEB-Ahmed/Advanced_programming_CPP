#pragma once

#include <complex>

namespace boids {
  
  namespace torus {
    // Here, we define all things related to "living on a torus surface".
    
    // Our complex type is boids::torus::complex.
    using complex = std::complex<double>; 

    // The boids::torus::pose type defined hereafter represents the location
    // of an agent (postion and orientation).
    struct pose {
      complex position;      // Should be kept in [0, 1[ x [0, 1[
      complex orientation;   // |orientation| = 1
    };
  }
}
