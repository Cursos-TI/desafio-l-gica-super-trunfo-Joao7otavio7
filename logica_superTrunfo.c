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


int main (){

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
   cartaB = 1 / cartaA.densidadepop;

    // calcular o super poder

   cartaA.superpoder = (cartaA.populacao + cartaA.pib + cartaA.area+ cartaA.nturisticos +
                  cartaA.rendapercapita + cartaA.inversiondensidade);
    cartaB.superpoder = (cartaA.populacao + cartaA.pib + cartaA.area + cartaA.nturisticos +
        cartaA.rendapercapita + cartaA.inversiondensidade);

   
    carta jogador,computador;
    int escolha;

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




    
    
   
    
   

  return 0;
}