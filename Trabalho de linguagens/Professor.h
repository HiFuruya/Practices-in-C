#ifndef PROFESSOR_H_INCLUDED
#define PROFESSOR_H_INCLUDED


#include "Pessoa.h"
#include <fstream>
#include<iostream>

using namespace std;

class Professor: public Pessoa
{
    private:
        string materia;

    public:
        Professor(string _nome, string _email, int _telefone, int _idade, string _materia);

        void Imprimir(){
            cout << "Imprimindo Professor";
        }

        void setMateria(string _materia);

        string getMateria();
        
};

Professor :: Professor(string _nome, string _email, int _telefone, int _idade, string _materia){
    setNome(_nome);
    setEmail(_email);
    setTelefone(_telefone);
    setIdade(_idade);
    materia = _materia;
}

void Professor :: setMateria(string _materia){
    materia = _materia;
}

string Professor :: getMateria(){
    return materia;
}

#endif
