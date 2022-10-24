#include "bibliotecas.h"
#include "cadastro_produto.h"
using namespace std;


typedef struct
{
    string nome;
    int senha;
}
usuario_loja;
void login_loja()
{
    usuario_loja loja, usuario;
    int quant_loja = 0;
    ifstream pega_loja;
    pega_loja.open("usuario_loja.txt");
    pega_loja >> usuario.nome;
    pega_loja >> usuario.senha;
    pega_loja.close();
    cout << "Faça seu login";
    sleep(2);
    system("cls");
    cout << "Informe seu nome: ";
    fflush(stdin);
    getline(cin, loja.nome);
    system("cls");
    cout << "Informe a senha: ";
    cin >> loja.senha;
    system("cls");
    if(loja.senha == usuario.senha && loja.nome == usuario.nome)
        {
            cout << "Login aprovado";
            sleep(2);
            system("cls");
            CADASTRO_PRODUTO_H_INCLUDED
        }


}


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
    system("cls");
    ifstream se;
    se.open("senha_loja.txt");
    se >> senha;
    se.close();
    if (loja.senha == senha)
        {
            ofstream loja_login;
            loja_login.open("usuario_loja.txt");
            loja_login << loja.nome << endl;
            loja_login <<loja.senha << endl;
            loja_login.close();
            cout << "Cadastro de usuário bem sucedido";
            sleep(2);
            system("cls");
            cout << "Faça o login agora";
            sleep(2);
            system("cls");
            login_loja();
        }
    else
        {
            cout << "Senha incorreta" << endl << "Tente fazer o cadastro novamente";
            sleep(2);
            system("cls");
            cadastro_loja();
        }
}

