/*
  Alunos: Leonardo Borges Lopes, Lucas Barcia López Hellmann e Matheus Henrique Tomelin Mafra
*/
#include <iostream>
#include <locale.h>

#define TAM 9

using namespace std;

int main(){
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));

    int linha = 0, coluna = 0, option = 0, option1 = 0, option2;
    int principal[TAM][TAM] = {{4, 9, 5, 2, 8, 7, 3, 6, 1},
                               {7, 2, 8, 6, 1, 3, 4, 9, 5},
                               {3, 6, 1, 9, 5, 4, 7, 2, 8},
                               {6, 5, 3, 8, 4, 9, 2, 1, 7},
                               {9, 8, 4, 1, 7, 2, 6, 5, 3},
                               {2, 1, 7, 5, 3, 6, 9, 8, 4},
                               {1, 3, 2, 4, 6, 5, 8, 7, 9},
                               {5, 4, 6, 7, 9, 8, 1, 3, 2},
                               {8, 7, 9, 3, 2, 1, 5, 4, 6}};
    int gabarito[TAM][TAM];
    int jogo[TAM][TAM];

    bool vitoria;

    do{
        system("clear");
        cout << "--------------------------------------------------------" << endl;
        cout << "--------------------------------------------------------" << endl << endl;
        cout << "                       Sudoku" << endl;
        cout << "                  Escolha uma opção: " << endl<< endl;
        cout << "                     1 - Jogar" << endl;
        cout << "                     2 - Sobre" << endl;
        cout << "                     3 - Sair" << endl << endl;
        cout << "--------------------------------------------------------" << endl;
        cout << "--------------------------------------------------------" << endl;
        cin >> option;

        switch (option){
        case 1: // Case para iniciar o jogo
            vitoria = false;
            system("clear");
            option1 = rand() % 4 + 1; // Sortear a matriz a ser utilizada
            if (option1 == 1){ // Se for sorteado "1", a matriz gabarito será utilizada
                for (linha = 0; linha < TAM; linha++){
                    for (coluna = 0; coluna < TAM; coluna++){
                        gabarito[linha][coluna] = principal[linha][coluna];
                    }
                }
            }
            else if (option1 == 2){ // Se for sorteado "2", a matriz transposta será utilizada
                for (linha = 0; linha < TAM; linha++){
                    for (coluna = 0; coluna < TAM; coluna++){
                        gabarito[linha][coluna] = principal[coluna][linha];
                    }
                }
            }
            else if (option1 == 3){ // Se for sorteado "3", a matriz invertida por linha será utilizada
                for (linha = 8; linha >= 0; linha--){
                    for (coluna = 0; coluna < TAM; coluna++){
                        gabarito[8 - linha][coluna] = principal[linha][coluna];
                    }
                }
            }
            else if (option1 == 4){ // Se for sorteado "4", a matriz invertida por coluna será utilizada
                for (linha = 0; linha < TAM; linha++){
                    for (coluna = 8; coluna >= 0; coluna--)
                    {
                        gabarito[linha][8 - coluna] = principal[linha][coluna];
                    }
                }
            }

            for (int z = 0; z < 41; z++){ // Preenchimento aleatório da matriz jogo
                do{
                    linha = rand() % TAM;
                    coluna = rand() % TAM;
                } while (jogo[linha][coluna] != 0);
                jogo[linha][coluna] = gabarito[linha][coluna];
            }

            do{
                system("clear");
                cout << endl; // Imprime matriz jogo
                for (linha = 0; linha < TAM; linha++){
                    if (linha % 3 == 0 || linha % 6 == 0){
                        cout << " -----------------------" << endl;
                    }
                    for (coluna = 0; coluna < TAM; coluna++){
                        if (coluna % 3 == 0){
                            cout << "| ";
                        }
                        cout << jogo[linha][coluna] << " ";
                    }
                    cout << "|" << endl;
                }
                cout << " -----------------------" << endl;

                cout << endl << "Escolha uma linha (1-9): ";
                cin >> linha;
                linha--;
                cout << "Escolha uma coluna (1-9): ";
                cin >> coluna;
                coluna--;
                cout << "Escolha um número (1-9): ";
                cin >> option2;

                if (linha >= 0 && linha < TAM && coluna >= 0 && coluna < TAM && option2 >= 1 && option2 <= 9){ // Verifica os número digitado
                    if (jogo[linha][coluna] == 0){
                        if (option2 == gabarito[linha][coluna]){
                            cout << "Número correto!" << endl;
                            jogo[linha][coluna] = option2;
                            cout << "Pressione Enter para continuar..." << endl;
                            system("read 0 -p");
                            
                            vitoria = true;
                            for (linha = 0; linha < TAM; linha++){ // Verifica os número digitado com o gabarito
                                for (coluna = 0; coluna < TAM; coluna++){
                                    if (jogo[linha][coluna] != gabarito[linha][coluna]){
                                        vitoria = false;
                                    }
                                }
                            }
                        }
                        else { // Número digitado não corresponde ao gabarito
                            cout << "Número incorreto. Tente novamente." << endl;
                            cout << "Pressione Enter para continuar..." << endl;
                            system("read 0 -p");
                        }
                    }
                    else { // Posição já ocupada
                        cout << "Posição ocupada. Tente novamente." << endl;
                        cout << "Pressione Enter para continuar..." << endl;
                        system("read 0 -p");
                    }
                }
                else { // Entrada inválida
                    cout << "Entrada inválida. Tente novamente." << endl;
                    cout << "Pressione Enter para continuar..." << endl;
                    system("read 0 -p");
                }
            } while (!vitoria);

            if (vitoria) {
                system("clear");
                cout << endl;
                cout << "Parabéns! Você venceu o jogo!" << endl;
                cout << "Pressione Enter para continuar..." << endl;
                system("read 0 -p");
        
                for (linha = 0; linha < TAM; linha++) { // Reinicializa a matriz jogo para começar um novo jogo
                    for (coluna = 0; coluna < TAM; coluna++) {
                        jogo[linha][coluna] = 0;
                    }
                }
            }

            break;

        case 2: // Case para a página "Sobre"
            system("clear");
            cout << endl;
            cout << "Equipe de desenvolvimento: Leonardo Borges, Lucas Barcia e Matheus Mafra" << endl;
            cout << "Mês/ano: Junho/2023" << endl;
            cout << "Professor: Rafael Ballottin" << endl;
            cout << "Disciplina: Algoritmos e Programação" << endl;
            cout << "Pressione Enter para voltar ao menu..." << endl;
            system("read 0 -p");
            break;

        default: // Case para opção inválida
            system("clear");
            cout << endl << "Opção inválida. Tente novamente." << endl;
            break;
        }
    } while (option != 3); // Enquanto a opção "3" não for selecionado o código rodará

    system("clear");
    cout << endl << "Obrigado por jogar! Até a próxima." << endl;

    return 0;
}
