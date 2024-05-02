#include <stdlib.h>
#include <stdio.h>

#define N 5

void gera_sequencia(int nVetor, int vetor[], int indice, int vetor_de_troca[], int esta_em_vetor[]) {
    if(indice == nVetor) {
        for(int i = 0; i < nVetor; i++) {
            printf("%d ", vetor_de_troca[i]);
        }
        printf("- %d\n", nVetor);
    }  else {
        for(int i = 0; i < nVetor; i++) {     
            if(esta_em_vetor[i] != 1) {
                vetor_de_troca[indice] = vetor[i];
                esta_em_vetor[i] = 1;
                gera_sequencia(nVetor, vetor, indice + 1, vetor_de_troca, esta_em_vetor);
                esta_em_vetor[i] = 0;
            }
        }
    }

    
}

int main() {
    int vetor[N] = {1, 2, 3, 4, 5};
    int vetor_de_troca[N] = {0};
    int esta_em_vetor[N] = {0};
    
    gera_sequencia(N, vetor, 0, vetor_de_troca, esta_em_vetor);
    return 0;
}