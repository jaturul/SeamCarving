#ifndef IMAGE_GRAY_H
#define IMAGE_GRAY_H

#include <vector>

#include "../header/Size.h"
#include "../header/Orientation.h"

class ImageGray
{
public:
	ImageGray();
	ImageGray(std::vector<int> data, unsigned width, unsigned height);

	unsigned width() const;
	unsigned height() const;

	// indexes from range <0, width/height) are assumed!
	int at(unsigned row, unsigned col) const;
	int& operator()(unsigned row, unsigned col);

	void RemoveSeam(std::vector<unsigned> pointsToRemove, Orientation orientation);

private:

	std::vector<int> m_data;
	Size m_size;
};

#endif
