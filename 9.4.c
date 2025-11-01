#include <stdio.h>

typedef struct {
    char nombre[30];
    int numero_parte;
    float precio;
    int stock;
}inventario;

int main ( void )
{
    inventario inv = {
        "Inventario1",
        30,
        28.99,
        80
    };

    printf("\nNombre: %s", inv.nombre);
    printf("\nNumero de Parte: %d", inv.numero_parte);
    printf("\nPrecio: %.2f", inv.precio);
    printf("\nStock: %d", inv.stock);

    return 0;
}