#include <stdio.h>

// rodar no replit ou onlinegdb para que as linhas do tabuleiro sejam exibidas corretamente

#define TAMANHO_TABULEIRO 3

void exibirTabuleiro(char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("\n    0   1   2\n"); // para organização do tabuleiro
    printf("   ┌───┬───┬───┐\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf(" %d │", i); // Números das linhas ajustados com espaço extra
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf(" %c │", tabuleiro[i][j]);
        }
        printf("\n");
        if (i != TAMANHO_TABULEIRO - 1) {
            printf("   ├───┼───┼───┤\n");
        }
    }
    printf("   └───┴───┴───┘\n");
}

// Inicializa o tabuleiro com espaços em branco
void inicializarTabuleiro(char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = ' ';
        }
    }
}

// Verifica se a posição é valida ou está ocupada
int celulaValida(int linha, int coluna, char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    return linha >= 0 && linha < TAMANHO_TABULEIRO &&
           coluna >= 0 && coluna < TAMANHO_TABULEIRO &&
           tabuleiro[linha][coluna] == ' ';
}

// Verifica o vencedor ou empate
char verificarEstado(char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    // Linhas e colunas
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        if (tabuleiro[i][0] != ' ' && tabuleiro[i][0] == tabuleiro[i][1] && tabuleiro[i][1] == tabuleiro[i][2])
            return tabuleiro[i][0];
        if (tabuleiro[0][i] != ' ' && tabuleiro[0][i] == tabuleiro[1][i] && tabuleiro[1][i] == tabuleiro[2][i])
            return tabuleiro[0][i];
    }
    // Diagonais
    if (tabuleiro[0][0] != ' ' && tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2])
        return tabuleiro[0][0];
    if (tabuleiro[0][2] != ' ' && tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][0])
        return tabuleiro[0][2];
    // Verifica empate (tabuleiro cheio)
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            if (tabuleiro[i][j] == ' ') return ' '; // Ainda há jogadas possíveis
        }
    }
    return 'E'; // Empate
}

// Gerencia o jogo
void jogar() {
    char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    inicializarTabuleiro(tabuleiro);

    char jogadorAtual = 'X';
    char estado = ' ';

    while (estado == ' ') {
        exibirTabuleiro(tabuleiro);
        printf("\nJogador %c, informe sua jogada (linha coluna): ", jogadorAtual);
        int linha, coluna;
        scanf("%d %d", &linha, &coluna);

        if (!celulaValida(linha, coluna, tabuleiro)) {
            printf("Célula inválida. Tente novamente.\n");
            continue;
        }

        tabuleiro[linha][coluna] = jogadorAtual;
        estado = verificarEstado(tabuleiro);
        jogadorAtual = (jogadorAtual == 'X') ? 'O' : 'X';
    }

    exibirTabuleiro(tabuleiro);

    if (estado == 'E') {
        printf("\n Empate! Ninguém venceu.\n");
    } else {
        printf("\n Parabéns, jogador %c venceu!\n", estado);
    }
}

// Função principal
int main() {
    printf("Bem vindo ao Jogo da Velha!\n");
    jogar();
    return 0;
}
