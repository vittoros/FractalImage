#ifndef MANDELBROT_H
#define MANDELBROT_H

class Mandelbrot {
private:
	const int IMAGE_WIDTH, IMAGE_HEIGHT;	// Dimensions of original image
	static const int MAX_ITERATIONS = 1000;
	static const int REAL_MIN_VALUE = -2;	// Dimensions of Mandelbrot image
	static const int REAL_MAX_VALUE = 1;
	static const int IMAGINARY_MIN_VALUE = -1;
	static const int IMAGINARY_MAX_VALUE = 1;

public:
	// Constructor
	Mandelbrot(int imageMaxWidth, int imageMaxHeight);

	// Calculate if a coordinate is inside the set - returns [0,1]
	double MandelbrotSet(int col, int row);
};

#endif // !MANDELBROT_H
