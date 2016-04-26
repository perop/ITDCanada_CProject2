//
//  Finalexam.c
//  ITDCanada_CProject2
//
//  Created by TakahashiMai on 2016-04-24.
//  Copyright © 2016 TakahashiMai. All rights reserved.
//

#include "Finalexam.h"


const int SIZE_FINAL = 3;
const int ROW_FINAL =4;
const int COL_FINAL =4;

enum calc_num{
    ADD,
    SUB,
    MUL,
    DIV
};

void printArrayFinal(int *array, int index){
    printf("Array%d is : ",index);
    for (int i = 0; i < SIZE_FINAL; i++){
        printf("%6d", *(array+i));
    }
    puts("");
}

void addFinal(int *array1, int *array2, int *array3){
    for (int i = 0; i < SIZE_FINAL; i++) {
        *(array3 +i) = *(array1 +i) + *(array2 +i);
    }
    
}
void subFinal(int *array1, int *array2, int *array3){
    for (int i = 0; i < SIZE_FINAL; i++) {
        *(array3 +i) = *(array1 +i) - *(array2 +i);
    }
}

void mulFinal(int *array1, int *array2, int *array3){
    for (int i = 0; i < SIZE_FINAL; i++) {
        *(array3 +i) = *(array1 +i) * *(array2 +i);
    }
}

void divFinal(int *array1, int *array2, int *array3){
    for (int i = 0; i < SIZE_FINAL; i++) {
        *(array3 +i) = *(array1 +i) / *(array2 +i);
    }
}

void inputNumToArray(int *array, int index){
    
    printf("Enter the num for array%d(The Number has to be 10 ~ 99!)\n", index);
    for (int i = 0; i < SIZE_FINAL; i++) {
        printf("array%d[%d] = ", index, i);
        scanf("%d", array+i);
        if (10 <= *(array+i) && *(array+i) <= 99) {
            //Nothing
        }else{
            puts("Wrong Number. It must be two digit.");
            i--;
        }
    }
    puts("");
}

void seachNum(int *array1, int *array2){
    
    int searchNum = 0;
    bool isCorrectedNum = false;
    while(!isCorrectedNum){
        puts("Enter the number that you wanna search.(The number has to be 10~99!)");
        scanf("%d", &searchNum);
        if (searchNum < 10 || 99 < searchNum) {
            puts("Wrong num! The number has to be 10~99!");
        }else{
            isCorrectedNum = true;
        }
    }
    
    bool isFound1 = false, isFound2 = false;
    for (int i =0 ; i < SIZE_FINAL; i++) {
        
        if (*(array1+i) == searchNum) {
            printf("The number %d is found in the First Array, at index: %d.\n",searchNum, i);
            isFound1 = true;
        }
        
        if (*(array2+i) == searchNum) {
            printf("The number %d is found in the Second Array, at index: %d.\n",searchNum, i);
            isFound2 = true;
        }
    }
    
    if (!isFound1) {
        printf("The number %d is not found in the First Array.\n",searchNum);
    }
    
    if (!isFound2) {
        printf("The number %d is not found in the Secon Array.\n",searchNum);
    }
    
}

bool isDuplicated(int array[ROW_FINAL][COL_FINAL], int num){
    
    for (int i = 0; i < ROW_FINAL; i++) {
        for (int j= 0; j < COL_FINAL; j++) {
            if (array[i][j] == num) {
                return true;
            }
        }
    }
    return false;
}

void getValueToTowDimArray(int array[ROW_FINAL][COL_FINAL]){
    
    int getNum;
    puts("Enter the number that you wanna add to two dimentional array.(The number must not be duplicated.)");
    for (int i = 0; i < ROW_FINAL; i++) {
        for (int j= 0; j < COL_FINAL; j++) {
            printf("The number for array[%d][%d]: ", i, j);
            scanf("%d", &getNum);
            if(isDuplicated(array, getNum)){
                puts("This number is duplicated. Try Again.");
                j--;
            }else{
                array[i][j] = getNum;
            }
            
        }
    }
}

void printTwoDimArray(int array[ROW_FINAL][COL_FINAL]){
    
    puts("\n Two Dimentional Array is :");
    
    for (int i = 0; i < ROW_FINAL; i++) {
        for (int j= 0; j < COL_FINAL; j++) {
            printf("%6d", array[i][j]);
        }
        puts("");
    }
    
}

void finalExam(){
    
    int array1[SIZE_FINAL], array2[SIZE_FINAL], array3[SIZE_FINAL];
    int arrayTwoDim[ROW_FINAL][COL_FINAL];
    
    inputNumbToArray(array1, 1);
    inputNumToArray(array2, 2);
    
    printArrayFinal(array1,1);
    printArrayFinal(array2,2);
    
    void (*func_ptr[])(int*, int*, int*) ={addFinal, subFinal, mulFinal, divFinal};
    
    puts("Addion:");
    func_ptr[ADD](array1, array2, array3);
    printArrayFinal(array3, 3);
    puts("");
    
    puts("Subtraction:");
    func_ptr[SUB](array1, array2, array3);
    printArrayFinal(array3, 3);
    puts("");
    
    puts("Multiplication:");
    func_ptr[MUL](array1, array2, array3);
    printArrayFinal(array3, 3);
    puts("");
    
    puts("Division:");
    func_ptr[DIV](array1, array2, array3);
    printArrayFinal(array3, 3);
    puts("");
    
    seachNumber(array1, array2);
    puts("");
    
    getValueToTowDimArray(arrayTwoDim);
    printTwoDimArray(arrayTwoDim);
    puts("");
    
}