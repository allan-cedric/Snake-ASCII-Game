#include "lista_dupla_snake.h"

int inicializa_lista(t_lista *l)
{

	t_nodo *sent_ini, *sent_fim;

	sent_ini = (t_nodo *)malloc(sizeof(t_nodo));
	sent_fim = (t_nodo *)malloc(sizeof(t_nodo));

	if (sent_ini == NULL || sent_fim == NULL)
		return 0;

	l->ini = sent_ini;
	l->fim = sent_fim;

	sent_ini->prev = NULL;
	sent_ini->prox = sent_fim;

	sent_fim->prev = sent_ini;
	sent_fim->prox = NULL;

	l->atual = NULL;
	l->tamanho = 0;

	return 1;
}

int lista_vazia(t_lista *l)
{
	return (l->ini->prox == l->fim);
}

/* Verifica se a lista esta destruida */
int lista_destruida(t_lista *l)
{
	return (l->ini == NULL);
}

int tamanho_lista(int *tam, t_lista *l)
{

	*tam = l->tamanho;
	return 1;
}

int inicializa_atual_inicio(t_lista *l)
{

	if (lista_vazia(l) || lista_destruida(l))
		return 0;
	l->atual = l->ini->prox;
	return 1;
}

int inicializa_atual_fim(t_lista *l)
{

	if (lista_vazia(l) || lista_destruida(l))
		return 0;
	l->atual = l->fim->prev;
	return 1;
}

void incrementa_atual(t_lista *l)
{

	if (lista_vazia(l) || lista_destruida(l))
		return;

	if (l->atual == l->fim)
		l->atual = NULL;
	else
		l->atual = l->atual->prox;
}

void decrementa_atual(t_lista *l)
{

	if (lista_vazia(l) || lista_destruida(l))
		return;

	if (l->atual == l->ini)
		l->atual = NULL;
	else
		l->atual = l->atual->prev;
}

int consulta_item_atual(int *i, int *j, t_lista *l)
{

	if (lista_vazia(l) || lista_destruida(l))
		return 0;

	*i = l->atual->i;
	*j = l->atual->j;
	return 1;
}

int insere_inicio_lista(int i, int j, t_lista *l)
{

	if (lista_destruida(l))
		return 0;

	t_nodo *elemento;

	elemento = (t_nodo *)malloc(sizeof(t_nodo));

	if (elemento == NULL)
		return 0;

	elemento->i = i;
	elemento->j = j;
	elemento->prev = l->ini;	   /* Aponta para o NODO SENTINELA do inicio */
	elemento->prox = l->ini->prox; /* Aponta para o SEGUNDO NODO da lista */

	l->ini->prox->prev = elemento;
	l->ini->prox = elemento;

	(l->tamanho)++;

	return 1;
}

int insere_fim_lista(int i, int j, t_lista *l)
{

	if (lista_destruida(l))
		return 0;

	t_nodo *elemento;

	elemento = (t_nodo *)malloc(sizeof(t_nodo));

	if (elemento == NULL)
		return 0;

	elemento->i = i;
	elemento->j = j;
	elemento->prev = l->fim->prev; /*Aponta para o ULTIMO NODO da lista passada */
	elemento->prox = l->fim;	   /* Aponta para o NODO SENTINELA do fim */

	l->fim->prev->prox = elemento;
	l->fim->prev = elemento;

	(l->tamanho)++;

	return 1;
}

int remove_fim_lista(t_lista *l)
{

	if (lista_vazia(l) || lista_destruida(l))
		return 0;

	inicializa_atual_fim(l);

	l->atual->prox->prev = l->atual->prev;
	l->atual->prev->prox = l->fim;

	free(l->atual);
	l->atual = NULL;

	(l->tamanho)--;

	return 1;
}

int pertence_lista(int i, int j, t_lista *l)
{

	if (lista_vazia(l) || lista_destruida(l))
		return 0;

	inicializa_atual_inicio(l);

	l->fim->i = i;
	l->fim->j = j;

	while (l->atual->i != i || l->atual->j != j) /* Busca por sentinela */
		incrementa_atual(l);

	if (l->atual != l->fim)
		return 1;

	return 0;
}

void destroi_lista(t_lista *l)
{

	if (lista_destruida(l))
		return;

	while (!(lista_vazia(l)))
	{

		inicializa_atual_inicio(l);

		l->ini->prox = l->atual->prox;
		l->atual->prox->prev = l->ini;

		free(l->atual);
	}

	/* Libera memória dos SENTINELAS */
	free(l->ini);
	free(l->fim);

	l->ini = NULL;
	l->atual = NULL;
	l->fim = NULL;

	l->tamanho = 0;
}
