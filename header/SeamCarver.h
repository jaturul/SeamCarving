#ifndef SEAM_CARVER_H
#define SEAM_CARVER_H

#include "../header/ImageRGB.h"
#include "../header/ImageGray.h"
#include "../header/Size.h"
#include "../header/Seam.h"

enum class Orientation
{
	Horizontal = 1,
	Vertical = 2
};

class SeamCarver
{
public:
	static void resizeImage(ImageRGB& image, const Size& targetSize);

private:
	static ImageGray createCummulativeEnergyMap(const ImageGray& energyMap, Orientation orientation);
	static Seam findSeam(const ImageGray& cummulativeEnergyMap, Orientation orientation);
	static void removeSeam(ImageGray& image, const Seam& seam);
	static void removeSeam(ImageRGB& image, const Seam& seam);
};

#endif
