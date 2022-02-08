#ifndef COMANDOS_H_INCLUDED
#define COMANDOS_H_INCLUDED

#include"Professor.h"
#include"Aluno.h"
#include<string>
#include<iostream>
#include<fstream>
#include<stdio.h>
#include"sqlite3.h"
#include<sstream>

class Comandos
{
public:
    int cadastrarProfessor(Professor professor);

    bool cadastrarAluno(std::string nome, std::string email, int telefone, int idade, int anoMatricula);

    bool excluir(std::string nome);

    void listar();

    Comandos();

};

Comandos::Comandos(){}

int Comandos :: cadastrarProfessor(Professor professor){

    sqlite3* DB;
    int exit = 0;
    exit = sqlite3_open("seminario.db", &DB);

    if (exit) {
        std::cerr << "Erro na abertura " << sqlite3_errmsg(DB) << std::endl;
        return 0;
    }
    else{
        std::cout << "\n" << "Arquivo aberto com sucesso" << std::endl;
        std::stringstream strm;
        std::stringstream strmP;
        strm << "insert into pessoa(nome, email, telefone, idade) values(" << professor.getNome() << ", " << professor.getEmail() << ", " << professor.getTelefone() << ", " << professor.getIdade() << ")";
        strmP << "insert into professor(nome, materia) values(" << professor.getNome() << ", " << professor.getMateria() << ")";

        std::string s = strm.str();
        char *str = &s[0];

        std::string sP = strmP.str();
        char *strP = &sP[0];

        sqlite3_stmt *statement;
        int result;

        char *query = str; {
            if(sqlite3_prepare(DB,query,-1,&statement,0)==SQLITE_OK) {
                sqlite3_step(statement);
                sqlite3_finalize(statement);
            }
        }
        
        char *queryP = strP; {
            if(sqlite3_prepare(DB,queryP,-1,&statement,0)==SQLITE_OK) {
                int res=sqlite3_step(statement);
                result=res;
                sqlite3_finalize(statement);
            }
            sqlite3_close(DB);
            return result;
        }
    }

    return -1;
}

bool Comandos :: cadastrarAluno(std::string nome, std::string email, int telefone, int idade, int anoMatricula){

    Aluno *aluno = new Aluno(nome, email, telefone, idade, anoMatricula);

    std::ofstream ofs("Alunos.txt", std::fstream::app);

    ofs << "Nome: ";
    ofs << aluno->getNome();
    ofs << " / " << "Email: " << aluno->getEmail();
    ofs << " / " << "Telefone: " << aluno->getTelefone();
    ofs << " / " << "Idade: " << aluno->getIdade();
    ofs << " / " << "Materia: " << aluno->getAnoMatricula();

    ofs.close();

    return true;
}

void Comandos::listar(){

    Professor *p;

    std::ifstream ifsP ("Professores.txt");

    std::cout << "\nPROFESSORES\n";

    if (ifsP.is_open())
    {
        std::string linha;
        while (getline(ifsP, linha))
        {
            std::cout << "\n" << linha << "\n";
        }
        
    }else
    {
        std::cout << "Nao foi possivel abrir o arquivo de Professores";
    }
    
    ifsP.close();
    
    Aluno *a;

    std::ifstream ifsA ("Alunos.txt");

    std::cout << "\nALUNOS\n";

    if (ifsA.is_open())
    {
        std::string linha;
        while (getline(ifsA, linha))
        {
            std::cout << "\n" << linha << "\n";
        }
        
    }else
    {
        std::cout << "Nao foi possivel abrir o arquivo de Alunos";
    }
    
    ifsA.close();
}

#endif