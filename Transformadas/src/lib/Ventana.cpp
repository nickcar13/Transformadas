#include "Ventana.h"
#include "Colores.h"
#include <GL/glut.h>

Colores colorVentana;

void vacia() {}

Ventana::Ventana(int arg, char argv[])
{
	glutInit(&arg, &argv);
}

Ventana::~Ventana()
{
}

void Ventana::bufferSimple(char const *name, void (*funcion)(), float width, float height)
{
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	setHeight(height);
	setWidth(width);
	glutInitWindowSize(WIDTH, HEIGHT);
	glutInitWindowPosition(posX, posy);
	glutCreateWindow(name);
	glutDisplayFunc(funcion);
}

void Ventana::bufferSimple(char const* name, void(*funcion)())
{
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowSize(WIDTH, HEIGHT);
	glutInitWindowPosition(posX, posy);
	glutCreateWindow(name);
	glutDisplayFunc(funcion);
	
}

void Ventana::bufferSimple(char const* name)
{
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowSize(WIDTH, HEIGHT);
	glutInitWindowPosition(posX, posy);
	glutCreateWindow(name);
	glutDisplayFunc(vacia);
}

void Ventana::vistaOrto(int w, int h)
{
	glOrtho(-w / 2, w / 2, -h / 2, h / 2, -1, 1);
}



void Ventana::ciclo()
{
	glutMainLoop();
}

void Ventana::configVentana(float red, float green, float blue)
{
	float *ColorFondo = colorVentana.RGBToFloat(red, green, blue);
	glClearColor(*ColorFondo, *(ColorFondo + 1), *(ColorFondo + 2), 1);
	
	glClear(GL_COLOR_BUFFER_BIT);
	glFlush();
}



float Ventana::getWidth()
{
	return WIDTH;
}

float Ventana::getHeight()
{
	return HEIGHT;
}

void Ventana::setWidth(float width)
{
	WIDTH = width;
}

void Ventana::setHeight(float height)
{
	HEIGHT = height;
}
