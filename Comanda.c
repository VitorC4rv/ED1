#include <stdlib.h>
#include <stdio.h>
#include "Comanda.h"

//Implementação das funções da comanda

void gera_tamanho_comanda(struct comanda *comanda)
{
    srand(time(NULL));//Reseta a seed de geração
    int item = rand() %15;//Gera o tamanho aleatorio entre 0 e 15
    comanda->produtos = (int *)malloc(item*sizeof(int));//Aloca o tamanho dos produtos da comanda de acordo com o tamanho gerado
    comanda->num_produtos = item;
}

void gera_itens_comanda(struct comanda *comanda)
{
    int item;
    srand(time(NULL));//Reseta a seed de geração
    for(int i = 0; i < comanda->num_produtos; i++)
    {
        item = rand() % 5; //Gera um numero de produto aleatório e atribui ele a comanda
        comanda->produtos[i] = item;
    }

}
