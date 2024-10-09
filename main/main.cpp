#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <string.h>

// Fillipe de Souza Faria 24020425
// Letícia Akemi Sumida 24008474
// Lucas de Campos Ranzani 24004942
// Luis Gustavo Oliveira da Silva 24011554

using namespace std;

struct Livro
{
    char titulo[100];
    char autor[100];
    int numPag;
    int anoPublicacao;
    int codigoUnico;
    int qtdDisponivel;
    char pessoasComExemplares[100];
};

// 1. Cadastro de livros:
void Cadastrar(struct Livro li[], int *qtd)
{
    system("cls");
    cout << "Cadastrar livros: " << endl;

    cout << "Titulo: ";
    cin.ignore();
    cin.getline(li[*qtd].titulo, 100);

    cout << "Autor: ";
    cin.getline(li[*qtd].autor, 100);

    cout << "Numero de Paginas: ";
    cin >> li[*qtd].numPag;

    cout << "Ano de Publicao: ";
    cin >> li[*qtd].anoPublicacao;

    cout << "codigo unico: ";
    cin >> li[*qtd].codigoUnico;

    cout << "Quantidade disponivel: ";
    cin >> li[*qtd].qtdDisponivel;

    cout << "Nome das pessoas que estao com exemplares: ";
    cin.ignore();
    cin.getline(li[*qtd].pessoasComExemplares, 100);

    cout << "-------------------------------------------------------------\n";

    (*qtd)++;
}

// 2. Consulta de livros:
void MostraLivros(struct Livro li[], int qtd)
{
    system("cls");
    for (int i = 0; i < qtd; i++)
    {
        cout << "Titulo: " << li[i].titulo << endl;
        cout << "Autor: " << li[i].autor << endl;
        cout << "Numero de Paginas: " << li[i].numPag << endl;
        cout << "Ano de Publicacao: " << li[i].anoPublicacao << endl;
        cout << "Codigo Unico: " << li[i].codigoUnico << endl;
        cout << "Quantidade Disponivel: " << li[i].qtdDisponivel << endl;
        cout << "Pessoas com Exemplares: " << li[i].pessoasComExemplares << endl;
        cout << "-------------------------------------------------------------\n";
    }
}

void BuscarLivro(struct Livro li[], int qtd)
{
    system("cls");
    bool encontrado = false;
    int ID = 0;
    cout << "Digite o ID do livro: ";
    cin >> ID;

    for (int i = 0; i < qtd; i++)
    {

        if (li[i].codigoUnico == ID)
        {
            cout << "Titulo: " << li[i].titulo << endl;
            cout << "Autor: " << li[i].autor << endl;
            cout << "Numero de Paginas: " << li[i].numPag << endl;
            cout << "Ano de Publicacao: " << li[i].anoPublicacao << endl;
            cout << "Codigo Unico: " << li[i].codigoUnico << endl;
            cout << "Quantidade Disponivel: " << li[i].qtdDisponivel << endl;
            cout << "Pessoas com Exemplares: " << li[i].pessoasComExemplares << endl;
            cout << "-------------------------------------------------------------\n";
            bool encontrado = true;
        }
    }
    if (encontrado)
        cout << "Livro nao encontrado!" << endl;
}

// 3. Empréstimo de livros:
void EmprestimoLivro(struct Livro li[], int qtd)
{
    system("cls");
    char livro[50], nome[50];

    cout << "Digite seu nome: ";
    cin.ignore();
    cin.getline(nome, 50);

    cout << "Digite o nome do livro: ";
    cin.ignore();
    cin.getline(livro, 50);

    for (int i = 0; i < qtd; i++)
    {
        if (strcmp(livro, li[i].titulo) && li[i].qtdDisponivel > 0)
        {
            li[i].qtdDisponivel -= 1;
            // Verifica se já há algum nome registrado e concatena
            if (strlen(li[i].pessoasComExemplares) > 0)
            {
                strcat(li[i].pessoasComExemplares, ", ");
            }
            strcat(li[i].pessoasComExemplares, nome);

            cout << "Livro Emprestado!" << endl;
            break;
        }
        else
        {
            cout << "Nao Possuimos este Livro!" << endl;
            cout << "-------------------------------------------------------------\n";
            break;
        }
    }
}

// 5. Remoção de livros:
void RemoverLivro(struct Livro li[], int *qtd)
{
    system("cls");

    int ID = 0;
    int indexLi = 0;
    bool encontrado = false;

    while (!encontrado)
    {
        cout << "Digite o ID do livro:";
        cin >> ID;

        for (int i = 0; i < *qtd; i++)
        {
            if (li[i].codigoUnico == ID)
            {
                indexLi = i;
                encontrado = true;
                break;
            }
        }

        if (!encontrado)
        {
            cout << "Nao foi possivel encontrar o livro!" << endl;
            cout << "-------------------------------------------------------------\n";
            break;
        }
    }

    if (encontrado)
    {
        for (int i = 0; i < *qtd; i++)
        {
            if (i == indexLi)
            {
                li[i] = li[i + 1];
                (*qtd)--;
            }
        }

        cout << "Livro removido" << endl;
        cout << "-------------------------------------------------------------\n";
    }
}

int main()
{
    struct Livro li[100];
    int qtd = 0;
    int opt = 0;

    while (opt != 6)
    {
        cout << "1.Cadastro de Livro\n2.Consulta de Livro\n3.Emprestimo de Livro\n4.Devolucao de Livro\n5.Remocao Livro\nEscolha uma opcao: ";
        cin >> opt;

        switch (opt)
        {
        case 1:
        {
            Cadastrar(li, &qtd);
            break;
        }
        case 2:
        {
            int escolha = 0;

            while (escolha != (1 || 2))
            {
                cout << "Escolha uma opcao (1/2)" << endl;
                cout << "1 - Mostrar todos os livros cadastrados" << endl;
                cout << "2 - Mostrar livro especifico" << endl;
                cin >> escolha;

                if (escolha == 1)
                {
                    MostraLivros(li, qtd);
                    break;
                }
                else if (escolha == 2)
                {
                    BuscarLivro(li, qtd);
                    break;
                }
            }
            break;
        }
        case 3:
        {
            EmprestimoLivro(li, qtd);
            break;
        }
        case 4:
        {
            break;
        }
        case 5:
        {
            RemoverLivro(li, &qtd);
            break;
        }
        }
    }
    return 0;
}
