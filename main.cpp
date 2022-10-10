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
    string senha;
    char siap[7];

} cadastro_funcionario;
typedef struct
{
    char siap[7];
    string senha;
} login_funcionario;

typedef struct
{
    char matricula[17];
    string senha;
}
login_aluno;

typedef struct
{
    string usuario_adm;
    int senha;
} adm;

void senha_da_loja()
{
    int senha[8];
    for(int i = 0; i< 8; i++)
        {
            senha[i] = rand()%9;
        }
    ofstream senha_loja;
    senha_loja.open("senha_loja.txt");
    for(int i = 0; i < 8; i++)
        {
            senha_loja << senha[i];
        }
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
            cout << "Deseja criar a senha do usuario da loja? ( sim(1) não(2))";
            cin >> aux;
            switch(aux)
                {
                case(1):
                    cout << "criando a senha...";
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

}

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

void login_de_usuario_aluno()
{
    cin.ignore();
    cout << "Faça seu login" << endl;
    sleep(1);
    system("cls");
    login_aluno login_aluno;
    int quant_aluno = 0, aux, aux_login = 0;
    string matri, matricu;
    ifstream pegar_aluno;
    pegar_aluno.open("cadastro_aluno.txt");
    pegar_aluno >> quant_aluno;
    cadastro_do_aluno aluno[quant_aluno];
    for(int i = 0; i < quant_aluno; i++)
        {
            pegar_aluno >> aluno[i].nome_do_aluno;
            pegar_aluno >> aluno[i].matricula;
            pegar_aluno >> aluno[i].senha;
            pegar_aluno >> aluno[i].nome_do_curso;
            pegar_aluno >> aluno[i].turno;
            pegar_aluno >> aluno[i].ano;
        }
    pegar_aluno.close();
    cout << "Digite sua matricula: ";
    cin.getline(login_aluno.matricula, 18);
    system("cls");
    aux = strlen(login_aluno.matricula);
    matri = login_aluno.matricula;
    if( aux == 17)
        {
            cout << "Digite sua senha: ";
            cin >> login_aluno.senha;
            system("cls");
            for( int i = 0; i < quant_aluno; i++)
                {
                    matricu = aluno[i].matricula;
                    if(matri == matricu && login_aluno.senha == aluno[i].senha)
                        {
                            cout << "Login aprovado" << endl;
                            sleep(2);
                            system("cls");
                            aux_login = 1;
                        }
                }
            if(aux_login == 0)
                {
                    cout << "Login não aprovado" << endl << "Faça o login novamente" << endl;
                    sleep(2);
                    system("cls");
                    login_de_usuario_aluno();
                }
        }
}

void funcao_cadastro_do_aluno()
{
    int aluno_cont = 0, aux = 0,ano, turno,curso;
    ifstream pegar_alunos;
    pegar_alunos.open("cadastro_aluno.txt");
    pegar_alunos >> aluno_cont;
    aluno_cont++;
    cadastro_do_aluno aluno[aluno_cont];
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
            cout << "informe o nome do curso" << endl <<"Infirmática(1)" << endl << "Controle Ambiental (2)" <<  endl <<"Administração(3)" << endl;
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
                    aluno[aluno_cont - 1].nome_do_curso = "Administração";
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
                    aluno[aluno_cont - 1].turno = "Matutino";
                    break;
                case(2):
                    aluno[aluno_cont - 1].turno = "Vespertino";
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
                    aluno[aluno_cont - 1].ano = "1°ano";
                    break;
                case (2):
                    aluno[aluno_cont - 1].ano = "2°ano";
                    break;
                case (3):
                    aluno[aluno_cont - 1].ano = "3°ano";
                    break;
                default:
                    cout << "O ano que está cursando é invalido" << endl;
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
            cout << "Cadastro concluido" << endl;
            sleep(2);
            system("cls");
            login_de_usuario_aluno();
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

void tipo_de_usuario()
{
    int cadastro_de_usuario, aux, finalizacao;

    cout << "Com que tipo de usuário você deseja utilizar?  " << endl << "Aluno(1)" << endl << "Funcionário(2)" << endl << "Loja(3)" << endl << "Administrdor(4)" << endl;
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
                    login_de_usuario_funcionario();
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
        case(4):
            administrador();
        default:
            break;
        }
}
int main()
{
    setlocale(LC_ALL,"Portuguese");
    srand(time(NULL));
    senha_da_loja();
    tipo_de_usuario();
    return 0;
}
