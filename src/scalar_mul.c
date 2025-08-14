#include <stdio.h>
#include <stdlib.h>
int input_size(int *n);
int main()
{
    int n;
    char z;
    if (input_size(&n)){
        return 0;
    }
    int *buffer1 = (int*)malloc(n * sizeof(int));
    int *buffer2 = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++){
        if (scanf("%d%c", &buffer1[i], &z) != 2 || (z != ' ' && z != '\n')){
            printf("n/a");
            free(buffer2);
            free(buffer1);
            return 1;
        }
    }
    for (int i = 0; i < n; i++){
        if (scanf("%d%c", &buffer2[i], &z) != 2 || (z != ' ' && z != '\n')){
            printf("n/a");
            free(buffer2);
            free(buffer1);
            return 1;
        }
    }
    int result = 0, proiz = 0;
    for (int i = 0; i < n; i++){
        proiz = buffer1[i] * buffer2[i];
        result += proiz;
    }
    printf("%d", result);
    free(buffer2);
    free(buffer1);
    return 0;
}
int input_size(int *n){
    char z;
    if (scanf("%d%c", n, &z) != 2 || (z != ' ' && z != '\n') || *n < 0){
        printf("n/a");
        return 1;
    }
    return 0;
}