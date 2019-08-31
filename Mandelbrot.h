#ifndef MANDELBROT_H
#define MANDELBROT_H

#include <memory>

class Mandelbrot {
private:
	const int IMAGE_WIDTH, IMAGE_HEIGHT;	// Dimensions of original image
	static const int MAX_ITERATIONS = 1000;
	static const int REAL_MIN_VALUE = -2;	// Dimensions of Mandelbrot image
	static const int REAL_MAX_VALUE = 1;
	static const int IMAGINARY_MIN_VALUE = -1;
	static const int IMAGINARY_MAX_VALUE = 1;

	// For the implemenation of histogram coloring
	std::unique_ptr<int[]> m_histogram{ nullptr };
	std::unique_ptr<int[]> m_fractal{ nullptr };
	int m_sumHistogram{ 0 };

public:
	// Constructor
	Mandelbrot(int imageMaxWidth, int imageMaxHeight);

	// Calculate if a coordinate is inside the set - returns [0,1]
	void MandelbrotSet(int col, int row);

	// Getters
	int* getFractal();
	int* getHistogram();
	int getSumHistogram() const;
};

#endif // !MANDELBROT_H
