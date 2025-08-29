#include <stdio.h>

int main(){
	int numero1, numero2;
	
	printf("Digite o primeiro número: ");
	scanf("%d", &numero1);

	printf("Digite o segundo número: ");
	scanf("%d", &numero2);
	int soma = numero1 + numero2;
	int diferenca = numero1 - numero2;
	int produto = numero1 * numero2;
	float divReal = (float) numero1 / numero2;
	int resto = numero1 % numero2;
	float media = (float)(numero1 + numero2) / 2.0;

	printf("SOMA: %d\nDIFERENÇA: %d\nProduto: %d\nDIVISÃO REAL: %.02f\nRESTO DA DIVISÃO INTEIRA: %d\nMÉDIA ARITMÉTICA: %.02f\n", soma, diferenca, produto, divReal, resto, media);
	return 0;
}
