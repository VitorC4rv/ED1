#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED
#include <stdbool.h>

//Implementação das assinaturas da biblioteca "Pilha.h"

struct pilha
{
    int elementos[10];
    int topo;
};
typedef struct pilha Pilha;

void criar_pilha(Pilha *p);

bool vazia_pilha(Pilha p);

bool cheia_pilha(Pilha p);

bool empilhar(Pilha *p, int X);

bool desempilhar(Pilha *p, int *X);

#endif // PILHA_H_INCLUDED
