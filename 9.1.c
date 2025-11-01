#include <stdio.h>

typedef struct {
    char nombre[30];
    int numero_parte;
    float precio;
    int stock;
}inventario;

typedef struct {
    char direccion[30];
    char cuidad[25];
    int codpost[6];
}ubicacion;

int main(void) {

    inventario inv = {
        "Inventario1",
        2,
        12.50,
        10
    };

    ubicacion ubi = {
        "Francisco N de Laprida",
        "Cordoba",
        500
    };

    printf("Inventario\n");
    printf("\nNombre: %s", inv.nombre);
    printf("\nNumero Parte: %d", inv.numero_parte);
    printf("\nPrecio: %.2f", inv.precio);
    printf("\nStock: %d", inv.stock);

    printf("\nDireccion: %s", ubi.direccion);
    printf("\nCuidad: %s", ubi.cuidad);
    printf("\nCodigo Postal: %d", ubi.codpost[0]);




    return 0;
}