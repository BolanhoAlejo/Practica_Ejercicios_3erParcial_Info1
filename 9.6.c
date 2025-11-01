# include <stdio.h>
struct inventario {
    char nombre[30];
    int numero_parte;
    float precio;
    int stock;
};
void imprimir_inventario (struct inventario item);

int main () {

    struct inventario item1 = {
        "Resistor 10k",
        1234,
        0.15,
        250
    };

    imprimir_inventario (item1);
    return 0;
}

void imprimir_inventario(struct inventario item) {
    printf("\nInventario: ");
    printf("\nNombre: %s", item.nombre);
    printf("\nNumero de parte: %d", item.numero_parte);
    printf("\nPrecio: %.2f", item.precio);
    printf("\nStock: %d", item.stock);
}