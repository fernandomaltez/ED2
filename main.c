#include <stdio.h>

#define TAMANHO_HASH 10
#define TAMANHO_ENDEREÇO 100

typedef struct
{
    int id;
    char[TAMANHO_ENDEREÇO] endereço;
    int tamanhoPacote;
    int tempoEntrega,
}Entrega;

typedef struct
{
    Entrega* tabela[TAMANHO_HASH];
}TabelaHash;

int funcao_hash(int id) 
{
    return id % TAMANHO_HASH;  
}

void insercao(Entrega* tabela)


Entrega* funcaoBuscar(TabelaHash *tabela, int id) 
{
    int indice = funcao_hash(id);  // Calcula o índice para busca
    return tabela->tabela[indice];  // Retorna a transação encontrada
}

void funcaoRemover(TabelaHash *tabela, int id)
{
    int indice = funcao_hash(id);
    
    for(int i=0; i<TAMANHO_HASH; i++)
    {
        
    }
}

int main()
{
    

    return 0;
}
