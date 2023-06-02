#include <iostream>
using namespace std;

#define TAM 9

int main() {
    srand(time(NULL));
    int linha = 0, coluna = 0;
    int matA[TAM][TAM] = {4,9,5,2,8,7,3,6,1,7,2,8,6,1,3,4,9,5,3,6,1,9,5,4,7,2,8,6,5,3,8,4,9,2,1,7,9,8,4,1,7,2,6,5,3,2,1,7,5,3,6,9,8,4,1,3,2,4,6,5,8,7,9,5,4,6,7,9,8,1,3,2,8,7,9,3,2,1,5,4,6};
    int matB[TAM][TAM] = {0};

    cout << "\t Sudoku: " << endl;
    for (linha = 0; linha < TAM; linha++) {
        if (linha % 3 == 0 || linha % 6 == 0) {
            cout << " -----------------------" << endl;
        }
        for (coluna = 0; coluna < TAM; coluna++) {
            if (coluna % 3 == 0) {
                cout << "| ";
            }
            cout << matA[linha][coluna] << " ";
        }
        cout << "|";
        cout << endl;
    }
    cout << " -----------------------" << endl;

    cout << "       Transposta: " << endl;
    for (linha = 0; linha < TAM; linha++) {
        if (linha % 3 == 0 || linha % 6 == 0) {
            cout << " -----------------------" << endl;
        }
        for (coluna = 0; coluna < TAM; coluna++) {
            if (coluna % 3 == 0) {
                cout << "| ";
            }
            cout << matA[coluna][linha] << " ";
        }
        cout << "|";
        cout << endl;
    }

    for (int z = 0; z < 41; z++) {
        do {
            linha = rand() % TAM;
            coluna = rand() % TAM;
        } while (matB[linha][coluna] != 0);

        matB[linha][coluna] = matA[linha][coluna];
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
            cout << matB[linha][coluna] << " ";
        }
        cout << "|";
        cout << endl;
    }

    return 0;
}
