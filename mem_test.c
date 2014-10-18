#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define max(a,b) \
	a->index>b->index?a:b

#define min(a,b) max(a,b)!=a?a:b

typedef struct list{
	unsigned long int index;
	struct list *next;
}list;

inline void link(list *a,list *b){a->next = b;};

int main(void)
{	
	srand(time(NULL));
	unsigned long int num;
	
	list *first = (list *)malloc(100000000);
	first->index = (rand()%1000)+1;
	first->next = NULL;

	int i=0;
	while(1){	
		list *new = (list *)malloc(sizeof(100000000));
		new->index = (rand()%1000)+1;
		new->next = NULL;
		

		list *search = first;
		list *_next;
		if(first->next!=NULL)
			_next = search->next;
		while(search!=NULL){
			if(search->next==NULL){
				link(max(search,new),min(search,new));
				break;
			}
			if(max(search,new)&&min(_next,new)){
				link(search,new);
				link(new,_next);
				break;
			}
			search = search->next;
			_next = _next->next;
		}

		first = max(first,new);
		
		search = first;
		while(search!=NULL){
			printf("%d\n",search->index);
			search = search->next;
		}
		printf("%d\n",i++);

	}
}
