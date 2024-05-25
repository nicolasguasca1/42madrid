#include <stdio.h>

void rush(int x, int y) {
    if (x <= 0 || y <= 0) {
        return;
    }

    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            if ((i == 0 && j == 0) || (i == 0 && j == x - 1) || (i == y - 1 && j == 0) || (i == y - 1 && j == x - 1)) {
                // Esquinas
                printf("o");
            } else if (i == 0 || i == y - 1) {
                // Bordes superiores e inferiores
                printf("-");
            } else if (j == 0 || j == x - 1) {
                // Bordes laterales
                printf("|");
            } else {
                // Espacio interior
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {
    // Ejemplo de prueba
    rush(5, 3);
    printf("\n");
    rush(5, 1);
    printf("\n");
    rush(1, 1);
    printf("\n");
    rush(1, 5);
    return 0;
}

