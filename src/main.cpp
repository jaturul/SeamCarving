//============================================================================
// Name        : TooplooxSeamCarving.cpp
// Author      : Jacek Turula
// Version     :
// Copyright   : This program has been written by Jacek Turula.
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

#include "../thirdparty/lodepng.h"

#include "../header/ImageHelper.h"
#include "../header/ImageRGB.h"
#include "../header/ImageGray.h"
#include "../header/SeamCarver.h"
#include "../header/Orientation.h"
#include "../header/EnergyCalculator.h"

using namespace std;

int main(int argc, char** argv)
{
	std::string inputFile = "images/beach.png";
	std::string energyMask = "images/beachMask.png";

	ImageRGB input = ImageHelper::loadImageRGB(inputFile);
	ImageRGB mask = ImageHelper::loadImageRGB(energyMask);

	SeamCarver carver;
	Size targetSize(input.width() * 0.8, input.height() * 0.8);
	carver.resizeImage(input, mask, targetSize);
	std::string outputFile = "images/output.png";
	ImageHelper::saveImage(input, outputFile);

	return 0;
}
