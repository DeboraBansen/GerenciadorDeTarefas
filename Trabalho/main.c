#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "tarefa.c"

int main(int argc, char *argv[]) {
	int cont=0;
	tarefa *r=NULL;

	int opcao;
	
	do{
	menu();
	scanf("%d",&opcao);
	switch(opcao){
		case 1:
			r=incluirNovaTarefa(r,cont);
			cont++;
			break;
		case 2:
			visualizarTarefaCadastrada(r);
			break;
		case 3:
			r=excluirTarefa(r);
			break;
		case 4:
			r=editarTarefa(r);
			break;		
		case 5:
			lerArquivoDeTarefas();
			break;	
		case 6:
			gerarArquivoDeTarefas(r);	
			break;
		case 7:
			computarTarefas();
			break;
		case 8:
			salvarTarefas();
			break;		
	}
	}while(opcao!=0);
	return 0;
}
