#include <stdio.h>
#include <stdlib.h>

int comp(int *arr, int amo, int elem);
int main()
{
    int capasity = 5, size = 0, num;
    char z;
    int *buffer = (int*)malloc(capasity * sizeof(int));
    while (scanf("%d%c", &num, &z) == 2 && (z == ' ')){
        if (num == -1){
            break;
        }
        if (size == capasity){
            capasity = capasity * 2;
            int *tmp = (int*)realloc(buffer, capasity * sizeof(int));
            buffer = tmp;
        }
        buffer[size++] = num;
    }
    int coount = 0;
    int *result = (int*)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++){
        if(!comp(result, size, buffer[i])){
            if (coount == size){
                size = size * 2;
                int *tmp = (int*)realloc(result, size * sizeof(int));
                result = tmp;
            }
            result[coount] = buffer[i];
            coount++;
        }
    }
    for (int i = 0; i < coount; i++){
        if (i == coount - 1){
            printf("%d", result[i]);
        } else {
            printf("%d ", result[i]);
        }
    }
    return 0;
}
int comp(int *arr, int amo, int elem){
    for (int i= 0; i < amo; i++){
        if (arr[i] == elem){
            return 1;
        }
    }
    return 0;
}