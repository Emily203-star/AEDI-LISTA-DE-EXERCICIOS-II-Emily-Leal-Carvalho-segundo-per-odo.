#include <stdio.h>

#define NUM_CONTAS 100

int buscaBinaria(int contas[], int tamanho, int contaBusca, int *comparacoes) {
    int esquerda = 0;
    int direita = tamanho - 1;
    int meio;
    
    while (esquerda <= direita) {
        (*comparacoes)++;
        meio = esquerda + (direita - esquerda) / 2;
        
        if (contas[meio] == contaBusca) {
            return meio;
        } else if (contas[meio] < contaBusca) {
            esquerda = meio + 1;
        } else {
            direita = meio - 1;
        }
    }
    
    return -1;
}

int main() {
    int contas[NUM_CONTAS];
    int contaBusca;
    int comparacoes = 0;
    
    for (int i = 0; i < NUM_CONTAS; i++) {
        contas[i] = i + 1;
    }
    
    printf("Digite o número da conta a ser buscada: ");
    scanf("%d", &contaBusca);
    
    int resultado = buscaBinaria(contas, NUM_CONTAS, contaBusca, &comparacoes);
    
    if (resultado != -1) {
        printf("Conta %d encontrada na posição %d.\n", contaBusca, resultado);
    } else {
        printf("Conta %d não encontrada.\n", contaBusca);
    }
    
    printf("Número de comparações: %d\n", comparacoes);
    
    return 0;
}