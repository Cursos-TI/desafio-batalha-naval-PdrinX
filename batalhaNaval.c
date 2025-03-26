#include <stdio.h>

#define COLUNAS 5
#define LINHAS 3

void inserirMatriz(int tabuleiro[10][10], int Efeito[LINHAS][COLUNAS], int startRow, int startCol) {
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            tabuleiro[startRow + i][startCol + j] = Efeito[i][j];
        }
    }
}

//Criando a área de efeito das bombas

//Cone
int coneEfeito[LINHAS][COLUNAS] = {0};
void cone() {

        for(int i = 0; i <= 2; i++){
            for(int j = 0; j <= 4; j++){
                coneEfeito[i][2] = 5;
                coneEfeito[2][j] = 5;
                if (j >= 1 && i == 1 && j <= 3){
                    coneEfeito[1][j] = 5;
    
                }
    
            }
        }
}

//Cruz
int cruzEfeito[LINHAS][COLUNAS] = {0};
void cruz() {
        for(int i = 0; i < 3; i++){
        for(int j = 0; j < 5; j++){
            cruzEfeito[i][2] = 7;
            cruzEfeito[1][j] = 7;
        }
    }
}

//Octaedro
int octaedroEfeito[LINHAS][COLUNAS] = {0};
void octaedro(){
    for(int i = 0; i < 3; i++){
       for(int j = 1; j <5; j++){
        octaedroEfeito[i][2] = 8;
        octaedroEfeito[1][j] = 8;
        if(j == 3){
            break;
        }
       }
    }

}



int main(){

    printf("Jogo Batalha Naval !!!\n");
    printf(" ");

    //Crinado o tabuleiro utilizando matriz
    int numero[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    char letras[10]= {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};

    for(int i = 0; i < 10; i++){
        printf(" %c", letras[i]);//Imprime as letras

    }
    printf("\n");

   
    int tabuleiro[10][10] = {0};

    for (int i = 1; i <= 3; i++) {
        tabuleiro[i][i + 1] = 3;
        for (int j = 5; j <= 7; j++) {//Imprime os navios horizontal e vertical e um diagonal
            tabuleiro[5][j] = 3;
            tabuleiro[i][7] = 3;
        }
    }

    int num = 2;
    for(int i = 7; i <= 9; i++){//Imprime outro diagonal

        tabuleiro[i][num] = 3;
        num--;
    }

    //Adicionando o efeito das bombas
    cone();
    cruz();
    octaedro();

    inserirMatriz(tabuleiro, coneEfeito, 4, 4);
    inserirMatriz(tabuleiro, cruzEfeito, 2, 0);
    inserirMatriz(tabuleiro, octaedroEfeito, 7, 3);


    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){

            if (j == 0) {
                printf("%i ", numero[i]);//mprime os numeros das colunas
            }

            printf("%d ", tabuleiro[i][j]);//Imprime os 0's
            if(i == 3 && j == 4){
                cone();
                }
            }
        printf("\n");
    }

    return 0;
}