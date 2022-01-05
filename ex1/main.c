#include <stdio.h>
#include <stdlib.h>

int contaLinhas(){
    FILE *arq;
    int cont = 0;
    char c, letras = '\n';

    arq = fopen("entrada.txt", "rt");
    if(arq == NULL){
        printf("Erro no arquivo\n");
        return -1;
    }

    while(fread(&c, sizeof(char), 1, arq)){
        if(c == letras){
            cont++;
        }
    }

    fclose(arq);
    return cont;
}

int main(){
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

/*
Parece ser interessante
   
*/