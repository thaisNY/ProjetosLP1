#include <stdio.h>
#include <stdlib.h>

void inverter(void){
	printf("Bem vindo a opcao de inverter\n");
	
	int n1,cifra;
	printf("Digite um numero inteiro\n");
	scanf("%d",&n1);
	
	if(n1>= 0){
		do{
			cifra = n1 % 10;
			printf("%d",cifra);
			n1 /= 10;
		}while (n1 != 0);
		
		printf("\n");
	}
	else if(n1 < 1) {
		n1 = n1 * -1;
		
		printf("-");
		
		do{
			cifra = n1 % 10;
			printf("%d",cifra);
			n1 /= 10;
		}while (n1 != 0);
		
		printf("\n");
	}
}

void divisao(void){
	
	printf("Bem vindo a opacao de dividir\n");
	int num1,num2;
	int resto, quociente;
	
	printf("Digite dois numeros inteiros\n");
	scanf("%d %d",&num1,&num2);
	
	if(num2 == 0){
		printf("Valor invalido, nao pode dividir por 0\n");
	}
	else{
		resto = num1%num2;
		quociente = (num1 - resto) / num2;
		printf("o quociente eh %d o resto eh %d\n",quociente,resto);
	}
	
}

int fatorial(int n){
	int valor_fatorial;
	
	if(n == 0 || n == 1)
		return 1;
	else
	{
		valor_fatorial = n*(fatorial(n - 1));
		return valor_fatorial;
	}
}
void aux_fatorial(void) {
	printf("Bem vindo a opcao de fatorial\n");
	int n;
	int resp;
	printf("Digite um numero inteiro para achar o seu fatorial\n");
	scanf("%d",&n);
	resp = fatorial(n);
	printf("O fatorial de %d eh %d\n",n,resp);

}


int main()
{
	printf("Bem vindo a calculadora\n");
	
	
	while(1)
	{
		int op;
		printf("Digite 1  para inverter um numero,\n 2 para calcular o quociente e resto da divisao,\n 3 para calcular o fatorial\n e 0 para sair\n");
		scanf("%d",&op);
		
		if( op == 1){
			inverter();
		}
		else if(op == 2){
			divisao();
		}
		else if(op == 3){
			aux_fatorial();
		}
		else if(op == 0){
			exit(0);
		}
		else{
			printf("Voce digitou um valor invalido\n Tente novamente\n");
		}
	}
	
	return 0;
}
