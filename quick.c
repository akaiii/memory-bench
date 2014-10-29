#include <stdio.h>
#include <stdlib.h>
#include <time.h>


typedef struct list{
	int num;
	struct list *next;
}list;

inline void revision(list *a){while(a->next!=NULL){a->num++;a=a->next;}}
inline void revision_(list *a){while(a->next!=NULL){a->num--;a=a->next;}}


int main(void)
{
	int increase=1;	//increase memory
	printf("%d\n",sizeof(list*));
	list *first;
	first = malloc(sizeof(list*));
	first->num = 0;
	first->next = NULL;
	//insert and sort
	while(increase!=10000000){
		list *new;
		new = malloc(sizeof(list*));
		new->num = 0;
		new->next = first;
		first = new;
		increase++;
	}
	list *temp;
	increase = 0;
	time_t start_time = time(NULL);
	while(increase!=1){
		temp = first;
		revision(temp);
		temp = first;
		revision_(temp);
		increase++;
	}

	printf("Runing time: %g sec\n",difftime(time(NULL),start_time));
}

