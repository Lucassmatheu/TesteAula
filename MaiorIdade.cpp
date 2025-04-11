#include <iostream>
#include "Aulas.H"

void MaiorIdade() {
	int idade;
	std::cout << "Digite a sua idade: ";
	std::cin >> idade;
	
	if (!(idade < 18)) {
		std::cout << "Voce e maior de idade." << std::endl;
	}
	else {
		std::cout << "Voce e menor de idade." << std::endl;
	}
	system("pause");
}	