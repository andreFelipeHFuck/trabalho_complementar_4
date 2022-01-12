#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct 
{
   int n_casos;
   int *casos; 
}Linha;

typedef struct 
{
    int negativo, positivo;
    int invalido;
}Casos;


int main(){
    Linha linha;
    Casos casos;
    FILE *arq_entrada;
    FILE *arq_saida;
    char frase[30];
    int i;
    int posi, nega;

    arq_entrada = fopen("entrada", "rb");
    if(arq_entrada == NULL){
        printf("Erro no arquivo de entrada\n");
        return -1;
    }

    arq_saida = fopen("saida", "wb" );
    if(arq_saida == NULL){
        printf("Erro no arquivo de saida\n");
        return -1;
    }
    
    while (!feof(arq_entrada)){
        fread(&linha.n_casos, sizeof(int), 1, arq_entrada);

        if(linha.n_casos == 0){
            break;
        }

        if(linha.n_casos >= 2 && linha.n_casos <= 100000){
            posi = 0;
            nega = 0;

            linha.casos =  (int *) malloc(linha.n_casos * sizeof(int));
            fread(linha.casos, sizeof(int), linha.n_casos, arq_entrada);
            for(i = 0; i < linha.n_casos; i++){
                 if(linha.casos[i] < 0){
                    nega++;
                }else{
                    posi++;
                }
            }
            casos.positivo = posi;
            casos.negativo = nega;
            casos.invalido = 0;
            fwrite(&casos.positivo, sizeof(int), 1, arq_saida);
            fwrite(&casos.negativo, sizeof(int), 1, arq_saida);
            fwrite(&casos.invalido, sizeof(int), 1, arq_saida);
            free(linha.casos);
        }else{
            casos.positivo = 0;
            casos.negativo = 0;
            casos.invalido = 1;
            fwrite(&casos.positivo, sizeof(int), 1, arq_saida);
            fwrite(&casos.negativo, sizeof(int), 1, arq_saida);
            fwrite(&casos.invalido, sizeof(int), 1, arq_saida);
        }
    }
    
    fclose(arq_entrada);
    fclose(arq_saida);
}