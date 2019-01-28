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
#include "../header/InputParser.h"


int main(int argc, char** argv)
{
	try
	{
		std::vector<std::string> arguments = InputParser::parseInput(argc, argv);
		ImageRGB input = ImageHelper::loadImageRGB(arguments[2]);
		Size targetSize(std::stoi(arguments[1]), std::stoi(arguments[0]));

		SeamCarver carver;
		if (arguments.size() == 5)
		{
			std::string energyMask = arguments[4];
			ImageRGB mask = ImageHelper::loadImageRGB(energyMask);
			carver.resizeImage(input, mask, targetSize);
		}
		else
		{
			carver.resizeImage(input, targetSize);
		}

		std::string outputFile = arguments[3];
		ImageHelper::saveImage(input, outputFile);
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}
