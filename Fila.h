#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED
#include <stdbool.h>

//Implementação das assinaturas da biblioteca "Fila.h"

struct Fila
{
    int *elementos;
    int n_elem;
    int primeiro;
    int ultimo;
    int aux;
};

bool cheia_fila(struct Fila *F);
bool insere_fila(struct Fila* F, int x);
void *cria_fila();
bool vazia_fila(struct Fila *F);
bool retira_fila(struct Fila  *F, int *x);
#endif // FILA_H_INCLUDED
