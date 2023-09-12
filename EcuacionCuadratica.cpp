//Ejemplos:
//Soluciones imaginarias: 8, 7, 6
//Una Solucion: 36, -60, 25
//Dos soluciones raiz exacta: 1, 4, -5
//Dos soluciones raiz inexacta: 1, 4, -2

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <cmath>
float a, b, c, discriminante;

void valor_a(){
	scanf("%f", &a);
	if (a == 0){
		printf("La variable a no puede ser cero\n\n");
		printf("Ingresa otro valor para a: ");
		valor_a();
	}
	else{
		system("cls");
		printf("Ecuacion cuadratica\n");
		printf("%gx^2 + bx + c = 0\n\n", a);
		return;
	}
}

void valor_b(){
	scanf("%f", &b);
	system("cls");
	printf("Ecuacion cuadratica\n");
	printf("%gx^2 + %gx + c = 0\n\n", a, b);
}

void valor_c(){
	scanf("%f", &c);
	system("cls");
	printf("Ecuacion cuadratica\n");
	printf("%gx^2 + %gx + %g = 0\n\n", a, b, c);
}

void sin_soluciones_reales(){
	printf("La ecuacion no tiene soluciones reales\n\n");
	printf("Soluciones en fraccion:\n\n");
	printf("x1 = %g/%g + i(sqrt(%g)/%g)\n", -b, 2 * a, abs(discriminante), 2 * a);
	printf("x2 = %g/%g - i(sqrt(%g)/%g)\n\n", -b, 2 * a, abs(discriminante), 2 * a);
	printf("Soluciones en decimal:\n\n");
	printf("x1 = %g + %gi\n", -b / (2 * a), sqrt(abs(discriminante)) / (2 * a));
	printf("x2 = %g - %gi", -b / (2 * a), sqrt(abs(discriminante)) / (2 * a));
}

void una_solucion(){
	printf("La ecuacion tiene una sola solucion\n\n");
	printf("Solucion en fraccion:\n\nx = %g / %g\n\n", -b, 2 * a);
	printf("Solucion en decimal:\n\nx = %g", -b / (2 * a));
}

bool raiz_exacta(){
	if (sqrt(discriminante) == (int)sqrt(discriminante)){
		return true;
	}
	else{
		return false;
	}
}

void dos_soluciones(){
	printf("Soluciones:\n\n");
	printf("Soluciones en fraccion:\n\n");
	if(raiz_exacta()){
		printf("x1 = %g / %g\n", -b + sqrt(discriminante), 2 * a);
		printf("x2 = %g / %g\n\n", -b - sqrt(discriminante), 2 * a);
	}
	else{
		printf("x1 = (%g + sqrt(%g)) / %g\n", -b, discriminante, 2 * a);
		printf("x2 = (%g - sqrt(%g)) / %g\n\n", -b, discriminante, 2 * a);
	}
	printf("Soluciones en decimal:\n\n");
	printf("x1 = %g\n", (-b + sqrt(discriminante)) / (2 * a));
	printf("x2 = %g", (-b - sqrt(discriminante)) / (2 * a));
}

void calcular_resultado(){
	printf(" a = %g \n b = %g \n c = %g \n", a, b, c);
	printf(" x = (-b +- sqrt(b^2 - 4ac)) / 2a \n sqrt: raiz cuadrada\n\n");
	printf("El valor de x es:\n");
	printf("x = (-%g +- sqrt(%g^2 - 4 * %g * %g)) / (2 * %g) \n", b, b, a, c, a);
	discriminante = pow(b, 2) - 4 * a * c;
	printf("x = (%g +- sqrt(%g) / %g)\n\n", -b, discriminante, 2 * a);
	if (discriminante < 0){
		sin_soluciones_reales();
		return;
	}
	else if (discriminante == 0){
		una_solucion();
		return;
	}
	else dos_soluciones();
}

int main(){
	printf("Ecuacion cuadratica\n");
	printf("ax^2 + bx + c = 0\n\n");
	printf("Ingresa valor de a: ");
	valor_a();
	printf("Ingresa valor de b: ");
	valor_b();
	printf("Ingresa valor de c: ");
	valor_c();
	calcular_resultado();
	getch();
	system("cls");
	main();
	return 0;
}
