#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void){
    char filename[80];
    int arr[36]={0};
    printf("Input filename: ");
    scanf("%s", filename);      //getting file name 

    FILE *fp = fopen(filename, "r");

    if(fp == NULL){
        printf("Error: could not open file %s", filename);  // if file does not exist
        return 1;
    }

    char line[100];
    while(fgets(line, 100,fp)!= NULL){
        int length = strlen(line);
        for(int i=0;i<length; i++){
            char ch = line[i];
            if (isalpha(ch)){
                ch = toupper(ch);
                arr[ch-'A']++;
            } else if(isdigit(ch)) {
                arr[ch-22]++;
            }
        }
    }

    for(int i=0;i<36;i++){
        if(i<26){
            printf("%c: %d\n",i+'A', arr[i]);
        } else {
            printf("%c: %d\n",22+i, arr[i]);
        }
        
    }





    fclose(fp);
    return 0;
}