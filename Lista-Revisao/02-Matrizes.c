#include <stdio.h>

int main() {
    
    int i, j, n, soma = 0;
    
    printf("Escolha um tamanho para a linha e a coluna da matriz");
    
    scanf("%d", &n);
    
    
    int matriz[n][n];

    printf("Insira os elementos da matriz %dx%d:\n", n, n);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &matriz[i][j]);
            if (i == j) {
                soma += matriz[i][j];
            }
        }
    }

    printf("Soma dos elementos da diagonal principal: %d\n", soma);
    return 0;
}
