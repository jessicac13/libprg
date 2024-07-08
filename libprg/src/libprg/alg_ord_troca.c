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

//Algoritmo 3: Selection sort
//Entrada: vetor[1..n]
//Saída: vetor ordenado
//1 para i de 1 até n − 1 faça
//2 min ← i;
//3 para j de (i+1) até n faça
//4 se vetor[j] < vetor[min] então
//5 min ← j;
//6 fim
//7 fim
//8 se i ̸= min então
//9 aux ← vetor[i];
//10 vetor[i] ← vetor[min];
//11 vetor[min] ← aux;
//12 fim
//13 fim

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
            else
            {
                if(vetor[j] < vetor[min])
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
