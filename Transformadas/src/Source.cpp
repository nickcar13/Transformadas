#define _USE_MATH_DEFINES
#include <iostream>
#include <math.h>
//#include <cmath.h>
#include <GL/glut.h>

#include "lib/Ventana.h"
#include "lib/Colores.h"

#define nodes 168

//variables de transformacion inicial
double movX = 3, movY = 2, trasla = 0;
double esca = 2.0;
double angulo = 0.0;


int width = 680;
int height = 680;

double M[nodes][3] = { {290, 524,1},
{285, 541,1},
{296, 577,1},
{318, 562,1},
{326, 547,1},
{334, 555,1},
{346, 573,1},
{355, 545,1},
{351, 524,1},
{355, 523,1},
{400, 480,1},
{409, 449,1},
{460, 420,1},
{472, 414,1},
{474, 402,1},
{459, 391,1},
{457, 383,1},
{441, 372,1},
{378, 383,1},
{345, 350,1},
{346, 305,1},
{367, 249,1},
{370, 182,1},
{354, 197,1},
{324, 135,1},
{300, 144,1},
{277, 96, 1},
{260, 180,1},
{232, 178,1},
{200, 260,1},
{188, 234,1},
{164, 334,1},
{152, 331,1},
{159, 393,1},
{144, 402,1},
{177, 449,1},
{225, 483,1},
{211, 492,1},
{290, 524,1} };
//matrices auxiliares
double M1[nodes][3];
double M2[nodes][3];

//matrices de transformacion
double MaTr[3][3] = { {1,0,0},{0,1,0},{movX, movY, 1} };
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
	std::cout << m[0][0] << " ";
	std::cout << m[0][1] << " ";
	std::cout << m[0][2] << std::endl;
	std::cout << m[1][0] << " ";
	std::cout << m[1][1] << " ";
	std::cout << m[1][2] << std::endl;
	std::cout << m[2][0] << " ";
	std::cout << m[2][1] << " ";
	std::cout << m[2][2] << std::endl;
	for (int j = 0; j < (nodes - 1); j++)
	{
		for (int i = 0; i < 3; i++)
		{
			M1[j][i] = M2[j][0] * (m[0][i]) + M2[j][1] * m[1][i] + M2[j][2] * m[2][i];
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

void Traslacion(char direccion) {
	switch (direccion)
	{
	case 'a':
		movX = -50;
		movY = 0;
		MaTr[2][0] = movX;
		MaTr[2][1] = movY;
		Trasf(MaTr);
		Redibujar();
		break;
	case 'w':
		movX = 0;
		movY = 50;
		MaTr[2][0] = movX;
		MaTr[2][1] = movY;
		Trasf(MaTr);
		Redibujar();
		break;
	case 's':
		movX = 0;
		movY = -50;
		MaTr[2][0] = movX;
		MaTr[2][1] = movY;
		Trasf(MaTr);
		Redibujar();
		break;
	case 'd':
		movX = 50;
		movY = 0;
		MaTr[2][0] = movX;
		MaTr[2][1] = movY;
		Trasf(MaTr);
		Redibujar();
		break;
	default:
		break;
	}
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
	case 'a':
		Traslacion('a');
		break;
	case 'w':
		Traslacion('w');
		break;
	case 's':
		Traslacion('s');
		break;
	case 'd':
		Traslacion('d');
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
	Matrices();
	glutKeyboardFunc(Teclado);

	ventana1.ciclo();
	return 0;
}