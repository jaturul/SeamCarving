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
//
//	ImageRGB cummVert({{1, 1, 1, 1}, {0, 0, 0, 0}, {3, 3, 3, 3}, {1, 1, 1, 1},
//					   {2, 2, 2, 2}, {1, 1, 1, 1}, {3, 3, 3, 3}, {5, 5, 5, 5},
//					   {5, 5, 5, 5}, {2, 2, 2, 2}, {2, 2, 2, 2}, {3, 3, 3, 3},
//					   {2, 2, 2, 2}, {5, 5, 5, 5}, {4, 4, 4, 4}, {3, 3, 3, 3}}, 4, 4);
//
//	SeamCarver carver;
//	Seam seam({{3,0}, {2,1}, {1,1}, {0,1}}, Orientation::Vertical);
//	carver.removeSeam(cummVert, seam);


//	ImageGray cummHor({1, 1, 4, 5,
//						2, 2, 4, 6,
//						4, 1, 2, 2,
//						0, 3, 3, 3}, 4, 4);
//	SeamCarver carver;
//	Seam seam({{2,3}, {2,2}, {2,1}, {3,0}}, Orientation::Horizontal);
//	carver.removeSeam(cummHor, seam);

//	ImageGray cummHor({1, 1, 4, 5,
//						2, 2, 4, 6,
//						4, 1, 2, 2,
//						0, 3, 3, 3}, 4, 4);
//	ImageGray neig = cummHor.neighbourhood(0,0);
//	ImageGray neig2 = cummHor.neighbourhood(1,1);
//	ImageGray neig3 = cummHor.neighbourhood(3,3);
//
//	ImageRGB cummHorRGB({{1, 1, 1, 1}, {0, 0, 0, 0}, {3, 3, 3, 3}, {1, 1, 1, 1},
//					   {2, 2, 2, 2}, {1, 1, 1, 1}, {3, 3, 3, 3}, {5, 5, 5, 5},
//					   {5, 5, 5, 5}, {2, 2, 2, 2}, {2, 2, 2, 2}, {3, 3, 3, 3},
//					   {2, 2, 2, 2}, {5, 5, 5, 5}, {4, 4, 4, 4}, {3, 3, 3, 3}}, 4, 4);
//	ImageRGB neigRGB = cummHorRGB.neighbourhood(0,0);
//	ImageRGB neigRGB2 = cummHorRGB.neighbourhood(1,1);
//	ImageRGB neigRGB3 = cummHorRGB.neighbourhood(3,3);

//	ImageGray cummHor({1, 0, 2,
//					   2, 1, 1,
//					   1, 2, 0}, 3, 3);
//	EnergyCalculator calculator;
//	ImageGray energyMap = calculator.calculateEnergy(cummHor);

	std::string inputFile = "images/shoes.png";

	ImageRGB input = ImageHelper::loadImageRGB(inputFile);

	SeamCarver carver;
	Size targetSize(input.width() * 0.8, input.height() * 0.8);
	carver.resizeImage(input, targetSize);
	std::string outputFile = "images/output.png";
	ImageHelper::saveImage(input, outputFile);

	return 0;
}
