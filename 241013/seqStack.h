/**********************************************
** file name   : seqStack.h
** description : the head file of seqStack.cpp
** writer by   : Allenem
** create date : 2024-10-13
**********************************************/

#ifndef SEQSTACK_H
#define SEQSTACK_H

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

#define TRUE 1
#define FALSE 0

#define SUCCESS 1
#define FAILURE 0

#define MAXSIZE 100
typedef struct {
    int data[MAXSIZE];
    int top;
}seqStack;

seqStack *init_seqStack();                                              // 置空栈
int empty_seqStack(seqStack *s);                                        // 判栈空
int full_seqStack(seqStack *s);                                         // 判栈满
int push_seqStack(seqStack *s, int x);                                  // 入栈
int pop_seqStack(seqStack *s, int *x);                                  // 出栈
int gettop_seqStack(seqStack *s, int *x);                               // 取栈顶元素
void show_seqStack(seqStack *s);                                        // 输出
void free_seqStack(seqStack **s);                                       // 释放空间
void test_seqStack();

#endif //SEQSTACK_H
/********************END**********************/