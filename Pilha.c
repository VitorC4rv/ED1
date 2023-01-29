#include <stdlib.h>
#include <stdio.h>
#include "Pilha.h"

//Implementações das funções da Pilha
//Não possui nada de diferente da pilha vista em sala, apenas algumas funções que não estão presentes

typedef struct pilha Pilha;

void criar_pilha(Pilha *p)
{
    p->topo = -1;
}

bool vazia_pilha(Pilha p)
{
    if (p.topo == -1) return true;
    else return false;
}

bool cheia_pilha(Pilha p)
{
    if (p.topo == (10 - 1)) return true;
    else return false;
}

bool empilhar(Pilha *p, int X)
{
    bool deuCerto;

    if (cheia_pilha(*p) == true)
    {
        deuCerto = false;
        return deuCerto;
    }
    else
    {
        p->topo = p->topo + 1;
        p->elementos[ p->topo ] = X;
        deuCerto = true;
        return deuCerto;
    }
}

bool desempilhar(Pilha *p, int *X)
{
    bool deuCerto;

    if (vazia_pilha(*p) == true)
    {
        p->topo = -1;
        deuCerto = false;
        return deuCerto;
    }
    else
    {
        *X = p->elementos[ p->topo ];
        p->topo = p->topo - 1;
        deuCerto = true;
        return deuCerto;
    }

}
