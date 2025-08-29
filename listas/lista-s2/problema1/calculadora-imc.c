#include <stdio.h>
#include <math.h>

int main() {
	float peso;
	float altura;
	float imc;

	printf("Digite seu peso em KG: ");
	scanf("%f", &peso);

	printf("Digite sua altura: ");
	scanf("%f", &altura);

	imc = peso / (pow(altura, 2));

	printf("Seu IMC é: %.02f\n", imc);
	return 0;
}
