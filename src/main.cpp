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

using namespace std;

int main(int argc, char** argv)
{
//	std::string inputFile = "src/nausicaa.png";
//
//	ImageRGB input = ImageHelper::loadImageRGB(inputFile);
//
//	std::string outputFile = "src/output.png";
//	ImageHelper::saveImage(input, outputFile);

//	ImageGray image({1, 0, 3, 1,
//					 2, 1, 3, 4,
//					 4, 1, 1, 0,
//					 0, 3, 2, 1}, 4, 4);
//
//	SeamCarver carver;
//	ImageGray cummulativeMap = carver.createCummulativeEnergyMap(image, Orientation::Vertical);
//	cummulativeMap = carver.createCummulativeEnergyMap(image, Orientation::Horizontal);

//	ImageGray cummVert({1, 0, 3, 1,
//					    2, 1, 3, 5,
//						5, 2, 2, 3,
//						2, 5, 4, 3}, 4, 4);
//	ImageGray cummHor({1, 1, 4, 5,
//					   2, 2, 4, 6,
//					   4, 1, 2, 2,
//					   0, 3, 3, 3}, 4, 4);
//
//	SeamCarver carver;
//	Seam seamVert = carver.findSeam(cummVert, Orientation::Vertical);
//	for(int i = 0; i < seamVert.size(); ++i)
//	{
//		std::cout << "(" << seamVert.at(i).Row() << ", " << seamVert.at(i).Col() << ")" << " ";
//	}
//	std::cout << std::endl;
//
//	Seam seamHor = carver.findSeam(cummHor, Orientation::Horizontal);
//	for(int i = 0; i < seamHor.size(); ++i)
//	{
//		std::cout << "(" << seamHor.at(i).Row() << ", " << seamHor.at(i).Col() << ")" << " ";
//	}
//	std::cout << std::endl;

//	ImageGray cummVert({1, 0, 3, 1,
//						2, 1, 3, 5,
//						5, 2, 2, 3,
//						2, 5, 4, 3}, 4, 4);
//
//	SeamCarver carver;
//	Seam seam({{3,0}, {2,1}, {1,1}, {0,1}}, Orientation::Vertical);
//	carver.removeSeam(cummVert, seam);

	ImageRGB cummVert({{1, 1, 1, 1}, {0, 0, 0, 0}, {3, 3, 3, 3}, {1, 1, 1, 1},
					   {2, 2, 2, 2}, {1, 1, 1, 1}, {3, 3, 3, 3}, {5, 5, 5, 5},
					   {5, 5, 5, 5}, {2, 2, 2, 2}, {2, 2, 2, 2}, {3, 3, 3, 3},
					   {2, 2, 2, 2}, {5, 5, 5, 5}, {4, 4, 4, 4}, {3, 3, 3, 3}}, 4, 4);

	SeamCarver carver;
	Seam seam({{3,0}, {2,1}, {1,1}, {0,1}}, Orientation::Vertical);
	carver.removeSeam(cummVert, seam);

	return 0;
}
