#include "bibliotecas.h"
#include "aluno.h"
#include "funcionario.h"
#include "administrador.h"
using namespace std;

void tipo_de_usuario()
{
    int cadastro_de_usuario, aux, finalizacao;

    cout << "Com que tipo de usu�rio voc� deseja utilizar?  " << endl << "Aluno(1)" << endl << "Funcion�rio(2)" << endl << "Loja(3)" << endl << "Administrdor(4)" << endl;
    cin >> cadastro_de_usuario;
    system("cls");
    switch(cadastro_de_usuario)
        {
        case(1):
            cout << "Ja tem usu�rio cadastrado? ( Sim (1) ou N�o(2))" << endl;
            cin >> aux;
            system("cls");
            switch(aux)
                {
                case(1):
                    cout << "Deseja fazer login? (SIM(1) ou N�o(2))" << endl;
                    cin >> aux;
                    system("cls");
                    switch(aux)
                        {
                        case(1):
                            login_de_usuario_aluno();
                            break;
                        case(2):
                            cout << "Programa finalizado";
                            exit;
                            break;
                        default:
                            break;
                        }
                    break;
                case(2):
                    cout << "Deseja cadastrar um usu�rio? (SIM(1) ou N�o(2))" << endl;
                    cin >> aux;
                    system("cls");
                    switch(aux)
                        {
                        case(1):
                            funcao_cadastro_do_aluno();
                            break;
                        case(2):
                            cout << "Programa finalizado";
                            exit;
                            break;
                        default:
                            break;
                        }
                    break;
                }
            break;
        case(2):
            cout << "J� tem usu�rio cadastrodo? ( Sim(1) ou N�o(2))"<< endl;
            cin >> aux;
            system("cls");
            switch(aux)
                {
                case(1):
                    login_de_usuario_funcionario();
                    break;
                case(2):
                    cout << "Deseja cadastrar um usu�rio? (Sim(1) ou N�o(2)) " << endl;
                    cin >> aux;
                    system("cls");
                    switch(aux)
                        {
                        case(1):
                            funcao_cadastro_de_funcionario();
                            break;
                        case(2):
                            cout << "Programa finalizado";
                            exit;
                            break;
                        default:
                            break;
                        }
                    break;
                }
            break;
        case(3):
            cout << "EM DESENVOLVIMENTO";
            break;
        case(4):
            administrador();
        default:
            break;
        }
}
