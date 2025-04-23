#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
typedef struct 
{
    char pais[50]; //Variavel para País
    char estado[50];   //Variavel para estado
    char cdg[50];  //Variavél para código de carta
    char ncidade[50];  //Variavel para cidade
    unsigned long int populacao;  //Variavel para população
    float area;     //Variavel para area²
    long double pib;      //Variavel para PIB
    int nturisticos;  // Variavel para pontos turisticos
    float densidadepop; // Variavel para densidade populacional
    long double rendapercapita; // Variavel para Renda per capta
    long double superpoder; // Variavel para"A01", super poder.
    float inversiondensidade; // Variavel para calculo da densidade ivertida
} carta;

//Função para exibir os atributos das cartas
void mostrarCarta(carta c){
    printf ("\n\n");
    printf ("Carta 1: \n");
    printf ("País: %s\n", c.pais);
    printf ("Estado: %s\n", c.estado);
    printf ("Código: %s\n", c.cdg);
    printf ("Nome da cidade: %s\n", c.ncidade);
    printf ("População: %lu\n", c.populacao);
    printf ("Àrea: %.2f km²\n", c.area);
    printf ("PIB: %.2Lf bilhões de reais\n", c.pib);
    printf ("Números de Pontos Turísticos: %d\n", c.nturisticos);
    printf ("Densidade Populacional: %.2f hab/km²\n", c.densidadepop);
    printf ("PIB per Capita: %.2Lf reais\n", c.rendapercapita);
    printf ("Super Poder: %.2Lf\n", c.superpoder);
}

// Função para retornar o nome do atributo
char* nomeAtributo(int codigo) {
    switch (codigo) {
        case 1: return "População";
        case 2: return "Área";
        case 3: return "PIB";
        case 4: return "Densidade Populacional";
        case 5: return "Pontos Turísticos";
        case 6: return "Renda per Capita";
        case 7: return "Superpoder";
        default: return "Desconhecido";
    }
}

int main (){
    long double somajogador, somacomputador;

// Esse é o código do jogo super trunfo um jogo de cartas super divertido onde o usúario vai se divertir muito.
    //Somente para sorteio.
    srand(time(NULL));
    
    //Cartas prédefinidas
    carta cartaA = {"Brasil", "SP", "A01", "São Paulo",  11451245, 1521.00, 748000000000, 36};
    carta cartaB = {"Argentina", "CABA", "B01", "Buenos Aires", 3121000, 203.00, 111808600, 15};


     // Calculo de densidade populacional 

    cartaA.densidadepop = (cartaA.populacao / cartaA.area );
    cartaB.densidadepop = (cartaB.populacao / cartaB.area );

    // Calculo de para renda per capita
    
    cartaA.rendapercapita = (cartaA.pib / cartaA.populacao);
    cartaB.rendapercapita = (cartaB.pib / cartaB.populacao);

    // calcular a densidade invertida

   cartaA.inversiondensidade = 1 / cartaA.densidadepop;
   cartaB.inversiondensidade = 1 / cartaA.densidadepop;

    // calcular o super poder

   cartaA.superpoder = (cartaA.populacao + cartaA.pib + cartaA.area+ cartaA.nturisticos +
                  cartaA.rendapercapita + cartaA.inversiondensidade);
    cartaB.superpoder = (cartaA.populacao + cartaA.pib + cartaA.area + cartaA.nturisticos +
        cartaA.rendapercapita + cartaA.inversiondensidade);

   
    carta jogador,computador;
    int escolha,escolhacomputador1,escolhacomputador2,escolhaatributo1,escolhaatributo2;

    printf("Escolha sua carta:\n1 - Carta A (São Paulo)\n2 - Carta B (Buenos Aires)\n");
    scanf("%d", &escolha);
    if (escolha == 1) {
        jogador = cartaA;
        computador = cartaB;
    } else {
        jogador = cartaB;
        computador = cartaA;
    }

    printf("\nSua carta é:\n");
    mostrarCarta(jogador);

    printf ("\n Escolha o primeiro atributo para comparar:\n");
    printf ("1 - População:\n2 - Área em km²\n3 - PIB\n4 - Densidade Populacional\n5 - Números de pontos Turisticos\n6 - Renda per capita\n7 - Superpoder\n");
    scanf ("%d", &escolhaatributo1);
    printf ("\n Escolha o segundo atributo:\n");
    scanf ("%d", &escolhaatributo2);

    if (escolhaatributo1 == escolhaatributo2) {
        printf ("Você já escolheu esse atributo! Escolha outro diferente:\n");
        scanf ("%d", &escolhaatributo2);
    }
    // Computador escolhe aleatoriamente um atributo
    escolhacomputador1 = (rand() % 7) + 1;
    escolhacomputador2 = (rand() % 7) + 1;
    if (escolhacomputador1 == escolhacomputador2) {
        escolhacomputador2 = (rand() % 7) + 1;
    }

    printf ("Computador escolheu os atributos %d, e %d\n", escolhacomputador1, escolhacomputador2);

    float valorjogador1,valorjogador2,valorcomputador1,valorcomputador2;

    switch (escolhaatributo1)
    {
    case 1:
        valorjogador1 = jogador.populacao;    
        break;
        case 2:
        valorjogador1 = jogador.area;
        printf("\n%s: %.2f", nomeAtributo(escolhaatributo1), valorjogador1);       
        break;
        case 3:
        valorjogador1 = jogador.pib; 
        printf("\n%s: %.2Lf", nomeAtributo(escolhaatributo1), valorjogador1);       
        break;
        case 4:
        valorjogador1 = jogador.densidadepop;  
        printf("\n%s: %.2f", nomeAtributo(escolhaatributo1), valorjogador1);      
        break;
        case 5:
        valorjogador1 = jogador.nturisticos;
        printf("\n%s: %d", nomeAtributo(escolhaatributo1), valorjogador1);       
        break;
        case 6:
        valorjogador1 = jogador.rendapercapita; 
        printf("\n%s: %.2Lf", nomeAtributo(escolhaatributo1), valorjogador1);       
        break;
        case 7:
        valorjogador1 = jogador.superpoder;
        printf("\n%s: %.2Lf", nomeAtributo(escolhaatributo1), valorjogador1);
        break;

    
        default:
    printf ("Opção inválida!");
        break;
    }

    switch (escolhaatributo2)
    {
    case 1:
        valorjogador2 = jogador.populacao;
        printf("\n%s: %lu", nomeAtributo(escolhaatributo2), valorjogador2);
        break;
        case 2:
        valorjogador2 = jogador.area;
        printf("\n%s: %.2f", nomeAtributo(escolhaatributo2), valorjogador2);
        break;
        case 3:
        valorjogador2 = jogador.pib;
        printf("\n%s: %.2lu", nomeAtributo(escolhaatributo2), valorjogador2);
        break;
        case 4:        
        valorjogador2 = jogador.densidadepop;
        printf("\n%s: %.2f", nomeAtributo(escolhaatributo2), valorjogador2);
        break;
        case 5:       
        valorjogador2 = jogador.nturisticos;
        printf("\n%s: %d", nomeAtributo(escolhaatributo2), valorjogador2);
        break;
        case 6:       
        valorjogador2 = jogador.rendapercapita;
        printf("\n%s: %.2Lf", nomeAtributo(escolhaatributo2), valorjogador2);
        break;
        case 7:        
        valorjogador2 = jogador.superpoder;
        printf("\n%s: %.2Lf", nomeAtributo(escolhaatributo2), valorjogador2);
        break;

    
        default:
    printf ("Opção inválida!");
        break;
    }


    switch (escolhacomputador1)
    {
    case 1:
        valorcomputador1 = computador.populacao;        
        break;
        case 2:
        valorcomputador1 = computador.area;        
        break;
        case 3:
        valorcomputador1 = computador.pib;       
        break;
        case 4:
        valorcomputador1 = computador.densidadepop;        
        break;
        case 5:
        valorcomputador1 = computador.nturisticos;        
        break;
        case 6:
        valorcomputador1 = computador.rendapercapita;        
        break;
        case 7:
        valorcomputador1 = computador.superpoder;        
        break;

    
        default:
    printf ("Opção inválida!");
        break;
    }

    switch (escolhacomputador2)
    {
    case 1:       
        valorcomputador2 = computador.populacao;
        break;
        case 2:        
        valorcomputador2 = computador.area;
        break;
        case 3:       
        valorcomputador2 = computador.pib;
        break;
        case 4:        
        valorcomputador2 = computador.densidadepop;
        break;
        case 5:       
        valorcomputador2 = computador.nturisticos;
        break;
        case 6:        
        valorcomputador2 = computador.rendapercapita;
        break;
        case 7:        
        valorcomputador2 = computador.superpoder;
        break;

    
        default:
    printf ("Opção inválida!");
        break;
    }

    somajogador = (escolhaatributo1 + escolhaatributo2);
    somacomputador = (escolhacomputador1 + escolhacomputador2);

   

    printf("\n==============================\n");
    printf("Comparando as cartas...\n");

    printf("\nVocê escolheu a carta do país: %s", jogador.pais);
    printf("\nO computador ficou com a carta do país: %s\n", computador.pais);

    printf("\nAtributos escolhidos pelo Jogador: %s e %s\n",
        nomeAtributo(escolhaatributo1), nomeAtributo(escolhaatributo2));
    printf("\nAtributos escolhidos pelo Computador: %s e %s\n",
            nomeAtributo(escolhacomputador1), nomeAtributo(escolhacomputador2));
    
    printf("\nValores do jogador:");
    if (escolhaatributo1 = 1){
        printf("\n%s: %lu", nomeAtributo(escolhaatributo1), valorjogador1);
    }

    if (escolhaatributo2 = 2) {
        printf("\n%s: %.2f", nomeAtributo(escolhaatributo2), valorjogador2);

    }



   /* printf("\n%s: %.2Lf", nomeAtributo(escolhaatributo1), valorjogador1);*/
    /*printf("\n%s: %.2Lf", nomeAtributo(escolhaatributo2), valorjogador2);*/

    printf ("\nSoma atributos jogador:%.2Lf", somajogador);

    printf("\n\nValores do computador:");
    printf("\n%s: %.2Lf", nomeAtributo(escolhaatributo1), valorcomputador1);
    printf("\n%s: %.2Lf", nomeAtributo(escolhaatributo2), valorcomputador2);
    printf ("\nSoma atributos compupatador: %.2Lf", somacomputador);






    /*
    printf("\nResultado:\n");
    printf("Seu valor: %.2f, %.2f\n", valorjogador1, valorjogador2);
    printf("Valor do computador: %.2f, %.2f\n", valorcomputador1, valorcomputador2);

    */

    if (valorjogador1 > valorcomputador1 && valorjogador2 > valorcomputador2) {
        printf("\nParabéns! Você venceu!\n");
    } else if (valorjogador1 < valorcomputador1 && valorjogador2 < valorcomputador2) {
        printf("\nComputador venceu!\n");
    } else {
        printf("\nEmpate!\n");
    }











    
    
   
    
   

  return 0;
}