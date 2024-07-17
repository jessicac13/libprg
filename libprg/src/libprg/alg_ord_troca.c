#include <libprg/libprg.h>

int* bubbleSort(int* vetor, int tamanho, bool crescente)
{
    int i, j, aux;

    for(i=0; i<tamanho; i++)
    {
        for(j= 1; j< (tamanho - i); j++)
        {
           {
               if (crescente == true)
               {
                   if(vetor[j] < vetor[j-1])
                   {
                       aux = vetor[j];
                       vetor[j] = vetor[j-1];
                       vetor[j-1] = aux;
                   }
               }
               else
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
    }
    return vetor;
}

int* insertionSort(int* vetor, int tamanho, bool crescente)
{
    int j, chave;

    for(int i=0; i<tamanho; i++)
    {
        chave = vetor[i];
        j =i-1;

        if (crescente == true)
        {
            while (j>=0 && vetor[j]> chave)
            {
                vetor[j+1] = vetor[j];
                j = j-1;
            }
            vetor[j+1] = chave;
        }

        if (crescente == false)
        {
            while (j>=0 && vetor[j] < chave)
            {
                vetor[j+1] = vetor[j];
                j = j-1;
            }
            vetor[j+1] = chave;
        }
    }
    return vetor;
}

int* selectionSort(int* vetor, int tamanho, bool crescente)
{
    int min, aux;

    for(int i=0; i<tamanho;i++)
    {
        min = i;
        for (int j = i+1; j < tamanho; j++)
        {
            if(crescente == true)
            {
                if(vetor[j] < vetor[min])
                {
                    min = j;
                }
            }
            if(crescente == false)
            {
                if(vetor[j] > vetor[min])
                {
                    min = j;
                }
            }
        }
        if( i != min)
        {
            aux = vetor[i];
            vetor[i] = vetor[min];
            vetor[min] = aux;
        }
    }
    return vetor;
}

int* merge(int *vetor, int esquerda, int meio, int direita)
{
    int aux[(direita - esquerda +1)];
    int i = esquerda;
    int j = (meio + 1);
    int k = 0;

    while(i<= meio & j <= direita)
    {
        if ( vetor[i] <= vetor[j])
        {
            aux[k] = vetor[i];
            i++;
        }
        else
        {
            aux[k] = vetor[j];
            j++;

        }
        k++;
    }
    while ( i <= meio)
    {
        aux[k] = vetor[i];
        i++;
        k++;
    }
    while (j <= direita)
    {
        aux[k] = vetor[j];
        j++;
        k++;
    }
    for (i= esquerda;  i<= direita; i++)
    {
        vetor[i] = aux[i - esquerda];
    }
    return vetor;
}

int* mergeSort(int* vetor, int esquerda, int direita)
{
    int meio;
    if(esquerda < direita)
    {
        meio = esquerda + (direita - esquerda)/2;
        mergeSort(vetor, esquerda, meio);
        mergeSort(vetor, meio + 1, direita);
        merge(vetor, esquerda, meio, direita);
    }
    return vetor;
}

