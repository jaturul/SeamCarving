#ifndef ENERGY_CALCULATOR_H
#define ENERGY_CALCULATOR_H

#include "../header/ImageRGB.h"
#include "../header/ImageGray.h"

class EnergyCalculator
{
public:

	static ImageGray calculateEnergy(const ImageRGB& image);

private:

};

#endif
