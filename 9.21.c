#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define CANT 100

typedef struct {
    int palo: 4; // basto , copa , espada , oro
    int num: 12;
} cartasBit_t;

void crear_baraja (cartasBit_t *mazo, int cant);
void repartir_baraja (cartasBit_t *mazo , int cant);

int main ( void )
{
    srand(time(NULL));

    cartasBit_t cartas[CANT];

    printf("\nInicializando el maso...");
    printf("\nRepartiendo el mazo...");

    crear_baraja(cartas, CANT);
    repartir_baraja(cartas, CANT);

    return 0;
}

void crear_baraja(cartasBit_t *mazo, int cant) {
    for (int i=0;i<cant;i++) {
        mazo[i].palo = (rand() % 4)+1;
        mazo[i].num = (rand() % 12)+1;
    }
}

void repartir_baraja(cartasBit_t *mazo, int cant) {
    for (int i=0;i<cant/2;i+=2) {
        printf("\nCarta  Palo  Numero          Carta  Palo  Numero");
        printf("\n  %d     %d    %d              %d    %d     %d", i, mazo[i].palo, mazo[i].num, i+1, mazo[i+1].palo, mazo[i+1].num);
    }
}