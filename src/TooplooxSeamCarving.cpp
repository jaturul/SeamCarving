//============================================================================
// Name        : TooplooxSeamCarving.cpp
// Author      : Jacek Turula
// Version     :
// Copyright   : This program has been written by Jacek Turula.
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

#include "../thirdparty/lodepng.h"

#include "../header/Image.h"
#include "../header/ImageHelper.h"

using namespace std;

int main(int argc, char** argv)
{
	std::string inputFile = "src/nausicaa.png";
//	std::vector<unsigned char> imageData;
//	unsigned imageWidth = 0;
//	unsigned imageHeight = 0;
//	unsigned errorCode = lodepng::decode(imageData, imageWidth, imageHeight, fileName );
//	std::string outputName = "nausicaaOutput.png";
//	std::vector<unsigned char> outputData;
//	unsigned errorCode2 = lodepng::encode(outputData, imageData, imageWidth, imageHeight);
//
//	unsigned errorCode3 = lodepng::save_file(outputData, outputName);

	Image input = ImageHelper::loadImage(inputFile);

	for (unsigned i = 0; i < input.height(); ++i)
	{
		for (unsigned j = 0; j < input.width(); ++j)
		{
//			input(i,j).Red /= 2;
//			input(i,j).Green /=2;
//			input(i,j).Blue /=2;
			input(i,j).Alpha /=2;
		}
	}

	std::string outputFile = "src/output.png";
	ImageHelper::saveImage(input, outputFile);

	return 0;
}
