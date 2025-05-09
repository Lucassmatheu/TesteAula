#include <iostream>
#include "Aulas.h" 

void Sistema() 
{
   std::string usuario, resultado;
   int senha, menu{}, idade, numero, media, nota1, nota2, nota3;
   bool acesso = false;
   std::cout << "Digite o seu usuario: ";
   std::cin >> usuario;
   std::cout << "Digite a sua senha: ";
   std::cin >> senha;

   if (usuario == "Lucas" && senha >= 1000)
   {
       acesso = true;
       std::cout << "Acesso permitido\n";
       while (true)
       {
           std::cout << "\n[1] Verificar se o usuário é maior de idade\n[2] Calcular média\n[3] Contar de 0 até N\n[4] Sair\n";
           std::cin >> menu;

           switch (menu)
           {
           case 1:
               std::cout << "Digite a sua idade: ";
               std::cin >> idade;
               resultado = (idade >= 18) ? "Maior de idade" : "Menor de idade";
               std::cout << "Resultado: " << resultado << std::endl;
               break;
           case 2:
               std::cout << "Digite a nota 1: ";
               std::cin >> nota1;
               std::cout << "Digite a nota 2: ";
               std::cin >> nota2;
               std::cout << "Digite a nota 3: ";
               std::cin >> nota3;
               media = (nota1 + nota2 + nota3) / 3;
               std::cout << "A média é: " << media << std::endl;
               break;
           case 3:
               std::cout << "Digite um número: ";
               std::cin >> numero;
               for (int i = 0; i <= numero; i++)
               {
                   std::cout << i << std::endl;
               }
               break;
           case 4:
               std::cout << "Saindo do sistema...\n";
               return; 
           default:
               std::cout << "Opção inválida. Tente novamente.\n";
               break;
           }
       }
   }
   else
   {
       std::cout << "Acesso negado\n";
   }
}

