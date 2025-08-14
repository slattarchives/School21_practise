#include <stdlib.h>
#include <stdio.h>

void sort_k(int *buffer, int n, int *tmp);
int main()
{
    int size = 0, capasity = 5, num, *buffer = NULL;
    buffer = malloc(capasity * sizeof(int));
    if (buffer == NULL){
        printf("n/a");
        return 0;
    }
    
    char z;
    while(1){
        if (scanf("%d%c", &num, &z) != 2 || (z != ' ' && z != '\n') || (num < 0 && num != -1)){
            printf("n/a");
            return 0;
        }
        if (num == -1){
            break;
        }
        if (size == capasity){
            capasity = capasity * 2;
            int *tmp = (int *)realloc(buffer, capasity * sizeof(int));
            buffer = tmp;
        }
        buffer[size++] = num;
    }
    int *tmp = (int*)malloc(size * sizeof(int));
    if (tmp == NULL){
        printf("n/a");
        return 0;
    }
    //sort_k(buffer, size, tmp);
    tmp[0] = buffer[0]; 
    int count = 1, count_opp = size-1;
    for (int i = 1; i < size; i++){
        if (i % 2 != 0){
            tmp[i] = buffer[count_opp];
            count_opp--;
            
        } else {
            tmp[i] = buffer[count];
            count++;
        }
    }
    for (int i = 0; i < size; i++){
        if (i == size - 1){
            printf("%d", tmp[i]);
        } else {
            printf("%d ", tmp[i]);
        }
    }
    return 0;
}
void sort_k(int *buffer, int n, int *tmp){
    //tmp[0] = buffer[0]; 
    for (int i = 0; i < n; i++){
        if (n % 2 != 0){
            for (int j = n - 1; j >= 0; j--){
                tmp[i] = buffer[j];
            }
        } else {
            tmp[i] = buffer[i];
        }
    }
    for (int i = 1; i < n; i++){
        buffer[i] = tmp[i];
    }
    free(tmp);
}