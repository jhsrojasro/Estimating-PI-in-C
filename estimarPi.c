/*
	Estimar el valor de PI a través del producto de
	Wallis, de una parte y de Ramanujan de otra.
	Hacer un estudio comparativo en la velocidad de
	convergencia de ambos métodos. Su
	implementación debe realizarse en lenguaje C
	(Instalación estándar).
*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

int factorial(int x){
	if(x == 0) return 1;
	else return factorial(x-1) * x;
}

int main(){
	double e[3] = {1e-5, 1e-7, 1e-9};
	int d[3] = {4,6,8};
	double PI = M_PI;

	for(int i=0; i<3; i++){
		//Metodo 1:Producto de Wallis
		double pi = 2;
		clock_t start, end;
		start = clock();
		for(int n = 1; fabs(pi - PI) > e[i]; n++){
			pi = pi * (2*n / (double)(2*n - 1)) * (2*n / (double)(2 * n+1)); 
		}
		end = clock();
		double time = ((double)(end-start)) / CLOCKS_PER_SEC;
		printf("Metodo 1(%d decimales): PI: %.15f Tiempo: %f segundos\n", d[i], pi, time);
		
		//Metodo 2: serie de Ramanujan-Sato
		start = clock();
		double K = 2*sqrt(2)/9801, sum = 0;
		pi = K/(K * K);
		for(int k = 0; fabs(pi - PI) > e[i]; k++){
			sum  = sum + (factorial(4*k)*(1103+26390*k) / (double)(pow(factorial(k), 4) * pow(396, 4*k)));
			pi = sum * K / (sum * K * sum * K);
		}
		end = clock();
		time = ((double)(end-start)) / CLOCKS_PER_SEC;
		printf("Metodo 2(%d decimales): PI: %.15f Tiempo: %f segundos\n", d[i], pi, time);
	}
	
	return 0;
}