#include<stdio.h>
#include"Comandos.h"
#include"Professor.h"
#include<iostream>
#include "sqlite3.h"

using namespace std;

int main()
{
    int opcao;
    string nome;
    string email;
    int telefone;
    int idade;
    int ano;
    string materia;
    bool retorno;

    Comandos *comando = new Comandos();

    do
    {
        cout << "\nSelecione a opcao:\n";
        cout << "1 - Cadastrar\n";
        cout << "2 - Alterar\n";
        cout << "3 - Listar\n";
        cout << "4 - Excluir\n";
        cout << "0 - Sair\n";
        cout << ">";
        cin >> opcao;

        switch (opcao)
        {
        case 1:
            
            cout << "\n1 - Aluno\n";
            cout << "2 - Professor\n";
            cin >> opcao;

            if (opcao == 1)
            {
                cout << "\nDigite o nome: ";
                cin >> nome;
                cout << "\nDigite o email: ";
                cin >> email;
                cout << "\nDigite o telefone: ";
                cin >> telefone;
                cout << "\nDigite a idade: ";
                cin >> idade;
                cout << "\nDigite o ano da matricula: ";
                cin >> ano;

                retorno = comando->cadastrarAluno(nome, email, telefone, idade, ano);

                if (retorno = SQLITE_DONE)
                {
                    cout << "\nAluno Cadastrado com Sucesso!\n";
                }else
                {
                    cout << "\nNao foi possivel realizar cadastro!\n";
                }
                

            }else if (opcao == 2)
            {
                cout << "\nDigite o nome: ";
                cin >> nome;
                cout << "\nDigite o email: ";
                cin >> email;
                cout << "\nDigite o telefone: ";
                cin >> telefone;
                cout << "\nDigite a idade: ";
                cin >> idade;
                cout << "\nDigite a materia: ";
                cin >> materia;

                Professor *professor = new Professor(nome, email, telefone, idade, materia);

                retorno = comando->cadastrarProfessor(*professor);

                if (retorno = SQLITE_DONE)
                {
                    cout << "\nProfessor Cadastrado com Sucesso!\n";
                }else
                {
                    cout << "\nNao foi possivel realizar cadastro!\n";
                }

            }else
            {
                cout << "\nOpcao invalida\n";
            }
            
        break;

        case 3:
            comando->listar();
        break;

        case 0: break;
        
        default:
            printf("\nOpcao invalida\n");
        break;
        }
    } while (opcao != 0);
    
    return 0;
}
