//Programa de pagamenos de uma empresa de programação
//Sistema Finaceiro
//O programa deve ler o NOME, ESPECIALIDADE do Dev, numero da conta bancaria, banco E quantos trabalhos
//ele entregou esse mes
//deve calcular o deposito que deve ser feito
//Baseado no fato que a 3 tipos de profissionais na empresa
//designers que ganham 2000 fixo, dev_web que ganha 3000 fixo, dev_mobile que ganha 5000 fixo
//cada profissional ganha 250 reais por cada trabalho entregue como bonus
//especialidades serao designer, dev_web e dev_mobile

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>      //contém declarações para manipulação de caracteres.
#include <locale.h>     //para o programa aceitar acentuação
#define TAM 100         //TAM recebe o valor de 100 inteiros

typedef struct dados{
        char nome[100];
        char especialidade[100];
        char banco[100];
        char conta[100];
        int  entregas; 
        float salario;
} d_dados;

void criaLista();
void cadastrar(void);   
void listar(void); // listar
void listarOrdenadoSalario(void);
void listarOrdenadoNome(void);
void pesquisar(char * nome);  // função para Pesquisar funcionario
void excluirFuncionario(char * nome);
float calculaSalario(char * especialidade, int entregas); //função para calcular o salario do funcionario usando o nome
void pesquisar(char * nome);  // função para Pesquisar funcionario
void atualizar(char * nome);    // função para atualizar dados do funcionario
void salva(void);

/*============  Variaveis Globais  =============*/
static int qtd = 0;     // qtd é uma variavel do tipo estatica que conta a quantidade de contatos incritos
d_dados lista[TAM];      // agora max[100] é um vetor do tipo contatos definido com o typedef
FILE *arq;              // declarar a variável(*arq) como ponteiro do arquivo(FILE)

//função principal

int main (){
    int entrada, sair;
    char nome[100];
    
    arq = fopen("dados.txt", "a");// fopen cria arquivo de entrada  <=====
    
    if (arq == NULL){//caso o sistema não consiga criar o arquivo
        printf ("Erro! O arquivo da lista não pode ser aberto!\n");//sera mostrada esta mensagen
        return -1;
     }
    
    
    system("title SISTEMA FINACEIRO");
    system("color 1f");// Define a o plano de Fundo Azul Marinho e o texto em Branco
    setlocale(LC_ALL, "Portuguese");//Define no console o idioma Portugues
    printf("SISTEMA FINANCEIRO DE UMA EMPRESA DE PROGRAMAÇÃO \n\n");
    printf("Veja todas as funções disponiveis no menu.\n");
    printf("Use os numeros para selecionar a opção desejada.\n");
    
    sair = 0;
    
    while(!sair){
    	
	    do{
	    	puts("[1] - CADASTRAR");
	    	puts("[2] - LISTAR");
	    	puts("[3] - LISTAR ORDENADO POR NOME");
	    	puts("[4] - LISTAR ORDENADO POR SALARIO");
	    	puts("[5] - PESQUISAR");
	    	puts("[6] - ATUALIZAR");
	    	puts("[7] - EXCLUIR");
	    	puts("[8] - SAIR");
	    	printf("---> ");
	    	scanf("%d", &entrada);
	    	fflush(stdin);
		} while(entrada < 1 || entrada > 8);
		
		switch(entrada){
			
			case 1:
					cadastrar();
					break;
			case 2:
					listar();
					break;
			case 3:
					listarOrdenadoNome();
					break;
			case 4:
					listarOrdenadoSalario();
					break;
			case 5:	
					printf("DIGITE O NOME: ");
					gets(nome);
					fflush(stdin);
					pesquisar(nome);
					break;
			case 6:
					printf("DIGITE O NOME: ");
					gets(nome);
					fflush(stdin);
					atualizar(nome);
					break;
			case 7:
					printf("DIGITE O NOME: ");
					gets(nome);
					fflush(stdin);
					excluirFuncionario(nome);
					break;
			case 8: 
					salva();
					sair = 1;
					break;
		}
	}
	
  	return 0;
}

float calculaSalario(char * especialidade, int entregas) {
	int salario = 0;
	
	if(!strcmp("designer", especialidade)){
		salario = 2000 + (250 * entregas);
	}
	else if(!strcmp("dev_web", especialidade)){
		salario = 3000 + (250 * entregas);
	}
	else if(!strcmp("dev_mobile", especialidade)){
		salario = 5000 + (250 * entregas);
	}
	
	return salario;
}

/*========  Incluir Funcionarios ao Sistema  ===========*/

void cadastrar(void){
   puts("--------------------");
   printf("DIGITE O NOME DO DEV: ");
   gets(lista[qtd].nome);
   fflush(stdin);
   printf("DIGITE A ESPECIALIDADE: ");
   gets(lista[qtd].especialidade);
   fflush(stdin);
   printf("DIGITE O BANCO: ");
   gets(lista[qtd].banco);
   fflush(stdin);
   printf("DIGITE O CONTA: ");
   gets(lista[qtd].conta);
   fflush(stdin);
   printf("DIGITE A QUANTIDADE DE ENTREGAS: ");
   scanf("%d", &lista[qtd].entregas);
   fflush(stdin);
   lista[qtd].salario = calculaSalario(lista[qtd].especialidade, lista[qtd].entregas);
   printf("O SALARIO É: %0.2f\n", lista[qtd].salario);
   puts("--------------------");
   qtd++;
}

/*==============  calcular salario do funcionario  ===============*/

void listar(){
	int i;
	
	for(i = 0; i < qtd; i++){
		
		if(strcmp(lista[i].nome, "x") != 0){
			puts("--------------------");
			printf("NOME: %s\n", lista[i].nome);
			printf("ESPECIALIDADE: %s\n", lista[i].especialidade);
			printf("BANCO: %s\n", lista[i].banco);
			printf("CONTA: %s\n", lista[i].conta);
			printf("ENTREGAS: %d\n", lista[i].entregas);
			printf("SALÁRIO: %02f\n", lista[i].salario);
			puts("--------------------");
		}
	}
}

void troca(d_dados *a, d_dados *b){
	d_dados temp;
	/* temp recebe a */
	strcpy(temp.nome, a->nome);
	strcpy(temp.especialidade, a->especialidade);
	strcpy(temp.banco, a->banco);
	strcpy(temp.conta, a->conta);
	temp.entregas = a->entregas;
	temp.salario = a->salario;
	/* a recebe b */
	strcpy(a->nome, b->nome);
	strcpy(a->especialidade, b->especialidade);
	strcpy(a->banco, b->banco);
	strcpy(a->conta, b->conta);
	a->entregas = b->entregas;
	a->salario = b->salario;
	/* b recebe temp */
	strcpy(b->nome, temp.nome);
	strcpy(b->especialidade, temp.especialidade);
	strcpy(b->banco, temp.banco);
	strcpy(b->conta, temp.conta);
	b->entregas = temp.entregas;
	b->salario = temp.salario;
}

void listarOrdenadoSalario(){
	int i, j;
	
	for(i = 0; i < qtd; i++){
		
		for(j = 0; j < qtd - 1; j++){
			
			if(lista[j].salario > lista[j + 1].salario){
					troca(&lista[j], &lista[j + 1]);
			}
		}
	}
	
	listar();
}

void listarOrdenadoNome(){
	int i, j;
	
	for(i = 0; i < qtd; i++){
		
		for(j = 0; j < qtd - 1; j++){
			
			if(strcmp(lista[j].nome, lista[j + 1].nome) == 1){
					troca(&lista[j], &lista[j + 1]);
			}
		}
	}
	
	listar();
}

void pesquisar(char * nome){
	int i;
	
	for(i = 0; i < qtd; i++){
		
		if(!strcmp(lista[i].nome, nome) && strcmp(lista[i].nome, "x") != 0){
			puts("--------------------");
			printf("NOME: %s\n", lista[i].nome);
			printf("ESPECIALIDADE: %s\n", lista[i].especialidade);
			printf("BANCO: %s\n", lista[i].banco);
			printf("CONTA: %s\n", lista[i].conta);
			printf("ENTREGAS: %d\n", lista[i].entregas);
			printf("SALÁRIO: %f\n", lista[i].salario);
			puts("--------------------");
		}
	}
}

void atualizar(char * nome){
	int i;
	
	for(i = 0; i < qtd; i++){
		
		if(!strcmp(lista[i].nome, nome) && strcmp(lista[i].nome, "x") != 0){
			printf("DIGITE A ESPECIALIDADE: ");
			gets(lista[i].especialidade);
			fflush(stdin);
		    printf("DIGITE A QUANTIDADE DE ENTREGAS: ");
		    scanf("%d", &lista[i].entregas);
		    fflush(stdin);
		    lista[i].salario = calculaSalario(lista[i].especialidade, lista[i].entregas);
		    printf("O SALARIO É: %0.2f\n", lista[i].salario);
		    puts("--------------------");
		}
	}
}

void excluirFuncionario(char *nome){
	int i;
	
	for(i = 0; i < qtd; i++){
		
		if(!strcmp(lista[i].nome, nome) && strcmp(lista[i].nome, "x") != 0){
			strcpy(lista[i].nome, lista[i + 1].nome);
			strcpy(lista[i].especialidade, lista[i + 1].especialidade);
			strcpy(lista[i].banco, lista[i + 1].banco);
			strcpy(lista[i].conta, lista[i + 1].conta);
			lista[i].entregas = lista[i + 1].entregas;
			lista[i].salario = lista[i + 1].salario;
		}
	}
	
	strcpy(lista[qtd - 1].nome, "x");
}

void salva(){
	int i;
	
	for(i = 0; i < qtd; i++){
		
		if(strcmp(lista[i].nome, "x") != 0){
			fprintf(arq, "%s\n", lista[i].nome);
			fprintf(arq, "%s\n", lista[i].especialidade);
			fprintf(arq, "%s\n", lista[i].banco);
			fprintf(arq, "%s\n", lista[i].conta);
			fprintf(arq, "%d\n", lista[i].entregas);
			fprintf(arq, "%f\n", lista[i].salario);
			fprintf(arq, "--------------------\n");
		}
	}
	
	close(arq);
}
