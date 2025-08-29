#include <stdio.h>

int main(){
	float tempCelsius;

	printf("Digite a temperatura em Celsius: ");
	scanf("%f", &tempCelsius);
	
	float tempFahrenheit = (tempCelsius * 9 / 5) + 32;
	float tempKelvin = tempCelsius + 273.15;

	printf("Abaixo a conversão de %.01f° Celsius para Fahrenheit e Kelvin\nFahrenheit: %.01f\nKelvin: %.01f\n", tempCelsius, tempFahrenheit, tempKelvin);
	return 0;
}
