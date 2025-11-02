#include <stdio.h>
#include <stdlib.h>

struct producto {
    char nombre[30];
    float precio;
    int stock;
};

void cargar_producto(struct producto *);
void imprimir_producto(struct producto);
void actualizar_stock(struct producto *, int);

int main () {

    char update[30];
    int bandera = 0;

    struct producto *p;

    cargar_producto(p);

    imprimir_producto(*p);

    printf("\nActualizar stock");
    do {
        printf("\nSumar o Restar? ");
        scanf("%s", &update);
        printf("%s", update);
        if (update[0] == 'S' || update[0] == 's') {
            actualizar_stock(p, 1);
            bandera = 0;
        }else if (update[0] == 'R' || update[0] == 'r') {
            actualizar_stock(p, 0);
            bandera = 0;
        }else {
            printf("\nRespuesta no valida");
            bandera = 1;
        }
    }while (bandera == 1);

    imprimir_producto(*p);

    return 0;
}

void cargar_producto(struct producto *p) {
    printf("\nCargar producto");
    printf("\nNombre: ");
    scanf("%s", p->nombre);
    printf("\nPrecio: ");
    scanf("%f", &p->precio);
    printf("\nStock: ");
    scanf("%d", &p->stock);
}

void imprimir_producto(struct producto p) {
    printf("\nProducto: ");
    printf("%s %.2f %d", p.nombre, p.precio, p.stock);
}

void actualizar_stock(struct producto *p, int o) {
    int update;
    if (o==1) {
        printf("\nCuando quiere sumar?");
        scanf("%d", &update);
        p->stock += update;
    }else {
        printf("\nCuando quiere restar?");
        scanf("%d", &update);
        p->stock -= update;
    }
}