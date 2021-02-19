#include <iostream>
#include <vector>
#include <string>
#include <Windows.h>
#include "headers/loadpng.h"
#include "main.h"

#define _WIN32_WINNT 0x0500

std::vector<unsigned char> png;
std::vector<unsigned char> image;
unsigned width, height;


class Color
{
public:
	Color() {};
	Color(char r, char g, char b) { this->r = b; this->g = g; this->b = r; }
	unsigned char r;
	unsigned char g;
	unsigned char b;
};

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
std::vector<Chunk> GenerateChunks(std::vector<Color> pixels)
{
	std::vector<Chunk> temp;
	for (unsigned int i = 0; i < pixels.size();)
	{
		Chunk dave;
		dave.width = 10;
		dave.height = 10;
		temp.push_back(dave);
		i += 100;
	}

	unsigned int offsetX = 0;
	unsigned int offsetY = 0;

	for (auto iter = temp.begin(); iter != temp.end(); iter++)
	{
		std::vector<Color> colorsInChunk;
		unsigned int j = 0;
		unsigned int k = 0;

		for (unsigned int i = 0; i < (*iter).height * (*iter).width; i++)
		{
			unsigned int pixelToUse;
			pixelToUse = (j + k * 800) + offsetX * 10 + offsetY * 10 * 800;
			auto Tim = pixels.at(pixelToUse);
			colorsInChunk.push_back(Tim);
			j++;
			if (j > 9)
			{
				j = 0;
				k++;
			}
		}

		(*iter).GetAverageColor(colorsInChunk);
		++offsetX;
		if (offsetX > 79)
		{
			offsetX = 0;
			offsetY++;
		}
	}
	return temp;
}

void decodeTwoSteps(const char* filename)
{
	//load and decode
	unsigned error = lodepng::load_file(png, filename);
	if (!error) error = lodepng::decode(image, width, height, png);

	//if there's an error, display it
	if (error) std::cout << "decoder error " << error << ": " << lodepng_error_text(error) << std::endl;

	//the pixels are now in the vector "image", 4 bytes per pixel, ordered RGBARGBA..., use it as texture, draw it, ...
}
std::vector<Color> ConvertToPixels(std::vector<unsigned char> channels)
{
	std::vector<Color> pixelData;
	for (auto iter = channels.begin(); iter != channels.end(); ++iter)
	{
		Color color((*iter++), (*iter++), (*iter++));
		pixelData.push_back(color);
	}

	return pixelData;
}


int main()
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, 800, 800, TRUE);

	system("CLS");
	png.clear();
	image.clear();
	decodeTwoSteps("C:/Users/aidan.mckeown/Desktop/image0.png");

	while (true)
	{
		int ch;
		while ((ch = std::getchar()) != '\n' && ch != EOF);

		unsigned char temp = std::getchar();

		if (temp == '0')
		{
			system("CLS");
			png.clear();
			image.clear();
			decodeTwoSteps("C:/Users/aidan.mckeown/Desktop/image0.png");
		}
		else if (temp == '1')
		{
			system("CLS");
			png.clear();
			image.clear();
			decodeTwoSteps("C:/Users/aidan.mckeown/Desktop/image.png");
		}
		else if (temp == '2')
		{
			system("CLS");
			png.clear();
			image.clear();
			decodeTwoSteps("C:/Users/aidan.mckeown/Desktop/image2.png");
		}
		else if (temp == '3')
		{
			system("CLS");
			png.clear();
			image.clear();
			decodeTwoSteps("C:/Users/aidan.mckeown/Desktop/image3.png");
		}
		else if (temp == '4')
		{
			system("CLS");
			png.clear();
			image.clear();
			decodeTwoSteps("C:/Users/aidan.mckeown/Desktop/image4.png");
		}
		else if (temp == '5')
		{
			system("CLS");
			png.clear();
			image.clear();
			decodeTwoSteps("C:/Users/aidan.mckeown/Desktop/image5.png");
		}
		else if (temp == '6')
		{
			system("CLS");
			png.clear();
			image.clear();
			decodeTwoSteps("C:/Users/aidan.mckeown/Desktop/image6.png");
		}

		auto imagePixels = ConvertToPixels(image);

		auto chunkList = GenerateChunks(imagePixels);

		unsigned int i = 0;
		for (auto iter = chunkList.begin(); iter != chunkList.end(); iter++)
		{
			(*iter).Draw();
		}
		temp = 'k';

	}

	system("pause");
	return 0;
}


