#include <stdio.h>

int main(){

	float n1, n2, n3;
	float media;
	
	printf("Digite a nota 1: ");
	scanf("%f", &n1);

	printf("Digite a nota 2: ");
	scanf("%f", &n2);

	printf("Digite a nota 2: ");
	scanf("%f", &n3);

	media = (n1 + n2 + n3) / 3.0;
	if(media >= 7.0){
		printf("Aprovado \n");
	}
	else if(media < 4){
		printf("Reprovado\n");
	}else{
		printf("Você está em Recuperação\n");

		float notaNecessaria = 10.0 - media;

		if(notaNecessaria > 10){
			printf("O aluno não tem como ser aprovado, pois precisa de %.1f pontos, e a nota máxima é de 10.0 pontos\n", notaNecessaria);			
		}
		else{
			printf("O aluno precisa de pelo menos %.1f pontos na prova final para passar\n", notaNecessaria);
		}		
	}
}
