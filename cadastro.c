#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

struct Pessoa {
	int id;
	char nome[MAX];
	int idade;
	int status;
};

typedef struct Pessoa TPessoa;

void cadastrar(TPessoa vetor[], int pos) {
	
	printf("\nEntre com os dados \n");
	
	vetor[pos].id = pos;
	
	printf("Nome: ");
	fgets(vetor[pos].nome, MAX-1, stdin);   
		
	printf("Idade: ");
	scanf("%d", &vetor[pos].idade);	
	
	vetor[pos].status = 1;
}

void listar(TPessoa vetor[], int n) {
	
	int i;
	
	printf("\n***Pessoas cadastradas***\n");
	
	for (i=0; i<n; i++) {
		
		if (vetor[i].status == 1) {
			printf("Id: %d\n", vetor[i].id);
			printf("Nome: %s", vetor[i].nome);
			printf("Idade: %d\n\n", vetor[i].idade);
		}
	}
}

void pesquisar(TPessoa vetor[], int n) {
	
	int i;
	char nome[MAX];
	int encontrou = 0;
	
	printf("\nEntre com um nome: ");
	fgets(nome, MAX-1, stdin);
	
	for (i=0; i<n; i++) {
	
		if (vetor[i].status == 1 && strcmp(vetor[i].nome, nome) == 0) {
			printf("Id: %d\n", vetor[i].id);
			printf("Nome: %s", vetor[i].nome);
			printf("Idade: %d\n", vetor[i].idade);
			encontrou = 1;
		}
	}
	
	if (!encontrou) {
		printf("Pessoa nao encontrada\n");
	}
}

void remover(TPessoa vetor[], int n) {
	
	int id;
	
	printf("Entre com o id: ");
	scanf("%d", &id);
	
	if (id < 0 || id >= n) {
		printf("Id invalido\n");
		return;
	}
	
	if (vetor[id].status == 1) {
		
		vetor[id].status = 0;
		printf("Cadastro removido\n");
	}	
}

void menu() {
	printf("1 - Cadastrar\n");
	printf("2 - Listar\n");
	printf("3 - Pesquisar\n");
	printf("4 - Remover\n");
	printf("5 - Sair\n");
}

int main() {
	
	TPessoa *vetor;
	int n, op;
	n = 0;
	
	do {
		menu();
		printf("Entre com a opcao: ");
		scanf("%d", &op);
		getchar();
		
		switch (op) {
			case 1:
				n++;
				
				if (n == 1) {
					vetor = (TPessoa *) malloc(sizeof(TPessoa));
				}
				else {
					vetor = (TPessoa *) realloc(vetor, n * sizeof(TPessoa));
				}
				
				cadastrar(vetor, n-1);
				
				printf("Cadastro realizado com sucesso\n");
				break;
			case 2:
				listar(vetor, n);
				break;
			case 3:
				pesquisar(vetor, n);
				break;
			case 4:
				remover(vetor, n);
				break;
			default:
				printf("Opcao invalida\n");
				break;
		}
		printf("\n");
		
	} while (op != 5);
}
