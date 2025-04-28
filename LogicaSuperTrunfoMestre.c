#include <stdio.h>
#include <string.h>

int main() {
    // Dados da primeira carta
    char estado[25], codigo[5], nomeCidade[30];
    float pib, area;
    unsigned long int populacao;
    int numeroPontoturistico;
    float densidadePopulacional, pibperCapita;

    // Dados da segunda carta
    char estado2[25], codigo2[5], nomeCidade2[30];
    float pib2, area2;
    unsigned long int populacao2;
    int numeroPontoturistico2;
    float densidadePopulacional2, pibperCapita2;

    // Variáveis para jogo
    int atributo1 = -1, atributo2 = -1;
    float valorCarta1_attr1 = 0, valorCarta2_attr1 = 0;
    float valorCarta1_attr2 = 0, valorCarta2_attr2 = 0;
    float somaCarta1 = 0, somaCarta2 = 0;

    printf("##### Cadastro das cartas SuperTrunfo! #####\n");

    printf("\n*** Primeira carta ***\n");
    printf("Estado: ");
    fgets(estado, sizeof(estado), stdin);
    estado[strcspn(estado, "\n")] = '\0';

    printf("Código: ");
    scanf("%s", codigo);

    printf("Nome da cidade: ");
    getchar();
    fgets(nomeCidade, sizeof(nomeCidade), stdin);
    nomeCidade[strcspn(nomeCidade, "\n")] = '\0';

    printf("População: ");
    scanf("%lu", &populacao);

    printf("Área (km²): ");
    scanf("%f", &area);

    printf("PIB (em bilhões): ");
    scanf("%f", &pib);

    printf("Número de pontos turísticos: ");
    scanf("%d", &numeroPontoturistico);

    densidadePopulacional = populacao / area;
    pibperCapita = pib / populacao;

    printf("\n*** Segunda carta ***\n");
    getchar();
    printf("Estado: ");
    fgets(estado2, sizeof(estado2), stdin);
    estado2[strcspn(estado2, "\n")] = '\0';

    printf("Código: ");
    scanf("%s", codigo2);

    printf("Nome da cidade: ");
    getchar();
    fgets(nomeCidade2, sizeof(nomeCidade2), stdin);
    nomeCidade2[strcspn(nomeCidade2, "\n")] = '\0';

    printf("População: ");
    scanf("%lu", &populacao2);

    printf("Área (km²): ");
    scanf("%f", &area2);

    printf("PIB (em bilhões): ");
    scanf("%f", &pib2);

    printf("Número de pontos turísticos: ");
    scanf("%d", &numeroPontoturistico2);

    densidadePopulacional2 = populacao2 / area2;
    pibperCapita2 = pib2 / populacao2;

    // Tela de escolha dos atributos
    printf("\n##### Escolha dois atributos para comparação! #####\n");

    printf("\nAtributos disponíveis:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Número de Pontos Turísticos\n");
    printf("5 - Densidade Populacional\n");
    printf("6 - PIB per Capita\n");

    printf("\nEscolha o primeiro atributo (1-6): ");
    scanf("%d", &atributo1);

    switch (atributo1) {
        case 1:
            valorCarta1_attr1 = populacao;
            valorCarta2_attr1 = populacao2;
            break;
        case 2:
            valorCarta1_attr1 = area;
            valorCarta2_attr1 = area2;
            break;
        case 3:
            valorCarta1_attr1 = pib;
            valorCarta2_attr1 = pib2;
            break;
        case 4:
            valorCarta1_attr1 = numeroPontoturistico;
            valorCarta2_attr1 = numeroPontoturistico2;
            break;
        case 5:
            valorCarta1_attr1 = densidadePopulacional;
            valorCarta2_attr1 = densidadePopulacional2;
            break;
        case 6:
            valorCarta1_attr1 = pibperCapita;
            valorCarta2_attr1 = pibperCapita2;
            break;
        default:
            printf("Opção inválida! Encerrando...\n");
            return 1;
    }

    // Agora escolher o segundo atributo (sem repetir o primeiro)
    do {
        printf("\nEscolha o segundo atributo (1-6), diferente do primeiro: ");
        scanf("%d", &atributo2);

        if (atributo2 == atributo1) {
            printf("Você já escolheu esse! Escolha outro.\n");
        }

    } while (atributo2 == atributo1);

    switch (atributo2) {
        case 1:
            valorCarta1_attr2 = populacao;
            valorCarta2_attr2 = populacao2;
            break;
        case 2:
            valorCarta1_attr2 = area;
            valorCarta2_attr2 = area2;
            break;
        case 3:
            valorCarta1_attr2 = pib;
            valorCarta2_attr2 = pib2;
            break;
        case 4:
            valorCarta1_attr2 = numeroPontoturistico;
            valorCarta2_attr2 = numeroPontoturistico2;
            break;
        case 5:
            valorCarta1_attr2 = densidadePopulacional;
            valorCarta2_attr2 = densidadePopulacional2;
            break;
        case 6:
            valorCarta1_attr2 = pibperCapita;
            valorCarta2_attr2 = pibperCapita2;
            break;
        default:
            printf("Opção inválida! Encerrando...\n");
            return 1;
    }

    // Soma dos valores dos dois atributos de cada carta
    somaCarta1 = valorCarta1_attr1 + valorCarta1_attr2;
    somaCarta2 = valorCarta2_attr1 + valorCarta2_attr2;

    printf("\n##### Resultado #####\n");
    printf("\nSoma dos atributos:\n");
    printf("%s: %.2f\n", nomeCidade, somaCarta1);
    printf("%s: %.2f\n", nomeCidade2, somaCarta2);

    // Determinando o vencedor
    if (somaCarta1 > somaCarta2) {
        printf("\n%s venceu!\n", nomeCidade);
    } else if (somaCarta2 > somaCarta1) {
        printf("\n%s venceu!\n", nomeCidade2);
    } else {
        printf("\nEmpate!\n");
    }

    return 0;
}
