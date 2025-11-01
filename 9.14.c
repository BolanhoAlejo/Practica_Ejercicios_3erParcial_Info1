#include <stdio.h>
#define size 3

struct producto {
    char nombre[30];
    float precio;
    int cantidad;
};

void cargar_producto(struct producto *p, int tam);
void imprimir_producto(struct producto *p, int tam);

int main () {

    struct producto p[size];

    cargar_producto(p, size);

    imprimir_producto(p, size);

    return 0;
}

void cargar_producto(struct producto *p, int tam) {
    for (int i=0;i<tam; i++) {
        printf("\nIngrese los datos del producto[%d]", i+1);
        printf("\nNombre:");
        scanf("%s", p[i].nombre);
        printf("\nPrecio:");
        scanf("%f", &p[i].precio);
        printf("\nCantidad:");
        scanf("%d", &p[i].cantidad);
    }
}

void imprimir_producto(struct producto *p, int tam) {
    for (int i=0;i<tam;i++){
        printf("\nProducto: %3s $%.2f %3d", p[i].nombre, p[i].precio, p[i].cantidad);
    }
}