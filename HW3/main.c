#include <stdio.h>
#include <stdlib.h>

float **make2dArray(int rows, int cols);
void free2dArray(float **arr, int rows);
float **add_matrix(float **a, int ah, int aw, float **b, int bh, int bw);
float **mul_matrix(float **a, int ah, int aw, float **b, int bh, int bw);
float **transpose_matrix(float **a, int ah, int aw);


int main() {
    char operation;
    char filename1[100], filename2[100];
    FILE *file1;
    float **a;
    int rows1, cols1;
    printf("What operation do you want? ('a', 'm', 't')\n");    //getting operation value
    scanf(" %c", &operation);

    
    printf("Input file names:\n");
    scanf("%s", filename1);
    if (operation != 't') scanf("%s", filename2);

    //first file getting values
    file1 = fopen(filename1, "r");
    if (file1 == NULL) {
        printf("File does not exist");
        return 1;
    }

    //first line contains rows and cols info
    fscanf(file1, "%d %d", &rows1, &cols1);
    a = make2dArray(rows1, cols1);  //2d array import
    
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols1; j++) {
            fscanf(file1, "%f", &a[i][j]);
        }
    }

    fclose(file1);

    float **result;//RESULT 
    int rowsf, colsf; //For result 
    
    if (operation == 'a' || operation == 'm') {
        FILE *file2 = fopen(filename2, "r");
        if (file2 == NULL) {
            printf("File cannot be opened");
            free2dArray(a, rows1);//file does not exist then free the memory
            return 1;
        }

        int rows2, cols2;
        fscanf(file2, "%d %d", &rows2, &cols2);
        float **b = make2dArray(rows2, cols2); 
        for (int i = 0; i < rows2; i++) {
            for (int j = 0; j < cols2; j++) {
                fscanf(file2, "%f", &b[i][j]);
            }
        }
        fclose(file2);

        if (operation == 'a') {
            result = add_matrix(a, rows1, cols1, b, rows2, cols2);
            rowsf = rows1;
            colsf = cols1;
        } else { // operation m
            result = mul_matrix(a, rows1, cols1,b, rows2, cols2);
            rowsf = rows1;
            colsf = cols2;
        }

        free2dArray(b, rows2);
    } else { // operation t
        result = transpose_matrix(a, rows1, cols1);
        rowsf = cols1;
        colsf = rows1;
    }

    if (result != 0) {
        printf("The output is:\n");
        printf("%d %d\n", rowsf, colsf);
        for (int i = 0; i < rowsf; i++) {
            for (int j = 0; j < colsf; j++) {
                printf("%.1f ", result[i][j]);  //printing out result
            }
            printf("\n");   
        }
        free2dArray(result, rowsf);
    }

    free2dArray(a, rows1);

    return 0;
}

float **make2dArray(int rows, int cols) {
    float **arr = (float **)malloc(rows * sizeof(float *));
    for (int i = 0; i < rows; i++)
        arr[i] = (float *)malloc(cols * sizeof(float));
    return arr;
}

void free2dArray(float **arr, int rows) {
    for (int i = 0; i < rows; i++)
        free(arr[i]);
    free(arr);
}

float **add_matrix(float **a, int ah, int aw, float **b, int bh, int bw) {
    if (ah != bh || aw != bw) {
        printf("Matrix dimensions mismatch\n");
        return 0;
    }

    float **result = make2dArray(ah, aw);//for return 
    //add is just matching i and j value
    for (int i = 0; i < ah; i++) {
        for (int j = 0; j < aw; j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }

    return result;
}

float **mul_matrix(float **a, int ah, int aw, float **b, int bh, int bw) {
    if (aw != bh) {
        printf("Matrix dimensions mismatch\n");
        return NULL;
    }

    float **result = make2dArray(ah, bw);

    for (int i = 0; i < ah; i++) {
        for (int j = 0; j < bw; j++) {
            result[i][j] = 0;
            for (int k = 0; k < aw; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    return result;
}

float **transpose_matrix(float **a, int ah, int aw) {
    float **result = make2dArray(aw, ah);

    for (int i = 0; i < ah; i++) {  //change i j 
        for (int j = 0; j < aw; j++) {
            result[j][i] = a[i][j];
        }
    }

    return result;
}
