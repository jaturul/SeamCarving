#include <stdexcept>

#include "../header/ImageRGB.h"

ImageRGB::ImageRGB() :
	m_data(std::vector<Pixel>()),
	m_size(0,0)
{

}

ImageRGB::ImageRGB(std::vector<Pixel> data, unsigned width, unsigned height) :
	m_data(data),
	m_size(width,height)
{
	if(width * height != data.size())
	{
		throw std::invalid_argument("Provided image data and size are mismatched!");
	}

}

unsigned ImageRGB::width() const
{
	return m_size.Width;
}

unsigned ImageRGB::height() const
{
	return m_size.Height;
}

Pixel ImageRGB::at(unsigned row, unsigned col) const
{
	unsigned index = row * m_size.Width + col;
	return m_data[index];
}

Pixel& ImageRGB::operator()(unsigned row, unsigned col)
{
	unsigned index = row * m_size.Width + col;
	return m_data[index];
}
