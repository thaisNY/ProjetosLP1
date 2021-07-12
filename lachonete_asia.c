#include <stdio.h>
#include <stdlib.h>
int main ()
{
	char esp;
	int codigo = 0;
	int pedidos = 0;
	int total_100 = 0;
	int total_200 = 0;
	int total = 0;
	int pago_cliente = 0;
	int troco = 0;
	
	
	printf("<<<BEM VINDO AO SISTEMA DA LANCHONETE>>>\n");
	
	printf("Aperte espaco para limpar a tela\n");
	esp = getch();
	system("cls");
	
	while(1)
	{
		printf("Digite o codigo de acordo com o pedido e 0 para sair\nComida coreana      codigo:100      valor:10\nComida Japonesa     codigo:200     valor:20\n");
		scanf("%d",&codigo);
		
		if (codigo == 0){
		    break;
		}
		
		else if (codigo == 100)
		{
			printf("Quantos pedidos?");
			scanf("%d", &pedidos);
			total_100 += 10*pedidos;
			continue;
		}
		else if (codigo == 200)
		{
			printf("Quantos pedidos?");
			scanf("%d", &pedidos);
			total_200 += 20*pedidos;
			continue;
		}
		else
		{
			printf("Voce digitou um codigo invalido\n Digite o codigo novamente\n");
			continue;
			
		}
		
	}
	
	total = (total_100 + total_200);
	printf("O total do pedido foi %d \n",total);
	
	printf("Aperte espaco para limpar a tela\n");
	esp = getch();
	system("cls");

	printf("Digite o valor que o cliente pagou\n");
	scanf("%d",&pago_cliente);
	troco = pago_cliente - total;
	
	if (troco == 0)
	{
		printf("Volte sempre\n");
	}
	else 
	{
		printf("O troco tem valor %d\n",troco);
		printf("Volte sempre\n");
	}

	
	return 0;
	
}
