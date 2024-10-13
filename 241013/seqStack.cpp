/**********************************************
** file name   : seqStack.cpp
** description : the source file of seqStack.cpp
** writer by   : Allenem
** create date : 2024-10-13
**********************************************/

#include "seqStack.h"

void test_seqStack() {
    seqStack *s;
    int i, x;

    s = init_seqStack();
    show_seqStack(s);

    for (i = 1; i <= 101; i++) {
        if (push_seqStack(s, i) == FAILURE) {
            printf("Stack overflowed!\n");
            _getch();
            break;
        }
    }
    show_seqStack(s);

    if (pop_seqStack(s, &x) == FAILURE) {
        printf("Stack empty!");
        _getch();
    }
    else
    {
        printf("Pop Stack=%d\n", x);
    }
    show_seqStack(s);

    if (gettop_seqStack(s, &x) == FAILURE) {
        printf("Get top of Stack failed!\n");
        _getch();
    }
    else
    {
        printf("Top Stack=%d\n", x);
    }
    show_seqStack(s);

    free_seqStack(&s);
}

seqStack *init_seqStack() {
    seqStack *s;

    s = (seqStack *)malloc(sizeof(seqStack));
    s->top = -1;

    return s;
}

int empty_seqStack(seqStack *s) {
    if (s->top == -1) {
        return TRUE;
    }
    return FALSE;
}

int full_seqStack(seqStack *s) {
    if (s->top == MAXSIZE - 1) {
        return TRUE;
    }
    return FALSE;
}

int push_seqStack(seqStack *s, int x) {
    if (full_seqStack(s)) {
        return FAILURE;
    }

    s->top++;
    s->data[s->top] = x;

    return SUCCESS;
}

int pop_seqStack(seqStack *s, int *x) {
    if (empty_seqStack(s)) {
        return FAILURE;
    }

    *x = s->data[s->top];
    s->top--;

    return SUCCESS;
}

int gettop_seqStack(seqStack *s, int *x) {
    if (empty_seqStack(s)) {
        return FAILURE;
    }

    *x = s->data[s->top];

    return SUCCESS;
}

void show_seqStack(seqStack *s) {
    int i;

    if (empty_seqStack(s)) {
        printf("The stack is empty!\n");
        _getch(); // pause
        return;
    }

    for (i = s->top; i >= 0; i--) {
        printf("%d\t", s->data[i]);
    }

    printf("\nshow finished!\n");
    _getch();
}

void free_seqStack(seqStack **s) {
    if (*s == NULL) {
        return;
    }
    free(*s);
    *s = NULL;
}

/********************END**********************/