#include <iostream>
#include <stdlib.h>

int main(){
	
	char palavra[30], letra[1], secreta[30], usadas[30];
	int tam, i, chances, acertos;
	bool acerto;

	chances = 6;
	tam = 0;
	i = 0;
	acertos = 0;

	std::cout << "JOGO DA FORCA!!\n";
	std::cout << "Peça ao seu amigo que tape os olhos e então digite a palavra secreta: ";
	std::cin >> palavra;
	system("cls");

	while(palavra[i] != '\0'){
		i++;
		tam++;
	}

	for(i=0;i<30;i++){
		secreta[i] = '-';
	}

	while((chances > 0)&&(acertos < tam)){
		acerto = false;

		std::cout << "Chances restantes: " << chances << std::endl;
		std::cout << "Palavra secreta: ";
		for(i=0; i<tam; i++){
			std::cout << secreta[i];
		}
		std::cout << "\n\nDigite uma letra: ";
		std::cin >> letra[0];
		for(i=0; i<tam; i++){
			if(palavra[i]==letra[0]){
				if(usadas[i]!=letra[0]){
					acerto = true;
					secreta[i] = palavra[i];
					usadas[i] = palavra[i];
					acertos++;
				}
			}
		}
		if(!acerto){
			chances--;
		}
		system("cls");
	}

	if(acertos==tam){
		std::cout << "Parabéns, você venceu!" << std::endl;
	}else if(chances == 0){
		std::cout << "Você foi enforcado! :( " << std::endl;
	}

	return 0;
}