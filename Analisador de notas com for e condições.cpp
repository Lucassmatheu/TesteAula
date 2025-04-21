#include <iostream>
#include <iomanip>

static void AnalisadorNotas()
{
	float boas = 0, regulares = 0, ruins = 0, limite, nota;

	std::cout << "Digite o limite de notas: ";
	std::cin >> limite;

	for (float i= 1; i < limite; i++) 
	{
		std::cout << "DIGITE A  NOTA " << i << ": ";	
		std::cin >> nota;

		if (nota >= 7)
		{
			boas++;
			std::cout << "Nota boa\n";
		}
		else if (nota >= 5)
		{
			regulares++;
			std::cout << "Nota regular\n";
		}
		else
		{
			ruins++;
			std::cout << "Nota ruim\n";
		}



	}
	std::cout << "Total de notas boas: " << boas << "\n";
	std::cout << "Total de notas regulares: " << regulares << "\n";
	std::cout << "Total de notas ruins: " << ruins << "\n";
	std::cout << "Total de notas: " << boas + regulares + ruins << "\n";

}