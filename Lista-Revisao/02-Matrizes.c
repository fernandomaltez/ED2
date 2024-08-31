#include <stdio.h>

int main() {
    
    int i, j, n, soma = 0;
    
    printf("Escolha um tamanho para a linha e a coluna da matriz");
    
    scanf("%d", &n);
    
    
    int matriz[n][n];

    
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) 
        {
            printf("Insira o elemento da posição %dx%d:\n", (i+1), (j+1));
            
            scanf("%d", &matriz[i][j]);
            if (i == j) {
                soma += matriz[i][j];
            }
        }
    }

    printf("Soma dos elementos da diagonal principal: %d\n", soma);
    return 0;
}
