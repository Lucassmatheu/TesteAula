#include <iostream>
#include "Aulas.h"

void detemperatura() 
{
	float temperaturaCelsius, temperaturaFahrenheit;

	std::cout << "Digite a temperatura em Celsius: ";
	std::cin >> temperaturaCelsius;
	temperaturaFahrenheit = (temperaturaCelsius * 9 / 5) + 32;
	std::cout << "A temperatura em Fahrenheit é: " << temperaturaFahrenheit << "°F" << std::endl;
	std::cout << "Digite a temperatura em Fahrenheit: ";
	std::cin >> temperaturaFahrenheit;
	temperaturaCelsius = (temperaturaFahrenheit - 32) * 5 / 9;

	std::cout << "A temperatura em Celsius é: " << temperaturaCelsius << "°C" << std::endl;
	std::cout << "A temperatura em Fahrenheit é: " << temperaturaFahrenheit << "°F" << std::endl;

	

}