#include <iostream>
using namespace std;

int main(){
    srand(time(NULL));
    int TAM = 9, matA[TAM][TAM], temp;
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            matA[i][j] = 1;
            matA[i+1][j+1] = 2;
        }
    }
    cout << "Matriz A: "<< endl;
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
    return 0;
}
