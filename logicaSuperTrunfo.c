#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Função para exibir o menu e obter a escolha do usuário
int exibirMenuAtributos(int atributoExcluido) {
    int escolha;
    printf("\nEscolha um atributo para comparacao:\n");

    if (atributoExcluido != 1) {
        printf("1. Populacao\n");
    }
    if (atributoExcluido != 2) {
        printf("2. Area\n");
    }
    if (atributoExcluido != 3) {
        printf("3. PIB\n");
    }
    if (atributoExcluido != 4) {
        printf("4. Pontos Turisticos\n");
    }
    if (atributoExcluido != 5) {
        printf("5. Densidade Demografica\n");
    }
    printf("Digite sua escolha: ");
    scanf("%d", &escolha);

    if (escolha < 1 || escolha > 5 || escolha == atributoExcluido) {
        printf("Escolha invalida ou atributo ja selecionado. O programa prosseguira com um valor padrao ou sem repeticao.\n");
        return 0;
    }
    return escolha;
}

int main(){
    int resultado1 = 0, resultado2 = 0;
    int primeiroAtributoInt, segundoAtributoInt;

    // Dados da Carta 1 (Brasil)
    char pais1[] = "Brasil";
    long long populacao1 = 210000000LL;
    float area1 = 8515767.0f;
    float pib1 = 22000.0f;
    int pontos_turisticos1 = 75;
    float densidade1 = populacao1 / area1;

    // Dados da Carta 2 (Argentina)
    char pais2[] = "Argentina";
    long long populacao2 = 45000000LL;
    float area2 = 2780400.0f;
    float pib2 = 630.0f;
    int pontos_turisticos2 = 50;
    float densidade2 = populacao2 / area2;
    
    printf("Bem-vindo ao Super Trunfo de Paises!\n");
    printf("Voce ira comparar %s e %s.\n", pais1, pais2);

    primeiroAtributoInt = exibirMenuAtributos(0);

    if (primeiroAtributoInt == 0) {
        printf("Primeiro atributo nao selecionado corretamente. O jogo nao pode continuar.\n");
        return 1;
    }

    printf("\nAgora escolha o segundo atributo para comparacao (diferente do primeiro):\n");
    segundoAtributoInt = exibirMenuAtributos(primeiroAtributoInt);

    if (segundoAtributoInt == 0) {
        printf("Segundo atributo nao selecionado corretamente. O jogo nao pode continuar.\n");
        return 1;
    }

    float valorAtr1_Pais1, valorAtr2_Pais1;
    float valorAtr1_Pais2, valorAtr2_Pais2;

    // Atribuição dos valores para o Pais 1
    if (primeiroAtributoInt == 1) valorAtr1_Pais1 = populacao1;
    else if (primeiroAtributoInt == 2) valorAtr1_Pais1 = area1;
    else if (primeiroAtributoInt == 3) valorAtr1_Pais1 = pib1;
    else if (primeiroAtributoInt == 4) valorAtr1_Pais1 = pontos_turisticos1;
    else if (primeiroAtributoInt == 5) valorAtr1_Pais1 = densidade1;

    if (segundoAtributoInt == 1) valorAtr2_Pais1 = populacao1;
    else if (segundoAtributoInt == 2) valorAtr2_Pais1 = area1;
    else if (segundoAtributoInt == 3) valorAtr2_Pais1 = pib1;
    else if (segundoAtributoInt == 4) valorAtr2_Pais1 = pontos_turisticos1;
    else if (segundoAtributoInt == 5) valorAtr2_Pais1 = densidade1;

    // Atribuição dos valores para o Pais 2
    if (primeiroAtributoInt == 1) valorAtr1_Pais2 = populacao2;
    else if (primeiroAtributoInt == 2) valorAtr1_Pais2 = area2;
    else if (primeiroAtributoInt == 3) valorAtr1_Pais2 = pib2;
    else if (primeiroAtributoInt == 4) valorAtr1_Pais2 = pontos_turisticos2;
    else if (primeiroAtributoInt == 5) valorAtr1_Pais2 = densidade2;

    if (segundoAtributoInt == 1) valorAtr2_Pais2 = populacao2;
    else if (segundoAtributoInt == 2) valorAtr2_Pais2 = area2;
    else if (segundoAtributoInt == 3) valorAtr2_Pais2 = pib2;
    else if (segundoAtributoInt == 4) valorAtr2_Pais2 = pontos_turisticos2;
    else if (segundoAtributoInt == 5) valorAtr2_Pais2 = densidade2;

    // Lógica de comparação para o primeiro atributo
    int resultadoAtr1;
    resultadoAtr1 = (primeiroAtributoInt == 5) ?
                    ((valorAtr1_Pais1 < valorAtr1_Pais2) ? 1 : ((valorAtr1_Pais2 < valorAtr1_Pais1) ? 2 : 0)) :
                    ((valorAtr1_Pais1 > valorAtr1_Pais2) ? 1 : ((valorAtr1_Pais2 > valorAtr1_Pais1) ? 2 : 0));

    // Lógica de comparação para o segundo atributo
    int resultadoAtr2;
    resultadoAtr2 = (segundoAtributoInt == 5) ?
                    ((valorAtr2_Pais1 < valorAtr2_Pais2) ? 1 : ((valorAtr2_Pais2 < valorAtr2_Pais1) ? 2 : 0)) :
                    ((valorAtr2_Pais1 > valorAtr2_Pais2) ? 1 : ((valorAtr2_Pais2 > valorAtr2_Pais1) ? 2 : 0));
    
    // Somar pontos se vencerem o atributo
    if (resultadoAtr1 == 1) resultado1++;
    else if (resultadoAtr1 == 2) resultado2++;

    if (resultadoAtr2 == 1) resultado1++;
    else if (resultadoAtr2 == 2) resultado2++;

    printf("\n--- Resultado da Comparacao ---\n");
    printf("Cartas Comparadas: %s vs %s\n", pais1, pais2);
    
    // Exibição do nome do primeiro atributo diretamente no printf
    if (primeiroAtributoInt == 1) printf("Atributos Escolhidos: Populacao");
    else if (primeiroAtributoInt == 2) printf("Atributos Escolhidos: Area");
    else if (primeiroAtributoInt == 3) printf("Atributos Escolhidos: PIB");
    else if (primeiroAtributoInt == 4) printf("Atributos Escolhidos: Pontos Turisticos");
    else if (primeiroAtributoInt == 5) printf("Atributos Escolhidos: Densidade Demografica");

    // Exibição do nome do segundo atributo diretamente no printf
    if (segundoAtributoInt == 1) printf(" e Populacao\n");
    else if (segundoAtributoInt == 2) printf(" e Area\n");
    else if (segundoAtributoInt == 3) printf(" e PIB\n");
    else if (segundoAtributoInt == 4) printf(" e Pontos Turisticos\n");
    else if (segundoAtributoInt == 5) printf(" e Densidade Demografica\n");


    printf("\n%s:\n", pais1);
    // Exibição do nome do primeiro atributo diretamente no printf
    if (primeiroAtributoInt == 1) printf("  Populacao: %.2f\n", valorAtr1_Pais1);
    else if (primeiroAtributoInt == 2) printf("  Area: %.2f\n", valorAtr1_Pais1);
    else if (primeiroAtributoInt == 3) printf("  PIB: %.2f\n", valorAtr1_Pais1);
    else if (primeiroAtributoInt == 4) printf("  Pontos Turisticos: %.2f\n", valorAtr1_Pais1);
    else if (primeiroAtributoInt == 5) printf("  Densidade Demografica: %.2f\n", valorAtr1_Pais1);

    // Exibição do nome do segundo atributo diretamente no printf
    if (segundoAtributoInt == 1) printf("  Populacao: %.2f\n", valorAtr2_Pais1);
    else if (segundoAtributoInt == 2) printf("  Area: %.2f\n", valorAtr2_Pais1);
    else if (segundoAtributoInt == 3) printf("  PIB: %.2f\n", valorAtr2_Pais1);
    else if (segundoAtributoInt == 4) printf("  Pontos Turisticos: %.2f\n", valorAtr2_Pais1);
    else if (segundoAtributoInt == 5) printf("  Densidade Demografica: %.2f\n", valorAtr2_Pais1);


    printf("\n%s:\n", pais2);
    // Exibição do nome do primeiro atributo diretamente no printf
    if (primeiroAtributoInt == 1) printf("  Populacao: %.2f\n", valorAtr1_Pais2);
    else if (primeiroAtributoInt == 2) printf("  Area: %.2f\n", valorAtr1_Pais2);
    else if (primeiroAtributoInt == 3) printf("  PIB: %.2f\n", valorAtr1_Pais2);
    else if (primeiroAtributoInt == 4) printf("  Pontos Turisticos: %.2f\n", valorAtr1_Pais2);
    else if (primeiroAtributoInt == 5) printf("  Densidade Demografica: %.2f\n", valorAtr1_Pais2);

    // Exibição do nome do segundo atributo diretamente no printf
    if (segundoAtributoInt == 1) printf("  Populacao: %.2f\n", valorAtr2_Pais2);
    else if (segundoAtributoInt == 2) printf("  Area: %.2f\n", valorAtr2_Pais2);
    else if (segundoAtributoInt == 3) printf("  PIB: %.2f\n", valorAtr2_Pais2);
    else if (segundoAtributoInt == 4) printf("  Pontos Turisticos: %.2f\n", valorAtr2_Pais2);
    else if (segundoAtributoInt == 5) printf("  Densidade Demografica: %.2f\n", valorAtr2_Pais2);
    
    printf("\n--- Resultado Final da Rodada ---\n");
    printf("Pontuacao %s: %d\n", pais1, resultado1);
    printf("Pontuacao %s: %d\n", pais2, resultado2);

    if (resultado1 > resultado2) {
        printf("VENCEDOR GERAL: %s!\n", pais1);
    } else if (resultado2 > resultado1) {
        printf("VENCEDOR GERAL: %s!\n", pais2);
    } else {
        printf("EMPATE GERAL!\n");
    }

    printf("\nFim do jogo!\n");

    return 0;
}