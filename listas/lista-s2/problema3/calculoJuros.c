#include <stdio.h>
#include <math.h>

int main(){
	float capitalInicial;
	float taxaJuros;
	int anos;

	printf("Digite o capital inicial em R$: ");
	scanf("%f", &capitalInicial);

	printf("Digite a taxa de juros: ");
	scanf("%f", &taxaJuros);

	printf("Digite a quantidade de tempo em anos: ");
	scanf("%d", &anos);

	float montante = capitalInicial * pow((1 + taxaJuros/100), anos);

	printf("Montante: %.02fR$\n", montante);	
	return 0;
}

