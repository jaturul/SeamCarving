#ifndef IMAGE_RGB_H
#define IMAGE_RGB_H

#include <vector>

#include "../header/Pixel.h"
#include "../header/Size.h"

class ImageRGB
{
public:
	ImageRGB();
	ImageRGB(std::vector<Pixel> data, unsigned width, unsigned height);

	unsigned width() const;
	unsigned height() const;

	// indexes from range <0, width/height) are assumed!
	Pixel at(unsigned row, unsigned col) const;
	Pixel& operator()(unsigned row, unsigned col);

private:

	std::vector<Pixel> m_data;
	Size m_size;
};

#endif
