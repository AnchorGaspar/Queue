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


int main(int argc, const char * argv[]) {
    // insert code here...

	QUEUE_HEAD Head={.FIRST = NULL,.COUNT = 0};
	PACKAGE_STRUCT *Mypackage;
	int Loop;

	for(Loop = 0;Loop < 100;Loop++)
	{
		Mypackage = (PACKAGE_STRUCT *)malloc(sizeof(PACKAGE_STRUCT));
		Mypackage->Value = Loop;
		queue_push(&Head,Mypackage);
	}


	Mypackage = queue_pop(&Head);
	printf("Value = %d\n",Mypackage->Value);
	free(Mypackage);

	Mypackage = queue_pop(&Head);
	printf("Value = %d\n",Mypackage->Value);
	free(Mypackage);

	Mypackage = queue_pop(&Head);
	printf("Value = %d\n",Mypackage->Value);
	free(Mypackage);


    return 0;
}
