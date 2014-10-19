#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//#define test
#define merge

#define max(a,b) \
	a->num>b->num?a:b

#define min(a,b) \
	a->num<b->num?a:b


typedef struct list{
	unsigned long int index;
	unsigned long int num;
	struct list *next;
}list;

inline void link(list *a,list *b){a->next = b;}
inline int re(list *a,list *b){return (a==b)?1:0;}

#ifdef merge
int merge_sort(list *,int,int);
int merge_(list *,int,int,int);
#endif

int main(void)
{
	
	unsigned long int increase=1;	//increase memory
	unsigned long int num=0;
	
	srand(time(NULL));
	list *first;
	list *tail;
	list *search;
	first = (list *)malloc(sizeof(list *));
	first->index = num;
	first->num = rand()%1000000+1;
	first->next = NULL;
	tail = first;	

	//insert and sort
	while(increase!=10000){
		list *new;
		new = (list *)malloc(sizeof(list *));
		new->index = num++;
		new->num = rand()%1000000+1;
		new->next = NULL;

		search = first;
		list *_next;
		if(first->next!=NULL)
			_next = search->next;

		unsigned long int index=0;
		while(search!=NULL){
			if(search->next==NULL){
				new->index = re(new,min(new,search))+index;
				link(max(search,new),min(search,new));
				break;
			}
			if(re(search,max(search,new))&&re(_next,min(_next,new))){
				new->index = index;
				link(search,new);
				link(new,_next);
				break;
			}
			if(re(new,max(new,search))){
				new->index = 0;
				link(new,search);
				break;
			}
			index++;
			search = search->next;
			_next = _next->next;
		}
		first = max(search,new);
		increase++;
	}
#ifdef test
		search = first;
		while(search!=NULL){
			printf("%d\n",search->num);
			search = search->next;
		}
#endif

#ifdef swap
	//use swap
	while(1){
		merge_(first,0,tail->index);	
			
	}
#endif
}

#ifdef merge
int merge_sort(list *l,int p,int r){
	if(p<r){
		int q = (p+r)/2;
		merge_sort(l,p,q);
		merge_sort(l,q+1,r);
		merge(l,p,q,r);
	}


	return 0;
}

int merge_(list *l,int p,int q,int r){
	int n1 = q-p+1;
	int n2 = r-q;

	return 0;
}
#endif



#ifdef finish
int partition(int p,int r){
	int x,i,j,k;

	x=A[r];
	i=p-1;
	for (j=p;j<=r-1;j++){
		if (A[j]<=x){
			i++;
			k=A[i];
			A[i]=A[j];
			A[j]=k;
		}
	}
	k=A[i+1];
	A[i+1]=A[r];
	A[r]=k;
	return i+1;
}

void quicksort(int p,int r){
	int q;

	if (p<r){
	   q=partition(p,r); 
	   quicksort(p,q-1);
	   quicksort(q+1,r);	
	}
}
#endif

