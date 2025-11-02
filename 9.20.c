#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char apodo[20];
    int rango;
    float vida;
    float escudo;
    float sales;
    struct{
        char nombre[20];
        char apellido[20];
        int edad;
    } info_personal;
}personaje_t;

int main () {

    srand(time(NULL));

    personaje_t *p;

    p = malloc(sizeof(personaje_t));

    printf("\nIngrese su apodo: ");
    scanf("%s", p->apodo);
    printf("\nIngrese su nombre: ");
    scanf("%s", p->info_personal.nombre);
    printf("\nIngrese su apellido: ");
    scanf("%s", p->info_personal.apellido);
    printf("\nIngrese su edad: ");
    scanf("%d", &p->info_personal.edad);

    p->escudo = 0;
    p->sales = 0;
    p->vida = 150.0;
    p->rango = rand() % 101;

    printf("\nEl apodo es %s", p->apodo);
    printf("\nEl nombre es %s", p->info_personal.nombre);
    printf("\nEl apellido es %s", p->info_personal.apellido);
    printf("\nRango: %d", p->rango);
    printf("\nVida %.2f", p->vida);
    printf("\nEscudo %.2f", p->escudo);
    printf("\nSales %.2f", p->sales);



    return 0;
}
