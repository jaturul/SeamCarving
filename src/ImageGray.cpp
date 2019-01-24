#include "../header/ImageGray.h"

ImageGray::ImageGray():
	m_data(std::vector<int>()),
	m_size(0,0)
{

}

ImageGray::ImageGray(std::vector<int> data, unsigned width, unsigned height):
	m_data(data),
	m_size(width, height)
{

}

unsigned ImageGray::width() const
{
	return m_size.Width;
}

unsigned ImageGray::height() const
{
	return m_size.Height;
}

// indexes from range <0, width/height) are assumed!
int ImageGray::at(unsigned row, unsigned col) const
{
	int currentIndex = row * width() + col;

	return m_data[currentIndex];
}

int& ImageGray::operator()(unsigned row, unsigned col)
{
	int currentIndex = row * width() + col;

	return m_data[currentIndex];
}
