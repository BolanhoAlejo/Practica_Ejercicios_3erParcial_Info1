# include <stdio.h>

struct producto {
    char nombre[30];
    float precio;
    int cantidad;
};

void cargar_producto(struct producto *p);
void imprimir_producto(struct producto p);

int main () {

    struct producto p;

    cargar_producto(&p);

    imprimir_producto(p);

    return 0;
}

void cargar_producto(struct producto *p) {
    printf("\nIngrese los datos del producto");
    printf("\nNombre:");
    scanf("%s", p->nombre);
    printf("\nPrecio:");
    scanf("%f", &p->precio);
    printf("\nCantidad:");
    scanf("%d", &p->cantidad);
}

void imprimir_producto(struct producto p) {
    printf("Producto: %3s $%.2f %3d", p.nombre, p.precio, p.cantidad);
}