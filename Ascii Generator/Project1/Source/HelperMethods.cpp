#include "../Headers/HelperMethods.h"
#include "../Headers/loadpng.h"
#include "../Headers/Chunk.h"
#include <iostream>

/// <summary>
/// Loads and stores an image as a vector of pixel values. 
/// </summary>
/// <param name="filename"></param>
/// <returns>Vector of Byte values, 4 bytes are used per pixel, ordered RGBARGBA...</returns>
std::vector<unsigned char> decodeTwoSteps(const char* filename)
{
	std::vector<unsigned char> png;
	std::vector<unsigned char> image;
	unsigned width, height;

	//load and decode
	unsigned error = lodepng::load_file(png, filename);
	if (!error) error = lodepng::decode(image, width, height, png);

	//if there's an error, display it
	if (error) std::cout << "decoder error " << error << ": " << lodepng_error_text(error) << std::endl;

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
