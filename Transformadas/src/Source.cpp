#define _USE_MATH_DEFINES
#include <iostream>
#include <math.h>
//#include <cmath.h>
#include <GL/glut.h>

#include "lib/Ventana.h"
#include "lib/Colores.h"

#define nodes 168

//variables de transformacion inicial
double movX = 0, movY = 0, trasla = 0;
double esca = 1.0, escala = 0.5;
double angulo = 0.0;


int width = 680;
int height = 680;

double M[nodes][3] = { {290, 524}, {285, 541}, {296, 577}, {318, 562}, {326, 547}, {334, 555}, {346, 573}, {355, 545}, {351, 524}, {355, 523}, {400, 480}, {409, 449}, {460, 420}, {472, 414}, {474, 402}, {459, 391}, {457, 383}, {441, 372}, {378, 383}, {345, 350}, {346, 305}, {367, 249}, {370, 182}, {354, 197}, {324, 135}, {300, 144}, {277, 96}, {260, 180}, {232, 178}, {200, 260}, {188, 234}, {164, 334}, {152, 331}, {159, 393}, {144, 402}, {177, 449}, {225, 483}, {211, 492},{290, 524} };

//matrices auxiliares
double M1[nodes][3];
double M2[nodes][3];

//matrices de transformacion
double MaTr[3][3] = { {1,0,movX},{0,1,movY},{0, 0, 1} };
double MaEs[3][3] = { {esca,0,0},{0,esca,0},{0,0,1} };
double MaRo[3][3] = { {cos(angulo),-sin(angulo), 1},{sin(angulo),cos(angulo),1 },{0,0,1} };



Colores mainColores;

void PintarPoligono()
{
	glBegin(GL_POLYGON);
	glPointSize(1);
	glColor3fv(mainColores.RGBToFloat(114, 9, 183));
	for (int i = 0; i < nodes - 1; i++)
	{
		glVertex2d(M1[i][0], M1[i][1]);
	}
	glEnd();
	glFlush();
}

void Display() {
	PintarPoligono();
}

void Matrices()
{
	for (int i = 0; i < (nodes - 1); i++)
	{
		M1[i][0] = M[i][0];
		M1[i][1] = M[i][1];
		M1[i][2] = M[i][2];
		M2[i][0] = M[i][0];
		M2[i][1] = M[i][1];
		M2[i][2] = M[i][2];
	}
}

void Trasf(double m[3][3])
{
	for (int j = 0; j < (nodes - 1); j++)
	{
		for (int i = 0; i < 3; i++)
		{
			M1[j][i] = M2[j][0] * m[0][i] + M2[j][1] * m[1][i] + M2[j][2] * m[2][i];
		}
	}
	for (int j = 0; j < (nodes - 1); j++)
	{
		for (int i = 0; i < 3; i++)
		{
			M2[j][i] = M1[j][i];
		}
	}
}

void Redibujar() {
	glClear(GL_COLOR_BUFFER_BIT);
	PintarPoligono();
}

void Traslacion() {
	movX = 90;
	movY = 90;
	MaTr[0][2] = movX;
	MaTr[1][2] = movY;
	Trasf(MaTr);
	Redibujar();
}

void Rotar() {
	for (int i = 0; i < 11; i++)
	{
		angulo = (15 * M_PI) / 180;
		MaRo[0][0] = cos(angulo);
		MaRo[0][1] = -sin(angulo);
		MaRo[1][0] = sin(angulo);
		MaRo[1][1] = cos(angulo);
	}
	Trasf(MaRo);
	Redibujar();
}

void Teclado(unsigned char k, int x, int y) {
	if (k == 27) exit(0);
	switch (k)
	{
	case 't':
		Traslacion();
		break;
	case 'r':
		Rotar();
		break;

	case '+':
		esca = 1.1;
		MaEs[0][0] = esca;
		MaEs[1][1] = esca;
		Trasf(MaEs);
		Redibujar();
		break;
	case '-':
		esca = 0.9;
		MaEs[0][0] = esca;
		MaEs[1][1] = esca;
		Trasf(MaEs);
		Redibujar();
		break;
	default:
		break;
	}
}



int main(int arg, char* argv[]) {
	Ventana ventana1(arg, *argv); //Objeto encargado de la ventana

	ventana1.bufferSimple("Transformadas 2D", Display, width, height); //creacion de la ventana
	ventana1.configVentana(13, 6, 40); //Configuracion del color dela ventana
	ventana1.vistaOrto(1200, 1200);

	std::cout << M_PI;
	Matrices();
	glutKeyboardFunc(Teclado);

	ventana1.ciclo();
	return 0;
}