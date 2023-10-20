#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define n 50
#define e 50
#define p 10

struct paciente {
    char nombre[n];
    int edades;
    char enfermedades[e];
} pacientes[p];

int main() {
    int i, c, d = 1;
    char temp[50];
    char respuesta[10];

    for (i = 0; i < p; i++) {
        c = i + 1; 

        printf("Nombre del paciente %d:\n", c);
        fflush(stdin);
        scanf("%s", pacientes[i].nombre);

        printf("Edad del paciente:\n");
        fflush(stdin);
        scanf("%d", &pacientes[i].edades);

        printf("¿El paciente tiene enfermedades?\nIntroduzca 'NA' si el paciente no tiene enfermedades, introduzca 'Si' en caso de que el paciente cuente con enfermedades:");
        fflush(stdin);
        scanf("%s", respuesta);

        if (strcmp(respuesta, "NA") == 0) {
            continue;
        } else {
            d = 1; 
            do {
                fflush(stdin);
                printf("Introduzca las enfermedades //Cuando finalice, introduzca 'Finalizar'\n");
                printf("Enfermedad %d:", d++);
                scanf("%s", temp);

                if (strcmp(temp, "Finalizar") == 0 || strcmp(temp, "finalizar") == 0) {
                    break; 
                } else {
                    strcpy(pacientes[i].enfermedades, temp);
                }
            } while (1); 
        }
    }
    printf("\nInformación de los pacientes:\n");
    for (i = 0; i < p; i++) {
        printf("Paciente %d:\n", i + 1);
        printf("Nombre: %s\n", pacientes[i].nombre);
        printf("Edad: %d\n", pacientes[i].edades);
        if (strlen(pacientes[i].enfermedades) > 0) {
            printf("Enfermedades: %s\n", pacientes[i].enfermedades);
        }
        printf("\n");
    }

    return 0;
}
