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
    int qtdEmprestada;
    char pessoasComExemplares[10][100];
};

// Função que valida se o ID ja existe
bool validaId(struct Livro li[], int qtd, int *ID){
    bool encontrado = false;

    do {
        encontrado = false;

        cout << "Digite o ID do livro: ";
        cin >> *ID;

        for (int i = 0; i < qtd; i++) {
            if (li[i].codigoUnico == *ID) {
                encontrado = true;
                cout << "ID já existe. Digite outro ID." << endl;
                break;
            }
        }
    } while (encontrado);

    return true;
}

// 1. Cadastro de livros:
void Cadastrar(struct Livro li[], int *qtd){
    system("cls");
    int codigo = 0;
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

    if (*qtd == 0){
        cout << "Digite o ID do livro:";
        cin >> li[*qtd].codigoUnico;;
    }else{
        if (validaId(li, *qtd, &codigo)) li[*qtd].codigoUnico = codigo;
    }


    cout << "Quantidade disponivel: ";
    cin >> li[*qtd].qtdDisponivel;

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
        cout << "Pessoas com Exemplares: " << endl;
        for (int j = 0; j < 10; j++) {
            if(strlen(li[i].pessoasComExemplares[j]) != 0){
                cout << li[i].pessoasComExemplares[j] << ", ";
            }
        }
        cout << "\n-------------------------------------------------------------\n";
    }
}

// 2.1 Consulta de livros por ID:
void BuscarLivroId(struct Livro li[], int qtd)
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
            for (int j = 0; j < 10; j++) {
                if(strlen(li[i].pessoasComExemplares[j]) != 0){
                    cout << li[i].pessoasComExemplares[j] << ", ";
                }
            }
            cout << "\n-------------------------------------------------------------\n";
            bool encontrado = true;
            return;
        }
    }

    if (!encontrado)
        cout << "Livro nao encontrado!" << endl;
}

// 2.2 Consulta de livros pelo Titulo:
void BuscarLivroAutor(struct Livro li[], int qtd){
    system("cls");
    bool encontrado = false;
    char titulo[100];
    cout << "Digite o título do livro: ";
    cin.ignore();
    cin.getline(titulo, 100);

    for (int i=0; i<qtd; i++){
        if (strcmp(titulo, li[i].titulo) == 0){
            cout << "Titulo: " << li[i].titulo << endl;
            cout << "Autor: " << li[i].autor << endl;
            cout << "Numero de Paginas: " << li[i].numPag << endl;
            cout << "Ano de Publicacao: " << li[i].anoPublicacao << endl;
            cout << "Codigo Unico: " << li[i].codigoUnico << endl;
            cout << "Quantidade Disponivel: " << li[i].qtdDisponivel << endl;
            for (int j = 0; j < qtd; j++) {
               cout << "Pessoas com Exemplares: " << li[i].pessoasComExemplares[j] << endl;
               break;
            }
            cout << "-------------------------------------------------------------\n";
            bool encontrado = true;
            return;
        }
    }
    if (encontrado == false) cout << "Livro nao encontrado!" << endl;
}

// 3. Empréstimo de livros:
void EmprestimoLivro(struct Livro li[], int qtd)
{
    system("cls");
    char livro[100], nome[100];

    cout << "Digite seu nome: ";
    cin.ignore();
    cin.getline(nome, 100);

    cout << "Digite o nome do livro: ";

    cin.ignore(0);
    cin.getline(livro, 100);

    for (int i = 0; i < qtd; i++){
        if (strcmp(livro, li[i].titulo) == 0 && li[i].qtdDisponivel > 0){
            li[i].qtdDisponivel -= 1;
            li[i].qtdEmprestada += 1;

            for (int j = 0; j < 10; j++){
                if(strlen(li[i].pessoasComExemplares[j]) == 0){
                    strcpy(li[i].pessoasComExemplares[j], nome);
                    break;
                }
            }
            cout << "Livro Emprestado!" << endl;
            return;
        }
    }
    
    cout << "Nao Possuimos este Livro!" << endl;
    cout << "-------------------------------------------------------------\n";
    return;
}

// 4. Devolução de livros
void DevolverLivro (struct Livro li[], int qtd){
    system("cls");
    
    bool pEncontrado = false;
    bool liEncontrado = false;
    char livro[100], nome[100];
    
    cout << "Digite o nome do livro devolvido: ";
    cin.ignore();
    cin.getline(livro, 100);
    
    for (int i = 0; i < qtd; i++){
        if (strcmp(livro, li[i].titulo) == 0){
            cout << "Livro encontrado!" << endl;
            liEncontrado = true;
            
            cout << "Digite o nome de quem o devolveu: ";
            cin.ignore(0);
            cin.getline(nome, 100);
            
            if(strlen(nome) != 0){
                for (int j = 0; j < 10; j++){
                    if (strcmp(nome, li[i].pessoasComExemplares[j]) == 0) {
                        cout << "Pessoa encontrada!" <<endl;
                        pEncontrado = true;
                        
                        strcpy(li[i].pessoasComExemplares[j], "");
                        li[i].qtdDisponivel += 1;
                        li[i].qtdEmprestada -= 1;
                        cout << "Livro devolvido com sucesso!"<< endl;
                        break;
                    }
                }
            }
            break;
        }
    }
    
    if (liEncontrado == true){
        if (pEncontrado == false){
            cout << "Nome não encontrado, tente novamente!";
        }
    }else{
        cout<<"Livro não encontrado, tente novamente!"; 
    }
    
}
// 5. Remoção de livros:
void RemoverLivro(struct Livro li[], int *qtd)
{
    system("cls");

    int ID = 0;
    int indexLi = 0;
    bool encontrado = false;

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
    }
    
    if (encontrado)
    {
        for (int i = indexLi; i < *qtd; i++)
        {
            li[i] = li[i + 1];
        }
        (*qtd)--;

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

            while (escolha != (1 || 2 || 3))
            {
                cout << "Escolha uma opcao (1/2)" << endl;
                cout << "1 - Mostrar todos os livros cadastrados" << endl;
                cout << "2 - Mostrar livro especifico" << endl;
                cout << "3 - Buscar livro por titulo" << endl;
                cin >> escolha;

                if (escolha == 1)
                {
                    MostraLivros(li, qtd);
                    break;
                }
                else if (escolha == 2)
                {
                    BuscarLivroId(li, qtd);
                    break;
                }else if (escolha == 3)
                {
                    BuscarLivroAutor(li, qtd);
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
            DevolverLivro(li, qtd);
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
