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

using namespace std;

class Comandos
{
public:
    int cadastrarProfessor(Professor professor);

    int cadastrarAluno(Aluno aluno);

    bool excluir(string nome);

    void listar();

    Comandos();

};

Comandos::Comandos(){}

int Comandos :: cadastrarProfessor(Professor professor){

    sqlite3* DB;
    int exit = 0;
    exit = sqlite3_open("seminario.db", &DB);

    if (exit) {
        cerr << "Erro na abertura " << sqlite3_errmsg(DB) << endl;
        return 0;
    }
    else{
        cout << "\n" << "Arquivo aberto com sucesso" << endl;
        stringstream strm;
        stringstream strmP;

        strm << "insert into pessoa(nome, email, telefone, idade) values('"<< professor.getNome() <<"', '" << professor.getEmail() << "', " << professor.getTelefone() << ", " << professor.getIdade() << ")";
        strmP << "insert into professor(nome, materia) values('" << professor.getNome() << "', '" << professor.getMateria() << "')";

        string s = strm.str();
        char *str = &s[0];

        string sP = strmP.str();
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

int Comandos :: cadastrarAluno(Aluno aluno){

    sqlite3* DB;
    int exit = 0;
    exit = sqlite3_open("seminario.db", &DB);

    if (exit) {
        cerr << "Erro na abertura " << sqlite3_errmsg(DB) << std::endl;
        return 0;
    }
    else{
        cout << "\n" << "Arquivo aberto com sucesso" << endl;
        stringstream strm;
        stringstream strmA;
        strm << "insert into pessoa(nome, email, telefone, idade) values('" << aluno.getNome() << "', '" << aluno.getEmail() << "', " << aluno.getTelefone() << ", " << aluno.getIdade() << ")";
        strmA << "insert into aluno(nome, anoMatricula) values('" << aluno.getNome() << "', " << aluno.getAnoMatricula() << ")";

        string s = strm.str();
        char *str = &s[0];

        string sA = strmA.str();
        char *strA = &sA[0];

        sqlite3_stmt *statement;
        int result;

        char *query = str; {
            if(sqlite3_prepare(DB,query,-1,&statement,0)==SQLITE_OK) {
                sqlite3_step(statement);
                sqlite3_finalize(statement);
            }
        }
        
        char *queryA = strA; {
            if(sqlite3_prepare(DB,queryA,-1,&statement,0)==SQLITE_OK) {
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

void Comandos::listar(){

}

#endif