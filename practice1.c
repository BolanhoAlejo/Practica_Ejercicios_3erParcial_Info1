#include <stdio.h>

union float_ieee754 {
    float real;
    struct {
        unsigned int matisa:23;
        unsigned int exponente:8;
        unsigned int signo:1;
    }ieee754;
    unsigned int entero;
};

void cargar_real(union float_ieee754 *p);
void imprimir_ieee754(union float_ieee754 *p);
void imprimir_32bits(unsigned int entero);

int main (void)
{
    union float_ieee754 dato;

    cargar_real(&dato);
    imprimir_ieee754(&dato);
    imprimir_32bits(dato.entero);

    return 0;
}

void cargar_real(union float_ieee754 *p) {
    printf("Ingrese un numero real: ");
    scanf("%f", &p->real);
}

void imprimir_ieee754(union float_ieee754 *p) {
    printf("%d", p->ieee754.signo);
    printf("%d", p->ieee754.exponente);
    printf("%d", p->ieee754.matisa);
    printf("\n");
}

void imprimir_32bits(unsigned int entero) {
    unsigned int mascara = 1 << 31;
    for (int i=0;i<32;i++) {
        printf("%d", entero & mascara ? 1 : 0);
        mascara >>= 1;
    }
    printf("\n");
}