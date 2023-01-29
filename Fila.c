#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "Fila.h"

//Funcionalidades da Fila
//Implementei apenas as funções utilizadas para o programa
//Basicamente, estão praticamente iguais as feitas em aula, com exceção da função "cria_fila"

bool cheia_fila(struct Fila *F)
{
    if(F->n_elem == F->aux)return true;
    else return false;
}

bool insere_fila(struct Fila* F, int x)
{
    bool deuCerto;

    if (cheia_fila(F) == true)
    {
        deuCerto = false;
        return deuCerto;
    }
    deuCerto = true;
    F->elementos[ F->ultimo ] = x;
    F->n_elem = F->n_elem + 1;
    F->ultimo = F->ultimo + 1;

    return deuCerto;
}

void *cria_fila()
{
    srand(time(NULL));//Reseta a seed de geração
    int aux = rand() % 30;//atribui um valor aleatório entre 0 e 30 para o tamanho da fila
    struct Fila *F;
    F = (struct Fila *)malloc(sizeof(struct Fila));

    if(F != NULL)
    {
        F->elementos = (int *)malloc(aux*sizeof(int));
        F->n_elem = 0;
        F->primeiro = 0;
        F->ultimo = 0;
        F->aux = aux;//A variavel aux foi criada na necessidade de armazenar o tamanho maximo da fila
    }
    return F;
}

bool vazia_fila(struct Fila *F)
{
    if(F->n_elem == 0) return true;
    else return false;
}

bool retira_fila(struct Fila  *F, int *x)
{
    bool certo;

    if(vazia_fila(F) == true)
    {
        certo = false;
        return certo;
    }
    certo = true;
    *x = F->elementos[F->primeiro];
    F->n_elem = F->n_elem - 1;
    F->primeiro = F->primeiro + 1;
    return true;
}
