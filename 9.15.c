#include <stdio.h>
#include <stdlib.h>

struct alumno {
    char nombre[30];
    int legajo;
    float notas[3];
    float promedio;
    char estado[10];
};

void cargar_alumno(struct alumno *a);
void calcular_promedio(struct alumno *a);
void determinar_estado(struct alumno *a);
void imprimir_alumno(struct alumno *a);

int main () {

    struct alumno *a;

    a = (struct alumno *) malloc(3 * sizeof(struct alumno));

    if (a == NULL) {
        printf("Error: No se pudo asignar memoria.\n");
        return 1;
    }

    cargar_alumno(a);
    calcular_promedio(a);
    determinar_estado(a);
    imprimir_alumno(a);

    free(a);

    return 0;
}

void cargar_alumno(struct alumno *a) {
    for (int i=0;i<3;i++) {
        printf("\nCargar alumno[%d]", i+1);
        printf("\nNombre: ");
        scanf("%s", (a+i)->nombre);
        printf("\nLegajo: ");
        scanf("%d", &(a+i)->legajo);
        for (int j=0;j<3;j++) {
            printf("\nNota[%d]: ", j+1);
            scanf("%f", &(a+i)->notas[j]);
        }
    }
}

void calcular_promedio(struct alumno *a) {
    for (int i=0; i<3; i++) {
        (a+i)->promedio = 0;
        for (int j=0;j<3;j++){
            (a+i)->promedio += (a+i)->notas[j];
        }
        (a+i)->promedio /= 3;
    }
}

void determinar_estado(struct alumno *a) {
    for (int i=0; i<3; i++) {
        if ((a+i)->promedio >= 8) {
            (a+i)->estado[0]= 'P';
            (a+i)->estado[1]= 'R';
            (a+i)->estado[2]= '0';
            (a+i)->estado[3]= 'M';
            (a+i)->estado[4]= '0';
            (a+i)->estado[5]= '\0';
        }
        if ((a+i)->promedio <= 8 && (a+i)->promedio >= 6) {
            (a+i)->estado[0]= 'R';
            (a+i)->estado[1]= 'E';
            (a+i)->estado[2]= 'G';
            (a+i)->estado[3]= 'U';
            (a+i)->estado[4]= 'L';
            (a+i)->estado[5]= 'A';
            (a+i)->estado[6]= 'R';
            (a+i)->estado[7]= '\0';
        }
        if ((a+i)->promedio < 6) {
            (a+i)->estado[0]= 'L';
            (a+i)->estado[1]= 'I';
            (a+i)->estado[2]= 'B';
            (a+i)->estado[3]= 'R';
            (a+i)->estado[4]= 'E';
            (a+i)->estado[5]= '\0';
        }
    }
}

void imprimir_alumno(struct alumno *a) {
    for (int i=0;i<3;i++) {
        printf("\nAlumno[%d]", i+1);
        printf("%s %d %.2f %s", (a+i)->nombre, (a+i)->legajo, (a+i)->promedio, (a+i)->estado);
    }
}
