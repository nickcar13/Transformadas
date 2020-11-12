#pragma once
class Ventana
{
public:
	Ventana(int arg, char argv[]);
	~Ventana();
	void bufferSimple(char const* name, void (*funcion)(), float width, float heigh);
	void bufferSimple(char const* name, void (*funcion)());
	void bufferSimple(char const* name); //Llama una funcion vacia
	void vistaOrto(int w, int h);
	

	//TODO void bufferDoble();
	void ciclo();
	void configVentana(float red, float green, float blue);
	float getWidth();
	float getHeight();
	void setWidth(float width);
	void setHeight(float height);
private:
	float WIDTH = 1000, HEIGHT = 600;
	int RESOLUTIONX = 1366, RESOLUTIONY = 768;
	float posX = ((RESOLUTIONX / 2) - (WIDTH / 2));
	float posy = ((RESOLUTIONY / 2) - (HEIGHT / 2) - 40);
};

