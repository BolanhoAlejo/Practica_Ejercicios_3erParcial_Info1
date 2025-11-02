# include <stdio.h>
# include <stdlib.h>
# include <time.h>

typedef enum{
    TIPO_TEMPERATURA,
    TIPO_PRESION,
    TIPO_ESTADO
    } TipoLectura;

typedef union{
    float temperatura;
    int presion_kpa;
    long codigo_error;
} ValorLectura;

typedef struct {
    long timestamp;
    TipoLectura tipo;
    ValorLectura valor;
} SensorLectura;

void imprimirLectura(SensorLectura *);

int main(void) {

    srand(time(NULL));

    SensorLectura lecturaActual;
    SensorLectura *pLectura = &lecturaActual;

    lecturaActual.timestamp = time(NULL);

    lecturaActual.tipo = rand() %3;

    switch(pLectura->tipo) {
        case TIPO_TEMPERATURA:
            printf("\nIngrese una temperatura:");
            scanf("%f", &pLectura->valor.temperatura);
            break;
        case TIPO_PRESION:
            printf("\nIngrese una Presion:");
            scanf("%d", &pLectura->valor.presion_kpa);
            break;
        case TIPO_ESTADO:
            printf("\nIngrese un codigo de estado:");
            scanf("%ld", &pLectura->valor.codigo_error);
            break;
        default:  printf("\nOpcion no valida");
            break;
    }

    imprimirLectura(pLectura);

    return 0;
}

void imprimirLectura(SensorLectura *p) {
    printf("Timestamp: %ld", p->timestamp);
    switch (p->tipo) {
        case TIPO_TEMPERATURA:
            printf("\nTemperatura: %.2f C", p->valor.temperatura);
        break;
        case TIPO_PRESION:
            printf("\nPresion: %d kPa", p->valor.presion_kpa);
        break;
        case TIPO_ESTADO:
            printf("\nCodigo de estado: %ld", p->valor.codigo_error);
        break;
        default:  printf("\nOpcion no valida");
        break;
    }
}