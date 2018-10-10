//
//  OWQueue.h
//  Queue
//
//  Created by Anchor Ke on 2018/10/9.
//  Copyright © 2018 Anchor Ke. All rights reserved.
//

#ifndef OWQueue_h
#define OWQueue_h

#include <stdio.h>

//Queue
typedef struct _OWLINKED_
{
    void *Data;
    struct _OWLINKED_ *Next;
} OWLINKED;

unsigned char AddOWQueue(OWLINKED **Queue);
void FreeOWQueue(OWLINKED **Queue);
#endif /* OWQueue_h */
