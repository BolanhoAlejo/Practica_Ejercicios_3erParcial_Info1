# include <stdio.h>

struct producto {
    char nombre[30];
    float precio;
    int cantidad;
};

struct producto cargar_producto(void);
void imprimir_producto(struct producto p);

int main () {

    struct producto prod;

    prod = cargar_producto();
    imprimir_producto(prod);

    return 0;
}

struct producto cargar_producto() {
    struct producto prod;
    printf("\nProducto");
    printf("\nNombre: ");
    scanf("%s", prod.nombre);
    printf("\nPrecio: ");
    scanf("%f", &prod.precio);
    printf("\nCantidad: ");
    scanf("%d", &prod.cantidad);

    return prod;
}

void imprimir_producto(struct producto p) {
    printf("\nProducto: %s $%.2f %3d", p.nombre, p.precio, p.cantidad);
}



