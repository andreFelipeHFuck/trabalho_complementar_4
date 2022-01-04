#include <stdio.h>
#include <stdlib.h>


int main(){
    FILE *arq;
    int *v;
    int i, n;
    int posi, nega;

    arq = fopen("entrada.txt", "rt");
    if(arq == NULL){
        printf("Erro no arquivo\n");
        return -1;
    }

    while (1)
    {
        fscanf(arq, "%d", &n);
        if(n == 0){
            break;
        }

        if(n >= 2 && n <= 100000){
            posi = 0;
            nega = 0;
            v = malloc(n * sizeof(int));

            for(i = 0; i < n; i ++){
                fscanf(arq, "%d", &v[i]);
                if(v[i] < 0){
                    nega++;
                }else{
                    posi++;
                }
            }
            printf("%d positivo, %d negativo", posi, nega);

        }else{
            printf("Quantidade invalida de casos\n");
        }
        
               
    }
    
    fclose(arq);
}

/*
Parece ser interessante
   
*/