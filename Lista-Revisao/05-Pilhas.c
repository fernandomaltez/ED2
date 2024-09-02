#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 3 

int *pilha; 
int topo = -1; 
int capacidade = MAX_SIZE; 

// Função para adicionar um elemento ao topo da pilha
void push(int elemento) {
    if (topo < capacidade - 1) { 
        pilha[++topo] = elemento; 
    } else {
        printf("Pilha cheia! Expansão aplicada.\n");
        capacidade *= 2; 
        pilha = realloc(pilha, capacidade * sizeof(int)); 
        if (pilha == NULL) { 
            printf("Erro ao expandir a pilha.\n");
            exit(1); 
        }
        pilha[++topo] = elemento; 
    }
}

// Função para remover o elemento do topo da pilha
int pop() {
    if (topo == -1) { 
        printf("Pilha vazia!\n");
        return -1; 
    } else {
        return pilha[topo--]; 
    }
}

// Função que retorna o elemento do topo da pilha
int top() {
    if (topo == -1) { // Verifica se a pilha está vazia
        printf("Pilha vazia!\n");
        return -1; // Retorna -1 indicando que a pilha está vazia
    } else {
        return pilha[topo]; // Retorna o elemento do topo
    }
}

// Função que imprime os elementos da pilha
void imprimir() {
    if (topo == -1) { 
        printf("A pilha está vazia.\n");
        return;
    }
    printf("Conteúdo da pilha:\n");
    for (int i = topo; i >= 0; i--) { 
        printf("%d ", pilha[i]); 
    }
    printf("\n"); 
}

// Função que verifica se a pilha está vazia
int isEmpty() {
    return topo == -1; 
}

int main() {
    pilha = (int*)malloc(capacidade * sizeof(int)); 
    if (pilha == NULL) { 
        printf("Erro ao alocar memória para a pilha.\n");
        return 1; 
    }

    push(10); 
    push(320); 
    push(4); 
    push(52); 
    push(80); 

    imprimir(); 

    printf("Elemento no topo: %d\n", top()); 
    printf("Elemento removido: %d\n", pop()); 
    imprimir(); 

    
    if (isEmpty()) {
        printf("A pilha está vazia.\n");
    } else {
        printf("A pilha não está vazia.\n");
    }

    free(pilha); 
    return 0;
}
