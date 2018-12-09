//
//  main.c
//  Queue
//
//  Created by Anchor Ke on 2018/10/9.
//  Copyright © 2018 Anchor Ke. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct _PACKAGE_STRUCT_
{
    unsigned char Value;
} PACKAGE_STRUCT;

typedef struct _QUEUE_STRUCT_
{
    struct _QUEUE_STRUCT_ *NEXT;
    PACKAGE_STRUCT *VALUE;
} QUEUE_STRUCT;

typedef enum
{
    Q_SUCCESSFUL = 0,
    Q_MEMORY_ERROR = -1,
    Q_EMPTY = -2
} QUEUE_STATUS;

/*
char queue_initial(QUEUE_STRUCT **queue);
char queue_push(QUEUE_STRUCT **queue,PACKAGE_STRUCT *package);
PACKAGE_STRUCT* queue_pop(QUEUE_STRUCT **queue);
unsigned char queue_count(void);
unsigned char queue_removeat(unsigned char index);
*/
 


char queue_push(QUEUE_STRUCT **queue,PACKAGE_STRUCT *package)
{
    char RET = Q_SUCCESSFUL;
    QUEUE_STRUCT *localQueue;
    
    
    if(NULL == (QUEUE_STRUCT *)*queue)
    {
        *queue = (QUEUE_STRUCT *)malloc(sizeof(QUEUE_STRUCT));
        if(NULL != *queue)
            localQueue = *queue;
        else
            RET = Q_MEMORY_ERROR;
    }
    else
    {
        localQueue = *queue;
        while(NULL != localQueue->NEXT)
            localQueue = localQueue->NEXT;
        localQueue->NEXT = (QUEUE_STRUCT *)malloc(sizeof(QUEUE_STRUCT));
        if(NULL != localQueue->NEXT)
            localQueue = localQueue->NEXT;
        else
            RET = Q_MEMORY_ERROR;
    }
    if(!RET)
    {
        localQueue->NEXT = NULL;
        localQueue->VALUE = package;
    }

    return RET;
}

char queue_pop(QUEUE_STRUCT **queue,PACKAGE_STRUCT **package)
{
    char RET = Q_SUCCESSFUL;
    QUEUE_STRUCT *localQueue;
    
    localQueue = *queue;
    if(NULL != localQueue)
    {
        *package = localQueue->VALUE;
        *queue = localQueue->NEXT;
        free(localQueue);
    }
    else
    {
        RET = Q_EMPTY;
    }

    
    return RET;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    QUEUE_STRUCT *MyQueue;
    PACKAGE_STRUCT *Mypackage;
    
    printf("Hello, World!\n");
    
    MyQueue = NULL;
    
    Mypackage = (PACKAGE_STRUCT *)malloc(sizeof(PACKAGE_STRUCT));
    Mypackage->Value = 0;
    queue_push(&MyQueue,Mypackage);
    
    Mypackage = (PACKAGE_STRUCT *)malloc(sizeof(PACKAGE_STRUCT));
    Mypackage->Value = 1;
    queue_push(&MyQueue,Mypackage);
    
    Mypackage = (PACKAGE_STRUCT *)malloc(sizeof(PACKAGE_STRUCT));
    Mypackage->Value = 2;
    queue_push(&MyQueue,Mypackage);

    queue_pop(&MyQueue,&Mypackage);
    free(Mypackage);
    queue_pop(&MyQueue,&Mypackage);
    free(Mypackage);
    queue_pop(&MyQueue,&Mypackage);
    free(Mypackage);

    return 0;
}
