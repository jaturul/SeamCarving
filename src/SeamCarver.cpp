#include <algorithm>
#include <iostream>

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
	ImageGray cummulativeMap(std::vector<int>(energyMap.width() * energyMap.height()), energyMap.width(), energyMap.height());

	if (orientation == Orientation::Vertical)
	{
		for(unsigned i = 0; i < energyMap.width(); ++i)
		{
			cummulativeMap(0,i) = energyMap.at(0,i);
		}

		for(int i = 1; i < int(energyMap.height()); ++i)
		{
			for(int j = 0; j < int(energyMap.width()); ++j)
			{
				int indexLeftNeighbour= std::max(0, j - 1);
				int indexRightNeighbour= std::min(int(cummulativeMap.width()) - 1, j + 1);
				int indexPrevRow = i -1;

				cummulativeMap(i,j) = energyMap.at(i,j) +
						std::min( cummulativeMap(indexPrevRow, indexLeftNeighbour), std::min(cummulativeMap(indexPrevRow, j), cummulativeMap(indexPrevRow, indexRightNeighbour)) );
			}
		}
	}
	else
	{
		for(unsigned i = 0; i < energyMap.height(); ++i)
		{
			cummulativeMap(i,0) = energyMap.at(i,0);
		}

		for(int i = 1; i < int(energyMap.width()); ++i)
		{
			for(int j = 0; j < int(energyMap.height()); ++j)
			{
				int indexTopNeighbour= std::max(0, j - 1);
				int indexBottomNeighbour= std::min(int(cummulativeMap.height()) - 1, j + 1);
				int indexPrevCol = i - 1;

				cummulativeMap(j, i) = energyMap.at(j, i) +
						std::min( cummulativeMap(indexTopNeighbour, indexPrevCol), std::min(cummulativeMap(j, indexPrevCol), cummulativeMap(indexBottomNeighbour, indexPrevCol)) );
			}
		}
	}

	//TODO

	return cummulativeMap;
}

Seam SeamCarver::findSeam(const ImageGray& cummulativeEnergyMap, Orientation orientation)
{
	if (orientation == Orientation::Vertical)
	{
		unsigned lastRow = cummulativeEnergyMap.height() - 1;
		unsigned currentMinEnergyCol = 0;
		int minEnergy = cummulativeEnergyMap.at(lastRow, currentMinEnergyCol);
		for (unsigned col = 1; col < cummulativeEnergyMap.width(); ++col)
		{
			if (cummulativeEnergyMap.at(lastRow, col) < minEnergy)
			{
				currentMinEnergyCol = col;
				minEnergy = cummulativeEnergyMap.at(lastRow, col);
			}
		}
		Coord2D startingPoint(lastRow, currentMinEnergyCol);

		Seam seam(Orientation::Vertical);
		seam.addElement(startingPoint);

		int prevMinEnergyCol = startingPoint.Col();
		for(int row = int(lastRow) - 1; row >= 0; --row)
		{
			int leftCol= std::max(0, prevMinEnergyCol - 1);
			int middleCol = prevMinEnergyCol;
			int rightCol= std::min(int(cummulativeEnergyMap.width()) - 1, prevMinEnergyCol + 1);

			// to start with, we assume the pixel to the top left has minimal energy
			int minEnergy = cummulativeEnergyMap.at(row, leftCol);
			int currentMinEnergyCol = leftCol;

			if (cummulativeEnergyMap.at(row, middleCol) < minEnergy)
			{
				minEnergy = cummulativeEnergyMap.at(row, middleCol);
				currentMinEnergyCol = middleCol;
			}
			else if (cummulativeEnergyMap.at(row, rightCol) < minEnergy)
			{
				minEnergy = cummulativeEnergyMap.at(row, rightCol);
				currentMinEnergyCol = rightCol;
			}

			seam.addElement(Coord2D(row, currentMinEnergyCol));

			prevMinEnergyCol = currentMinEnergyCol;
		}

		return seam;
	}
	else if (orientation == Orientation::Horizontal)
	{
		unsigned lastCol = cummulativeEnergyMap.width() - 1;
		unsigned currentMinEnergyRow = 0;
		int minEnergy = cummulativeEnergyMap.at(currentMinEnergyRow , lastCol);
		for (unsigned row = 1; row < cummulativeEnergyMap.height(); ++row)
		{
			if (cummulativeEnergyMap.at(row, lastCol) < minEnergy)
			{
				currentMinEnergyRow = row;
				minEnergy = cummulativeEnergyMap.at(row, lastCol);
			}
		}
		Coord2D startingPoint(currentMinEnergyRow , lastCol);

		Seam seam(Orientation::Horizontal);
		seam.addElement(startingPoint);

		int prevMinEnergyRow = startingPoint.Row();
		for(int col = int(lastCol) - 1; col >= 0; --col)
		{
			int topRow = std::max(0, prevMinEnergyRow - 1);
			int middleRow = prevMinEnergyRow;
			int bottomRow= std::min(int(cummulativeEnergyMap.height()) - 1, prevMinEnergyRow + 1);

			// to start with, we assume the pixel to the top left has minimal energy
			int minEnergy = cummulativeEnergyMap.at(topRow, col);
			currentMinEnergyRow = topRow;

			if (cummulativeEnergyMap.at(middleRow, col) < minEnergy)
			{
				minEnergy = cummulativeEnergyMap.at(middleRow, col);
				currentMinEnergyRow = middleRow;
			}
			else if (cummulativeEnergyMap.at(bottomRow, col) < minEnergy)
			{
				minEnergy = cummulativeEnergyMap.at(bottomRow, col);
				currentMinEnergyRow = bottomRow;
			}

			seam.addElement(Coord2D(currentMinEnergyRow, col));

			prevMinEnergyRow = currentMinEnergyRow;
		}

		return seam;
	}
}

void SeamCarver::removeSeam(ImageGray& image, const Seam& seam)
{
	std::vector<unsigned> coordinates1DToRemove = convertSeamTo1DCoord(seam, image.width());
	std::sort(coordinates1DToRemove.rbegin(), coordinates1DToRemove.rend());
	image.RemoveSeam(coordinates1DToRemove, seam.orientation());
	//TODO
}

void SeamCarver::removeSeam(ImageRGB& image, const Seam& seam)
{
	std::vector<unsigned> coordinates1DToRemove = convertSeamTo1DCoord(seam, image.width());
	std::sort(coordinates1DToRemove.rbegin(), coordinates1DToRemove.rend());
	image.RemoveSeam(coordinates1DToRemove, seam.orientation());
}

std::vector<unsigned> SeamCarver::convertSeamTo1DCoord(const Seam& seam, unsigned imageWidth)
{
	std::vector<unsigned> coordinates1D(seam.size());
	for(int i = 0; i < seam.size(); ++i)
	{
		coordinates1D[i] = int(seam.at(i).Row() * imageWidth + seam.at(i).Col());
	}

	return coordinates1D;
}
