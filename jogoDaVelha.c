#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void jogoDaVelha();
void jogoDaVelha_Regras();
void jogoDaVelha_Jogar();
int jogoDavelha_Ganhador(char[3][3]);
void jogoDaVelha_JogarPessoa();
void jogoDaVelha_JogarMaquina();
int *jogoDaVelha_JogadaDaMaquina(char[3][3]);
int *jogoDaVelha_Jogada(char[3][3]);
void jogoDaVelha_ExibeTabuleiro(char[3][3]);

void jogoDaVelha()
{
    int seletor;

    do
    {
        printf("---JOGO DA VELHA---\n");
        printf("1) Jogar\n");
        printf("2) Regras\n");
        printf("3) Sair\n");
        printf("Entrada: ");
        scanf("%d", &seletor);

        if (seletor < 1 || seletor > 3)
        {
            system("cls");
            printf("\nOpcao invalida!\n\n");
        }
    } while (seletor < 1 || seletor > 3);

    switch (seletor)
    {
    case 1:
        jogoDaVelha_Jogar();
        break;
    case 2:
        jogoDaVelha_Regras();
        break;
    case 3:
        break;
    }
};

void jogoDaVelha_Regras()
{
    system("cls");
    printf("\nRegras do Jogo da Velha:\n");
    printf("O objetivo do jogo eh fazer uma sequencia de tres simbolos iguais, seja em linha vertical, horizontal ou diagonal, enquanto tenta impedir que seu adversario faca o mesmo.\n\n");
    jogoDaVelha();
}

void jogoDaVelha_Jogar()
{
    system("cls");
    int seletor;

    do
    {
        printf("1) Jogar contra pessoa\n");
        printf("2) Jogar contra maquina\n");
        printf("3) Voltar\n");
        printf("Entrada: ");
        scanf("%d", &seletor);

        if (seletor < 1 || seletor > 3)
        {
            system("cls");
            printf("\nOpcao invalida!\n\n");
        }
    } while (seletor < 1 || seletor > 3);

    system("cls");

    switch (seletor)
    {
    case 1:
        jogoDaVelha_JogarPessoa();
        break;
    case 2:
        jogoDaVelha_JogarMaquina();
        break;
    case 3:
        jogoDaVelha();
        break;
    }
}

int jogoDaVelha_Ganhador(char matriz[3][3])
{

    if (
        // Condicao de vitoria para o Jogador 1
        // Mesma Linha
        (matriz[0][0] == 'x' && matriz[0][1] == 'x' && matriz[0][2] == 'x') ||
        (matriz[1][0] == 'x' && matriz[1][1] == 'x' && matriz[1][2] == 'x') ||
        (matriz[2][0] == 'x' && matriz[2][1] == 'x' && matriz[2][2] == 'x') ||
        // Mesma Coluna
        (matriz[0][0] == 'x' && matriz[1][0] == 'x' && matriz[2][0] == 'x') ||
        (matriz[0][1] == 'x' && matriz[1][1] == 'x' && matriz[2][1] == 'x') ||
        (matriz[0][2] == 'x' && matriz[1][2] == 'x' && matriz[2][2] == 'x') ||
        // Diagonal
        (matriz[0][0] == 'x' && matriz[1][1] == 'x' && matriz[2][2] == 'x') ||
        (matriz[0][2] == 'x' && matriz[1][1] == 'x' && matriz[2][0] == 'x'))
    {
        return 1;
    }
    else if (
        // Condicao de vitoria para o Jogador 2
        // Mesma Linha
        (matriz[0][0] == 'o' && matriz[0][1] == 'o' && matriz[0][2] == 'o') ||
        (matriz[1][0] == 'o' && matriz[1][1] == 'o' && matriz[1][2] == 'o') ||
        (matriz[2][0] == 'o' && matriz[2][1] == 'o' && matriz[2][2] == 'o') ||
        // Mesma Coluna
        (matriz[0][0] == 'o' && matriz[1][0] == 'o' && matriz[2][0] == 'o') ||
        (matriz[0][1] == 'o' && matriz[1][1] == 'o' && matriz[2][1] == 'o') ||
        (matriz[0][2] == 'o' && matriz[1][2] == 'o' && matriz[2][2] == 'o') ||
        // Diagonal
        (matriz[0][0] == 'o' && matriz[1][1] == 'o' && matriz[2][2] == 'o') ||
        (matriz[0][2] == 'o' && matriz[1][1] == 'o' && matriz[2][0] == 'o'))
    {
        return 2;
    }

    else if (
        // Condicao de velha, Nenhum jogador ganha
        matriz[0][0] != ' ' && matriz[0][1] != ' ' && matriz[0][2] != ' ' &&
        matriz[1][0] != ' ' && matriz[1][1] != ' ' && matriz[1][2] != ' ' &&
        matriz[2][0] != ' ' && matriz[2][1] != ' ' && matriz[2][2] != ' ')
    {
        return 3;
    }
    return 0;
};

void jogoDaVelha_JogarPessoa()
{
    system("cls");

    int ganhador = 0, rodada = 1, seletor;
    char matriz[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};

    do
    {
        // printf("\n======================\n");
        printf("Rodada: %d\n", rodada);
        printf("Jogador 1: x\n");
        printf("Jogador 2: o\n\n");

        jogoDaVelha_ExibeTabuleiro(matriz);

        if (rodada % 2 != 0)
        {
            printf("\nVez do jogador 1 (x):\n");
            int *jogada = jogoDaVelha_Jogada(matriz);
            matriz[*jogada - 1][(*jogada + 1) - 1] = 'x';
        }
        else
        {
            printf("\nVez do jogador 2 (o):\n");
            int *jogada = jogoDaVelha_Jogada(matriz);
            matriz[*jogada - 1][*(jogada + 1) - 1] = 'o';
        }

        ganhador = jogoDaVelha_Ganhador(matriz);

        rodada += 1;
    } while (ganhador == 0);

    switch (ganhador)
    {
    case 1:
        printf("\nVitoria do jogador 1!\n");
        printf("\n");
        break;
    case 2:
        printf("\nVitoria do jogador 2!\n");
        printf("\n");
        break;
    case 3:
        printf("\nDeu velha!\n");
        break;
    }
    jogoDaVelha_ExibeTabuleiro(matriz);

    do
    {
        printf("\n--- Jogar novamente? ---\n");
        printf("1) Jogar\n");
        printf("2) Sair\n");
        printf("Entrada: ");
        scanf("%d", &seletor);

        if (seletor < 1 || seletor > 2)
        {
            printf("\nOpcao invalida!\n\n");
        }
    } while (seletor < 1 || seletor > 2);

    switch (seletor)
    {
    case 1:
        jogoDaVelha_Jogar();
        break;
    case 2:
        break;
    }
};

void jogoDaVelha_JogarMaquina()
{
    int ganhador = 0, rodada = 1, seletor;
    char matriz[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};

    do
    {
        // printf("\n======================\n");
        printf("Rodada: %d\n", rodada);
        printf("Jogador: x\n");
        printf("Maquina: o\n\n");

        jogoDaVelha_ExibeTabuleiro(matriz);

        if (rodada % 2 != 0)
        {
            printf("\nVez do jogador (x):\n");
            int *jogada = jogoDaVelha_Jogada(matriz);
            matriz[*jogada - 1][*(jogada + 1) - 1] = 'x';
        }
        else
        {
            int *jogada = jogoDaVelha_JogadaDaMaquina(matriz);
            matriz[*jogada - 1][*(jogada + 1) - 1] = 'o';
        }

        ganhador = jogoDaVelha_Ganhador(matriz);

        rodada += 1;
    } while (ganhador == 0);

    switch (ganhador)
    {
    case 1:
        printf("\nVitoria do jogador!\n");
        printf("\n");
        break;
    case 2:
        printf("\nVitoria da Maquina!\n");
        printf("\n");
        break;
    case 3:
        printf("\nDeu velha!\n");
        break;
    }
    jogoDaVelha_ExibeTabuleiro(matriz);

    do
    {
        printf("\n--- Jogar novamente? ---\n");
        printf("1) Jogar\n");
        printf("2) Sair\n");
        printf("Entrada: ");
        scanf("%d", &seletor);

        if (seletor < 1 || seletor > 2)
        {
            printf("\nOpcao invalida!\n\n");
        }
    } while (seletor < 1 || seletor > 2);

    switch (seletor)
    {
    case 1:
        jogoDaVelha_Jogar();
        break;
    case 2:
        break;
    }
};

int *jogoDaVelha_JogadaDaMaquina(char matriz[3][3])
{
    system("cls");
    static int jogada[2] = {0, 0};

    do
    {
        jogada[0] = (rand() % (3 - 1 + 1)) + 1;
        jogada[1] = (rand() % (3 - 1 + 1)) + 1;

    } while (matriz[jogada[0] - 1][jogada[1] - 1] != ' ');

    return jogada;
}

int *jogoDaVelha_Jogada(char matriz[3][3])
{
    static int jogada[2] = {0, 0};

    do
    {
        do
        {
            printf("Digite o numero da linha (1,2,3): ");
            scanf("%d", &jogada[0]);
            if (jogada[0] != 1 && jogada[0] != 2 && jogada[0] != 3)
                printf("Linha invalida\n");

        } while (jogada[0] != 1 && jogada[0] != 2 && jogada[0] != 3);
        do
        {
            printf("Digite o numero da coluna (1,2,3): ");
            scanf(" %d", &jogada[1]);
            if (jogada[1] != 1 && jogada[1] != 2 && jogada[1] != 3)
                printf("Coluna invalida\n");
        } while (jogada[1] != 1 && jogada[1] != 2 && jogada[1] != 3);
        if (matriz[jogada[0] - 1][jogada[1] - 1] != ' ')
            printf("Posicao invalida!\n\n");

    } while (matriz[jogada[0] - 1][jogada[1] - 1] != ' ');

    system("cls");
    return jogada;
}

void jogoDaVelha_ExibeTabuleiro(char matriz[3][3])
{

    printf("     1   2   3\n");
    printf("     v   v   v\n");
    printf("1>   %c | %c | %c \n", matriz[0][0], matriz[0][1], matriz[0][2]);
    printf("   -------------\n");
    printf("2>   %c | %c | %c \n", matriz[1][0], matriz[1][1], matriz[1][2]);
    printf("   -------------\n");
    printf("3>   %c | %c | %c \n", matriz[2][0], matriz[2][1], matriz[2][2]);
};

int main()
{
    system("cls");
    jogoDaVelha();
    system("cls");

    return 0;
}