#include <stdio.h>

void recursiveloop (int n){
    if(n > 0){
        printf("%d", n);
        recursiveloop(n - 1);

    }
}

int main () {
    int numero = 5;
    printf("Contagem regressiva:");
    recursiveloop (numero);
    return 0;

}