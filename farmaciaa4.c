#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Remedio
{
	char nome[100];
	float preco;
	char validade[11];
};
int criar (int cont,struct Remedio dados[]);
int ler (int cont,struct Remedio dados[]);
int deletar (int cont,struct Remedio dados[]);
int atualizar (int cont,struct Remedio dados[]);
int main ()
{
	struct Remedio dados[1000];
	char res1[100];
	int cont = 0;
	printf("<<<Bem Vindo ao Sistema de Gestao do Estoque da Farmacia>>>\n");
	
	while(1)
	{
        printf("Digite criar para adicionar um remedio ao estoque\n Digite ler para para mostrar os remedios do estoque\n Digite atualizar para atualizar\n Digite deletar para deletar\nDigite sair para sair\n");
	    scanf("%s", res1);
		getchar();
		if (strcmp("criar",res1) == 0)
		{
			cont=criar(cont,dados);
		}
		else if (strcmp("ler",res1) == 0)
		{
			cont=ler(cont,dados);
		}
		else if (strcmp("atualizar",res1) == 0)
		{
			cont=atualizar(cont,dados);
		}
		else if (strcmp("deletar",res1) == 0)
		{
			cont=deletar(cont,dados);
		}
		else if (strcmp("sair",res1) == 0)
		{
			exit(0);
		}
        else 
		{
			printf("Voce digitou um valor invalido\n Tente novamente\n");
		}
	}
	return 0;
}
int criar (int cont,struct Remedio dados[])
{
    char nome[100];
    float preco;
  	char validade[11];
    printf("Digite o nome do medicamento que voce quer adicionar\n");
    fgets(dados[cont].nome, 100, stdin);


    printf("Digite o preco do medicamento\n");
    scanf("%f",&preco);
	getchar();

    dados[cont].preco = preco;

    printf("Digite a data da validade como no exemplo 01/01/2021\n");
    fgets(dados[cont].validade, 11, stdin);

	cont++;
    printf(">>>>>>  Adicionado com sucesso\n");
		
	return cont;
}
int ler (int cont,struct Remedio dados[])
{
	int i=0;
	for (i=0;i<cont;i++)
		{
			printf("Nome %s\n",dados[i].nome);
			printf("Preco %f\n",dados[i].preco);
			printf("Data de validade %s\n",dados[i].validade);
			
		}
	return cont;
}
int deletar (int cont,struct Remedio dados[])
{
	//observe que cont é quantidade de remedios unicos da lista que é o tamanho do array dados
    int pos = 0;
    int i =0;
    int j =0;
    char nome_excluir[100];
	
	printf("Digite o nome do remedio que voce quer excluir\n");
    fgets(nome_excluir,100,stdin);
    for (i=0;i<cont;i++) 
    {	
       	if (strcmp(dados[i].nome,nome_excluir) == 0)//compara o nome do remedio a ser excluido com a "lista" dos remedios salvos no sistema
        {
            pos = i;
        }
    }
    for (j=pos;j<cont-1;j++)
	{
	dados[j] = dados[j+1];
	}
	cont--;
    printf(">>>>>>  Deletado com sucesso\n");
	return cont;
}
int atualizar (int cont,struct Remedio dados[])
{	
	int pos = 0;
    int i =0;
   	char nome_atualizar[100];
  	char res[100];
    char novo_nome[100];
    char nova_validade[100];
    float novo_preco;
	
	printf("Digite o nome do remedio que voce quer atualizar");
    fgets(nome_atualizar,100,stdin);
    
	for (i=0;i<cont;i++) 
    {
       	if (strcmp(dados[i].nome,nome_atualizar) == 0)//compara o nome do remedio a ser atualizado com a "lista" dos remedios salvos no sistema
        {
            pos=i;// acha a posição do remedio dentro do array dados q eu quero atualizar
        }
        
    }
    
	printf("Voce quer mudar o nome, preco ou validade?");
    scanf("%s",res);
    getchar();
   
    if (strcmp("nome",res) == 0)
	{
		printf("Qual o novo nome do medicamento?");
		fgets(novo_nome,100,stdin);
		strcpy(dados[pos].nome,novo_nome);
	}
	else if (strcmp("preco",res) == 0)
	{
		printf("Qual o novo preco do medicamento?");
		scanf("%f",&novo_preco);
		dados[pos].preco = novo_preco;
	}
	else if (strcmp("validade",res) == 0)
	{
		printf("Qual a nova validade do medicamento?");
		fgets(nova_validade,100,stdin);
		strcpy(dados[pos].validade,nova_validade);
	}
	else
	{
		printf("Voce digitou um caracteristica invalida");
	}
	return cont;
}

