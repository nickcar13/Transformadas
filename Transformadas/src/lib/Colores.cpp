#include "Colores.h"

Colores::Colores()
{
}

float* Colores::RGBToFloat(float red, float green, float blue)
{
	red = red / 255;
	green = green / 255;
	blue = blue / 255;

	colors[0] = red;
	colors[1] = green;
	colors[2] = blue;

	return (colors);
}
