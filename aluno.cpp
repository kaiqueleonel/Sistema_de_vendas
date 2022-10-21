#include "bibliotecas.h"

using namespace std;

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
    char matricula[17];
    string senha;
}
login_aluno;

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
