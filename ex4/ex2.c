#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct 
{
   int n_casos;
   int *casos; 
}Linha;


int main(){
    Linha l;
    int n;
    int i, j;
    FILE *arq;

    arq = fopen("entrada", "wt");
    if(arq){
        printf("N: ");
        scanf("%d", &n);
        srand(time(NULL));
        for(i = 0; i < n; i++){
           
            l.n_casos = rand() % 20;
            printf("%d", l.n_casos);
            l.casos = malloc(l.n_casos * sizeof(int));
            for(j = 0; j < l.n_casos; j++){
                l.casos[j] = (rand() % 21 -10);
                printf(" %d ", l.casos[j]);
            }
            printf("\n");

            fwrite(&l.n_casos, sizeof(int), 1, arq);
            fwrite(l.casos, sizeof(int), l.n_casos, arq);
            free(l.casos);
        }
        l.n_casos = 0;
        fwrite(&l.n_casos, sizeof(int), 1, arq);
        printf("0\n");
    }else{
        printf("Erro no arquivo de entrada\n");
        return 0;
    }
    fclose(arq);

    return 0;
}