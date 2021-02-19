#pragma once
class HelperMethods
{
public:
	static std::vector<unsigned char> decodeTwoSteps(const char* filename);
	static	std::vector<Color> ConvertToPixels(std::vector<unsigned char> channels);
	static std::vector<Chunk> GenerateChunks(std::vector<Color> pixels);
};

