#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

char fundo[30][30];
int menu1, gerar, menu2, coluna = 1, linha = 1, vizinhos, vizinhos2;

void menu() {
    system("color 09");
    printf("..######......###....##.....##.########.....#######..########....##.......####.########.########\n");
    printf(".##....##....##.##...###...###.##..........##.....##.##..........##........##..##.......##......\n");
    printf(".##.........##...##..####.####.##..........##.....##.##..........##........##..##.......##......\n");
    printf(".##...####.##.....##.##.###.##.######......##.....##.######......##........##..######...######..\n");
    printf(".##....##..#########.##.....##.##..........##.....##.##..........##........##..##.......##......\n");
    printf(".##....##..##.....##.##.....##.##..........##.....##.##..........##........##..##.......##......\n");
    printf("..######...##.....##.##.....##.########.....#######..##..........########.####.##.......########\n");
    printf("\n\nDIGITE A OPCAO\n\n");
    printf("1- Escolha manualmente\n\n");
    printf("2- Gerar Automaticamente\n\n");
    printf("3- Escolha modelos pre-definitos\n\n");

}

void escolhaManual() {

    while ((linha > 0) && (coluna > 0)) {

        printf("\n\n\nEscolha a linha que esteja entre 1 e 30 [Digite 0 para parar]\n\n");
        scanf("%d", &linha);

        if (linha > 0) {
            printf("\n\nEscolha a coluna que deseja entre 1 e 30 [Digite 0 para parar]\n\n");
            scanf("%d", &coluna);
        }
        if ((linha > 0) && (coluna > 0))
            fundo[linha + 1][coluna + 1] = 'O';
    }

    for (int i = 0; i < 30; i++) {
        for (int j = 0; j < 30; j++)
            printf("%c", fundo[i][j]);
        printf("\n");
    }


}


void geraAutomaticamente() {

    int num;

    srand(time(NULL));

    for (int i = 0; i < 30; i++) {
        for (int j = 0; j < 30; j++) {
            num = (rand() % 5);
            if (num == 0) {
                fundo[i][j] = 'O';
            }
        }
    }
    for (int i = 0; i < 30; i++) {
        for (int j = 0; j < 30; j++)
            printf("%c", fundo[i][j]);
        printf("\n");
    }
}

void modelosDefinidos() {

    printf("\n\n1-Glider\n\n2-Blinker\n\n3-Frog\n\n4-Bloco\n\n5-Die_Hard\n\n");
    scanf("%d", &menu2);
    system("cls");

    if (menu2 == 1) {
        fundo[2][2] = 'O';
        fundo[3][3] = 'O';
        fundo[4][3] = 'O';
        fundo[4][2] = 'O';
        fundo[4][1] = 'O';
    }
    if (menu2 == 2) {
        fundo[2][2] = 'O';
        fundo[2][3] = 'O';
        fundo[2][4] = 'O';
    }
    if (menu2 == 3) {
        fundo[2][2] = 'O';
        fundo[2][3] = 'O';
        fundo[2][4] = 'O';
        fundo[3][3] = 'O';
        fundo[3][4] = 'O';
        fundo[3][5] = 'O';
    }
    if (menu2 == 4) {
        fundo[2][2] = 'O';
        fundo[2][3] = 'O';
        fundo[3][3] = 'O';
        fundo[3][2] = 'O';
    }
    if (menu2 == 5) {
        fundo[12][12] = 'O';
        fundo[13][12] = 'O';
        fundo[13][13] = 'O';
        fundo[13][17] = 'O';
        fundo[13][18] = 'O';
        fundo[13][19] = 'O';
        fundo[11][18] = 'O';
    }
    for (int i = 0; i < 30; i++) {
        for (int j = 0; j < 30; j++)
            printf("%c", fundo[i][j]);
        printf("\n");
    }


}

void geraFundo() {
    for (int i = 0; i < 30; i++) {
        for (int j = 0; j < 30; j++) {
            fundo[i][j] = ' ';
        }
    }
}


void simula() {
    printf("Quantas geracoes deseja simular????");
    scanf("%d", &gerar);

    for (int cont = 1; cont <= gerar; cont++) {
        system("cls");

        for (int i = 1; i < 30; i++) {
            for (int j = 1; j < 30; j++) {
                vizinhos = 0;
                if (fundo[i][j] == 'O') {
                    for (int a = -1; a < 2; a++) {
                        for (int b = -1; b < 2; b++)
                            if (((i + a) == i) && ((j + b) == j))
                                vizinhos = vizinhos;
                            else {

                                if ((fundo[i + a][j + b] == 'O') || (fundo[i + a][j + b] == 1) ||
                                    (fundo[i + a][j + b] == 0))
                                    vizinhos++;
                            }
                    }
                    if ((vizinhos == 2) || (vizinhos == 3))
                        fundo[i][j] = 1;
                    else if ((vizinhos < 2) || (vizinhos >= 4))
                        fundo[i][j] = 0;
                }
            }
        }

        for (int i = 1; i < 30 - 1; i++) {
            for (int j = 1; j < 30 - 1; j++) {
                vizinhos2 = 0;
                if (fundo[i][j] == ' ') {
                    for (int a = -1; a < 2; a++) {
                        for (int b = -1; b < 2; b++)
                            if (((i + a) == i) && ((j + b) == j))
                                vizinhos2 = vizinhos2;

                            else if ((fundo[i + a][j + b] == 'O') || (fundo[i + a][j + b] == 1) ||
                                     (fundo[i + a][j + b] == 0))
                                vizinhos2++;
                    }
                    if ((vizinhos2 == 3))
                        fundo[i][j] = 2;
                }
            }
        }

        for (int y = 1; y < 30; y++) {
            for (int z = 1; z < 30; z++) {
                if (fundo[y][z] == 1)
                    fundo[y][z] = 'O';
                else if (fundo[y][z] == 2)
                    fundo[y][z] = 'O';
                else if (fundo[y][z] == 0)
                    fundo[y][z] = ' ';
            }
        }

        for (int m = 0; m < 30; m++) {
            for (int n = 0; n < 30; n++)
                printf("%c", fundo[m][n]);
            printf("\n");
        }
    }
}

int main() {
    menu();
    geraFundo();
    scanf("%d", &menu1);
    if (menu1 == 1) escolhaManual();
    if (menu1 == 2) geraAutomaticamente();
    if (menu1 == 3) modelosDefinidos();
    simula();
}
