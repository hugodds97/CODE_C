#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define TAM 10

//PROTOTIPAGEM
void imprime_vetor(int *v, int n);
void preencher_vetor(int *v, int n);
void embaralha_vetor(int *v, int n);

void ord_bubble(int *v, int n);
void ord_insertion(int *v,int n);
void ord_selection(int *v, int n);

void ord_quicksort(int *v,int esq, int dir);
int separar(int *v, int esq, int dir);
void trocar(int *v, int i, int j);

void ord_mergesort(int *v,int *a,int ini, int fim);
void intercalar(int *v, int *a,int ini, int meio, int fim);

int main (void)
{
    int *v,*a;
    //clock_t inicio_t, fim_t;
    //float diff_t;

    v = malloc(TAM*sizeof(int));
    a = malloc(TAM*sizeof(int));

    preencher_vetor(v,TAM);
    embaralha_vetor(v,TAM);
    
    //inicio_t = clock();
    ord_bubble(v,TAM);
    //fim_t = clock();
    printf("ORD BUBBLE\n");
    imprime_vetor(v,TAM);
    printf("\n\n");

    embaralha_vetor(v,TAM);

    //inicio_t = clock();
    ord_insertion(v,TAM);
    //fim_t = clock();
    printf("ORD INSERTION\n");
    imprime_vetor(v,TAM);
    printf("\n\n");

    embaralha_vetor(v,TAM);

    //inicio_t = clock();
    ord_selection(v,TAM);
    //fim_t = clock();
    printf("ORD SELECTION\n");
    imprime_vetor(v,TAM);
    printf("\n\n");

    embaralha_vetor(v,TAM);

    //inicio_t = clock();
    ord_quicksort(v,0,TAM-1);
    //fim_t = clock();
    printf("ORD QUICK\n");
    imprime_vetor(v,TAM);
    printf("\n\n");

    embaralha_vetor(v,TAM);

    //inicio_t = clock();
    ord_mergesort(v,a,0,TAM-1);
    //fim_t = clock();
    printf("ORD MERGE\n");
    imprime_vetor(v,TAM);
    printf("\n\n");

    //diff_t = ((float)(fim_t - inicio_t)/CLOCKS_PER_SEC);
    //printf("TEMPO %1.3f\n\n",diff_t);

    return 0;
}

void imprime_vetor(int *v, int n)
{
    int i;

    for(i = 0 ; i < n ; i++) printf("[%d]",v[i]);
}

void preencher_vetor(int *v, int n)
{
    int i;

    for(i = 0 ; i < n ; i++) v[i] = i;

    printf("PREENCHE\n");
    imprime_vetor(v,TAM);
    printf("\n\n");
}

void embaralha_vetor(int *v, int n)
{
    int i,escolha, aux;

    for(i = 0 ; i < n ; i++)
    {
        escolha = rand() % n;
        aux = v[i];
        v[i] = v[escolha];
        v[escolha] = aux;
    }

    printf("EMBARALHA\n");
    imprime_vetor(v,TAM);
    printf("\n\n");
}

void ord_bubble(int *v, int n)
{
    int i,j,aux =0;

    for(j = n-1 ; j >= 1 ; j--)
    {
        for(i = 0; i < j ; i++)
        {
            if(v[i] > v[i+1])
            {
                aux = v[i];
                v[i] = v[i+1];
                v[i+1] = aux;
            }
        }
    }
}

void ord_selection(int *v, int n)
{
    int i,j,aux;

    for(i = 0 ; i < n ; i++)
    {
        for(j = i+1 ; j < n ; j++)
        {
            if(v[j] < v[i])
            {
                aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }
        }
    }
}

void ord_insertion(int *v,int n)
{
    int i,j,aux=0;

    for(i = 1 ; i < n ; i++)
    {
        j = i;
        while((j > 0) && (v[j] < v[j-1]))
        {
            aux = v[j];
            v[j] = v[j-1];
            v[j-1] = aux;
            j--;
        }
    }
}

void ord_quicksort(int *v,int esq, int dir)
{
    if(esq < dir)
    {
        int j = separar(v,esq,dir);
        ord_quicksort(v,esq,j-1);
        ord_quicksort(v,j+1,dir);
    }
}

int separar (int *v, int esq, int dir)
{
    int i = esq, j= dir;

    while (i < j)
    {
        while(i < dir && v[i] <= v[esq])i++;
        while(j > esq && v[j] >= v[esq])j--;
        if (i < j)
        {
            trocar(v,i,j);
            i++;
            j--;
        }
    }
    trocar(v,esq,j);
    return j;
}

void trocar(int *v, int i, int j)
{
    int aux = v[i];
    v[i] = v[j];
    v[j] = aux;
}

void ord_mergesort(int *v,int *a,int ini, int fim)
{
    int meio;
    if(ini<fim)
    {
        meio = (ini+fim)/2;
        ord_mergesort(v,a,ini,meio);
        ord_mergesort(v,a,meio+1,fim);
        intercalar(v,a,ini,meio,fim);
    }
}

void intercalar(int *v, int *a,int ini, int meio, int fim)
{
    int k,i=ini,j = meio+1;

    for(k = ini ; k <= fim ; k++)
    {
        a[k] = v[k];
    }
    for(k = ini ; k <= fim ; k++)
    {
        if(i > meio) v[k] = a[j++];
        else if(j > fim) v[k] = a[i++];
        else if(a[i] < a[j]) v[k] = a[i++];
        else v[k] = a[j++];
    }
}