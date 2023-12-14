#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <graphics.h>

// Define uma estrutura para representar um jogador de futebol
struct jogador {
    int numero;
    char nome[50];
    int idade;
    float altura;
    float peso;
    int golos;
};

// Define uma função para calcular o gol médio de um jogador
float calcular_gol_medio(struct jogador jogador) {
    return jogador.golos / jogador.partidas;
}

// Define uma função para calcular o salário de um jogador
float calcular_salario(struct jogador jogador) {
    return jogador.golos * 1000;
}

// Define uma função para impressiar os dados de um jogador
void imprimir_jogador(struct jogador jogador) {
    printf("Número: %d\n", jogador.numero);
    printf("Nome: %s\n", jogador.nome);
    printf("Idade: %d\n", jogador.idade);
    printf("Altura: %f\n", jogador.altura);
    printf("Peso: %f\n", jogador.peso);
    printf("Golos: %d\n", jogador.golos);
    printf("Gol médio: %f\n", calcular_gol_medio(jogador));
    printf("Salário: %f\n", calcular_salario(jogador));
}

// Define uma função para ler os dados de um jogador
struct jogador ler_jogador() {
    struct jogador jogador;
    printf("Entre com o número do jogador: ");
    scanf("%d", &jogador.numero);
    printf("Entre com o nome do jogador: ");
    scanf("%s", jogador.nome, 50);
    printf("Entre com a idade do jogador: ");
    scanf("%d", &jogador.idade);
    printf("Entre com a altura do jogador: ");
    scanf("%f", &jogador.altura);
    printf("Entre com o peso do jogador: ");
    scanf("%f", &jogador.peso);
    printf("Entre com o número de golos do jogador: ");
    scanf("%d", &jogador.golos);
    return jogador;
}

// Define uma função para calcular o gol médio de uma equipe
float calcular_gol_medio_equipe(struct jogador jogadores[10]) {
    int i;
    float golos_totais = 0;
    for (i = 0; i < 10; i++) {
        golos_totais += jogadores[i].golos;
    }
    return golos_totais / 10;
}

// Define uma função para calcular o salário total de uma equipe
float calcular_salario_equipe(struct jogador jogadores[10]) {
    int i;
    float salarios_totais = 0;
    for (i = 0; i < 10; i++) {
        salarios_totais += calcular_salario(jogadores[i]);
    }
    return salarios_totais;
}

// Define uma função para impressiar os dados de uma equipe
void imprimir_equipe(struct jogador jogadores[10]) {
    int i;
    for (i = 0; i < 10; i++) {
        imprimir_jogador(jogadores[i]);
    }
}

// Define uma função para ler os dados de uma equipe
struct jogador ler_equipe() {
    struct jogador jogadores[10];
    int i;
    for (i = 0; i < 10; i++) {
        jogadores[i] = ler_jogador();
    }
    return jogadores;
}

// Define uma função para calcular o melhor jogador de uma equipe
struct jogador melhor_jogador(struct jogador jogadores[10]) {
    struct jogador melhor = jogadores[0];
    int i;
    for (i = 1; i < 10; i++) {
        if (calcular_gol_medio(jogadores[i]) > calcular_gol_medio(melhor)) {
            melhor = jogadores[i];
        }
    }
    return melhor;
}

// Define uma função para calcular o melhor gol da partida
float melhor_gol(struct jogador jogadores[10]) {
    float melhor_gol = -1;
    int i;
    for (i = 0; i < 10; i++) {
        if (jogadores[i].golos > melhor_gol) {
            melhor_gol = jogadores[i].golos;
        }
    }
    return melhor_gol;
}

// Define uma função para calcular o vencedor da partida
struct jogador vencedor(struct jogador jogadores[10]) {
    struct jogador vencedor = jogadores[0];
    int i;
    for (i = 1; i < 10; i++) {
        if (calcular_gol_medio(jogadores[i]) > calcular_gol_medio(vencedor)) {
            vencedor = jogadores[i];
        }
    }
    return vencedor;
}

int main() {
    // Define uma equipe com 10 jogadores
    struct jogador jogadores[10] = {
        {1, "Joao", 25, 1.80, 70, 10},
        {2, "Jose", 30, 1.70, 60, 15},
        {3, "Mario", 28, 1.60, 55, 12},
        {4, "Pedro", 22, 1.90, 75, 8},
        {5, "Mateus", 27, 1.70, 62, 11},
        {6, "Lucas", 23, 1.80, 70, 13},
        {7, "Natan", 29, 1.60, 58, 10},
        {8, "Rafael", 31, 1.90, 80, 15},
        {9, "Sergio", 26, 1.70, 63, 12},
        {10, "Tiago", 24, 1.80, 72, 11}
    };

    // Imprime os dados da equipe
    imprimir_equipe(jogadores);

    // Calcula o gol médio da equipe
    float gol_medio = calcular_gol_medio_equipe(jogadores);
    printf("Gol médio da equipe: %f\n", gol_medio);

    // Calcula o salário total da equipe
    float salario_total = calcular_salario_equipe(jogadores);
    printf("Salário total da equipe: %f\n", salario_total);

    // Define um jogador como o melhor jogador da equipe
    struct jogador melhor_jogador = melhor_jogador(jogadores);
    printf("Melhor jogador da equipe: %s\n", melhor_jogador.nome);

    // Define o melhor gol da partida
    float melhor_gol = melhor_gol(jogadores);
    printf("Melhor gol da partida: %f\n", melhor_gol);

    // Define o vencedor da partida
    struct jogador vencedor = vencedor(jogadores);
    printf("Vencedor da partida: %s\n", vencedor.nome);

    return 0;
}
