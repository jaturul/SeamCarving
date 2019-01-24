#ifndef IMAGE_HELPER_H
#define IMAGE_HELPER_H

#include <string>
#include "../header/Image.h"
#include "../header/Pixel.h"

class ImageHelper
{
public:

	static Image loadImage(const std::string& fileName);

	static void saveImage(const Image& image, const std::string& outputName);

private:
	// raw data of format RGBA is assumed
	static std::vector<Pixel> convertRawToPixelData(const std::vector<unsigned char>& rawData);

	static std::vector<unsigned char> convertImageToRawData(const Image& image);
};

#endif
