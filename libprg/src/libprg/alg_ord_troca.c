#include "libprg/libprg.h"

int* bubbleSort(int* vetor, int tamanho)
{
    int i, j, aux;

    for(i=0; i<tamanho; i++)
    {
        for(j= 0; j< (tamanho - i); j++)
        {
            if(vetor[j] > vetor[j+1])
            {
                aux = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = aux;
            }
        }
    }
    return vetor;
}