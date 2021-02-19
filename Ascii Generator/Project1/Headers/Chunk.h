#pragma once
#include <vector>
#include "../Headers/Color.h"

class Chunk
{
public:
	Chunk() {};

	unsigned char width;
	unsigned char height;

	Color color;

	void Draw();
	Color GetAverageColor(std::vector<Color> colors);
};

