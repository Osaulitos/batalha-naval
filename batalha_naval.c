#include <stdio.h>
#define TAM 10

// Inicializa o tabuleiro
void inicializarTabuleiro(char tabuleiro[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = '~';  // '~' representa água
        }
    }
}

// Exibe o tabuleiro
void mostrarTabuleiro(char tabuleiro[TAM][TAM]) {
    printf("  ");
    for (int i = 0; i < TAM; i++) {
        printf("%d ", i);
    }
    printf("\n");
    for (int i = 0; i < TAM; i++) {
        printf("%d ", i);
        for (int j = 0; j < TAM; j++) {
            printf("%c ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Função para ataque simples
void ataqueSimples(char tabuleiro[TAM][TAM], int x, int y) {
    if (x >= 0 && x < TAM && y >= 0 && y < TAM) {
        tabuleiro[x][y] = 'X';  // 'X' representa acerto
    }
}

// Habilidade: Cruz (linha + coluna)
void habilidadeCruz(char tabuleiro[TAM][TAM], int x, int y) {
    for (int i = 0; i < TAM; i++) {
        tabuleiro[x][i] = '*';
        tabuleiro[i][y] = '*';
    }
}

// Habilidade: Cone (diagonais)
void habilidadeCone(char tabuleiro[TAM][TAM], int x, int y) {
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if ((i == j || i == -j) && (x+i >= 0 && x+i < TAM && y+j >= 0 && y+j < TAM)) {
                tabuleiro[x+i][y+j] = '+';
            }
        }
    }
}

// Habilidade: Octaedro (em volta da célula central)
void habilidadeOctaedro(char tabuleiro[TAM][TAM], int x, int y) {
    for (int i = x-1; i <= x+1; i++) {
        for (int j = y-1; j <= y+1; j++) {
            if (i >= 0 && i < TAM && j >= 0 && j < TAM) {
                if (!(i == x && j == y)) {
                    tabuleiro[i][j] = 'O';
                }
            }
        }
    }
}

// Menu interativo
void menu() {
    char tabuleiro[TAM][TAM];
    inicializarTabuleiro(tabuleiro);
    int opcao, x, y;

    do {
        printf("\n=== Batalha Naval – Oceanic Games ===\n");
        mostrarTabuleiro(tabuleiro);
        printf("\nEscolha a ação:\n");
        printf("1 - Ataque Simples\n");
        printf("2 - Habilidade Cruz\n");
        printf("3 - Habilidade Cone\n");
        printf("4 - Habilidade Octaedro\n");
        printf("0 - Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);

        if (opcao >= 1 && opcao <= 4) {
            printf("Digite as coordenadas (x y): ");
            scanf("%d %d", &x, &y);
        }

        switch (opcao) {
            case 1:
                ataqueSimples(tabuleiro, x, y);
                break;
            case 2:
                habilidadeCruz(tabuleiro, x, y);
                break;
            case 3:
                habilidadeCone(tabuleiro, x, y);
                break;
            case 4:
                habilidadeOctaedro(tabuleiro, x, y);
                break;
            case 0:
                printf("Saindo do jogo...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }

    } while (opcao != 0);
}

int main() {
    menu();
    return 0;
}
