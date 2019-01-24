#include <stdexcept>

#include "../header/Image.h"

Image::Image() :
	m_data(std::vector<Pixel>()),
	m_size(0,0)
{

}

Image::Image(std::vector<Pixel> data, unsigned width, unsigned height) :
	m_data(data),
	m_size(width,height)
{
	if(width * height != data.size())
	{
		throw std::invalid_argument("Provided image data and size are mismatched!");
	}

}

unsigned Image::width() const
{
	return m_size.Width;
}

unsigned Image::height() const
{
	return m_size.Height;
}

Pixel Image::at(unsigned row, unsigned col) const
{
	unsigned index = row * m_size.Width + col;
	return m_data[index];
}

Pixel& Image::operator()(unsigned row, unsigned col)
{
	unsigned index = row * m_size.Width + col;
	return m_data[index];
}
