#include "Util.h"

#include <random>
#include <sstream>
#include <string>

using namespace std;

const int util::generateRandomNumber(int min, int max)
{

	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_real_distribution<double> dist(min, max);

	return (int)dist(mt);
}

const float util::generateRandomNumber(float min, float max)
{

	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_real_distribution<double> dist(min, max);

	return (float)dist(mt);
}

const SDL_Color util::generateRandomColor()
{
	Uint8 red, green, blue, alpha;

	red = generateRandomNumber(0, 255);
	green = generateRandomNumber(0, 255);
	blue = generateRandomNumber(0, 255);
	SDL_Color color;
	color.a = 0;
	color.r = red;
	color.g = green;
	color.b = blue;

	return color;

}

const float util::radiansToDegrees(float angleInRadians)
{
	float angle = angleInRadians / M_PI * 180;
	return angle;

}

const float util::degreesToRadians(float angleInDegrees)
{
	float angle = angleInDegrees * 0.0174532925199432957f;
	return angle;

}

const string util::floatToString(float x, int decDigits)
{
	stringstream ss;
	ss << fixed;
	ss.precision(decDigits); // set # places after decimal
	ss << x;
	return ss.str();
}





