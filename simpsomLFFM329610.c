#include<stdio.h>
#include<conio.h>
#include<math.h>
#define EULER 2.718281828459

double simpson(double a, double b);
double f(double x);
double f2(double a, double h, int i);
double f4(double x);
double error(double a, double b, double h,double xProm);

int main(int argc, char **args){

	double a=0.0, b=0.0, res=0.0;

	printf("\n Ingresa el valor de a: ");
	scanf("%lf", &a);
	printf("\n Ingresa el valor de b: ");
	scanf("%lf", &b);

	res = simpson(a,b);

	printf("\n La aproximacion de la integral es: %lf", res);

}

double simpson(double a, double b){
	int n = 6;
	double h = (b-a)/n;
	double x = (b-a)/2;
    double xProm = (a+b)/2;

	double aprox = (h/3) * (f2(a,h,0) + 4*f2(a,h,1) + 2*f2(a,h,2) + 4*f2(a,h,3)
                   + 2*f2(a,h,4) + 4*f2(a,h,5) + f2(a,h,6))+ error(a,b,h,xProm);
	return aprox;
}

double error(double a, double b, double h,double xProm){
	return -(b-a)*((pow(h,4))/(180))*f4(xProm);
}

double f4(double x){
	double h = 0.01;
	return (f(x+2*h) - 4*f(x+h) + 6*f(x) - 4*f(x-h) + f(x-2*h)) / pow(h,4);
}

double f(double x){
	return pow(EULER, x)*pow(x, 2);
}

double f2(double a, double h, int i){
    double x = a + (i*h);
	return pow(EULER, x)*pow(x, 2);
}
