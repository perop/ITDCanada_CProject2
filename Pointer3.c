//
//  Pointer3.c
//  ITDCanada_CProject2
//
//  Created by TakahashiMai on 2016-04-18.
//  Copyright © 2016 TakahashiMai. All rights reserved.
//

#include "Pointer3.h"


void add(int a, int b){
    printf("Addition is %d\n", a+b);
}

void subtract(int a, int b){
    printf("Subtraction is %d\n", a-b);
}


void multiply(int a, int b){
    printf("Multiplication is %d\n", a*b);
}

//int mainPointer(){
//// fun_ptr is an arrat of function pointers.
//    
//    void(*fun_ptr_arr[])(int,int) = {add, subtract, multiply};
//    unsigned int ch, a = 15, b = 10;
//    
//    printf("Enter Choice : 0 or add, 1 for substract and 2""for mutioly\n");
////    scan("%d", &ch);
//    
//    if(ch > 2) return 0;
//    
//    (*fun_ptr_arr[ch])(a,b);}


