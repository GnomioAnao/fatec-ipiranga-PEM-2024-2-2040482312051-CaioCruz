#include <stdio.h>


int main(){
    float   menor, maior, total=0, soma;
    int i, n;
    while(1){
        printf("digite quantos testes o candidato ira fazer (digite 0 para sair):\n");
        scanf("%d", &n);
        if(n == 0){
            break;
        }
        float notas[n];
        printf("Agora digite as notas dos %d testes que o candidato fez:\n", n);
        for(i=0; i<n; i++){
            scanf("%f", &notas[i]);
        }
        maior = notas[0];
        menor = notas[0];
        soma = 0;
        for(i=0; i<n; i++){
            if(notas[i] < menor){
                menor = notas[i];
            }
            if (notas[i] > maior){
                maior = notas[i];
            }
            
            soma += notas[i];
        }
        soma -= menor; 
        soma -= maior;
        total += soma;
        printf("Nota final: %.2f\n\n", soma);
    }
    printf("Nota Total: %.2f", total);

    return 0;
}