#include <stdio.h>
 
int main() {
    int matriz[3][3];

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(j % 2 == 0){
                matriz[i][j] = 1;
            } else {
                matriz[i][j] = 0;
            }
        }
 }
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
printf("%d ", matriz[i][j]);
        }
    printf("\n");
    }
return 0;
}