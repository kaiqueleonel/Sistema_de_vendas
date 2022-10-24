#include "bibliotecas.h"

using namespace std;

typedef struct
{
    string nome_do_produto;
    float valor_do_produto;
    string descricao_do_produto;
    int quant_do_produto;
}
cadastro_duto;

void cadastramento_de_produto()
{

    int quant_produto=0;
    ifstream pegue_produto;
    pegue_produto.open("cadastro_produto.txt");
    pegue_produto >> quant_produto;
    quant_produto++;
    cadastro_duto produto[quant_produto];
    for(int i=0; i < quant_produto; i++)
        {
            pegue_produto >> produto[i].nome_do_produto;
            pegue_produto >> produto[i].valor_do_produto;
            pegue_produto >> produto[i].descricao_do_produto;
            pegue_produto >> produto[i].quant_do_produto;
        }
    pegue_produto.close();
    cout << "Cadastre um produto";
    sleep(3);
    system("cls");
    cout << "Digite o nome do produto: ";
    fflush(stdin);
    getline(cin, produto[quant_produto-1].nome_do_produto);
    system("cls");
    cout << "Digite o valor do produto: ";
    cin >> produto[quant_produto-1].valor_do_produto;
    system("cls");
    cout << "Digite a descrição do produto: ";
    fflush(stdin);
    getline(cin, produto[quant_produto-1].descricao_do_produto);
    system("cls");
    cout << "Digite a quantidade do produto disponivel: ";
    cin >> produto[quant_produto-1].quant_do_produto;
    system("cls");
    ofstream guardar_produto;
    guardar_produto.open("cadastro_produto.txt  ");
    guardar_produto << quant_produto;
    for(int i=0; i < quant_produto; i++)
        {
            guardar_produto << produto[i].nome_do_produto << endl;
            guardar_produto << produto[i].valor_do_produto << endl;
            guardar_produto << produto[i].descricao_do_produto << endl;
            guardar_produto << produto[i].quant_do_produto << endl;
        }
    guardar_produto.close();
    cout << "Cadastro de produto bem sucedido ";
}
