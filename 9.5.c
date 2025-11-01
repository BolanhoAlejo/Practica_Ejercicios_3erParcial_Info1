#include <stdio.h>

struct alumno{
    int legajo;
    int dni;
    float notas[3];
    float promedio;
    char estado[10];
};

void calculo_promedio(struct alumno *);
void determinar_estado(struct alumno *);
void mostrar_alumnos(struct alumno *);

int main ( void )
{
    struct alumno alu[3];

    for (int i=0;i<3;i++) {
        printf("\nAlumno [%d]", i+1);
        do {
            printf("\nLegajo:");
            scanf("%d", &alu[i].legajo);
        }while (alu[i].legajo<0);
        do {
            printf("\nDNI:");
            scanf("%d", &alu[i].dni);
        }while (alu[i].dni<0);
        for (int j=0;j<3;j++) {
            printf("\nNota: [%d]", j+1);
            scanf("%f", &alu[i].notas[j]);
        }
    }

    calculo_promedio(alu);
    determinar_estado(alu);
    mostrar_alumnos(alu);

    return 0;
}

void calculo_promedio(struct alumno *p) {
    for (int i=0;i<3;i++) {
        p[i].promedio = 0;
        for (int j=0;j<3;j++) {
            p[i].promedio += p[i].notas[j];
        }
        p[i].promedio /= 3;
    }
}

void determinar_estado(struct alumno *p) {
    for (int i=0;i<3;i++) {
        if (p[i].promedio >= 8) {
            p[i].estado[0] = 'P';
            p[i].estado[1] = 'R';
            p[i].estado[2] = 'O';
            p[i].estado[3] = 'M';
            p[i].estado[4] = 'O';
            p[i].estado[5] = '\0';
        }
        if (p[i].promedio >= 6 && p[i].promedio <= 8) {
            p[i].estado[0] = 'R';
            p[i].estado[1] = 'E';
            p[i].estado[2] = 'G';
            p[i].estado[3] = 'U';
            p[i].estado[4] = 'L';
            p[i].estado[5] = 'A';
            p[i].estado[6] = 'R';
            p[i].estado[7] = '\0';
        }
        if (p[i].promedio < 6) {
            p[i].estado[0] = 'L';
            p[i].estado[1] = 'I';
            p[i].estado[2] = 'B';
            p[i].estado[3] = 'R';
            p[i].estado[4] = 'E';
            p[i].estado[5] = '\0';
        }
    }
}

void mostrar_alumnos(struct alumno *p) {
    for (int i=0;i<3;i++) {
        printf("\nAlumno [%d]", i+1);
        printf("\nLegajo: %d", p[i].legajo);
        printf("\nDNI: %d", p[i].dni);
        for (int j=0; j<3;j++) {
            printf("\nNota [%d]: %.2f", j+1, p[i].notas[j]);
        }
        printf("\nPromedio: %.2f", p[i].promedio);
        printf("\nEstado: %s", p[i].estado);
    }
}