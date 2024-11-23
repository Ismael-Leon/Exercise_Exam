#include <stdio.h>
#include <stdbool.h>

bool esPar(int numero) {
    return numero % 2 == 0;
}

bool esImpar(int numero) {
    return numero % 2 != 0;
}

void imprimirNumerosYCalcularSuma(int inicio, int fin, bool (*criterio)(int), const char *tipo) {
    int suma = 0;
    printf("Numeros %s en el rango [%d, %d]:\n", tipo, inicio, fin);
    for (int i = inicio; i <= fin; i++) {
        if (criterio(i)) {
            printf("%d ", i);
            suma += i;
        }
    }
    printf("\nSuma de los numeros %s: %d\n", tipo, suma);
}

void manejarOpciones(int inicio, int fin) {
    int opcion;
    do {
        printf("\nSeleccione una opcion:\n");
        printf("1. Mostrar todos los numeros pares en el rango y calcular su suma\n");
        printf("2. Mostrar todos los numeros impares en el rango y calcular su suma\n");
        printf("3. Mostrar tanto los numeros pares como los impares, junto con sus respectivas sumas\n");
        printf("4. Salir.\n");
        printf("Ingrese su opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                imprimirNumerosYCalcularSuma(inicio, fin, esPar, "pares");
                break;
            case 2:
                imprimirNumerosYCalcularSuma(inicio, fin, esImpar, "impares");
                break;
            case 3:
                imprimirNumerosYCalcularSuma(inicio, fin, esPar, "pares");
                imprimirNumerosYCalcularSuma(inicio, fin, esImpar, "impares");
                break;
            case 4:
                printf("Fin del programa\n");
                break;
            default:
                printf("Opcion invalida. Intente otra ves.\n");
        }
    } while (opcion != 4);
}

int main() {
    int inicio, fin;


    do {
        printf("Ingrese el numeo inicial del rango: ");
        scanf("%d", &inicio);
        printf("Ingrese el numero final del rango: ");
        scanf("%d", &fin);

        if (inicio > fin) {
            printf("El numero inicial debe ser menor o igual al numero final. Intente otra ves.\n");
        }
    } while (inicio > fin);

    manejarOpciones(inicio, fin);

    return 0;
}
