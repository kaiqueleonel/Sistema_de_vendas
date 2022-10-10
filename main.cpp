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
    char siap[7];
}
cadastro_funcionario;

typedef struct
{
    char matricula[17];
    string senha;
}
login_aluno;

void login_de_usuario_aluno()
{
    login_aluno login_aluno;
    int quant_aluno = 0, aux;
    cadastro_do_aluno aluno;
    ifstream pegar_aluno;
    pegar_aluno.open("cadastro_aluno.txt");
    pegar_aluno >> quant_aluno;
    for(int i = 0; i < quant_aluno; i++)
        {
            pegar_aluno >> aluno[i].nome_do_aluno;
            pegar_aluno >> aluno[i].matricula;
            pegar_aluno >> aluno[i].senha;
            pegar_aluno >> aluno[i].nome_do_curso;
            pegar_aluno >> aluno[i].turno;
            pegar_aluno >> aluno[i].ano;
        }
    pegar_quant_aluno.close();
    cout << "Digite sua matricula: ";
    cin.getline(login_aluno.matricula, 18);
    system("cls");
    aux = strlen(login_aluno.matricula);
    if( aux == 17)
        {
            cout << "Digite sua senha: ";
            cin >> login_aluno.senha;
            system("cls");
            for( int i = 0; i < quant_aluno; i++)
                {
                    if(login_aluno.matricula == aluno[i].matricula && login_aluno.senha == aluno[i].senha) {}
                    cout << "Login aprovado" << endl;
                }
            else
                {
                    cout << "Login n�o aprovado" << endl << "Fa�a o login novamente" << endl;
                    sleep(2);
                    system("cls");
                    login_de_usuario_aluno();
                }
        }


}

void funcao_cadastro_do_aluno()
{
    int aluno_cont = 0, lixo,aux = 0,ano, turno,curso;
    ifstream pegar_alunos;
    pegar_alunos.open("cadastro_aluno.txt");
    pegar_alunos >> aluno_cont;
    aluno_cont++;
    cadastro_do_aluno aluno[aluno_cont];
    pegar_alunos >> lixo;
    for (int i = 0; i < aluno_cont; i++)
        {
            pegar_alunos >> aluno[i].nome_do_aluno;
            pegar_alunos >> aluno[i].matricula;
            pegar_alunos >> aluno[i].senha;
            pegar_alunos >> aluno[i].nome_do_curso;
            pegar_alunos >> aluno[i].turno;
            pegar_alunos >> aluno[i].ano;
        }
    pegar_alunos.close();

    system("cls");
    cout << "informe o nome:";
    fflush(stdin);
    getline(cin, aluno[aluno_cont - 1].nome_do_aluno);
    system("cls");
    cout << "informe o numero da matricula: ";
    cin.getline(aluno[aluno_cont - 1].matricula,18);
    system("cls");
    aux = strlen(aluno[aluno_cont - 1].matricula);
    if(aux == 17)
        {
            cout << "informe a senha: ";
            cin >> aluno[aluno_cont - 1].senha;
            system("cls");
            cout << "informe o nome do curso" << endl <<"Infirm�tica(1)" << endl << "Controle Ambiental (2)" <<  endl <<"Administra��o(3)" << endl;
            cin >> curso;
            switch(curso)
                {
                case(1):
                    aluno[aluno_cont - 1].nome_do_curso = "Informatica";
                    break;
                case(2):
                    aluno[aluno_cont - 1].nome_do_curso = "Controle Ambiental";
                    break;
                case(3):
                    aluno[aluno_cont - 1].nome_do_curso = "Administra��o";
                    break;
                default:
                    cout << "Curso n�o encontrado" << endl;
                    break;
                }
            system("cls");
            cout << "informe o turno de aula (Matutino(1); Vespertino(2)): "  << endl;
            cin >> turno;
            switch(turno)
                {
                case(1):
                    aluno[aluno_cont - 1].turno = "Matutino";
                    break;
                case(2):
                    aluno[aluno_cont - 1].turno = "Vespertino";
                    break;
                default:
                    cout << "O turno est� errado" << endl;
                    break;
                }
            system("cls");
            cout << "informe o ano que esta cursando( 1�ano(1); 2�ano(2); 3�ano(3): " << endl;
            cin >> ano;
            switch(ano)
                {
                case (1):
                    aluno[aluno_cont - 1].ano = "1�ano";
                    break;
                case (2):
                    aluno[aluno_cont - 1].ano = "2�ano";
                    break;
                case (3):
                    aluno[aluno_cont - 1].ano = "3�ano";
                    break;
                default:
                    cout << "O ano que est� cursando � invalido" << endl;
                    break;
                }
            system("cls");
            ofstream cdt_aluno;
            cdt_aluno.open("cadastro_aluno.txt");
            cdt_aluno << aluno_cont << endl;
            for(int i = 0; i < aluno_cont; i++)
                {
                    cdt_aluno << aluno[i].nome_do_aluno << endl;
                    cdt_aluno << aluno[i].matricula << endl;
                    cdt_aluno << aluno[i].senha << endl;
                    cdt_aluno << aluno[i].nome_do_curso << endl;
                    cdt_aluno << aluno[i].turno << endl;
                    cdt_aluno << aluno[i].ano << endl;
                }
            cdt_aluno.close();
        }
    else
        {
            cout << "Matricula invalida" << endl;
            cout << "Refa�a seu cadastro " << endl;
            sleep(2);
            funcao_cadastro_do_aluno();
        }
}

void funcao_cadastro_de_funcionario()
{


    int aux = 0;
    int quant_funcionario = 0, lixo;
    ifstream pegar_quant_funcionario;
    pegar_quant_funcionario.open("cadastro_de_funcionario.txt");
    pegar_quant_funcionario >> quant_funcionario;
    pegar_quant_funcionario.close();
    quant_funcionario++;
    cadastro_funcionario funcionario[quant_funcionario];
    ifstream pegar_cadastro;
    pegar_cadastro.open("cadastro_de_funcionario.txt");
    pegar_cadastro >> lixo;
    for(int i = 0; i < quant_funcionario; i++)
        {
            pegar_cadastro >> funcionario[i].nome;
            pegar_cadastro >> funcionario[i].cargo;
            pegar_cadastro >> funcionario[i].siap;
        }
    pegar_cadastro.close();
    system("cls");
    cout << "Informe seu nome: ";
    cin >> funcionario[quant_funcionario - 1].nome;
    system("cls");
    cout << "Informe o seu cargo: ";
    cin >> funcionario[quant_funcionario - 1].cargo;
    system("cls");
    cout << "Informe seu SIAP: ";
    cin.ignore();//perguntar como esse comando funciona direito
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
                    cada_funcionario << funcionario[i].siap << endl;
                }
            cada_funcionario.close();
        }
    else
        {
            cout << "O SIAP informado � invalido" << endl;
            cout << "Refassa seu cadastro" << endl;
            sleep(2);
            funcao_cadastro_de_funcionario();
        }

}

void tipo_de_usuario()
{
    int cadastro_de_usuario, aux, finalizacao;

    cout << "Com que tipo de usu�rio voc� deseja utilizar?  " << endl << "Aluno(1)" << endl << "Funcion�rio(2)" << endl << "Loja(3)" << endl;
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
                    cout << "EM DESENVOLVIMENTO";
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
        }
}
int main()
{
    setlocale(LC_ALL,"Portuguese");
    srand(time(NULL));
    tipo_de_usuario();
    return 0;
}
