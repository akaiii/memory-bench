#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define max(a,b) \
	a->index>b->index?a:b

#define min(a,b) max(a,b)!=a?a:b

typedef struct list{
	long int index;
	struct list *next;
}list;

inline void link(list *a,list *b){a->next = b;};

int main(void)
{	
	//random
	srand(time(NULL));
	long int num;
	
	//linklist
	list *first = (list *)malloc(sizeof(list *));
	first->index = rand()%100000+1;
	first->next = NULL;
	
	//sort
	while(1){	
		list *new = (list *)malloc(sizeof(list *));
		new->index = rand()%100000+1;
		new->next = NULL;
		

		list *search = first;
		list *_next = search->next;
		while(search!=NULL)
			if(max(search,new)&&min(_next,new))
				link(max(search,new),min(_next,new));
		

		first = max(first,new);
	
		
		search = first;
		while(search!=NULL){
			printf("%d\n",search->index);
			search = search->next;
		}
	}
		
	
}
