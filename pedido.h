#ifndef PEDIDO_H_INCLUDED
#define PEDIDO_H_INCLUDED

using namespace std;

typedef struct
{
    string nome_do_produto_a_comprar;
    int quantidade_do_produto;
    string forma_de_pagamento;
    float valor_total_da_compra;
}
pedir;

#endif // PEDIDO_H_INCLUDED
