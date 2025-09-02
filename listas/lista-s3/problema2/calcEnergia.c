#include <stdio.h>
#include <ctype.h>

int main(){
	char tipoConsumidor;
	float consumo;
	
	printf("Bem vindo a calculadora da conta de energia!\n\n"
	"Residencial: R$0,60 por kWh\n"
	"Comercial: R$0,48 por kWh\n"
	"Industrial: R$1,29 por kWh\n");

	printf("Que tipo de consumidor você é: R, C ou I? ");
	scanf("%c", &tipoConsumidor);
	tipoConsumidor = toupper(tipoConsumidor);
	
	printf("Qual foi o seu consumo? ");
	scanf("%f", &consumo);

	if(tipoConsumidor == 'R'){
		double valor = (consumo*0.60);
		printf("\nValor da conta para consumidor RESIDENCIAL:\n");
		printf("R$15 - valor fixo\n");
		printf("R$%.2f - valor por %.2fkWh de consumo ao preço de R$0,60 por kWh\n", valor, consumo);
		printf("Valor Total: R$%.2f\n", valor + 15.0);
	}
	else if(tipoConsumidor == 'C'){
		double valor = (consumo*0.48);
		printf("\nValor da conta para consumidor COMERCIAL:\n");
		printf("R$15 - valor fixo\n");
		printf("R$%.2f - valor por %.2fkWh de consumo ao preço de R$0,48 por kWh\n", valor, consumo);
		printf("Valor Total: R$%.2f\n", valor + 15.0);
	}
	else if(tipoConsumidor == 'I'){
		double valor = (consumo*1.29);
		printf("\nValor da conta para consumidor INDUSTRIAL:\n");
		printf("R$15 - valor fixo\n");
		printf("R$%.2f - valor por %.2fkWh de consumo ao preço de R$1,29 por kWh\n", valor, consumo);
		printf("Valor Total: R$%.2f\n", valor + 15.0);
	}else{
		printf("TIPO DE CONSUMIDOR INVÁLIDO!\n");
	}
}
