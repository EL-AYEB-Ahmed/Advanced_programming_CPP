#include <complex>   // For complex numbers stuff.
#include <numbers>   // For pi.
#include <iostream>  // For printing.

// Provides the "i" litteral
using namespace std::complex_literals;

// We well base our complex type on double, so it may
// be convenient to have a type name for this.
using complex = std::complex<double>;

int main(int argc, char* argv[]) {

  // Warning: 2 is an int, 2. is a double. Our complex type
  // requires double.
  
  complex c1  {2. + 3.i};
  complex c2  {std::polar(12., std::numbers::pi/2)};

  std::cout << c1 << ' ' << c2 << ' '
	    << std::real(c1) << ' ' << std::imag(c2) << std::endl
	    << std::arg(c1)  << ' ' // we won't need it.
	    << std::abs(c1)  << ' ' // the module
	    << std::norm(c1) << ' ' // the squared module... needs less computation !
	    << std::endl;

  // operations are implemented
  c2 /= (c2 + 1.);
  
  return 0;
}
