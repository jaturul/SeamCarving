#ifndef ENERGY_CALCULATOR_H
#define ENERGY_CALCULATOR_H

#include "../header/ImageRGB.h"
#include "../header/ImageGray.h"
#include "../header/ImageCalculator.h"

class EnergyCalculator
{
public:

	static ImageGray calculateEnergy(const ImageRGB& image);
	static ImageGray calculateEnergy(const ImageRGB& image, const ImageRGB& mask);

private:

};

#endif
