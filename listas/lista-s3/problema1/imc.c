#include <stdio.h>
#include <math.h>

int main(){
	float peso;
	float altura;
	float imc;
		
	printf("Digite seu peso em KG: ");
	scanf("%f", &peso);

	printf("Digite sua altura: ");
	scanf("%f", &altura);

	imc = peso / pow(altura, 2);
	printf("imc:%.2f\n", imc);

	if(imc < 18.5){
		printf("Abaixo do peso\n");
	}
	else if(imc >= 18.5 && imc < 25){
		printf("Peso normal\n");
	}
	else if(imc >= 25 && imc < 30){
		printf("Sobrepeso\n");
	}
	else{
		printf("Obesidade\n");
	}
}
