#include <iostream>
#include <cstdint>

#include "Bitmap.h"
#include "Mandelbrot.h"

const int WIDTH = 800;
const int HEIGHT = 600;

int main() {
	Bitmap bitmap(WIDTH, HEIGHT);
	Mandelbrot mandelbrot(WIDTH, HEIGHT);

	// Set bottom left as red
	for (int x = 0; x < WIDTH; x++) {
		for (int y = 0; y < HEIGHT; y++) {
			uint8_t color = static_cast<uint8_t>(256 * mandelbrot.MandelbrotSet(x, y));

			bitmap.setPixel(x, y, 0, color, 0);
		}
	}

	bitmap.write("test.bmp");

	//std::cout << "Test bitmap written!" << std::endl;

	return 0;
}


