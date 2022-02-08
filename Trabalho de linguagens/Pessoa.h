#ifndef PESSOA_H_INCLUDED
#define PESSOA_H_INCLUDED

#include<string>
#include <fstream>

class Pessoa
{
private:
    std::string nome;
    std::string email;
    int telefone;
    int idade;

public:
    Pessoa(std::string _nome, std::string _email, int _telefone, int _idade);

    Pessoa();

    void setNome(std::string _nome);
    std::string getNome();

    void setEmail(std::string _email);
    std::string getEmail();

    void setTelefone(int _telefone);
    int getTelefone();

    void setIdade(int _idade);
    int getIdade();
};

Pessoa :: Pessoa(std::string _nome, std::string _email, int _telefone, int _idade){
    nome = _nome;
    email = _email;
    telefone = _telefone;
    idade = _idade;
}

Pessoa::Pessoa(){}

void Pessoa :: setNome(std::string _nome){
    nome = _nome;
}

std::string Pessoa::getNome(){
    return nome;
}

void Pessoa :: setEmail(std::string _email){
    email = _email;
}

std::string Pessoa :: getEmail(){
    return email;
}

void Pessoa :: setTelefone(int _telefone){
    telefone = _telefone;
}

int Pessoa :: getTelefone(){
    return telefone;
}

void Pessoa :: setIdade(int _idade){
    idade = _idade;
}

int Pessoa :: getIdade(){
    return idade;
}

#endif