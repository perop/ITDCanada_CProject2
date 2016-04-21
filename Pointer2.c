//
//  Pointer2.c
//  ITDCanada_CProject2
//
//  Created by TakahashiMai on 2016-04-18.
//  Copyright © 2016 TakahashiMai. All rights reserved.
//

#include "Pointer2.h"

void print(int a){

    printf("Value of a is %d\n", a);
    
}

void mainPointer(){
    
//    int *ptr;
    //int型の ptrという変数を定義

    //fun_ptr is a pointer to function print()
    void (*fun_ptr)(int) = &print;
    // fun_ptrのポインタ変数
    // ポインタ変数はアドレスを持つことができる
    //&をつけると、printという変数のアドレスがかえってくる
    
    
    /*
     void (*fun_ptr)(int);
     fun_ptr = &print;
     
     */
    
    //Invoking print() using fun_ptr
    (*fun_ptr)(10);

    
    
}

