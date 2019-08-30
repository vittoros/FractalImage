#include "Bitmap.h"

#include "BitmapFileHeader.h"
#include "BitmapInfoHeader.h"
#include <fstream>

// Constructor
Bitmap::Bitmap(int width, int height): m_width(width), m_height(height), m_pPixels(std::make_unique<uint8_t[]>(width * height * 3)) {
		
}


// -------------------------------------------------------------
// Save the BMP image
bool Bitmap::write(std::string filename) {
	// Initialize info for bitmap header
	BitmapFileHeader fileHeader;
	BitmapInfoHeader infoHeader;

	fileHeader.fileSize = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader) + m_width * m_height * 3;
	fileHeader.offsetData = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader);

	infoHeader.width = m_width;
	infoHeader.height = m_height;

	// Write the bitmap on the file
	std::ofstream file;
	file.open(filename, std::ios::out | std::ios::binary);

	if (!file)
		return false;

	file.write((char*)& fileHeader, sizeof(fileHeader));
	file.write((char*)& infoHeader, sizeof(infoHeader));
	file.write((char*)m_pPixels.get(), m_width * m_height * 3);

	file.close();

	if (!file)
		return false;

	return true;
}


// -------------------------------------------------------------
// Modify the pixel data
void Bitmap::setPixel(int col, int row, uint8_t red, uint8_t green, uint8_t blue) {

}