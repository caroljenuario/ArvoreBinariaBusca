
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

typedef struct no
{
    int conteudo;
    struct no *esquerda, *direita;
} No;

typedef struct
{
    No *raiz;
} ArvoreBinaria;

No *incluirArvoreBinariaBusca(No *raiz, int numero)
{
    if (raiz == NULL)
    {
        No *novo = (No *)malloc(sizeof(No));
        novo->conteudo = numero;
        novo->esquerda = NULL;
        novo->direita = NULL;
        return novo;
    }
    else
    {
        if (numero < raiz->conteudo)
            raiz->esquerda = incluirArvoreBinariaBusca(raiz->esquerda, numero);
        if (numero > raiz->conteudo)
            raiz->direita = incluirArvoreBinariaBusca(raiz->direita, numero);
        return raiz;
    }
}

int buscarArvoreBinariaBusca(No *raiz, int procurarNumero)
{
    if (raiz != NULL)
    {
        if (raiz->conteudo == procurarNumero)
            return 1; // raiz->conteudo;
        else
        {
            if (procurarNumero < raiz->conteudo)
                return buscarArvoreBinariaBusca(raiz->esquerda, procurarNumero);
            else
                return buscarArvoreBinariaBusca(raiz->direita, procurarNumero);
        }
    }
    else
        return 0;
}

void imprimirEmOrdem(No *raiz)
{
    if (raiz != NULL)
    {
        imprimirEmOrdem(raiz->esquerda);
        printf("%d ", raiz->conteudo);
        imprimirEmOrdem(raiz->direita);
    }
}

No *incluirArvoreBinaria(No *raiz, int numero)
{
    if (raiz == NULL)
    {
        No *novo = (No *)malloc(sizeof(No));
        novo->conteudo = numero;
        novo->esquerda = NULL;
        novo->direita = NULL;
        return novo;
    }
    else
    {
        if (numero)
            raiz->esquerda = incluirArvoreBinaria(raiz->esquerda, numero);
        else
            raiz->direita = incluirArvoreBinaria(raiz->direita, numero);
        return raiz;
    }
}

int buscarArvoreBinaria(No *raiz, int procurarNumero)
{
    if (raiz != NULL)
    {
        if (raiz->conteudo == procurarNumero)
            return 1; 
      }
       else
        {
            if (procurarNumero)
                return buscarArvoreBinaria(raiz->esquerda, procurarNumero);
            else
                return buscarArvoreBinaria(raiz->direita, procurarNumero);
        }  
  return 0;
}


int main()
{
    int opcao, numero [100000];
    double media, soma, desvioPadrao;
    ArvoreBinaria arvore;
    arvore.raiz = NULL;
    No *raiz = NULL;
    clock_t tempo;
    clock_t tempoIndividual[10000];

    do
    {
        printf("\nDigite a opcao desejada: \n 1 - Adicionar (Arvore Binaria de Busca) \n 2 - Imprimir (Arvore Binaria de busca)\n 3 - Buscar numeros\n 4 - Adicionar (Arvore Binaria)\n 5 - Buscar (Arvore Binaria)\n 0 - Sair\n");
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            printf("\nGerando 10.000 numeros aleatorios... \n");
            tempo = clock();
            for (int i = 0; i < 10000; i++)
            {
                numero[i] = rand() % 100000;
                arvore.raiz = incluirArvoreBinariaBusca(arvore.raiz, numero[i]);
                tempo = clock() - tempo;
            }
            printf("Tempo de execucao total: %lf \n",
                   ((double)tempo) / ((CLOCKS_PER_SEC / 1000)));
            break;

        case 2:
            printf("Numeros: \n");
            imprimirEmOrdem(arvore.raiz);
            break;
          
        case 3:
            tempo = clock();
            for (int i = 0; i < 100; i++)
            {
                tempoIndividual[i] = clock();
                printf("Resultado: %d\n", buscarArvoreBinariaBusca(arvore.raiz, numero[i]));
                tempo = clock() - tempo;
                tempoIndividual[i] = clock() - tempoIndividual[i];
                printf("Tempo de execucao: %lf \n",
                       ((double)tempoIndividual[i]) /
                           ((CLOCKS_PER_SEC / 1000)));
                soma = soma + ((double)tempoIndividual[i]) /
                                  ((CLOCKS_PER_SEC / 1000));
                media = soma / 100;
                desvioPadrao = desvioPadrao + pow(((double)tempoIndividual[i]) /
                                                          ((CLOCKS_PER_SEC / 1000)) -
                                                      media,
                                                  2);
             //   desvioPadrao = sqrt(desvioPadrao / 99);
            }

            printf("\nTempo de execucao total: %lf \n",
                   ((double)tempo) / ((CLOCKS_PER_SEC / 1000)));
            printf("Media: %f \n", media);
            printf("Desvio padrao: %f \n", desvioPadrao);
            break;

        case 4:
            tempo = clock();
            for (int i = 0; i < 10000; i++)
            {
                numero[i] = rand() % 1000000;
                arvore.raiz = incluirArvoreBinaria(arvore.raiz, numero[i]);
                tempo = clock() - tempo;
            }
            printf("Tempo de execucao total: %lf \n",
                   ((double)tempo) / ((CLOCKS_PER_SEC / 1000)));
            break;

        case 5:
            tempo = clock();
            for (int i = 0; i < 100; i++)
            {
                tempoIndividual[i] = clock();
                printf("Resultado: %d\n", buscarArvoreBinaria(arvore.raiz, numero[i]));
                tempo = clock() - tempo;
                tempoIndividual[i] = clock() - tempoIndividual[i];
                printf("Tempo de execucao: %lf \n",
                       ((double)tempoIndividual[i]) /
                           ((CLOCKS_PER_SEC / 1000)));
                soma = soma + ((double)tempoIndividual[i]) /
                                  ((CLOCKS_PER_SEC / 1000));
                media = soma / 100;
                desvioPadrao = desvioPadrao + pow(((double)tempoIndividual[i]) /
                                                          ((CLOCKS_PER_SEC / 1000)) -
                                                      media,
                                                  2);
              //  desvioPadrao = sqrt(desvioPadrao / 99);
            }
            printf("\nTempo de execucao total: %lf \n",
                   ((double)tempo) / ((CLOCKS_PER_SEC / 1000)));
            printf("Media: %f \n", media);
            printf("Desvio padrao: %f \n", desvioPadrao);

            break;
        }
    } while (opcao != 0);
}
