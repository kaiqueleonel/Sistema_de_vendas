#include "bibliotecas.h"

using namespace std;


typedef struct
{
    string nome;
    int senha;
}
usuario_loja;

void cadastro_loja()
{
    usuario_loja loja;
    int senha;
    cout << "Informe o seu nome: ";
    fflush(stdin);
    getline(cin,loja.nome);
    system("cls");
    cout << "Informe a senha: ";
    cin >> loja.senha;
    ifstream se;
    se.open("senha_loja.txt");
    se >> senha;
    se.close();
    if (loja.senha == senha)
        {
            ofstream loja_login;
            loja_login.open("usuario_loja");
            loja_login << loja.nome << endl;
            loja_login <<loja.senha << endl;
            loja_login.close();
        }

}
