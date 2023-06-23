#include <iostream>
using namespace std;

#define TAM 9

int main() {
    srand(time(NULL));
    int linha=0, coluna=0, option=0, option1=0;
    int principal[TAM][TAM] = {4,9,5,2,8,7,3,6,1,7,2,8,6,1,3,4,9,5,3,6,1,9,5,4,7,2,8,6,5,3,8,4,9,2,1,7,9,8,4,1,7,2,6,5,3,2,1,7,5,3,6,9,8,4,1,3,2,4,6,5,8,7,9,5,4,6,7,9,8,1,3,2,8,7,9,3,2,1,5,4,6};
    int gabarito[TAM][TAM];
    int jogo[TAM][TAM];
    
    do {
        cout << "--------------------------------------------------------" << endl;
        cout << "--------------------------------------------------------" << endl;
        cout << "                       Sudoku" << endl;
        cout << "                  Escolha uma opcão: " << endl << endl;
        cout << "                     1 - Jogar" << endl;
        cout << "                     2 - Sobre" << endl;
        cout << "                     3 - Sair" << endl;
        cout << "--------------------------------------------------------" << endl;
        cout << "--------------------------------------------------------" << endl;
        cin >> option;
        switch (option){
            case 1:
                option1 = rand()%4+1;
                cout << option1;
                if (option1 == 1){
                    for (linha = 0; linha < TAM; linha++) { // MATRIZ GABARITO
                        for (coluna = 0; coluna < TAM; coluna++) {
                            gabarito[linha][coluna] = principal[linha][coluna];
                        }
                    }
                }else if (option1 == 2){
                    for (linha = 0; linha < TAM; linha++){ // MATRIZ TRANSPOSTA
                        for (coluna = 0; coluna < TAM; coluna++){
                            gabarito[linha][coluna] = principal[coluna][linha];
                        }
                    }
                }else if (option1 == 3){
                    for (int linha = 9; linha > 0; linha--){ // MATRIZ INVERTIDA POR LINHA 
                        for (int coluna = 0; coluna < TAM; coluna++){
                            gabarito[linha][coluna] = principal[linha-1][coluna];
                        }
                    }
                }else if (option1 == 4){
                    for (int linha = 0; linha < TAM; linha++){ // MATRIZ INVERTIDA POR COLUNA
                        for (int coluna = 9; coluna > 0; coluna--){
                            gabarito[linha][coluna] = principal[linha][coluna-1];
                        }
                    }
                }
                for (int z = 0; z < 41; z++) {
                    do {
                        linha = rand() % TAM;
                        coluna = rand() % TAM;
                    } while (jogo[linha][coluna] != 0);
                    jogo[linha][coluna] = gabarito[linha][coluna];
                }
                cout << endl;
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
                    cout << "|";
                    cout << endl;
                }
                cout << " -----------------------" << endl;
                
                
                
                
                break;
            case 2:
                system("clear");
                cout << "Equipe de desenvolvimento: Leonardo Borges, Lucas Barcia e Matheus Mafra" << endl;
                cout << "Mês/ano: Junho/2023" << endl;
                cout << "Professor: Rafael Ballottin" << endl;
                cout << "Disciplina: Algoritmos e Programação" << endl;
                system("read 0 -p");
                system("clear");
                break;
            default:
                system("clear");
                cout  << endl << "Opção invalida. Tente novamente." << endl;
                system("read 0 -p");
                system("clear");
                break;
        }
    } while (option != 3);
    system("clear");
    cout  << endl << "Obrigado por jogar! Até a proxima." << endl;
    return 0;
}
