include <stdio.h>
#include <math.h>
int main () 
{	int r; // resposta se quer pa ou pg
	int n; // enesimo termo
	int rz; // razao da progressao
	int p; // primeiro termo
	int cont = 0; // contador
	int cont2 = 1;
	printf("Se voce quer uma pa digite 1 caso queira uma pg digite 2\n");
	scanf("%d",&r);
	printf("Informe qual enesimo termo voce deseja calcular\n");
	scanf("%d",&n);
	printf("Informe a razao da progressao\n");
	scanf("%d",&rz);
	printf("Informe o primeiro termo da progressao\n");
	scanf("%d",&p);
	
	if (r == 1) // opacao de pa
	{
		while (cont < n)
		{
			n = p + (rz*cont);
			cont++;
		}
	}
	else if ( r == 2) // opcao de pg
	{
		for (cont2=1;cont2 <= n;cont2++)
		{
			n = p*pow(rz,cont - 1);
		}
	}
	printf("O seu enesimo termo eh : %d",n);
	return 0;
}
