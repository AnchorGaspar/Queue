//
//  OWQueue.c
//  Queue
//
//  Created by Anchor Ke on 2018/10/9.
//  Copyright © 2018 Anchor Ke. All rights reserved.
//

#include "OWQueue.h"
#include <stdio.h>
#include <stdlib.h>

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
