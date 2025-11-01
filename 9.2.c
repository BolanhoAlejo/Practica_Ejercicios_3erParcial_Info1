#include <stdio.h>

struct cliente {
    char apellido[20];
    char nombre[20];
    int numero;
    int dni;
    char calle[20];
    char ciudad[20];
};

int main(void){

    struct cliente c1;

    printf("Ingrese los datos del cliente");
    printf("\nApellido:");
    scanf("%s", c1.apellido);
    printf("\nNombre:");
    scanf("%s", c1.nombre);
    printf("\nNumero:");
    scanf("%d", &c1.numero);
    printf("\nDNI:");
    scanf("%d", &c1.dni);
    printf("\nCalle:");
    scanf("%s", c1.calle);
    printf("\nCiudad:");
    scanf("%s", c1.ciudad);

    printf("\nApellido: %s", c1.apellido);
    printf("\nNombre: %s", c1.nombre);
    printf("\nNumero: %d", c1.numero);
    printf("\nDNI: %d", c1.dni);
    printf("\nCalle: %s", c1.calle);
    printf("\nCuidad: %s", c1.ciudad);


    return 0;
}