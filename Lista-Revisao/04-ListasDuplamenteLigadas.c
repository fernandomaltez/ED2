#include <stdio.h>
#include <stdlib.h>

//criando o tipo abstrato de dado "nó", que possui como atributos um valor, um ponteiro para o proximo nó e um ponteiro para o nó anterior
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

//definindo o "nó raiz" da lista
Node* head = NULL;

//função que cria um novo "nó" e insere ele na lista
void insertFront() 
{
    int num;
    
    printf("Digite um valor para esse nó :");
    scanf("%d", &num);
    
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = num;
    newNode->next = head;
    newNode->prev = NULL;
    if (head != NULL)
        head->prev = newNode;
    head = newNode;
}

//função que remove o "nó"
void deleteNode(Node* node) {
    if (node == head)
        head = node->next;
    if (node->next != NULL)
        node->next->prev = node->prev;
    if (node->prev != NULL)
        node->prev->next = node->next;
    free(node);
}

//função que imprime a lista
void printList() {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void buscar()
{
    int elemento;
    printf("Digite o valor a ser buscado: ");
    scanf("%d", &elemento);

    while (1)
    {
        int aux = 1;
        Node *temp = head;
        while (temp != NULL)
        {
            if (temp->data == elemento)
            {
                break;
            }
            temp = temp->next;
            aux++;
        }
        
        if(temp != NULL)
        {
            printf("Elemento %d encontrado na posição %d \n", elemento, aux);
            printf("Elemento anterior: %d \n", temp->prev->data);
            printf("Elemento seguinte: %d", temp->next->data);
        }
        
        else
        {
            printf("Elemento %d não encontrado\n", elemento);
        }
       
        
        return;
    }

    
}


int main() 
{
    int n, aux2;
    
    printf("Digite a quantidade de valores que será inserido: ");
    
    scanf("%d", &n);
    
    for(int i = 0; i < n; i++)
    {
        insertFront();
    }
    
    
    printList();
    
    printf("Deseja buscar um numero? Se sim digite 1, se não digite 2");
    
    scanf("%d", &aux2);
    
    if(aux2 == 1)
    {
        buscar();
    }
    
    else
    {
        return 0;
    }
    
    
    
    return 0;
}
