#include "bibliotecas.h"

using namespace std;

typedef struct
{
    string nome;
    string cargo;
    string senha;
    char siap[7];
}
cadastro_funcionario;

typedef struct
{
    char siap[7];
    string senha;
}
login_funcionario;

void login_de_usuario_funcionario()
{
    cin.ignore();
    cout << "Faça seu login" << endl;
    sleep(1);
    system("cls");
    login_funcionario funcionario_login;
    int quant_funcionario = 0, aux, aux_login = 0;
    string siap, sia;
    ifstream pegar_funcionario;
    pegar_funcionario.open("cadastro_de_funcionario.txt");
    pegar_funcionario >> quant_funcionario;
    cadastro_funcionario funcionario[quant_funcionario];
    for(int i = 0; i < quant_funcionario; i++)
        {
            pegar_funcionario >> funcionario[i].nome;
            pegar_funcionario >> funcionario[i].cargo;
            pegar_funcionario >> funcionario[i].senha;
            pegar_funcionario >> funcionario[i].siap;
        }
    pegar_funcionario.close();
    cout << "Digite seu SIAP: ";
    cin.getline(funcionario_login.siap, 8);
    system("cls");
    siap = funcionario_login.siap;
    aux = strlen(funcionario_login.siap);
    if(aux == 7)
        {
            cout << "Digite sua senha: ";
            cin >> funcionario_login.senha;
            system("cls");
            for (int i = 0; i < quant_funcionario; i++)
                {
                    sia = funcionario[i].siap;
                    if( siap == sia && funcionario_login.senha == funcionario[i].senha)
                        {
                            cout << "Login aprovado";
                            sleep(2);
                            system("cls");
                            aux_login = 1;
                        }
                }
            if (aux_login == 0)
                {
                    cout << "Login não aprovado" << endl << "Faça o login novamente" << endl;
                    sleep(2);
                    system("cls");
                    login_de_usuario_funcionario();
                }
        }
}

void funcao_cadastro_de_funcionario()
{


    int aux = 0;
    int quant_funcionario = 0;
    ifstream pegar_funcionario;
    pegar_funcionario.open("cadastro_de_funcionario.txt");
    pegar_funcionario >> quant_funcionario;
    quant_funcionario++;
    cadastro_funcionario funcionario[quant_funcionario];
    for(int i = 0; i < quant_funcionario; i++)
        {
            pegar_funcionario>> funcionario[i].nome;
            pegar_funcionario >> funcionario[i].cargo;
            pegar_funcionario >> funcionario[i].senha;
            pegar_funcionario >> funcionario[i].siap;
        }
    pegar_funcionario.close();
    system("cls");
    cout << "Informe seu nome: ";
    cin >> funcionario[quant_funcionario - 1].nome;
    system("cls");
    cout << "Informe o seu cargo: ";
    cin >> funcionario[quant_funcionario - 1].cargo;
    system("cls");
    cout << "Informe sua senha: ";
    cin >> funcionario[quant_funcionario - 1].senha;
    system("cls");
    cout << "Informe seu SIAP: ";
    cin.ignore();
    cin.getline(funcionario[quant_funcionario - 1].siap,8);
    system("cls");
    aux = strlen(funcionario[quant_funcionario - 1].siap);
    if(aux == 7)
        {
            ofstream cada_funcionario;
            cada_funcionario.open("cadastro_de_funcionario.txt");
            cada_funcionario << quant_funcionario << endl;
            for(int i = 0; i < quant_funcionario; i++)
                {
                    cada_funcionario << funcionario[i].nome << endl;
                    cada_funcionario << funcionario[i].cargo << endl;
                    cada_funcionario << funcionario[i].senha << endl;
                    cada_funcionario << funcionario[i].siap << endl;
                }
            cada_funcionario.close();
            cout << "Cadastro concluido";
            sleep(2);
            system("cls");
            login_de_usuario_funcionario();
        }
    else
        {
            cout << "O SIAP informado é invalido" << endl;
            cout << "Refassa seu cadastro" << endl;
            sleep(2);
            funcao_cadastro_de_funcionario();
        }

}
