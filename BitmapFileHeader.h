/* 
* BitMapFIleHeader.h 
* Find how BitMap files header needs to be structured in the following link:  
* https://en.wikipedia.org/wiki/BMP_file_format#Bitmap_file_header 
* Needs to be stored exactly in 14 bytes 
*/

#ifndef BITMAPFILEHEADER_H
#define BITMAPFILEHEADER_H

#include <cstdint>  

#pragma pack(push, 1)

struct BitmapFileHeader {
	uint16_t file_type{ 0x4D42 };	// 'BM' in little-endian format
	uint32_t fileSize{ 0 };
	uint16_t reserved1{ 0 };
	uint16_t reserved2{ 0 };
	uint32_t offsetData{ 0 };
};

#pragma pack(pop)

#endif // BITMAPFILEHEADER_H


