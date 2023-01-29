/*
 * Arquivo: main.c
 * Autor: Vitor de Carvalho Silva
 * Matricula: 12121BSI263
 * Data: 29/01/2023
 * Descrição: Programa para gerenciar as comandas de um restaurante,
 * incluindo a geração de itens de comanda aleatórios e o gerenciamento de uma fila de clientes, cujo o tamanho também é dado de forma aleatória.
 * Além disso, o programa gerencia uma pilha de chocolates para distribuir como brinde aos clientes.
 */

#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
#include "Pilha.h"
#include "Fila.h"
#include "Comanda.h"


//Inicialização da estrutura menu
struct menu
{
    int id;
    char nome[30];
    float preco;
};

//Implementação dos dados dessa estrutura por meio de um vetor de estruturas
struct menu item_menu[5] =
{
    {0,"Pizza",10.50},
    {1,"Hamburguer",12.30},
    {2,"Refrigerante",3.99},
    {3,"Sorvete",5.80},
    {4,"Cerveja",8.40}
};

//A implementaçao da estrutura chocolates assim como seus dados funciona de maneira igual a estrutura menu
struct chocolates
{
    int id;
    char nome[30];
};

struct chocolates id_chocolates[3] =
{
    {0, "Diamante Negro"},
    {1, "Sonho de Valsa"},
    {2, "Bis"}
};

int main() {
    struct comanda *comanda;
    comanda = malloc(sizeof(struct comanda)); // Definição e alocação de memoria da estrutura Comanda, presente na biblioteca "Comanda.h"

    int num_mesa, num_chocolate, opcao, opcao_chocolate; //Declaração das variáveis utilizadas no programa. Optei pela maneira mais didatica ao nomea-las

    struct Fila *fila;
    fila = cria_fila();//Definição e alocação de memoria da estrutura Fila, por meio da função cria_fila, que está presente na biblioteca "Fila.h"

    Pilha pilha_chocolates;
    criar_pilha(&pilha_chocolates);//Definição e alocação de memoria da estrutura Pilha, por meio da função criar_pilha, presente na biblioteca "Pilha.h"

    for (int i = 0; i < fila->aux; i++) {
        insere_fila(fila, i + 1);
    } //Nesse trecho de codigo eu inseri na fila numeros entre 1 e seu F auxiliar, uma variável q aponta o tamanho maximo de elementos possiveis na fila

    srand(time(NULL)); //reseta a seed de geração

    while (!cheia_pilha(pilha_chocolates)) {
        num_chocolate = rand() % 3;
        empilhar(&pilha_chocolates, num_chocolate);
    } //Nesse trecho, a pilha de chocolates foi cheia com numeros aleatorios.
    /*
    O sistema aleatório utilizado no prigrama funciona da seguinte maneira:
        A estrutura (Fila ou Pilha) é cheia com numeros "aleatórios"
        Ao desempilhar/retirar um item da estrutura, uma variável recebe esse valor então utilizo ela para acessar uma posição específica no vetor de estruturas desejado.
        Dessa forma, consigo obter um sistema totalmente aleatorio de quais itens chegam a comanda ou o tamanho da fila etc.
    */

    printf("\n===== Menu do Restaurante =====");

    while (opcao != 2) { //Inicialização do menu
        printf("\n1- Novo cliente.\n2- Sair do programa.");
        printf("\nEscolha uma opcao: ");
        scanf(" %d", &opcao);
        switch (opcao) {
        case 1:
            if (retira_fila(fila, &num_mesa) == true) {
                gera_tamanho_comanda(comanda); //Funções que geram o tamanho e itens da comanda
                gera_itens_comanda(comanda);

                printf("\n==========");
                printf("\nCliente %d \n", fila->primeiro);
                printf("==========\n\n");

                for (int i = 0; i < comanda->num_produtos; i++) {
                    int item = comanda->produtos[i];
                    printf("||No %d - %s - R$ %.2f\n", item_menu[item].id, item_menu[item].nome, item_menu[item].preco);
                    comanda->total += item_menu[item].preco; //Nesse trecho, o laço vai percorrer todos os itens dessa comanda, imprimindo nomes, valores e numero de identificação e tambem somando o total
                }

                printf("\n\n O valor total eh: R$ %.2f\n\n", comanda->total);
                comanda->total = 0;//reseta o valor total da comanda

                desempilhar(&pilha_chocolates, &opcao_chocolate);
                if (!vazia_pilha(pilha_chocolates)) {
                    printf("\nCliente recebeu um %s\n\n", id_chocolates[opcao_chocolate].nome);//Desempilha o chocolate e acessa o seu nome. Coloquei o tamanho da pilha estaticamente valendo 10
                } else {
                    printf("\nA pilha de chocolates acabou, mas ja estara cheia para o proximo cliente\n");
                    while (!cheia_pilha(pilha_chocolates)) {
                        num_chocolate = rand() % 3;
                        empilhar(&pilha_chocolates, num_chocolate);
                    }//Caso a pilha esteja vazia, ela será cheia novamente
                }
            }
            else {
                printf("\nFila vazia!!\n");
            }//Fila vazia, so resta reiniciar o programa, a fila não é cheia durante a execução assim como a pilha
            break;
        case 2:
            break;
        }
    }

    return 0;
}
