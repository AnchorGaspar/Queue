//
//  OWQueue.h
//  Queue
//
//  Created by Anchor Ke on 2018/10/9.
//  Copyright © 2018 Anchor Ke. All rights reserved.
//

#ifndef _OWQUEUE_
#define _OWQUEUE_

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

char queue_push(QUEUE_STRUCT **queue,PACKAGE_STRUCT *package);
char queue_pop(QUEUE_STRUCT **queue,PACKAGE_STRUCT **package);

#endif
