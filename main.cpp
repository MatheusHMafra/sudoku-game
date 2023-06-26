#include <iostream>
#include <locale.h>

#define TAM 9

using namespace std;

int main() {
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));
    
    int linha = 0, coluna = 0, option = 0, option1 = 0;
    int principal[TAM][TAM] = { {4,9,5,2,8,7,3,6,1},
                                {7,2,8,6,1,3,4,9,5},
                                {3,6,1,9,5,4,7,2,8},
                                {6,5,3,8,4,9,2,1,7},
                                {9,8,4,1,7,2,6,5,3},
                                {2,1,7,5,3,6,9,8,4},
                                {1,3,2,4,6,5,8,7,9},
                                {5,4,6,7,9,8,1,3,2},
                                {8,7,9,3,2,1,5,4,6} };
    int gabarito[TAM][TAM];
    int jogo[TAM][TAM];
    
    bool vitoria = false;

    do {
        system("clear");
        cout << "--------------------------------------------------------" << endl;
        cout << "--------------------------------------------------------" << endl;
        cout << "                       Sudoku" << endl;
        cout << "                  Escolha uma opção: " << endl << endl;
        cout << "                     1 - Jogar" << endl;
        cout << "                     2 - Sobre" << endl;
        cout << "                     3 - Sair" << endl;
        cout << "--------------------------------------------------------" << endl;
        cout << "--------------------------------------------------------" << endl;
        cin >> option;

        switch (option) {
            case 1:
                system("clear");
                option1 = rand() % 4 + 1;
                if (option1 == 1) {
                    for (linha = 0; linha < TAM; linha++) { // MATRIZ GABARITO
                        for (coluna = 0; coluna < TAM; coluna++) {
                            gabarito[linha][coluna] = principal[linha][coluna];
                        }
                    }
                }
                else if (option1 == 2) {
                    for (linha = 0; linha < TAM; linha++) { // MATRIZ TRANSPOSTA
                        for (coluna = 0; coluna < TAM; coluna++) {
                            gabarito[linha][coluna] = principal[coluna][linha];
                        }
                    }
                }
                else if (option1 == 3) {
                    for (linha = 8; linha >= 0; linha--) { // MATRIZ INVERTIDA POR LINHA
                        for (coluna = 0; coluna < TAM; coluna++) {
                            gabarito[8 - linha][coluna] = principal[linha][coluna];
                        }
                    }
                }
                else if (option1 == 4) {
                    for (linha = 0; linha < TAM; linha++) { // MATRIZ INVERTIDA POR COLUNA
                        for (coluna = 8; coluna >= 0; coluna--) {
                            gabarito[linha][8 - coluna] = principal[linha][coluna];
                        }
                    }
                }

                for (int z = 0; z < 80; z++) {
                    do {
                        linha = rand() % TAM;
                        coluna = rand() % TAM;
                    } while (jogo[linha][coluna] != 0);
                    jogo[linha][coluna] = gabarito[linha][coluna];
                }

                while (!vitoria) {
                    cout << endl; //Imprime matriz jogo
                    for (linha = 0; linha < TAM; linha++) {
                        if (linha % 3 == 0 || linha % 6 == 0) {
                            cout << " -----------------------" << endl;
                        }
                        for (coluna = 0; coluna < TAM; coluna++) {
                            if (coluna % 3 == 0) {
                                cout << "| ";
                            }
                            cout << jogo[linha][coluna] << " ";
                        }
                        cout << "|" << endl;
                    }
                    cout << " -----------------------" << endl;
                    
                    cout << endl << "Escolha uma linha (0-8): ";
                    cin >> linha;
                    cout << "Escolha uma coluna (0-8): ";
                    cin >> coluna;
                    cout << "Escolha um número (1-9): ";
                    cin >> option;

                    if (linha >= 0 && linha < TAM && coluna >= 0 && coluna < TAM && option >= 1 && option <= 9) { //Verifica  jogo com gabarito
                        if (jogo[linha][coluna] == 0) {
                            if (option == gabarito[linha][coluna]) {
                                jogo[linha][coluna] = option;

                                vitoria = true;
                                for (linha = 0; linha < TAM; linha++) {
                                    for (coluna = 0; coluna < TAM; coluna++) {
                                        if (jogo[linha][coluna] != gabarito[linha][coluna]) {
                                            vitoria = false;
                                            break;
                                        }
                                    }
                                    if (!vitoria) {
                                        break;
                                    }
                                }
                            }
                            else {
                                cout << "Número incorreto. Tente novamente." << endl;
                                cout << "Pressione Enter para continuar...";
                                cin.ignore();
                                cin.get();
                                system("clear");
                            }
                        }
                        else {
                            cout << "Posição ocupada. Tente novamente." << endl;
                            cout << "Pressione Enter para continuar...";
                            cin.ignore();
                            cin.get();
                            system("clear");
                        }
                    }
                    else {
                        cout << "Entrada inválida. Tente novamente." << endl;
                        cout << "Pressione Enter para continuar...";
                        cin.ignore();
                        cin.get();
                        system("clear");
                    }
                }

                if (vitoria) {
                    system("clear");
                    cout << "Parabéns! Você venceu o jogo!" << endl;
                    cout << "Pressione Enter para continuar...";
                    cin.ignore();
                    cin.get();
                }
                
                break;

            case 2:
                system("clear");
                cout << "Equipe de desenvolvimento: Leonardo Borges, Lucas Barcia e Matheus Mafra" << endl;
                cout << "Mês/ano: Junho/2023" << endl;
                cout << "Professor: Rafael Ballottin" << endl;
                cout << "Disciplina: Algoritmos e Programação" << endl;
                cout << "Pressione Enter para voltar ao menu..." << endl;
                cin.ignore();
                cin.get();
                break;

            default:
                system("clear");
                cout << endl << "Opção inválida. Tente novamente." << endl;
                break;
        }
    } while (option != 3);
    
    system("clear");
    cout << endl << "Obrigado por jogar! Até a próxima." << endl;

    return 0;
}
