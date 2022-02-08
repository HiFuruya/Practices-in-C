#ifndef ALUNO_H_INCLUDED
#define ALUNO_H_INCLUDED

#include"Pessoa.h"

class Aluno: public Pessoa
{
    private:
        int anoMatricula;

    public:
        Aluno(std::string _nome, std::string _email, int _telefone, int _idade, int _anoMatricula);

        void setAnoMatricula(int anoMatricula);

        int getAnoMatricula();
};

Aluno :: Aluno(std::string _nome, std::string _email, int _telefone, int _idade, int _anoMatricula){
    setNome(_nome);
    setEmail(_email);
    setTelefone(_telefone);
    setIdade(_idade);
    anoMatricula = _anoMatricula;
}

void Aluno :: setAnoMatricula(int _anoMatricula){
    anoMatricula = _anoMatricula;
}

int Aluno :: getAnoMatricula(){
    return anoMatricula;
}

#endif