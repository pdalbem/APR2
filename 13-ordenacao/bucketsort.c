
#include <stdio.h>
#include <stdlib.h>

// Complexidade:
// Melhor caso: O(n), sob distribuição adequada dos valores.
// Caso médio: O(n), supondo distribuição aproximadamente uniforme.
// Pior caso: O(n²), quando muitos elementos ficam no mesmo balde.
// Espaço auxiliar: O(n).

typedef struct No
{
    float valor;
    struct No *prox;
} No;

// Insere um elemento no balde, mantendo a ordem crescente
No *inserirOrdenado(No *lista, No *novo)
{
    if (lista == NULL || novo->valor < lista->valor)
    {
        novo->prox = lista;
        return novo;
    }

    No *atual = lista;

    while (atual->prox != NULL &&
           atual->prox->valor <= novo->valor)
    {
        atual = atual->prox;
    }

    novo->prox = atual->prox;
    atual->prox = novo;

    return lista;
}

// Libera todos os nós de uma lista
void liberarLista(No *lista)
{
    while (lista != NULL)
    {
        No *temp = lista;
        lista = lista->prox;
        free(temp);
    }
}

// Bucket Sort
int bucketSort(float arr[], int n)
{
    if (n <= 1)
    {
        if (n == 1 && (arr[0] < 0.0f || arr[0] >= 1.0f))
            return 0;

        return 1;
    }

    // Valida os valores antes de modificar o vetor
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < 0.0f || arr[i] >= 1.0f)
            return 0;
    }

    No **baldes = calloc((size_t)n, sizeof(No *));

    if (baldes == NULL)
        return 0;

    // Distribui os elementos pelos baldes
    for (int i = 0; i < n; i++)
    {
        int indice = (int)(arr[i] * n);

        No *novo = malloc(sizeof(No));

        if (novo == NULL)
        {
            for (int j = 0; j < n; j++)
                liberarLista(baldes[j]);

            free(baldes);
            return 0;
        }

        novo->valor = arr[i];
        novo->prox = NULL;

        baldes[indice] = inserirOrdenado(
            baldes[indice], novo);
    }

    // Reúne os elementos na ordem dos baldes
    int indice = 0;

    for (int i = 0; i < n; i++)
    {
        No *atual = baldes[i];

        while (atual != NULL)
        {
            arr[indice] = atual->valor;
            indice++;

            atual = atual->prox;
        }

        liberarLista(baldes[i]);
    }

    free(baldes);
    return 1;
}

void printArray(float arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%.2f ", arr[i]);

    printf("\n");
}

int main()
{
    float arr[] = {0.64f, 0.25f, 0.12f, 0.22f, 0.11f};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Vetor original:\n");
    printArray(arr, n);

    if (bucketSort(arr, n))
    {
        printf("Vetor ordenado:\n");
        printArray(arr, n);
    }
    else
    {
        printf("Erro: valores fora do intervalo ou falta de memória.\n");
    }

    return 0;
}
