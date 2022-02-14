#include <iostream>
#include <stdlib.h>
#include "sqlite3.h" 
#include <sstream>
using namespace std;

static int callback(void* data, int argc, char** argv, char** azColName)
{
  
    for (int i = 0; i < argc; i++) {
        printf("%s: %s/ ", azColName[i], argv[i] ? argv[i] : "NULL");
    }
  
    printf("\n");
    return 0;
}

int adicionar(string nome, string email, int telefone, int idade){

    sqlite3* DB;
    sqlite3_open("pessoa.db", &DB);
    int result;

        stringstream strm;
        strm << "insert into pessoa(nome, email, telefone, idade) values('" << nome << "', '" << email << "', " << telefone << ", " << idade << ")";
        string s = strm.str();
        char *str = &s[0];
        sqlite3_stmt *statement;

        char *query = str; {
            if(sqlite3_prepare(DB,query,-1,&statement,0)==SQLITE_OK) {
                result = sqlite3_step(statement);
                sqlite3_finalize(statement);
            }
        }
    sqlite3_close(DB);
    return result;
}

void listar(){

    sqlite3* DB;
    sqlite3_open("pessoa.db", &DB);

    string query = "select * from pessoa";

    sqlite3_exec(DB, query.c_str(), callback, NULL, NULL);
}

int deletar(string nome){

    sqlite3* DB;
    sqlite3_open("pessoa.db", &DB);

    stringstream strm;
    strm << "delete from pessoa where nome='" << nome << "'";

    string s = strm.str();
    char *str = &s[0];

    sqlite3_stmt *statement;
    int result;
    char *query = str;

    {
        if(sqlite3_prepare(DB,query,-1,&statement,0)==SQLITE_OK) {
            int res=sqlite3_step(statement);
            result=res;
            sqlite3_finalize(statement);
        }

    }
    sqlite3_close(DB);
    return result;
}

int alterar(string nome,string email, int telefone, int idade){

    sqlite3* DB;
    sqlite3_open("pessoa.db", &DB);

    stringstream strm;
    strm << "update pessoa set email = '" << email << "',telefone = " << telefone << ",idade = " << idade << " where nome ='"<<nome<<"'";

    string s = strm.str();
    char *str = &s[0];

    sqlite3_stmt *statement;
    int result;
    char *query = str;

    {
        if(sqlite3_prepare(DB,query,-1,&statement,0)==SQLITE_OK) {
            int res=sqlite3_step(statement);
            result=res;
            sqlite3_finalize(statement);
        }

    }
    sqlite3_close(DB);
    return result;
}

int main(int argc, char* argv[]) {
   
   int opcao = 1;
   string nome;
   string email;
   int telefone;
   int idade;
   int retorno;

   while (opcao != 0)
   {
       cout << "\nEscolha uma opcao" << endl;
       cout << "1 - Adicionar" << endl;
       cout << "2 - Remover" << endl;
       cout << "3 - Atualizar" << endl;
       cout << "4 - Listar" << endl;
       cout << "0 - Sair" << endl;
       cout << "> ";
       cin >> opcao;

       switch (opcao)
       {
       case 1:
            cout<<"\nNome: ";
            cin>> nome;
            cout<<"Email: ";
            cin>> email;
            cout<<"Telefone: ";
            cin>> telefone;
            cout<<"Idade: ";
            cin>> idade;
            retorno = adicionar(nome, email, telefone, idade);

            if (retorno == SQLITE_DONE)
                {
                    cout << "\nPessoa Cadastrada com Sucesso!\n";
            }else{
                cout << "\nNao foi possivel realizar cadastro!\n";
            }
           break;

        case 2: 

            cout<<"Digite o nome: ";
            cin>>nome;

            retorno = deletar(nome);

            if (retorno == SQLITE_DONE)
                {
                    cout << "\nPessoa Excluida\n";
            }else{
                cout << "\nNao foi possivel excluir\n";
            }
        break;

        case 3:
            cout<<"\nNome: ";
            cin>> nome;
            cout<<"Email: ";
            cin>> email;
            cout<<"Telefone: ";
            cin>> telefone;
            cout<<"Idade: ";
            cin>> idade;
            retorno = alterar(nome, email, telefone, idade);

            if (retorno == SQLITE_DONE)
                {
                    cout << "\n" << nome <<" alterado com sucesso\n";
            }else{
                cout << "\nNao foi possivel alterar "<<nome<<"\n";
            }
        break;
       case 4:
            listar();
            break;
       default:
           break;
       }
   }
   
   return 0;
}



