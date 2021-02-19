#include <iostream>
#include <vector>
#include <string>
#include <Windows.h>
#include <algorithm>
#include "headers/loadpng.h"
#include "headers/HelperMethods.h"

void RenderVideo();
void RenderPicture();
void CheckInput();

int main()
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, 800, 800, TRUE);

	system("CLS");

	while (true)
	{
		CheckInput();

		

	}

	system("pause");
	return 0;
}

void CheckInput()
{
	//Display Options
	std::cout << "Would you like to render a Video capture device(v) or a Picture(p)";

	//Read to temp string
	std::string response;
	std::getline(std::cin, response);
	std::transform(response.begin(), response.end(), response.begin(),
		[](unsigned char c) { return std::tolower(c); });

	//Check temp string for answer
	if (response == "v" || response == "video")
		RenderVideo();
	else if (response == "p" || response == "picture")
		RenderPicture();
	else
	{
		std::cout << "You have not chosen a valid option, please choose again.";
		CheckInput();
	}
}

void RenderVideo()
{

}

void RenderPicture()
{
	int ch;
	while ((ch = std::getchar()) != '\n' && ch != EOF);

	unsigned char temp = std::getchar();

	if (temp == '0')
	{
		system("CLS");
		png.clear();
		image.clear();
		decodeTwoSteps("C:/Users/aidos/Downloads/800Justine.png");
	}
	else if (temp == '1')
	{
		system("CLS");
		png.clear();
		image.clear();
		decodeTwoSteps("C:/Users/aidos/Downloads/800Justine2.png");
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

	auto imagePixels = HelperMethods::ConvertToPixels(image);

	auto chunkList = HelperMethods::GenerateChunks(imagePixels);

	unsigned int i = 0;
	for (auto iter = chunkList.begin(); iter != chunkList.end(); iter++)
	{
		(*iter).Draw();
	}
	temp = 'k';
}