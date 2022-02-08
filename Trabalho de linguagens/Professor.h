#ifndef PROFESSOR_H_INCLUDED
#define PROFESSOR_H_INCLUDED


#include "Pessoa.h"
#include <fstream>

class Professor: public Pessoa
{
    private:
        std::string materia;

    public:
        Professor(std::string _nome, std::string _email, int _telefone, int _idade, std::string _materia);

        void setMateria(std::string _materia);

        std::string getMateria();
        
};

Professor :: Professor(std::string _nome, std::string _email, int _telefone, int _idade, std::string _materia){
    setNome(_nome);
    setEmail(_email);
    setTelefone(_telefone);
    setIdade(_idade);
    materia = _materia;
}

void Professor :: setMateria(std::string _materia){
    materia = _materia;
}

std::string Professor :: getMateria(){
    return materia;
}

#endif
