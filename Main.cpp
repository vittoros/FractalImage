#include <iostream>
#include <cstdint>
#include <math.h>

#include "Bitmap.h"
#include "Mandelbrot.h"

const int WIDTH = 800;
const int HEIGHT = 600;

int main() {
	Bitmap bitmap(WIDTH, HEIGHT);
	Mandelbrot mandelbrot(WIDTH, HEIGHT);

	// --------------------------------------
	// Apply the mandelbrot algorithm 
	for (int x = 0; x < WIDTH; x++) {
		for (int y = 0; y < HEIGHT; y++) {
			mandelbrot.MandelbrotSet(x, y);
		}
	}

	// --------------------------------------
	// Apply the histogram coloring technique
	int* fractal = mandelbrot.getFractal();
	int* histogram = mandelbrot.getHistogram();
	int total = mandelbrot.getSumHistogram();
	for (int x = 0; x < WIDTH; x++) {
		for (int y = 0; y < HEIGHT; y++) {
			int iteration = fractal[y * WIDTH + x];

			double hue = 0;
			for (int i = 0; i <= iteration; i++)
				hue += histogram[i] / (double)total;

			uint8_t red;
			uint8_t green = pow(255, hue);
			uint8_t blue;

			bitmap.setPixel(x, y, 0, green, 0);
		}
	}

	bitmap.write("test.bmp");
	std::cout << "Test bitmap written!" << std::endl;

	return 0;
}


