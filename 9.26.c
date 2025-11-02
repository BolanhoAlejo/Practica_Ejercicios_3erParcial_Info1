#include <stdio.h>
#include <stdint.h>

typedef enum {
    REPORTE_TEMP,
    REPORTE_ESTADO,
    ALERTA,
    RESERVADO
};

struct REPORTE_TEMP {
    int tipo: 2;
    int id_sensor: 8;
    int temperatura: 10;
    int humedad: 7;
    int relleno: 5;
};

struct REPORTE_ESTADO {
    int tipo: 2;
    int id_actuador: 8;
    int estado: 1;
    int potencia_actual: 5;
    int relleno: 16;
};

struct ALERTA {
    int tipo: 2;
    int codigo_error: 16;
    int timestamp_relativo: 14;
};

union TramaIoT {
    uint32_t raw_data;
    struct REPORTE_TEMP r_t;
    struct REPORTE_ESTADO r_e;
    struct ALERTA alerta;
    struct{
        unsigned int tipo: 2;
    }tramaGenerica;
};

void procesarTrama(union TramaIoT trama);

int main(void) {

    union TramaIoT miTrama;

    miTrama.raw_data = 0x1A4C8401;

    procesarTrama(miTrama);

    miTrama.raw_data = 0x00A2000A;

    procesarTrama(miTrama);

    return 0;
}

void procesarTrama(union TramaIoT trama) {
    switch(trama.tramaGenerica.tipo) {
        case REPORTE_TEMP:
            printf("\nID sensor: %d, temperatura: %d C, humedad: %d", trama.r_t.id_sensor, trama.r_t.temperatura, trama.r_t.humedad);
            break;
        case REPORTE_ESTADO:
            printf("\nID actuador: %d, estado: %d , nivel de potencia: %d", trama.r_e.id_actuador, trama.r_e.estado, trama.r_e.potencia_actual);
            break;
        case ALERTA:
            printf("\nCodigo de Error: %d, Timestamp: %d", trama.alerta.codigo_error, trama.alerta.timestamp_relativo);
            break;
        default: printf("\nNo valido");
            break;
    }
}

