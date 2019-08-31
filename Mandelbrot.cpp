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
Mandelbrot::Mandelbrot(int imageMaxWidth, int imageMaxHeight): IMAGE_WIDTH(imageMaxWidth), IMAGE_HEIGHT(imageMaxHeight),
m_histogram(std::make_unique<int[]>(MAX_ITERATIONS)), m_fractal(std::make_unique<int[]>(IMAGE_WIDTH* IMAGE_HEIGHT)) {

}


// -------------------------------------------------------------
// Calculate if a coordinate is inside the set
void Mandelbrot::MandelbrotSet(int col, int row) {
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

	// Calculate histogram - MAX_ITERATIONS entry isn't considered
	if (iteration != MAX_ITERATIONS) {
		m_histogram[iteration]++;
		m_sumHistogram++;
	}

	m_fractal[row * IMAGE_WIDTH + col] = iteration;
}

// -------------------------------------------------------------
// Getters
int* Mandelbrot::getFractal() {
	return m_fractal.get();
}

int* Mandelbrot::getHistogram() {
	return m_histogram.get();
}

int Mandelbrot::getSumHistogram() const {
	return m_sumHistogram;
}