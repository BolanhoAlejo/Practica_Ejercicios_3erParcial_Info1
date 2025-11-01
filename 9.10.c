# include <stdio.h>

struct domicilio {
    char calle[30];
    int numero;
    char ciudad[30];
};

struct alumno {
    char nombre[30];
    int legajo;
    struct domicilio dom_alumno;
};

void imprimir_alumno(struct alumno *);

int main () {

    struct alumno alum;

    printf("\nIngrese los datos del alumno:");
    printf("\nNombre:");
    scanf("%s", alum.nombre);
    do {
        printf("\nLegajo:");
        scanf("%d", &alum.legajo);
    }while (alum.legajo < 0);
    printf("\nIngrese los datos del domicilio del alumno:");
    printf("\nCalle:");
    scanf("%s", alum.dom_alumno.calle);
    do {
        printf("\nNumero:");
        scanf("%d", &alum.dom_alumno.numero);
    }while (alum.dom_alumno.numero < 0);
    printf("\nCuidad:");
    scanf("%s", alum.dom_alumno.ciudad);

    imprimir_alumno(&alum);

    return 0;
}

void imprimir_alumno(struct alumno *p) {
    printf("\nAlumno:");
    printf("%s %d", p->nombre, p->legajo);
    printf("\nDomicilio:");
    printf("%s %d %s", p->dom_alumno.calle, p->dom_alumno.numero, p->dom_alumno.ciudad);
}


