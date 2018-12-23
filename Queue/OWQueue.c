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



char queue_push(QUEUE_HEAD *head,const PACKAGE_STRUCT *package)
{
	char RET = Q_SUCCESSFUL;
	QUEUE_STRUCT *localQueue;


	if(NULL == head->FIRST)
	{
		if(NULL != (head->FIRST = (QUEUE_STRUCT*)malloc(sizeof(QUEUE_STRUCT))))
			localQueue = head->FIRST;
		else
			RET = Q_MEMORY_ERROR;
	}
	else
	{
		localQueue = head->FIRST;
		while(NULL != localQueue->NEXT)
			localQueue = localQueue->NEXT;
		if(NULL != (localQueue->NEXT = (QUEUE_STRUCT*)malloc(sizeof(QUEUE_STRUCT))))
			localQueue = localQueue->NEXT;
		else
			RET = Q_MEMORY_ERROR;
	}

	if(!RET)
	{
		head->COUNT ++;
		localQueue->NEXT = NULL;
		localQueue->VALUE = (PACKAGE_STRUCT *)package;
	}

	return RET;

}

PACKAGE_STRUCT* queue_pop(QUEUE_HEAD *head)
{
	PACKAGE_STRUCT *RET = NULL;
	QUEUE_STRUCT *localQueue;

	if(head->COUNT)
	{
		localQueue = head->FIRST;
		head->FIRST = localQueue->NEXT;
		head->COUNT --;
		RET = localQueue->VALUE;
		free(localQueue);
	}
	return RET;
}

static char queue_kill_element(QUEUE_STRUCT *element)
{
	char RET = 0;

#if USE_RECURCIVE
	if(NULL != element->NEXT)
		queue_kill_element(element->NEXT);
	free(element->VALUE);
	free(element);
#endif
	
	return RET;
}

char queue_destroy(QUEUE_HEAD *head)
{
	char RET = 0;

#if USE_RECURCIVE
	if(head->COUNT)
	{
		queue_kill_element(head->FIRST);
		head->FIRST = NULL;
		head->COUNT = 0;
	}
#endif
	return RET;
}

