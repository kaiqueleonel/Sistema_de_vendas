#include <iostream>
#include <fstream>
#include <time.h>
#include <ctime>
#include <cstring>
#include <unistd.h>
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
void funcao_cadastro_do_aluno()
{
    cadastro_do_aluno aluno;
    int aux = 0;
    int ano, turno,curso;
    system("cls");
    cout << "informe o nome: ";
    fflush(stdin);
    getline(cin, aluno.nome_do_aluno);
    system("cls");
    cout << "informe o numero da matricula: ";
    cin.getline(aluno.matricula,18);
    system("cls");
    aux = strlen(aluno.matricula);
    if(aux == 17)
        {
            cout << "informe a senha: ";
            cin >> aluno.senha;
            system("cls");
            cout << "informe o nome do curso (Infirmática(1); Controle Ambiental (2); Administração(3)): " << endl;
            cin >> curso;
            switch(curso)
                {
                case(1):
                    aluno.nome_do_curso = "Informatica";
                    break;
                case(2):
                    aluno.nome_do_curso = "Controle Ambiental";
                    break;
                case(3):
                    aluno.nome_do_curso = "Administração";
                    break;
                default:
                    cout << "Curso não encontrado" << endl;
                    break;
                }
            system("cls");
            cout << "informe o turno de aula (Matutino(1); Vespertino(2)): "  << endl;
            cin >> turno;
            switch(turno)
                {
                case(1):
                    aluno.turno = "Matutino";
                    break;
                case(2):
                    aluno.turno = "Vespertino";
                    break;
                default:
                    cout << "O turno está errado" << endl;
                    break;
                }
            system("cls");
            cout << "informe o ano que esta cursando( 1°ano(1); 2°ano(2); 3°ano(3): " << endl;
            cin >> ano;
            switch(ano)
                {
                case (1):
                    aluno.ano = "1°ano";
                    break;
                case (2):
                    aluno.ano = "2°ano";
                    break;
                case (3):
                    aluno.ano = "3°ano";
                    break;
                default:
                    cout << "O ano que está cursando é invalido" << endl;
                    break;
                }
            system("cls");
            aluno.numero_usuario++;
            ofstream cdt_aluno;
            cdt_aluno.open("aluno_cadastrado");
            cdt_aluno << aluno.numero_usuario << endl;
            cdt_aluno << aluno.nome_do_aluno << endl;
            cdt_aluno << aluno.matricula << endl;
            cdt_aluno << aluno.senha << endl;
            cdt_aluno << aluno.nome_do_curso << endl;
            cdt_aluno << aluno.turno << endl;
            cdt_aluno << aluno.ano << endl;
            cdt_aluno.close();
        }
    else
        {
            cout << "Matricula invalida" << endl;
            cout << "Refaça seu cadastro " << endl;
            sleep(2);
            funcao_cadastro_do_aluno();
        }
}


void funcao_cadastro_de_funcionario()
{
    cadastro_funcionario funcionario;
    int aux = 0;
    system("cls");
    cout << "Informe seu nome: ";
    cin >> funcionario.nome;
    system("cls");
    cout << "Informe o seu cargo: ";
    cin >> funcionario.cargo;
    system("cls");
    cout << "Informe seu SIAP: ";
    //o cin. getline está dando erro, ainda não encontrado
    cin.getline(funcionario.siap,8);
    system("cls");
    aux = strlen(funcionario.siap);
    cout << aux << endl;
    if(aux == 7)
        {
            ofstream cada_funcionario;
            cada_funcionario.open("cadastro_de_funcionario");
            cada_funcionario << funcionario.nome << endl;
            cada_funcionario << funcionario.cargo << endl;
            cada_funcionario << funcionario.siap << endl;
            cada_funcionario.close();
        }
    else
        {
            cout << "O SIAP informado é invalido" << endl;
            cout << "Refassa seu cadastro" << endl;
            sleep(2);
            funcao_cadastro_de_funcionario();
        }

}
void tipo_de_usuario()
{
    int cadastro_de_usuario, aux, finalizacao;

    cout << "Com que tipo de usuário você deseja utilizar? (digite um dos nomes) " << endl << "Aluno(1)" << endl << "Funcionário(2)" << endl << "Loja(3)" << endl;
    cin >> cadastro_de_usuario;
    system("cls");
    switch(cadastro_de_usuario)
        {
        case(1):
            cout << "Ja tem usuário cadastrado? ( Sim (1) ou Não(2))" << endl;
            cin >> aux;
            system("cls");
            switch(aux)
                {
                case(1):
                    cout << "Deseja fazer login? (SIM(1) ou Não(2))" << endl;
                    cin >> aux;
                    system("cls");
                    switch(aux)
                        {
                        case(1):
                            cout << "EMD ESENVOLVIMENTO";
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
                    cout << "Deseja cadastrar um usuário? (SIM(1) ou Não(2))" << endl;
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
            cout << "Já tem usuário cadastrodo? ( Sim(1) ou Não(2))"<< endl;
            cin >> aux;
            system("cls");
            switch(aux)
                {
                case(1):
                    cout << "EM DESENVOLVIMENTO";
                    break;
                case(2):
                    cout << "Deseja cadastrar um usuário? (Sim(1) ou Não(2)) " << endl;
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
        }
}
int main()
{
    setlocale(LC_ALL,"Portuguese");
    srand(time(NULL));
    tipo_de_usuario();
    return 0;
}
