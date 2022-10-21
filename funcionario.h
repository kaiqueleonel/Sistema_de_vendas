#ifndef FUNCIONARIO_H_INCLUDED
#define FUNCIONARIO_H_INCLUDED
#include <unistd.h>
#include <fstream>
#include <cstring>

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

void funcao_cadastro_de_funcionario();
void login_de_usuario_funcionario();


#endif // FUNCIONARIO_H_INCLUDED
