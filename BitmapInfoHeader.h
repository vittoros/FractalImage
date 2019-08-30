/* 
* BitMapFIleHeader.h
* Find how BitMap files header needs to be structured in the following link:
* https://en.wikipedia.org/wiki/BMP_file_format#DIB_header_(bitmap_information_header)
* Needs to be stored exactly in 40 bytes 
*/

#ifndef BITMAPINFOHEADER_H
#define BITMAPINFOHEADER_H

#include <cstdint>  

#pragma pack(push, 1)

struct BitmapInfoHeader {
	uint32_t headerSize{ 40 };
	int32_t width{ 0 };
	int32_t height{ 0 };
	uint16_t colorPlanes{ 1 };
	uint16_t bitsPerPixel{ 24 };	// 1 byte per color channel (rgb)
	uint32_t compression{ 0 };
	uint32_t imageSize{ 0 };
	int32_t horizontalResolution{ 2400 };	// 2400 seems to be fine preset value
	int32_t verticalResolution{ 2400 };	// 2400 seems to be fine preset value
	uint32_t colorNumber{ 0 };
	uint32_t importantColors{ 0 };
};

#pragma pack(pop)

#endif