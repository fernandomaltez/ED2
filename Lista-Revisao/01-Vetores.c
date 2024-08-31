#include <stdio.h>

int main() 
{
    int i, temp, n;
    
    printf("Insira um tamanho para o vetor");
    
    scanf("%d", &n);
    
    int vetor[n];
    
    for(i=0; i < n; i++)
    {
        printf("Insira o valor para a posição %d do vetor", i);
        
        scanf("%d", &vetor[i]);
    }
    
    
    //nesse caso o vetor possui um tamanho par
    if((n%2)==0)
    {
       for (i = 0; i < (n/2); i++) {
        temp = vetor[i];
        vetor[i] = vetor[n-i-1];
        vetor[n-i-1] = temp;
       }
    }
    
    //nesse caso o vetor possui um tamanho ímpar
    else
    {
        for (i = 0; i < ((n+1)/2); i++) {
        temp = vetor[i];
        vetor[i] = vetor[n-i-1];
        vetor[n-i-1] = temp;
        }
    }

    printf("Vetor invertido:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", vetor[i]);
    }

    return 0;
}
    
    
