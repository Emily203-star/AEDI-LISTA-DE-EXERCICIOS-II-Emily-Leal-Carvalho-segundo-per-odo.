#include <stdio.h>
#include <stdbool.h>

#define MAX_NUM 100
#define NUM_PRIMOS 25

bool ePrimo(int num) {
    if (num <= 1) return false;
    if (num <= 3) return true;
    if (num % 2 == 0 || num % 3 == 0) return false;
    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) return false;
    }
    return true;
}

int buscaBinaria(int primos[], int tamanho, int numeroBusca) {
    int esquerda = 0;
    int direita = tamanho - 1;
    int meio;
    
    while (esquerda <= direita) {
        meio = esquerda + (direita - esquerda) / 2;
        
        if (primos[meio] == numeroBusca) {
            return meio;
        } else if (primos[meio] < numeroBusca) {
            esquerda = meio + 1;
        } else {
            direita = meio - 1;
        }
    }
    
    return -1;
}

int main() {
    int primos[NUM_PRIMOS];
    int numPrimos = 0;
    int numeroBusca;
    
    for (int i = 2; i <= MAX_NUM; i++) {
        if (ePrimo(i)) {
            primos[numPrimos++] = i;
        }
    }
    
    printf("Digite um número de 1 a 100: ");
    scanf("%d", &numeroBusca);
    
    if (numeroBusca < 1 || numeroBusca > MAX_NUM) {
        printf("Número fora do intervalo permitido.\n");
        return 1;
    }
    
    int resultado = buscaBinaria(primos, numPrimos, numeroBusca);
    
    if (resultado != -1) {
        printf("Número %d é primo e está na posição %d da lista.\n", numeroBusca, resultado);
    } else {
        printf("Número %d não é primo ou não está na lista.\n", numeroBusca);
    }
    
    return 0;
}