#include <iostream>

using namespace std;
typedef struct
{
    string nome_do_produto;
    float valor_do_produto;
    string descricao_do_produto;
    int quant_do_produto;
}
cadastro_produto;

typedef struct
{
    int numero_usuario;
    string nome_do_aluno;
    char matricula[17];
    string senha;
    string nome_do_curso;
    string turno;
    string ano;
}
cadastro_do_aluno;

typedef struct
{
    string nome_do_produto_a_comprar;
    int quantidade_do_produto;
    string forma_de_pagamento;
    float valor_total_da_compra;
}
pedir;

typedef struct
{
    string dinheiro;
    string cartao;
    double pix;
}
forma_de_pagamento;

typedef struct
{
    string nome;
    string cargo;
    char siap[8];
}
cadastro_funcionario;
int main()
{
    return 0;
}
