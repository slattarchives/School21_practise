#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    char last_name[50];
    int height;
} Person;
int input_size(int *n);
int main()
{
    int n;
    char z;
    if (input_size(&n)){
        return 0;
    }
    Person *person = (Person *)malloc(n * sizeof(Person));
    if (person == NULL){
        printf("n/a");
        return 0;
    }
    for(int i = 0; i < n; i++){
        if (scanf("%s%c", person[i].name, &z) != 2 || z!='\n'){
            printf("n/a");
            return 0;
        }
        if (scanf("%s%c", person[i].last_name, &z) != 2 || z!='\n'){
            printf("n/a");
            return 0;
        }
        if (scanf("%d%c", &person[i].height, &z) != 2 || z!='\n'){
            printf("n/a");
            return 0;
        }
    }
    char last_name_f[50];
    if (scanf("%s%c", last_name_f, &z) != 2 || z!='\n'){
        printf("n/a");
        return 0;
    }
    int count = 0;
    int result_h = 0;
    for(int j = 0; j < n; j++){
        if (strcmp(last_name_f, person[j].last_name) == 0){
            count++;
            result_h += person[j].height;
        }
    }
    
    printf("%s - %d", last_name_f, result_h / count);

    return 0;
}
int input_size(int *n){
    char z;
    if (scanf("%d%c", n, &z) != 2 || (z!= ' ' && z != '\n')){
        printf("n/a");
        return 1;
    }
    return 0;
}