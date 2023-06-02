#include <iostream>
using namespace std;

#define TAM 9

int main(){
    int matA[TAM][TAM] = {4,9,5,2,8,7,3,6,1,7,2,8,6,1,3,4,9,5,3,6,1,9,5,4,7,2,8,6,5,3,8,4,9,2,1,7,9,8,4,1,7,2,6,5,3,2,1,7,5,3,6,9,8,4,1,3,2,4,6,5,8,7,9,5,4,6,7,9,8,1,3,2,8,7,9,3,2,1,5,4,6};
    cout << "\t Sudoku: "<< endl;
    for (int i = 0; i < TAM; i++){
        if (i % 3 ==0 or i % 6 ==0){
            cout << " -----------------------" << endl;
        }
        for (int j = 0; j < TAM; j++){
            if (j % 3 ==0){
                cout << "| ";
            }
            cout << matA[i][j] << " ";
        }
        cout << "|";
        cout << endl;
    }
    cout << " -----------------------" << endl;
    cout << "       Transposta: "<< endl;
    for (int i = 0; i < TAM; i++){
        if (i % 3 ==0 or i % 6 ==0){
            cout << " -----------------------" << endl;
        }
        for (int j = 0; j < TAM; j++){
            if (j % 3 ==0){
                cout << "| ";
            }
            cout << matA[j][i] << " ";
        }
        cout << "|";
        cout << endl;
    }
    cout << " -----------------------" << endl;
        cout << "  Invertida por linha: "<< endl;
    for (int i = 9; i > 0; i--){
        if (i % 3 ==0 or i % 6 ==0){
            cout << " -----------------------" << endl;
        }
        for (int j = 0; j < TAM; j++){
            if (j % 3 ==0){
                cout << "| ";
            }
            cout << matA[i-1][j] << " ";
        }
        cout << "|";
        cout << endl;
    }
    cout << " -----------------------" << endl;
    cout << "  Invertida por coluna: "<< endl;
    for (int i = 0; i < TAM; i++){
        if (i % 3 ==0 or i % 6 ==0){
            cout << " -----------------------" << endl;
        }
        for (int j = 9; j > 0; j--){
            if (j % 3 ==0){
                cout << "| ";
            }
            cout << matA[i][j-1] << " ";
        }
        cout << "|";
        cout << endl;
    }
    cout << " -----------------------" << endl;
    return 0;
}
