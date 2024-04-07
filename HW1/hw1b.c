#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(void){
    char filename[80];
    double answer =0;
    printf("Input filename: ");
    scanf("%s", filename);      //getting file name 

    FILE *fp = fopen(filename, "r");

    if(fp == NULL){
        printf("Error: could not open file %s", filename);  // if file does not exist
        return 1;
    }
    double value = 0; // each values to be added

    char line[200];
    fgets(line,200,fp);// example1.txt does not count;
    while (fgets(line, 200,fp)!= NULL){
        char str[50]="";    //number value to be changed later
        int index = 0;
        int len = strlen(line);//length for each line
        for(int i =0;i<len;i++){
            if(isdigit(line[i])){
                str[index++]= line[i];  //if character is number then add into array
            } else if (line[i]=='.'){   //distinguish decimal or full stop mark
                if(strlen(str)!=0){
                    if(isdigit(line[i+1])){
                        str[index++]='.';       //if the next value is number then decimal
                    } else {
                        value = atof(str);  //other wise we think it as full stop. change to number and add to the answer
                        printf("%.2f\n",value);
                        answer += value;
                        strcpy(str,"");
                        index=0;
                    }
                    
                }
            } else {
                if(strlen(str) != 0){
                    str[index] = '\0'; // otherwise you would get some strange values...
                    value = atof(str);
                    printf("%.2f\n", value);
                    answer += value;
                    strcpy(str,"");
                    index=0;
                }
            }
        }
    }
    fclose(fp);

    printf("The sum is %.2f",answer);
    
    

    return 0;
}