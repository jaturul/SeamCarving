#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <string>
#include <vector>

namespace Constants
{
	enum class OperationType { EROSION = 1, DILATION, THRESHOLD, MAX_SIZE, MIN_SIZE, BACKGROUND_SUB, GAMMA_CORRECTION };

	class ConstantElements
	{
	public:
		static std::vector<std::string> getAcceptableImageExtensions();
	};
}

#endif
