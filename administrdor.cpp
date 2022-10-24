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
    int senha_mat[8];
    for(int i = 0; i < 8; i++)
        {
            senha_mat[i] = rand()%9;
        }
    cout << "Senha criada" << endl;
    sleep(2);
    system("cls");
    cout << "A senha eh: ";
    for (int i = 0; i < 8; i++){
        cout << senha_mat[i];
    }
    sleep(10);
    system("cls");
    ofstream senha_loja;
    senha_loja.open("senha_loja.txt");
    for(int i = 0; i < 8; i++){
         senha_loja << senha_mat[i];
    }
    senha_loja << endl;
    senha_loja.close();
}

void administrador()
{
    adm admin, adm_login;
    int aux;
    cout << "Digite seu usuário: ";
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
            cout << "Deseja criar a senha do usuario da loja? ( sim(1) não(2)): ";
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
    else
        {
            cout << "Login invalido" << endl << "Faça o login novamente";
            sleep(2);
            system("cls");
            administrador();
        }
}
