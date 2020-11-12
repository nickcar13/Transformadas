#pragma once
class Colores
{
public:
	Colores();
	float* RGBToFloat(float red, float green, float blue);
private:
	float colors[3] = {};
};

