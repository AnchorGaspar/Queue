//
//  OWQueue.c
//  Queue
//
//  Created by Anchor Ke on 2018/10/9.
//  Copyright © 2018 Anchor Ke. All rights reserved.
//

#include "OWQueue.h"
#include "stdlib.h"



unsigned char AddOWQueue(OWLINKED **Queue)
{
    unsigned char RET = 0;
    OWLINKED *Tail = *Queue;
    
    while(NULL != Tail)
        Tail = Tail->Next;
    
    Tail = (OWLINKED*)malloc(sizeof(OWLINKED));
    
    if(NULL == Tail)
        RET = 1;
    
    return RET;
}

void FreeOWQueue(OWLINKED **Queue)
{
    
}

