#ifndef BITMAP_H
#define BITMAP_H

#include <string>
#include <cstdint>
#include <memory>

class Bitmap {
private:
	int m_width{ 0 };
	int m_height{ 0 };
	std::unique_ptr<uint8_t[]> m_pPixels{ nullptr };

public:
	// Constructor - Create a BMP image in memory
	Bitmap(int width, int height);

	// Save the image
	bool write(std::string filename);

	// Modify the pixel data
	void setPixel(int col, int row, uint8_t red, uint8_t green, uint8_t blue);
};

#endif // !BITMAP_H
