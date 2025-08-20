#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// ===== Funções auxiliares =====

// Remove \n do final
void tirarEnter(char *str) {
    str[strcspn(str, "\n")] = '\0';
}

// Verifica se string só tem dígitos (número inteiro válido)
int soDigitos(const char *str) {
    if (*str == '\0') return 0; // vazio
    for (int i = 0; str[i]; i++) {
        if (str[i] < '0' || str[i] > '9') return 0;
    }
    return 1;
}

// Lê string não vazia
void lerString(char *dest, int tamanho, const char *msg) {
    do {
        printf("%s", msg);
        fgets(dest, tamanho, stdin);
        tirarEnter(dest);
    } while (strlen(dest) == 0); // repete se vazio
}

// Lê número inteiro válido
int lerInteiro(const char *msg) {
    char buffer[50];
    do {
        printf("%s", msg);
        fgets(buffer, sizeof(buffer), stdin);
        tirarEnter(buffer);
    } while (!soDigitos(buffer)); // repete até ser número
    return atoi(buffer);
}

// Lê número real válido (simples: apenas não pode ser vazio)
float lerFloat(const char *msg) {
    char buffer[50];
    do {
        printf("%s", msg);
        fgets(buffer, sizeof(buffer), stdin);
        tirarEnter(buffer);
    } while (strlen(buffer) == 0); // repete se vazio
    return atof(buffer);
}

// ===== Programa principal =====
int main() {
    char estado[3], estado2[3];
    char codigocarta[10], codigocarta2[10];
    char ncidade[30], ncidade2[30];
    
    int populacao, npontosturisticos, pop2, npt2;
    float area, area2, pib, pib2;

    // Primeira carta
    printf("======Dados referentes à primeira carta======\n");
    lerString(estado, sizeof(estado), "Digite o nome do primeiro estado de A até H:\n");
    lerString(codigocarta, sizeof(codigocarta), "Digite o código da primeira carta (Ex: A01, B02):\n");
    lerString(ncidade, sizeof(ncidade), "Digite o nome da primeira cidade:\n");
    populacao = lerInteiro("Digite a população da primeira cidade:\n");
    npontosturisticos = lerInteiro("Digite a quantidade de pontos turísticos da primeira cidade:\n");
    area = lerFloat("Digite a área da primeira cidade:\n");
    pib = lerFloat("Digite o PIB da primeira cidade:\n");

    // Segunda carta
    printf("\n======Dados referentes à segunda carta======\n");
    lerString(estado2, sizeof(estado2), "Digite o nome do segundo estado de A até H:\n");
    lerString(codigocarta2, sizeof(codigocarta2), "Digite o código da segunda carta (Ex: A01, B02):\n");
    lerString(ncidade2, sizeof(ncidade2), "Digite o nome da segunda cidade:\n");
    pop2 = lerInteiro("Digite a população da segunda cidade:\n");
    npt2 = lerInteiro("Digite a quantidade de pontos turísticos da segunda cidade:\n");
    area2 = lerFloat("Digite a área da segunda cidade:\n");
    pib2 = lerFloat("Digite o PIB da segunda cidade:\n");

    // Comparações com pontuação
    int pontos1 = 0, pontos2 = 0;

    // População
    if (populacao > pop2) {
        printf("\nA primeira cidade (%s) tem mais população que a segunda (%s).\n", ncidade, ncidade2);
        pontos1++;
    } else if (pop2 > populacao) {
        printf("\nA segunda cidade (%s) tem mais população que a primeira (%s).\n", ncidade2, ncidade);
        pontos2++;
    }

    // Pontos turísticos
    if (npontosturisticos > npt2) {
        printf("\nA primeira cidade (%s) tem mais pontos turísticos que a segunda (%s).\n", ncidade, ncidade2);
        pontos1++;
    } else if (npt2 > npontosturisticos) {
        printf("\nA segunda cidade (%s) tem mais pontos turísticos que a primeira (%s).\n", ncidade2, ncidade);
        pontos2++;
    }

    // Área
    if (area > area2) {
        printf("\nA primeira cidade (%s) tem uma área maior que a segunda (%s).\n", ncidade, ncidade2);
        pontos1++;
    } else if (area2 > area) {
        printf("\nA segunda cidade (%s) tem uma área maior que a primeira (%s).\n", ncidade2, ncidade);
        pontos2++;
    }

    // PIB
    if (pib > pib2) {
        printf("\nA primeira cidade (%s) tem um PIB maior que a segunda (%s).\n", ncidade, ncidade2);
        pontos1++;
    } else if (pib2 > pib) {
        printf("\nA segunda cidade (%s) tem um PIB maior que a primeira (%s).\n", ncidade2, ncidade);
        pontos2++;
    }

    // Resultado final
    printf("\n======Resultado Final======\n");
    if (pontos1 > pontos2)
        printf("A primeira carta (%s - %s) é a vencedora!\n", codigocarta, ncidade);
    else if (pontos2 > pontos1)
        printf("A segunda carta (%s - %s) é a vencedora!\n", codigocarta2, ncidade2);
    else
        printf("As duas cartas empataram!\n");

    return 0;
}
