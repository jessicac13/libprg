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
//Algoritmo 2: Insertion sort
//Entrada: vetor[1..n]
//Saída: vetor ordenado
//1 para i de 1 até n − 1 faça
//2 chave ← vetor[i];
//3 j ← i − 1;
//4 enquanto j ≥ 0 E vetor[j] > chave faça
//5 vetor[j + 1] ← vetor[j];
//6 j ← j − 1;
//7 fim
//8 vetor[j + 1] ← chave
//9 fim

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
            while (j<=0 && vetor[j]< chave)
            {
                vetor[j+1] = vetor[j];
                j = j-1;
            }
            vetor[j+1] = chave;
        }


    }
    return vetor;
}