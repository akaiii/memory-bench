#include <stdio.h>
#include <stdlib.h>
#include <time.h>


typedef struct list{
	unsigned long int num;
	struct list *next;
}list;

inline void revision(list *a){while(a->next!=NULL){a->num++;a=a->next;}}
inline void revision_(list *a){while(a->next!=NULL){a->num--;a=a->next;}}

int main(void)
{
	
	unsigned long int increase=1;	//increase memory
	
	list *first;

	//insert and sort
	while(increase!=70000){
		list *new;
		new = (list *)malloc(8388608);
		new->num = 0;
		new->next = first;
		first = new;
		increase++;
	}
		
	list *temp;
	while(1){
		temp = first;
		revision(temp);
		temp = first;
		revision_(temp);
	}
}

