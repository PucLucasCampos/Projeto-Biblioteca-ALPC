#include <iostream>
#include <stdio.h>;

using namespace std;

struct Livro {
    char titulo[100];
    char autor[100];
    int numPag;
    int anoPublicacao;
    int codigoUnico;
    int qtdDisponivel;
    char pessoasComEmxemplares[100];
};

void Cadastrar(struct Livro li){
    cout << "Cadastrar livros: " << endl;

    cout << "Titulo: ";
    fgets(li.titulo, 100, stdin);

    cout << "Autor: ";
    fgets(li.autor, 100, stdin);

    cout << "Numero de Paginas: ";
    cin >> li.numPag;

    cout << "Ano de Publicação: ";
    cin >> li.anoPublicacao;

    cout << "codigo unico: ";
    cin >> li.codigoUnico;

    cout << "Quantidade disponivel: ";
    cin >> li.qtdDisponivel;

    cout << "Nome das pessoas que estão com exemplares: ";
    fgets(li.pessoasComEmxemplares, 100, stdin);

}

int main()
{

    return 0;
}
