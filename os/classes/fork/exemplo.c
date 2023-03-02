#include <stdio.h>

int main () {
        float hora;
        float minutos;

        printf("Digite a hora: ");
        scanf("%f", &hora);

        printf("Digite os minutos: ");
        scanf("%f", &minutos);

        minutos = minutos / 60;
        hora = hora + minutos;

        printf("A hora e minutos digitados convertidos\napenas para horas é igual a: %f\n", hora);

        return 0;
}