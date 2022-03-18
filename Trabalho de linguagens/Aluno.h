#ifndef ALUNO_H_INCLUDED
#define ALUNO_H_INCLUDED

#include"Pessoa.h"
#include<iostream>

using namespace std;

class Aluno: public Pessoa
{
    private:
        int anoMatricula;

    public:
        Aluno(string _nome, string _email, int _telefone, int _idade, int _anoMatricula);

        void Imprimir(){
            cout << "Imprimindo Aluno";
        }

        void setAnoMatricula(int anoMatricula);

        int getAnoMatricula();
};

Aluno :: Aluno(string _nome, string _email, int _telefone, int _idade, int _anoMatricula){
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