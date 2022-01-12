#include <stdio.h>
#include <stdlib.h>

void geraExemplos(){
     int n, n_entrada;
    int i, j, k;
    FILE *arq;

    arq = fopen("entrada.txt", "wt");
    if(arq == NULL){
        printf("Erro no arquivo de entrada\n");
    }

    printf("N: ");
    scanf("%d", &n);

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
}

int main(){
    geraExemplos();
    FILE *arq_entrada;
    FILE *arq_saida;
    int *v;
    int i, n, cont;
    int posi, nega;


    arq_entrada = fopen("entrada.txt", "rt");
    if(arq_entrada == NULL){
        printf("Erro no arquivo de entrada\n");
        return -1;
    }

    arq_saida = fopen("saida.txt", "wt" );
    if(arq_saida == NULL){
        printf("Erro no arquivo de saida\n");
        return -1;
    }
    

    while (1)
    {
        fscanf(arq_entrada, "%d", &n);
        if(n == 0){
            break;
        }

        if(n >= 2 && n <= 100000){
            posi = 0;
            nega = 0;
            v = malloc(n * sizeof(int));

            for(i = 0; i < n; i ++){
                fscanf(arq_entrada, "%d", &v[i]);
                if(v[i] < 0){
                    nega++;
                }else{
                    posi++;
                }
            }
           fprintf(arq_saida, "%d positivo, %d negativo\n", posi, nega);
           free(v);
        }else{
           fprintf(arq_saida, "Quantidade invalida de casos\n");
        }      
    }
    

    fclose(arq_entrada);
    fclose(arq_saida);
}