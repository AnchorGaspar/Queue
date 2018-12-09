//
//  main.c
//  Queue
//
//  Created by Anchor Ke on 2018/10/9.
//  Copyright © 2018 Anchor Ke. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "OWQueue.h"


/*
char queue_initial(QUEUE_STRUCT **queue);
char queue_push(QUEUE_STRUCT **queue,PACKAGE_STRUCT *package);
PACKAGE_STRUCT* queue_pop(QUEUE_STRUCT **queue);
unsigned char queue_count(void);
unsigned char queue_removeat(unsigned char index);
*/

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
