#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_CRIANÇAS 50
#define MIN_NOTA 1
#define MAX_NOTA 5

int main() {
    int notas[NUM_CRIANÇAS];
    int contagem[MAX_NOTA] = {0};

    srand(time(NULL));

    for (int i = 0; i < NUM_CRIANÇAS; i++) {
        notas[i] = MIN_NOTA + rand() % (MAX_NOTA - MIN_NOTA + 1);
    }

    for (int i = 0; i < NUM_CRIANÇAS; i++) {
        int nota = notas[i];
        if (nota >= MIN_NOTA && nota <= MAX_NOTA) {
            contagem[nota - 1]++;
        }
    }

    printf("Contagem de notas:\n");
    for (int i = 0; i < MAX_NOTA; i++) {
        printf("Nota %d: %d vez(es)\n", i + 1, contagem[i]);
    }

    return 0;
}