#include "bibliotecas.h"

using namespace std;

typedef struct
{
    string usuario_adm;
    int senha;
}
adm;

void senha_da_loja()
{
    int quant_senha, senha;
    ifstream salva_senha;
    salva_senha.open("senha_loja.txt");
    salva_senha >> quant_senha;
    quant_senha++;
    int senha_mat[quant_senha][8];
    for (int i = 0; i < quant_senha; i++)
        {
            for(int j = 0; j < 8; j++)
                {
                    salva_senha >> senha_mat[i][j];
                }
        }
    salva_senha.close();
    for(int i = 0; i < 8; i++)
        {
            senha_mat[quant_senha - 1][i] = rand()%9;
            senha = senha_mat[quant_senha - 1][i];
        }
    cout << "Senha criado" << endl;
    cout << "A senha eh: " <<  senha << endl;
    sleep(10);
    system("cls");
    ofstream senha_loja;
    senha_loja.open("senha_loja.txt");
    for(int i = 0; i < quant_senha; i++)
        {
            for(int j = 0; j < 8; j++)
                {
                    senha_loja << senha_mat[i][j];
                }
        }
    senha_loja.close();
}

void administrador()
{
    adm admin, adm_login;
    int aux;
    cout << "Digite seu usu�rio: ";
    fflush(stdin);
    getline(cin,admin.usuario_adm);
    system("cls");
    cout << "Digite sua senha: ";
    cin >> admin.senha;
    system("cls");
    ifstream login_adm;
    login_adm.open("login_adm.txt");
    fflush(stdin);
    getline(login_adm,adm_login.usuario_adm);
    login_adm >> adm_login.senha;
    login_adm.close();
    if( admin.usuario_adm == adm_login.usuario_adm && admin.senha == adm_login.senha)
        {
            cout << "Login concluido";
            sleep(2);
            system("cls");
            cout << "Deseja criar a senha do usuario da loja? ( sim(1) n�o(2)): ";
            cin >> aux;
            system("cls");
            switch(aux)
                {
                case(1):
                    cout << "Criando a senha...";
                    sleep(5);
                    system("cls");
                    senha_da_loja();
                    break;
                case(2):
                    cout << "Programa finalizado";
                    exit;
                    break;
                default:
                    break;
                }
        }
        else{
            cout << "Login invalido" << endl << "Fa�a o login novamente";
            sleep(2);
            system("cls");
            administrador();
        }
}
