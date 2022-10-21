#ifndef ALUNO_H_INCLUDED
#define ALUNO_H_INCLUDED

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

void funcao_cadastro_do_aluno();
void login_de_usuario_aluno();

#endif // ALUNO_H_INCLUDED
