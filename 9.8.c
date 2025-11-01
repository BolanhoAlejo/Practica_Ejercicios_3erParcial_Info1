# include <stdio.h>

struct vehiculo {
    char marca[30];
    char modelo[30];
    int anio;
    int kilometraje;
};

void mayor_kilometraje(struct vehiculo *);
void mostrar_vehiculos(struct vehiculo *);

int main () {

    struct vehiculo vehiculos[5];

    for (int i=0;i<5;i++) {
        printf("\nVehiculo[%d]", i+1);
        printf("\nMarca: ");
        scanf("%s", vehiculos[i].marca);
        printf("\nModelo: ");
        scanf("%s", vehiculos[i].modelo);
        do {
            printf("\nAnio: ");
            scanf("%d", &vehiculos[i].anio);
        }while (vehiculos[i].anio < 0);
        do {
            printf("\nKilometraje: ");
            scanf("%d", &vehiculos[i].kilometraje);
        }while (vehiculos[i].kilometraje < 0);
    }

    mostrar_vehiculos(vehiculos);
    mayor_kilometraje(vehiculos);

    return 0;
}

void mayor_kilometraje(struct vehiculo *p) {
    int may = 0;
    int indice = 0;
    for (int i=0;i<5;i++) {
        if (p[i].kilometraje > may) {
            may = p[i].kilometraje;
            indice = i+1;
        }
    }
    printf("\nEl mayor kilometraje lo tiene el veiculo Nro: %d", indice);
}

void mostrar_vehiculos(struct vehiculo *p) {
    for (int i=0;i<5;i++) {
        printf("\nVehiculo[%d]", i+1);
        printf("%s %s %d %d", p[i].marca, p[i].modelo, p[i].anio, p[i].kilometraje);
    }
}