#include "../header/SeamCarver.h"
#include "../header/EnergyCalculator.h"
#include "../header/Seam.h"



void SeamCarver::resizeImage(ImageRGB& image, const Size& targetSize)
{
	// for the moment, we assume only sizes smaller than the target size
	unsigned rowsToRemove = image.height() - targetSize.Height;
	unsigned colsToRemove = image.width() - targetSize.Width;

	ImageGray energyMap = EnergyCalculator::calculateEnergy(image);
	for(unsigned i = 0; i < rowsToRemove; ++i)
	{
		ImageGray cummulativeEnergyMap = createCummulativeEnergyMap(energyMap, Orientation::Horizontal);

		Seam currentSeam = findSeam(cummulativeEnergyMap, Orientation::Horizontal);

		removeSeam(image, currentSeam);
		removeSeam(energyMap, currentSeam);

	}

	for(unsigned i = 0; i < colsToRemove; ++i)
	{
		ImageGray cummulativeEnergyMap = createCummulativeEnergyMap(energyMap, Orientation::Vertical);

		Seam currentSeam = findSeam(cummulativeEnergyMap, Orientation::Vertical);

		removeSeam(image, currentSeam);
		removeSeam(energyMap, currentSeam);

	}
}

ImageGray SeamCarver::createCummulativeEnergyMap(const ImageGray& energyMap, Orientation orientation)
{
	//TODO
	return ImageGray(std::vector<int>(), energyMap.width(), energyMap.height());
}

Seam SeamCarver::findSeam(const ImageGray& cummulativeEnergyMap, Orientation orientation)
{
	//TODO
	Seam seam;
	seam.Elements.push_back({0, 0});
	return seam;
}

void SeamCarver::removeSeam(ImageGray& image, const Seam& seam)
{
	//TODO
}

void SeamCarver::removeSeam(ImageRGB& image, const Seam& seam)
{
	//TODO
}
