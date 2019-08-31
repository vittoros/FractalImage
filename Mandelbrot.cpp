/*
* The mandelbrot set is defined by the set of complex numbers c, for which
* the complex numbers of the sequence z n remain * bounded in absolute
* value. The sequence z n is defined by:
* z(0) = 0
* z(n+1) = z(n)^2 + c
* For this to stand, the abs(z) must not go greater than 2. If the value
* gets bigger than 2, it's guaranteed that it will go to infinity.
*/

#include "Mandelbrot.h"
#include <complex>

// Constructor
Mandelbrot::Mandelbrot(int imageMaxWidth, int imageMaxHeight): IMAGE_WIDTH(imageMaxWidth), IMAGE_HEIGHT(imageMaxHeight) {

}


// -------------------------------------------------------------
// Calculate if a coordinate is inside the set
double Mandelbrot::MandelbrotSet(int col, int row) {
	// Scaling between pixel coordinates and complex plane
	double complexCoor = (double)row / IMAGE_HEIGHT * (IMAGINARY_MAX_VALUE - IMAGINARY_MIN_VALUE) + IMAGINARY_MIN_VALUE;
	double realCoor = (double)col / IMAGE_WIDTH * (REAL_MAX_VALUE - REAL_MIN_VALUE) + REAL_MIN_VALUE;

	// Implement Mandelbrot algorithm
	std::complex<double> z = 0;
	std::complex<double> c(realCoor, complexCoor);

	int iteration = 0;
	while (norm(z) <= 4 && iteration < MAX_ITERATIONS) {
		z = z * z + c;	
		iteration++;
	}

	return (double)iteration / MAX_ITERATIONS;
}