#ifndef SEAM_H
#define SEAM_H

#include <utility>

struct Coord2D
{
public:

	Coord2D(unsigned row, unsigned col): m_rowCol(row,col) {}

	unsigned Row()
	{
		return m_rowCol.first;
	}

	unsigned Col()
	{
		return m_rowCol.second;
	}

private:
	std::pair<unsigned, unsigned> m_rowCol;
};

struct Seam
{
	std::vector<Coord2D> Elements;
};

#endif
