#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void){
    char filename[80];

    printf("Input filename: ");
    scanf("%s", filename);

    FILE *fp = fopen(filename, "r");

    if(fp == NULL){
        printf("Error: could not open file %s", filename);
        return 1;
    }
    int arr[50];
    int i=0;
    int number;
    char line[50];
    while (fgets(line, 50,fp)!= NULL){
        if(strcmp(line, "\n") != 0){
            number = atoi(line);
            arr[i++] = number;
        }     
    }
    fclose(fp);
    int small = arr[0];

    for(int j=0;j<i;j++){
        if(small>arr[j]){
            small = arr[j];
        }
    }

    printf("The smallest number is %d", small);

    return 0;
}