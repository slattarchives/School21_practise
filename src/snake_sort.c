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
int input_matrix(int **matrix, int N, int M){
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            if (scanf("%d", &matrix[i][j]) != 1){
                printf("n/a");
                return 1;
            }
            
        }
    }
    return 0;
}
void bubble_sort_matrix(int **matrix, int N, int M) {
    int total = N * M;
    for (int k = 0; k < total - 1; k++) {
        for (int l = 0; l < total - k - 1; l++) {
            // Преобразуем линейный индекс l в координаты (i1, j1)
            int i1 = l / M, j1 = l % M;
            // Следующий элемент (l + 1) -> (i2, j2)
            int i2 = (l + 1) / M, j2 = (l + 1) % M;
            
            if (matrix[i1][j1] > matrix[i2][j2]) {
                // Меняем местами
                int temp = matrix[i1][j1];
                matrix[i1][j1] = matrix[i2][j2];
                matrix[i2][j2] = temp;
            }
        }
    }
}
void snake_sort(int **matrix, int N, int M){
    int *tmp = (int*)malloc(N * M * sizeof(int));
    int count = 0;
    for (int l = 0; l < N; l++){
        for (int h = 0; h < M; h++){
            tmp[count] = matrix[l][h];
            count++;
        }
    }
    count = 0;
    for (int i = 0; i < N; i++){
        if (i % 2 == 0){
            for (int j = 0; j < M; j++){
                matrix[i][j] = tmp[count++];
            }
        } else {    
            for (int k = M - 1; k >= 0; k--){
                matrix[i][k] = tmp[count++];
            }
        }
    }
    free(tmp);
}
void output_matrix(int **matrix, int N, int M){
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            if (j == M - 1){
                printf("%d\n", matrix[i][j]);
            } else if (j == M - 1 && i == N - 1){
                printf("%d", matrix[i][j]);
            } else {
                printf("%d ", matrix[i][j]);
            }

        }
    }
}
void free_mat(int **matrix, int N){
    for (int i = 0; i < N; i++){
        free(matrix[i]);
    }
    free(matrix);
}
int main()
{
    int N, M, **matrix = NULL, **tmp = NULL;
    if (input_size(&N, &M)){
        return 0;
    }

    matrix = malloc(N * sizeof(int*));
    for (int i = 0; i < N; i++){
        matrix[i] = malloc(M * sizeof(int));
    }
    if (matrix == NULL){
        free_mat(matrix, N);
        printf("n/a");
        return 0;
    }
    tmp = malloc(N * sizeof(int*));
    for (int i = 0; i < N; i++){
        tmp[i] = malloc(M * sizeof(int));
    }
    if (tmp == NULL){
        free_mat(tmp, N);
        free_mat(matrix, N);
        printf("n/a");
        return 0;
    }
    if (input_matrix(matrix, N, M)){
        return 0;
    }
    bubble_sort_matrix(matrix, N, M);
    snake_sort(matrix, N, M);
    output_matrix(matrix, N, M);
    free_mat(matrix, N);
    free_mat(tmp, N);
    return 0;
}