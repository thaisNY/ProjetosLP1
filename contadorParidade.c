#include <stdio.h>

int main()
{
    int num = 0;
    int countPar = 0;
    int countImpar = 0;
    int somaPares = 0;
    int somaImpares = 0;
    int mediaImpares = 0;
   while(1){
       printf("Digite um numero\n");
       scanf("%d",&num);
       if (num == 0){
           printf("Programa encerrado\n");
           break;
       }
       else if(num % 2 == 0){
           countPar += 1;
           somaPares += num;
       }
       else{
           countImpar+= 1;
           somaImpares += num;
           
       }
        
    }
    
    mediaImpares =  somaImpares/countImpar;
    printf("A quantidades de numeros pare eh %d \n",countPar);
    printf("A quantidade de numeros impares eh %d\n",countImpar);
    printf("O total acumulado de pares eh %d\n",somaPares);
    printf("A media aritimetica dos impares eh %d\n",mediaImpares);
   

    return 0;
}
