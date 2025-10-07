#include <stdio.h>
 
int main() {
    int vetor [5];

    for(int i = 0; i < 5; i++){
        vetor [i] = i * 2;
        printf("vetor [%d] = %d\n", i, vetor[i]);
    }

    return 0;
}