#include <stdio.h>
#include <stdlib.h>

int main ()
{	
	// Declaracao

	int i = 0;
	int j = 0;
	int pontos = 0;
	char r,s,t,l,x;
	char esp;
	int pos_carta1i = 0, pos_carta1j = 0, pos_carta2i = 0, pos_carta2j = 0;
	
	//inicializando
	char cartas[4][2] = { {'r','s'},
						  {'s','r'},
						  {'t', 'l'},
						  {'t','l'} };
	
	char cartasx [4][2] ={ {'x','x'},
						   {'x','x'},
						   {'x', 'x'},
						   {'x','x'} };	
	
	
	//inicializando matrix das cartas
	for(i= 0;i<4;i++){
		for(j=0;j<2;j++){
			printf("%c",cartas[i][j]);
		}
		printf("\n");
	}
	printf("Aperte espaco para limpar a tela\n");
	esp = getch();
	system("cls");
	
	while (pontos < 4){
	
		printf("Digite um valor para linha da primeira carta que voce quer revelar\n");
		scanf("%d",&pos_carta1i);
		printf("Digite o valor da coluna da primeira carta que voce quer revelar\n");
		scanf("%d",&pos_carta1j);
		printf("Digite um valor para linha da segunda carta que voce quer revelar\n");
		scanf("%d",&pos_carta2i);
		printf("Digite o valor da coluna da segunda carta que voce quer revelar\n");
		scanf("%d",&pos_carta2j);

		if (pos_carta1i > 3 || pos_carta1j > 3 || pos_carta2i > 3 || pos_carta2j > 3){ 
			printf(" Posicao invalida\n");
			continue; // caso o usario digite 1 valor > 3 nao vai caber na matriz em outras palavras n tem cartas suficientes para posicao dada
		}
		char carta1 = cartas[pos_carta1i][pos_carta1j]; // carta1 vai receber uma das letras da matriz o mesmo para carta2
		char carta2 = cartas[pos_carta2i][pos_carta2j];
		
		if (carta1 == carta2){
			printf("voce acertou\n");

			cartasx[pos_carta1i][pos_carta1j] = cartas[pos_carta1i][pos_carta1j]; // troco valor o x pelo valor da carta1 e carta2 escolhida pelo user quando ele acertou
			cartasx[pos_carta2i][pos_carta2j] = cartas[pos_carta2i][pos_carta2j];


			//printando a matrix com as cartas acertadas 
			for(i=0; i<4; i++){
				for(j=0; j<2; j++){
					printf("%c",cartasx[i][j]);
				}
				printf("\n");
			}
			pontos++; // incrementar pontos
			printf("Voce fez %d pontos\n", pontos);
			printf("Aperte espaco para limpar a tela\n");
			esp = getch();
			system("cls");
		}
		else {
				printf("Voce errou jogue novamente\n");
				continue;
			}
		
		if (pontos == 4){
			system("cls"); // limpar a tela
			printf("Voce acabou o jogo\n");	
			break;
		}
	}
	return 0;
}
	
