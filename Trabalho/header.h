#include<stdio.h>
#include<stdlib.h>
typedef struct {
	int dia;
	int mes;
	int ano;
	int hora;
	int minuto;
}tempo;

typedef struct {
	char nome[50];
	tempo inicio;
	int duracao;
	tempo deadline;
} reg;

typedef struct nodo tarefa;
struct nodo{
	int id;
	reg dados;
	tarefa *prox;
};
