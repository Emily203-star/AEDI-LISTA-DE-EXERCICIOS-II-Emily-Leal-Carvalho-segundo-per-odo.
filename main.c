#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_TAM 10

void exibirPalavra(char palavra[], int acertou[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        if (acertou[i]) {
            printf("%c ", palavra[i]);
        } else {
            printf("_ ");
        }
    }
    printf("\n");
}

int main() {
    char palavra[MAX_TAM + 1], letra;
    int vidas, acertou[MAX_TAM] = {0}, letrasRestantes, encontrouLetra;
    
    printf("Digite a palavra secreta (até 10 caracteres): ");
    scanf("%s", palavra);
    
    int tamanhoPalavra = strlen(palavra);
    letrasRestantes = tamanhoPalavra;
    
    vidas = tamanhoPalavra + 2;
    
    printf("\n--- JOGO DA FORCA ---\n");
    
    while (vidas > 0 && letrasRestantes > 0) {
        encontrouLetra = 0;
        printf("\nPalavra: ");
        exibirPalavra(palavra, acertou, tamanhoPalavra);
        printf("Vidas restantes: %d\n", vidas);
        
        printf("Digite uma letra: ");
        scanf(" %c", &letra);
        letra = tolower(letra);
        
        for (int i = 0; i < tamanhoPalavra; i++) {
            if (tolower(palavra[i]) == letra && !acertou[i]) {
                acertou[i] = 1;
                letrasRestantes--;
                encontrouLetra = 1;
                printf("Letra %c encontrada na posição %d!\n", letra, i + 1);
            }
        }
        
        if (!encontrouLetra) {
            vidas--;
            printf("A letra %c não está na palavra!\n", letra);
        }
    }
    
    if (letrasRestantes == 0) {
        printf("\nParabéns! Você descobriu a palavra: %s\n", palavra);
    } else {
        printf("\nGame Over! Você ficou sem vidas. A palavra era: %s\n", palavra);
    }

    return 0;
}