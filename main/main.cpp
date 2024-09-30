#include <iostream>
#include <cstdio>

using namespace std;

struct Livro {
    char titulo[100];
    char autor[100];
    int numPag;
    int anoPublicacao;
    int codigoUnico;
    int qtdDisponivel;
    char pessoasComExemplares[100];
};

void Cadastrar(struct Livro li[], int *qtd){
    cout << "Cadastrar livros: " << endl;

    cout << "Titulo: ";
    fgets(li[*qtd].titulo, 100, stdin);

    cout << "Autor: ";
    fgets(li[*qtd].autor, 100, stdin);

    cout << "Numero de Paginas: ";
    cin >> li[*qtd].numPag;

    cout << "Ano de Publicao: ";
    cin >> li[*qtd].anoPublicacao;

    cout << "codigo unico: ";
    cin >> li[*qtd].codigoUnico;

    cout << "Quantidade disponivel: ";
    cin >> li[*qtd].qtdDisponivel;

    cout << "Nome das pessoas que estao com exemplares: ";
    fgets(li[*qtd].pessoasComExemplares, 100, stdin);

    (*qtd)++;
}

void MostraLivros(struct Livro li[], int qtd){
    for (int i = 0; i < qtd; i++) {
        cout << "Titulo: " << li[i].titulo << endl;
        cout << "Autor: " << li[i].autor << endl;
        cout << "Numero de Paginas: " << li[i].numPag << endl;
        cout << "Ano de Publicacao: " << li[i].anoPublicacao << endl;
        cout << "Codigo Unico: " << li[i].codigoUnico << endl;
        cout << "Quantidade Disponivel: " << li[i].qtdDisponivel << endl;
        cout << "Pessoas com Exemplares: " << li[i].pessoasComExemplares << endl;
    }
}

void BuscarLivro(struct Livro li[], int qtd){
    int ID = 0;
    cout << "Digite o ID do livro: " << endl;
    cin >> ID;
    
    for (int i=0; i<qtd; i++){
        if (li[i].codigoUnico == ID){
           cout << "Titulo: " << li[i].titulo << endl;
            cout << "Autor: " << li[i].autor << endl;
            cout << "Numero de Paginas: " << li[i].numPag << endl;
            cout << "Ano de Publicacao: " << li[i].anoPublicacao << endl;
            cout << "Codigo Unico: " << li[i].codigoUnico << endl;
            cout << "Quantidade Disponivel: " << li[i].qtdDisponivel << endl;
            cout << "Pessoas com Exemplares: " << li[i].pessoasComExemplares << endl;
        }
    }
}

int main()
{
    struct Livro li[100];
    int qtd = 0;
    int opt = 0;
    
    while (opt!=6){
        cout << "Escolha uma opcao: " << endl;
        cin >> opt;

        switch(opt){
            case 1:{
                Cadastrar(li, &qtd);
                break;
            }
            case 2:{
                int escolha = 0;

                while (escolha != (1||2)) {
                    cout << "Escolha uma opção (1/2)" << endl;
                    cout << "1 - Mostrar todos os livros cadastrados" << endl;
                    cout << "2 - Mostrar livro especifico" << endl;
                    cin >> escolha;

                    if (escolha == 1) {
                        MostraLivros(li, qtd);
                        break;
                    } else if (escolha == 2) {
                        BuscarLivro(li, qtd);
                        break;
                    }
                }
            }
            case 3:{
                break;
            }
            case 4:{
                break;
            }
            case 5:{
                break;
            }
        }
    }
    return 0;
}
