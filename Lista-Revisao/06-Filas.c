#include <stdio.h>
#include <stdlib.h>

//Criando o TAD "Node" que possui como atributos um valor e um ponteiro para "Node"
typedef struct Node {
    int data;            
    struct Node* next;   
} Node;

//Criando o TAD "Queue" que possui como atributos dois ponteiros, um para o início da fila e um para o fim
typedef struct Queue {
    Node* front;  
    Node* rear;   
} Queue;

//Função que cria uma fila
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));  
    if (q == NULL) {  
        printf("Falha na alocação de memória para a fila.\n");
        return NULL;  
    }
    q->front = q->rear = NULL;  
    return q;  
}

//Função que adiciona elementos à fila 
void enqueue(Queue* q, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));  
    if (newNode == NULL) { 
        printf("Falha na alocação de memória para o novo nó.\n");
        return;
    }
    newNode->data = value;  
    newNode->next = NULL;  
    if (q->rear == NULL) {  
        q->front = q->rear = newNode;  
    } else {  
        q->rear->next = newNode;  
        q->rear = newNode;  
    }
}

//Função que remove elementos da fila 
int dequeue(Queue* q) {
    if (q->front == NULL) {  
        printf("Fila está vazia.\n");
        return -1;  
    }
    Node* temp = q->front;  
    int data = temp->data;  
    q->front = q->front->next;  
    if (q->front == NULL) {  
        q->rear = NULL;  
    }
    free(temp);  
    return data;  
}

//Função que verifica se a fila está vazia
int isEmpty(Queue* q) {
    return q->front == NULL;  
}

//Função que imprime os elementos da fila
void printQueue(Queue* q) {
    if (isEmpty(q)) {  
        printf("A fila está vazia.\n");
        return;
    }
    Node* temp = q->front;  
    printf("Elementos da fila: ");
    while (temp != NULL) {  
        printf("%d ", temp->data);  
        temp = temp->next;  
    }
    printf("\n");  
}

//Função para contar o número de elementos na fila
int countElements(Queue* q) {
    int count = 0;  
    Node* temp = q->front;  
    while (temp != NULL) {  
        count++;  
        temp = temp->next;  
    }
    return count;  
}

//Função para limpar todos os elementos da fila e liberar a memória
void clearQueue(Queue* q) {
    Node* temp = q->front;  
    while (temp != NULL) {  
        Node* next = temp->next; 
        free(temp);  
        temp = next;  
    }
    q->front = q->rear = NULL;  
}

int main() {
    Queue* q = createQueue();  
    enqueue(q, 10);  
    enqueue(q, 20);  
    enqueue(q, 30);  
    printQueue(q);  

    printf("Número de elementos na fila: %d\n", countElements(q));  

    printf("Desenfileirado: %d\n", dequeue(q));  
    printQueue(q);  

    clearQueue(q);  
    printQueue(q);  

    free(q);  
    return 0; 
}
