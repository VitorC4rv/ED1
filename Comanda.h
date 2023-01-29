#ifndef COMANDA_H_INCLUDED
#define COMANDA_H_INCLUDED

//implementação das funções da comanda

struct comanda
{
    int *produtos;
    int num_produtos;
    float total;
};

void gera_tamanho_comanda(struct comanda *comanda);
void gera_itens_comanda(struct comanda *comanda);

#endif // COMANDA_H_INCLUDED
