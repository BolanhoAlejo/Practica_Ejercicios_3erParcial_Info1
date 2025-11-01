#include <stdio.h>

#define CANT_ALU 3

struct alumno {
    int legajo;
    char nombre[20];
    char apellido[20];
    char curso[3];
    int notas[4];
    float promedio;
    char estado;
};

void calcular_promedio(struct alumno *);
void determinar_estado(struct alumno *);
void mostrar_alumno(struct alumno *);

int main ( void )
{
    struct alumno alumnos [CANT_ALU];

    for (int i=0;i<CANT_ALU;i++) {
        printf("\nAlumno [%d]", i+1);
        printf("\nNombre:");
        scanf("%s", alumnos[i].nombre);
        printf("\nApellido:");
        scanf("%s", alumnos[i].apellido);
        printf("\nLegajo:");
        scanf("%d", &alumnos[i].legajo);
        printf("\nCurso:");
        scanf("%s", alumnos[i].curso);
        for (int j=0; j<3;j++) {
            printf("\nNota[%d]:", j);
            scanf("%d", &alumnos[i].notas[j]);
        }
    }

    calcular_promedio(alumnos);
    determinar_estado(alumnos);
    mostrar_alumno(alumnos);

    return 0;
}

void calcular_promedio(struct alumno *p) {
    for (int i=0;i<CANT_ALU;i++) {
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
            p[i].estado = 'P';
        }
        if (p[i].promedio >= 6 && p[i].promedio <= 8) {
            p[i].estado = 'R';
        }
        if (p[i].promedio <= 6) {
            p[i].estado = 'L';
        }
    }
}

void mostrar_alumno(struct alumno *p) {
    for (int i=0; i<3; i++) {
        printf("\nNombre: %s", p[i].nombre);
        printf("\nApellido: %s", p[i].apellido);
        printf("\nLegajo: %d", p[i].legajo);
        printf("\nCurso: %s", p[i].curso);
        for (int j=0;j<3;j++) {
            printf("\nNota: %d", p[i].notas[j]);
        }
        printf("\nPromedio: %.2f", p[i].promedio);
        printf("\nEstado: %c", p[i].estado);

    }
}