#include <stdio.h>
#include <stdlib.h>

struct parte {
    unsigned int partNumber;
    char partName[25];
};

int main () {

    struct parte a;
    struct parte b[10];
    struct parte *ptr;

    printf("\nIngrese un numero de parte:");
    scanf("%d", &a.partNumber);
    printf("\nIngrese el nombre de la parte:");
    scanf("%s", a.partName);

    b[2].partNumber = a.partNumber;
    for (int i=0;i<25;i++) {
        b[2].partName[i] = a.partName[i];
    }

    ptr = &b[2];

    printf("\nParte numero: %d", ptr->partNumber);
    printf("\nNombre: %s", ptr->partName);

    return 0;
}
