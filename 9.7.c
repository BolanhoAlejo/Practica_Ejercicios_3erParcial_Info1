# include <stdio.h>

struct libro {
    char titulo[50];
    char autor[40];
    int anio;
    float precio;
};

int main () {

    struct libro lib[3];

    for (int i=0;i<3;i++) {
        printf("\nLibro[%d]", i+1);
        printf("\nTitulo:");
        scanf("%s", lib[i].titulo);
        printf("\nAutor:");
        scanf("%s", lib[i].autor);
        do {
            printf("\nAnio:");
            scanf("%d", &lib[i].anio);
        }while (lib[i].anio <= 0);
        do {
            printf("\nPrecio:");
            scanf("%f", &lib[i].precio);
        }while (lib[i].precio <= 0);
    }

for (int i=0;i<3;i++) {
    printf("\nLibro[%d]: ", i+1);
    printf("%5s %5s %5d %.2f", lib[i].titulo, lib[i].autor, lib[i].anio, lib[i].precio);
}

    return 0;
}
