#ifndef SEAM_CARVER_H
#define SEAM_CARVER_H

#include "../header/ImageRGB.h"
#include "../header/ImageGray.h"
#include "../header/Size.h"
#include "../header/Seam.h"
#include "../header/Orientation.h"



class SeamCarver
{
public:
	static void resizeImage(ImageRGB& image, const Size& targetSize);

	static ImageGray createCummulativeEnergyMap(const ImageGray& energyMap, Orientation orientation);
	static Seam findSeam(const ImageGray& cummulativeEnergyMap, Orientation orientation);
	static void removeSeam(ImageGray& image, const Seam& seam);
	static void removeSeam(ImageRGB& image, const Seam& seam);

private:
	static std::vector<unsigned> convertSeamTo1DCoord(const Seam& seam, unsigned imageWidth);

};

#endif
