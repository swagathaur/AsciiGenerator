#include "../Headers/Chunk.h"
#include "../Headers/Color.h"
#include <iostream>
#include <vector>

void Chunk::Draw()
{
	unsigned char temp = ((0.299f * color.r) + (0.587f * color.g) + (0.114f * color.b));
	unsigned char symbol;

	if (temp > 230)
		symbol = '@';
	else if (temp > 170)
		symbol = 'A';
	else if (temp > 150)
		symbol = '*';
	else if (temp > 120)
		symbol = 'o';
	else if (temp > 100)
		symbol = '?';
	else if (temp > 82)
		symbol = '+';
	else if (temp > 62)
		symbol = ':';
	else if (temp > 50)
		symbol = '\'';
	else if (temp > 35)
		symbol = '.';
	else
		symbol = ' ';
	std::cout << symbol;
}

Color Chunk::GetAverageColor(std::vector<Color> colors)
{
	int R = 0;
	int G = 0;
	int B = 0;
	int amount = 0;

	for (auto iter = colors.begin(); iter != colors.end(); ++iter)
	{
		R += (*iter).r;
		G += (*iter).g;
		B += (*iter).b;
		++amount;
	}

	float temp = 1.0f / amount;
	R *= temp;
	G *= temp;
	B *= temp;

	return color = Color(R, G, B);
}

