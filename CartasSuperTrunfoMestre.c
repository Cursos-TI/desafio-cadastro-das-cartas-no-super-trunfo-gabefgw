#include <stdio.h>
#include <string.h>

int main () {

    // dados primeira carta
    char estado[25];
    char codigo[5];
    char nomeCidade[30];
    float pib;
    unsigned long int populacao;
    int numeroPontoturistico;
    float area;
    float densidadePopulacional;
    float pibperCapita;
    float superPoder1;

    // dados segunda carta
    char estado2[25];
    char codigo2[5];
    char nomeCidade2[30];
    float pib2;
    unsigned long int populacao2;
    int numeroPontoturistico2;
    float area2;
    float densidadePopulacional2;
    float pibperCapita2;
    float superPoder2;

    printf("##### Bem vindo ao cadastro de cartas do jogo SuperTrunfo! ##### \n");
    printf("*** Digite as informações da sua primeira carta SuperTrunfo! *** \n\n");

    printf("Digite o estado da sua primeira carta: \n");
    fgets(estado, sizeof(estado), stdin);
    estado[strcspn(estado, "\n")] = '\0';

    printf("Digite o código da sua primeira carta: \n");
    scanf("%s", codigo);

    printf("Digite o nome da cidade da sua primeira carta: \n");
    getchar(); 
    fgets(nomeCidade, sizeof(nomeCidade), stdin);
    nomeCidade[strcspn(nomeCidade, "\n")] = '\0';

    printf("Digite a população da sua primeira carta: \n");
    scanf("%lu", &populacao);

    printf("Digite a área da sua primeira carta: \n");
    scanf("%f", &area);

    printf("Digite o PIB da sua primeira carta: \n");
    scanf("%f", &pib);

    printf("Digite a quantidade de pontos turísticos da sua primeira carta: \n");
    scanf("%d", &numeroPontoturistico);

    densidadePopulacional = populacao / area;
    pibperCapita = pib / populacao;
    superPoder1 = (float)populacao + area + pib + numeroPontoturistico + pibperCapita + (1.0 / densidadePopulacional);

    printf("*** Os dados da primeira carta foram cadastrados! *** \n\n");

    printf("Os dados da sua primeira carta são:\n");
    printf("Estado: %s\n", estado);
    printf("Código: %s \n", codigo); 
    printf("Nome da cidade: %s \n", nomeCidade);
    printf("População: %lu \n", populacao);
    printf("Área: %.2f km² \n", area);  
    printf("PIB: %.2f Bilhões \n", pib);
    printf("Número de pontos turísticos: %d \n", numeroPontoturistico);
    printf("Densidade populacional: %.2f hab/km² \n", densidadePopulacional);
    printf("PIB per Capita: %.2f Reais \n", pibperCapita);


    printf("*** Digite as informações da sua segunda carta SuperTrunfo! *** \n\n");

    getchar(); // limpar buffer
    printf("Digite o estado da sua segunda carta: \n");
    fgets(estado2, sizeof(estado2), stdin);
    estado2[strcspn(estado2, "\n")] = '\0';

    printf("Digite o código da sua segunda carta: \n");
    scanf("%s", codigo2);

    printf("Digite o nome da cidade da sua segunda carta: \n");
    getchar(); 
    fgets(nomeCidade2, sizeof(nomeCidade2), stdin);
    nomeCidade2[strcspn(nomeCidade2, "\n")] = '\0';

    printf("Digite a população da sua segunda carta: \n");
    scanf("%lu", &populacao2);

    printf("Digite a área da sua segunda carta: \n");
    scanf("%f", &area2);

    printf("Digite o PIB da sua segunda carta: \n");
    scanf("%f", &pib2);

    printf("Digite a quantidade de pontos turísticos da sua segunda carta: \n");
    scanf("%d", &numeroPontoturistico2);

    densidadePopulacional2 = populacao2 / area2;
    pibperCapita2 = pib2 / populacao2;
    superPoder2 = (float)populacao2 + area2 + pib2 + numeroPontoturistico2 + pibperCapita2 + (1.0 / densidadePopulacional2);

    printf("*** Os dados da segunda carta foram cadastrados! *** \n\n");

    printf("Os dados da sua segunda carta são:\n");
    printf("Estado: %s\n", estado2);
    printf("Código: %s \n", codigo2); 
    printf("Nome da cidade: %s \n", nomeCidade2);
    printf("População: %lu \n", populacao2);
    printf("Área: %.2f km² \n", area2);  
    printf("PIB: %.2f Bilhões \n", pib2);
    printf("Número de pontos turísticos: %d \n", numeroPontoturistico2);
    printf("Densidade populacional: %.2f hab/km² \n", densidadePopulacional2);
    printf("PIB per Capita: %.2f Reais \n", pibperCapita2);

    printf("\n##### Hora das cartas lutarem! #####\n");
    printf("\n##### Comparação de Cartas #####\n\n");

    printf("População: Carta 1 venceu (%d)\n", populacao > populacao2);
    printf("Área: Carta 1 venceu (%d)\n", area > area2);
    printf("PIB: Carta 1 venceu (%d)\n", pib > pib2);
    printf("Pontos Turísticos: Carta 1 venceu (%d)\n", numeroPontoturistico > numeroPontoturistico2);
    printf("Densidade Populacional: Carta 1 venceu (%d)\n", densidadePopulacional < densidadePopulacional2);
    printf("PIB per Capita: Carta 1 venceu (%d)\n", pibperCapita > pibperCapita2);
    printf("Super Poder: Carta 1 venceu (%d)\n", superPoder1 > superPoder2);

    return 0;
}
