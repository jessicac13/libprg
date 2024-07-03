#include <libprg/libprg.h>


int* bubbleSort(int* vetor, int tamanho, bool crescente)
{
    int i, j, aux;

    if(crescente = true)
    {
        for(i=0; i<tamanho; i++)
        {
            for(j= 1; j< (tamanho - i); j++)
            {
                if(vetor[j] < vetor[j-1])
                {
                    aux = vetor[j];
                    vetor[j] = vetor[j-1];
                    vetor[j-1] = aux;
                }
            }
        }
    }
    if (crescente = false)
    {
        for(i=0; i<tamanho; i++)
        {
            for(j= 1; j< (tamanho - i); j++)
            {
                if(vetor[j] > vetor[j-1])
                {
                    aux = vetor[j];
                    vetor[j] = vetor[j-1];
                    vetor[j-1] = aux;
                }
            }
        }
    }

    return vetor;
}