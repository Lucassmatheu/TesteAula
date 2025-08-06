#include <iostream>
#include "Aulas.h"

/*Protótiposdde funções
Recebe um array por referência atraves de um ponteiro ou seja a variavel 
*Array irá receber um endereço de memoria que será enviado para etá função */ 
void DuplicaVetor(int* Array, int tamanho);

/* Está função também recebe um array via Poteiro
* mas tambem retorna um ponteiro que neste caso de ser 
* um ponteiro para int. logo será capaz de devover um ponteio
* para int ou seja um endereço de memória que será o endereço do
* array invertido. Na realidade vai retornar o endereço do primeiro elemento
* do array.
* 
*/
int *InvertdoVetor(int* Array, int tamanho);

/*Irar mostrar vetor recebido via ponteiro */
void MostrarVetor(int* Array, int tamanho);

// Função que não recebe nada e não retorna nada
void ArrayInvertido() 
{
	int numeros[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int tamanho = sizeof(numeros) / sizeof(int); // Calcula o tamanho do array
	/*Chamar a função e passa o vetor numeos para ela 
	o endereço do primeiro eleemnto do vetor será enviado para arrays */
	MostrarVetor(numeros, tamanho);
	DuplicaVetor(numeros, tamanho);
	MostrarVetor(numeros, tamanho);
	/* Aqui mostra o vetor e recebe o retorno da função InvertdoVetor
		e este retorno será o endereço do primeiro elemento do vetor invertido
	*/
		
	MostrarVetor(InvertdoVetor(numeros, tamanho), tamanho);



}

void DuplicaVetor(int* Array, int tamanho)
{
	/*Função percorre o vetor e duplica os valores  do vetor */
	for (int i = 0; i < tamanho; i++) 
	{
		Array[i] = 2 * Array[i]; // Duplicando cada elemento do vetor
	}
}

/*esta função receber um array( na realidade receber o endereço do primeiro elemnto do array)
e devolve um array invertido*/
int* InvertdoVetor(int* Array, int tamanho)
{
	/*/ para inverter o vetor iremos usar um vetor auxiliar
		ele precisa ser statico  pois  senão ao sair da função ele iria 
		desaparecer da memoria, e não conseguiria ser enviado como retorno da funçao 
		ou seja o endereço do primeiro elemento do vetor auxiliar seria perdido
		na memória.
		Por isso usamos o static, para que o vetor auxiliar permaneça na memória
		*/
	int j = 0;
	static int vetorInvertido[10]; // Array estático para armazenar o vetor invertido 

	/* Para conseguir um vetor com valoires invertidos, precisamos percorrer o vetor original */
	    for (int i = tamanho - 1; i >= 0; i--)
        {
			/* j vai de 0 até 9, ou seja, 
			 o vetor invertido vai de
				vetorInvertido[j]0 a 9 = Array [i] vai de 9 até 0
				vetorInvertido[0] = Array[9]
				vetorInvertido[i] = Array[8]
				vetorInvertido[2] = Array[7]
				vetorInvertido[3] = Array[6]
				vetorInvertido[4] = Array[5]
				vetorInvertido[5] = Array[4]
				vetorInvertido[6] = Array[3]
				vetorInvertido[7] = Array[2]
				vetorInvertido[8] = Array[1]
				vetorInvertido[9] = Array[0]*/
            vetorInvertido[j] = Array[i];
            j++;
        }
      /* Outra forma de fazer o mesmo
	   * for (int i = 0; i < tamanho; i++)
	   * {
	   *    vetorInvertido[i] = Array[tamanho - 1 - i];
	   * }
	   */

	return &vetorInvertido[0]; // Retorna o endereço do primeiro elemento do vetor invertido
	
}

void MostrarVetor(int* Array, int tamanho)
{
	std::cout << "Vetor: ";
	for (int i = 0; i < tamanho; i++) 
	{
		std::cout << Array[i] << " "; // Mostra cada elemento do vetor
	}

	std::cout << std::endl;
	
}
void menuArray(){
	std::cout << "===== MENU =====\n";
	std::cout << "[1] Array Invertido\n";
	std::cout << "[2] Sair\n";
	std::cout << "Escolha uma opção: ";
	int opcao;
	std::cin >> opcao;
	switch (opcao) 
	{
	case 1:
		ArrayInvertido();
		break;
	case 2:
		std::cout << "Saindo...\n";
		break;
	default:
		std::cout << "Opção inválida!\n";
		break;
	}
}
