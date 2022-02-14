#ifndef PESSOA_H_INCLUDED
#define PESSOA_H_INCLUDED

#include<string>
#include <fstream>

#include<iostream>

using namespace std;

class Pessoa
{
private:
    string nome;
    string email;
    int telefone;
    int idade;

public:
    Pessoa(string _nome, string _email, int _telefone, int _idade);

    Pessoa();

    void setNome(string _nome);
    string getNome();

    void setEmail(string _email);
    string getEmail();

    void setTelefone(int _telefone);
    int getTelefone();

    void setIdade(int _idade);
    int getIdade();
};

Pessoa :: Pessoa(string _nome, string _email, int _telefone, int _idade){
    nome = _nome;
    email = _email;
    telefone = _telefone;
    idade = _idade;
}

Pessoa::Pessoa(){}

void Pessoa :: setNome(string _nome){
    nome = _nome;
}

string Pessoa::getNome(){
    return nome;
}

void Pessoa :: setEmail(string _email){
    email = _email;
}

string Pessoa :: getEmail(){
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