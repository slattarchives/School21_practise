#include <stdio.h>
#include <stdlib.h>


int input_size(int *N, int *M){
    char z;
    if (scanf("%d %d%c", N, M, &z) != 3 || (z != ' ' && z != '\n')){
        printf("n/a");
        return 1;
    }
    return 0;
}
void free_mat(int **matrix, int N){
    for (int i = 0; i < N; i++){
        free(matrix[i]);
    }
    free(matrix);
}
void output(int **matrix, int N, int M){
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            if (j == M - 1){
                printf("%d\n", matrix[i][j]);
            } else if (j == M - 1 && i == N - 1) {
                printf("%d", matrix[i][j]);
            } else printf("%d ", matrix[i][j]);
        }
    }
}
int main(){
    int N, M, **matrix = NULL, **tmp = NULL;
    char z;
    if (input_size(&N, &M)){
        return 0;
    }
    matrix = malloc(N * sizeof(int *));
    for (int i = 0; i < N; i++){
        matrix[i] = malloc(M * sizeof(int));
    }
    if (matrix == NULL){
        printf("n/a");
        free_mat(matrix, N);
        return 0;
    }
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            if (scanf("%d%c", &matrix[i][j], &z) != 2 || (z != ' ' && z != '\n')){
                printf("n/a");
                free_mat(matrix, M);
                return 0;
            }
        }
    }
    tmp = malloc(M * sizeof(int *));
    for (int i = 0; i < M; i++){
        tmp[i] = malloc(N * sizeof(int));
    }
    if (tmp == NULL){
        printf("n/a");
        free_mat(matrix, M);
        free_mat(tmp, M);
        return 0;
    }
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            tmp[M - 1 - j][i] = matrix[i][j];
        }
    }
    output(tmp, M, N);
    free_mat(matrix, M);
    free_mat(tmp, M);
    return 0;
}