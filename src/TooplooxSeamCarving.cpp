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

using namespace std;

int main(int argc, char** argv)
{
	std::string inputFile = "src/nausicaa.png";

	ImageRGB input = ImageHelper::loadImageRGB(inputFile);

	std::string outputFile = "src/output.png";
	ImageHelper::saveImage(input, outputFile);

	return 0;
}
