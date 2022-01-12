#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int n, n_entrada;
    int i, j, k;
    FILE *arq;

    arq = fopen("entrada.txt", "wt");
    if(arq == NULL){
        printf("Erro no arquivo de entrada\n");
        return 0;
    }

    printf("N: ");
    scanf("%d", &n);

    srand(time(NULL));
    for(i = 0; i < n; i++){
        n_entrada = rand() % 20;
        fprintf(arq, "%d ", n_entrada);
        for(j = 0; j < n_entrada; j++){
            fprintf(arq, "%d ", rand() % 21-10);
        }
        fprintf(arq, "\n");
    }
    fprintf(arq, "0");

    fclose(arq);
    return 0;
}