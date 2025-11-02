#include<stdio.h>

typedef enum{
    ORDEN_DESCONOCIDO,
    LITTLE_ENDIAN,
    BIG_ENDIAN
}Endianness;

typedef union{
    unsigned int valorInt;
    unsigned char bytes[4];
}InspectorBytes;

Endianness chequearSistema(void);

int main(void) {

    InspectorBytes inspector;
    Endianness endianSistema;

    endianSistema = chequearSistema();

    printf("\nEl sistema es: %d", endianSistema);

    printf("\nIngrese un entero sin signo:");
    scanf("%ld", &inspector.valorInt);

    printf("\nEl valor [%ld] se representa en memoria como:");
    for (int i=0;i<4;i++) {
        printf("\nByte %d: 0x%02X\n", i, inspector.bytes[i]);
    }

    return 0;
}

Endianness chequearSistema(void) {
    InspectorBytes insp;
    insp.valorInt = 1;
    if (insp.bytes[0] == 1) {
        return LITTLE_ENDIAN;
    }else if (insp.bytes[0] == 0 && insp.bytes[3] == 1) {
        return BIG_ENDIAN;
    }else {
        return ORDEN_DESCONOCIDO;
    }
}