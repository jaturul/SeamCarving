#include <cmath>
#include "../header/EnergyCalculator.h"

ImageGray EnergyCalculator::calculateEnergy(const ImageRGB& image)
{
	ImageGray kernelX ({1, 0, -1,
						1, 0, -1,
						1, 0, -1}, 3, 3);
	ImageGray kernelY({1, 1, 1,
					   0, 0, 0,
					   -1, -1, -1}, 3, 3);
	ImageGray energyMap(std::vector<int>(image.width() * image.height(), 0), image.width(), image.height());
	for (unsigned i = 0; i < image.height(); ++i)
	{
		for (unsigned j = 0; j < image.width(); ++j)
		{
			ImageRGB currentNeighbourhood = image.neighbourhood(i,j);
			Pixel derivativeX = ImageCalculator::convolution(kernelX, currentNeighbourhood);
			Pixel derivativeY = ImageCalculator::convolution(kernelY, currentNeighbourhood);

			energyMap(i,j) = sqrt(derivativeX.Red * derivativeX.Red + derivativeY.Red * derivativeY.Red +
								  derivativeX.Green * derivativeX.Green + derivativeY.Green * derivativeY.Green +
								  derivativeX.Blue * derivativeX.Blue + derivativeY.Blue * derivativeY.Blue);
		}
	}

	return energyMap;
}

ImageGray EnergyCalculator::calculateEnergy(const ImageGray& image)
{
	ImageGray kernelX ({1, 0, -1,
						1, 0, -1,
						1, 0, -1}, 3, 3);
	ImageGray kernelY({1, 1, 1,
					   0, 0, 0,
					   -1, -1, -1}, 3, 3);
	ImageGray energyMap(std::vector<int>(image.width() * image.height(), 0), image.width(), image.height());
	for (unsigned i = 0; i < image.height(); ++i)
	{
		for (unsigned j = 0; j < image.width(); ++j)
		{
			ImageGray currentNeighbourhood = image.neighbourhood(i,j);
			int derivativeX = ImageCalculator::convolution(kernelX, currentNeighbourhood);
			int derivativeY = ImageCalculator::convolution(kernelY, currentNeighbourhood);

			energyMap(i,j) = sqrt(derivativeX * derivativeX + derivativeY * derivativeY);
		}
	}

	return energyMap;
}
