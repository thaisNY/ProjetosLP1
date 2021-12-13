#include <stdio.h>

int main()
{
   int num = 0;
   int countCand1 = 0;
   int countCand2 = 0;
   int countBranco = 0;
   int countNulo = 0;
   while(1){
       printf("Bem vindo ao sistema de votacao\n");
       printf("Digite 0 para encerar a votacao\n");
       printf("Digite 1 para votar no candidado 1\n");
       printf("Digite 2 para votar no candidato 2\n");
       printf("Digite 3 para votar em branco\n");
       printf("Digite 4 para votar nulo\n");
       scanf("%d",&num);
       if (num == 0)
           break;
       
       else if (num == 1)
             countCand1++;
        else if (num == 2)
            countCand2++;
        else if (num == 3)
            countBranco++;
        else if (num == 4)
             countNulo++;
        else{
            printf("Voce digitou um valor invalido\n Tente novamente\n");
            continue;
        }
    }
    printf("O numeros de voto no candidato 1 foi %d\n",countCand1);
    printf("O numero de votos no candidato 2 foi %d\n",countCand2);
    printf("O numero de votos em Branco foi %d\n",countBranco);
    printf("O numero de votos nulos foi %d\n",countNulo);
    printf("Ao total a votacao teve %d votos\n",countCand1 + countCand2 + countBranco + countNulo);
    return 0;
}