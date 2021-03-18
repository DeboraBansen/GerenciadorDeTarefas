#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "header.h"

void menu() {
	setlocale(LC_ALL,"Portuguese");
	printf("|--------------------------------|\n");
	printf("|\tCADASTRO DE TAREFAS\t |\n");
	printf("|________________________________|\n");
	printf("|\t MENU DE OPÇÕES\t         |\n");
	printf("\n|--------------------------------|\n");
	printf("\n|1-INCLUIR NOVA TAREFA           |\n");
	printf("\n|2-VISUALIZAR TAREFAS CADASTRADAS|\n");
	printf("\n|3-EXCLUIR TAREFA                |\n");
	printf("\n|4-EDITAR TAREFA                 |\n");
	printf("\n|5-CARREGAR ARQUIVO DE TAREFAS   |\n");
	printf("\n|6-GERAR ARQUIVO DE TAREFAS      |\n");
	printf("\n|7-COMPUTAR AGENDA DE TAREFAS    |\n");
	printf("\n|8-SALVAR A AGENDA DO DIA        |\n");
	printf("\n|0-SAIR                          |\n");
	printf("|________________________________|\n\n");

}

tarefa * inicializa() {
	tarefa *n;
	n=(tarefa*)malloc(sizeof(tarefa));
	n->prox=NULL;
	return n;
}

tarefa *incluirNovaTarefa(tarefa *r,int cont) {
	tarefa *p,*n;
	p=(tarefa*)malloc(sizeof(tarefa));
	p->prox=NULL;

	p->id=cont;
	printf("Digite o nome da Tarefa: ");
	scanf("%s",p->dados.nome);

	printf("Qual o dia de inicio da tarefa\n?");
	scanf("%d",&p->dados.inicio.dia);
	printf("Qual o mes de inicio da tarefa\n?");
	scanf("%d",&p->dados.inicio.mes);
	printf("Qual o ano de inicio da tarefa\n?");
	scanf("%d",&p->dados.inicio.ano);
	printf("Qual o hora de inicio da tarefa\n?");
	scanf("%d",&p->dados.inicio.hora);
	printf("Qual o minuto de inicio da tarefa\n?");
	scanf("%d",&p->dados.inicio.minuto);

	printf("Qual o dia do prazo final da tarefa\n?");
	scanf("%d",&p->dados.deadline.dia);
	printf("Qual o mes do prazo final da tarefa\n?");
	scanf("%d",&p->dados.deadline.mes);
	printf("Qual o ano do prazo final da tarefa?\n");
	scanf("%d",&p->dados.deadline.ano);
	printf("Qual o hora do prazo final da tarefa\n?");
	scanf("%d",&p->dados.deadline.hora);
	printf("Qual o minuto do prazo final da tarefa\n?");
	scanf("%d",&p->dados.deadline.minuto);

	printf("Digite a duração da tarefa:");
	scanf("%d",&p->dados.duracao);
	if(r!=NULL) {
		n=r;
		while(n->prox!=NULL) {
			n=n->prox;
		}
		n->prox=p;
	} else {
		r=p;
	}

	return r;

}

void visualizarTarefaCadastrada(tarefa *r) {
	tarefa *p;
	p=r;
	if(r==NULL) {
		printf("Lista vazia!\n");
	}
	while(p!=NULL) {
		printf("\n");
		printf("id = %d\n",p->id);
		printf("Nome = %s\n",p->dados.nome);
		printf("Data de Inicio : %d/%d/%d  às  %d:%d\n",p->dados.inicio.dia,p->dados.inicio.mes,p->dados.inicio.ano,p->dados.inicio.hora,p->dados.inicio.minuto);
		printf("Duração : %d\n",p->dados.duracao);
		printf("Deadline : %d/%d/%d  às  %d:%d\n",p->dados.deadline.dia,p->dados.deadline.mes,p->dados.deadline.ano,p->dados.deadline.hora,p->dados.deadline.minuto);
		printf("\n");
		p=p->prox;
	}
	printf("\n");

}

int visualizarUmaTarefa(tarefa *r,int valor) {
	tarefa *p;
	p=r;
	if(r==NULL) {
		printf("Lista Vazia!\n");
		return 1;
	}
	while(p->id!=valor&&p->prox!=NULL) {
		p=p->prox;
	}

	if(p->prox==NULL&&p->id!=valor) {
		printf("Tarefa nao encontrada!\n");
		return 1;
	}
	printf("\n");
	printf("id = %d\n",p->id);
	printf("Nome = %s\n",p->dados.nome);
	printf("Data de Inicio : %d/%d/%d  às  %d:%d\n",p->dados.inicio.dia,p->dados.inicio.mes,p->dados.inicio.ano,p->dados.inicio.hora,p->dados.inicio.minuto);
	printf("Duração : %d\n",p->dados.duracao);
	printf("Deadline : %d/%d/%d  às  %d:%d\n",p->dados.deadline.dia,p->dados.deadline.mes,p->dados.deadline.ano,p->dados.deadline.hora,p->dados.deadline.minuto);
	printf("\n");

	return 0;
}

tarefa *excluirTarefa(tarefa *r) {
	int valor;
	printf("Qual o id da tarefa que deseja excluir?  ");
	scanf("%d",&valor);
	tarefa *p;
	tarefa *ant=NULL;
	p=r;
	while(p->id!=valor&&p!=NULL) {
		ant=p;
		p=p->prox;
	}
	if(p==NULL) {
		printf("Valor nao encontrado!\n");
		return 0;
	} else {
		if(ant==NULL) {
			r=p->prox;
			return r;
		} else {
			ant->prox=p->prox;
		}
	}
	return ant;

}


tarefa *editarTarefa(tarefa *r) {
	int valor,opcao;
	printf("Qual o id da tarefa que deseja editar?  ");
	scanf("%d",&valor);

	tarefa *p;
	p=r;

	if(visualizarUmaTarefa(p,valor)==0) {
		printf("Deseja editar o nome?\n0-SIM\n1-NÃO\n");
		scanf("%d",&opcao);
		if(opcao==0) {
			printf("Digite o nome da Tarefa: ");
			scanf("%s",p->dados.nome);
		}
		printf("Deseja editar a data de início?\n0-SIM\n1-NÃO\n");
		scanf("%d",&opcao);
		if(opcao==0) {
			printf("Qual o dia de inicio da tarefa\n?");
			scanf("%d",&p->dados.inicio.dia);
			printf("Qual o mes de inicio da tarefa\n?");
			scanf("%d",&p->dados.inicio.mes);
			printf("Qual o ano de inicio da tarefa\n?");
			scanf("%d",&p->dados.inicio.ano);
		}
		printf("Deseja editar a hora de início?\n0-SIM\n1-NÃO\n");
		scanf("%d",&opcao);
		if(opcao==0) {
			printf("Qual o hora de inicio da tarefa\n?");
			scanf("%d",&p->dados.inicio.hora);
			printf("Qual o minuto de inicio da tarefa\n?");
			scanf("%d",&p->dados.inicio.minuto);
		}
		printf("Deseja editar a duração?\n0-SIM\n1-NÃO\n");
		scanf("%d",&opcao);
		if(opcao==0) {
			printf("Digite a duração da tarefa:");
			scanf("%d",&p->dados.duracao);
		}
		printf("Deseja editar a data do prazo final?\n0-SIM\n1-NÃO\n");
		scanf("%d",&opcao);
		if(opcao==0) {
			printf("Qual o dia do prazo final da tarefa\n?");
			scanf("%d",&p->dados.deadline.dia);
			printf("Qual o mes do prazo final da tarefa\n?");
			scanf("%d",&p->dados.deadline.mes);
			printf("Qual o ano do prazo final da tarefa?\n");
			scanf("%d",&p->dados.deadline.ano);
		}
		printf("Deseja editar a hora do prazo final?\n0-SIM\n1-NÃO\n");
		scanf("%d",&opcao);
		if(opcao==0) {
			printf("Qual o hora do prazo final da tarefa\n?");
			scanf("%d",&p->dados.deadline.hora);
			printf("Qual o minuto do prazo final da tarefa\n?");
			scanf("%d",&p->dados.deadline.minuto);
		}
	}
	return r;
}

void lerArquivoDeTarefas() {
	char url[]="tarefas.txt";
	char ch;
	FILE *arq;
	arq = fopen(url, "r");

	if(arq == NULL) {
		printf("Erro, nao foi possivel abrir o arquivo\n");
	} else {
		while( (ch=fgetc(arq))!= EOF ) {
			putchar(ch);
		}
		printf("\n");
	}


	fclose(arq);
}

void gerarArquivoDeTarefas(tarefa *r) {
	char url[]="tarefas.txt";

	FILE *arq;

	arq = fopen(url, "a");
	if(arq == NULL) {
		printf("Erro, nao foi possivel abrir o arquivo\n");
	} else {
		tarefa *p;
		p=r;
		if(r==NULL) {
			printf("Lista vazia!\n");
		}
		while(p!=NULL) {
			fprintf(arq,"%d, NOME: %s, INICIO %d/%d/%d as %d:%d, DURACAO: %d, DEADLINE %d/%d/%d as %d:%d\n",p->id,p->dados.nome,p->dados.inicio.dia,p->dados.inicio.mes,
			        p->dados.inicio.ano,p->dados.inicio.hora,p->dados.inicio.minuto,p->dados.duracao,p->dados.deadline.dia,p->dados.deadline.mes,p->dados.deadline.ano,
			        p->dados.deadline.hora,p->dados.deadline.minuto);
			p=p->prox;
		}

	}
	fclose(arq);
}

void troca_valor(tarefa *a,tarefa *b) {
	reg tmp;
	int i;
	tmp=a->dados;
	i=a->id;
	a->dados=b->dados;
	a->id=b->id;
	b->dados=tmp;
	b->id=i;
}

void *ordenar(tarefa *r) {
	tarefa *p,*a,*next;
	p=r;
	while(p!=NULL) {
		a=p;
		next=a->prox;
		while(next!=NULL) {
			if(a->dados.deadline.hora>next->dados.deadline.hora) {
				if(a->dados.deadline.hora==next->dados.deadline.hora) {
					if(a->dados.deadline.minuto>next->dados.deadline.minuto) {
						troca_valor(a,next);
						a=next;
						next=next->prox;
					} else {
						a=next;
						next=next->prox;
					}
				} else {
					troca_valor(a,next);
					a=next;
					next=next->prox;
				}
			} else {
				a=next;
				next=next->prox;
			}
		}
		p=p->prox;
	}
}
tarefa *compativel(tarefa *r) {
	tarefa *p,*next,*q;
	p=r;
	q=p;
	next=p->prox;

	while(next!=NULL) {
		if(p->dados.deadline.hora<=next->dados.inicio.hora) {
			q->prox=next;
			next=next->prox;
			p=p->prox;
		} else {
			next=next->prox;
		}
	
	}
	return q;
}
void computarTarefas(tarefa *r) {
	tarefa *p;
	p=r;
	if(r==NULL) {
		printf("Lista vazia!\n");
		return;
	}
	ordenar(p);
	compativel(p);
	visualizarTarefaCadastrada(p);

}

void salvarTarefas(r) {
	char url[]="Tarefas do dia.txt";
	compativel(r);
	FILE *arq;

	arq = fopen(url, "a");
	if(arq == NULL) {
		printf("Erro, nao foi possivel abrir o arquivo\n");
	} else {
		tarefa *p;
		p=r;
		if(r==NULL) {
			printf("Lista vazia!\n");
		}
		while(p!=NULL) {
			fprintf(arq,"%d, NOME: %s, INICIO %d/%d/%d as %d:%d, DURACAO: %d, DEADLINE %d/%d/%d as %d:%d\n",p->id,p->dados.nome,p->dados.inicio.dia,p->dados.inicio.mes,
			        p->dados.inicio.ano,p->dados.inicio.hora,p->dados.inicio.minuto,p->dados.duracao,p->dados.deadline.dia,p->dados.deadline.mes,p->dados.deadline.ano,
			        p->dados.deadline.hora,p->dados.deadline.minuto);
			p=p->prox;
		}

	}
	fclose(arq);
}
