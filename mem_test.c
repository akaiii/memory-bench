#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define test

#define max(a,b) \
	a->index>b->index?a:b

#define min(a,b) \
	a->index<b->index?a:b

typedef struct list{
	unsigned long int index;
	struct list *next;
}list;

inline void link(list *a,list *b){a->next = b;};
inline int re(list *a,list *b){if(a==b)return 1;else return 0;}

#ifdef finish
int merge_sort(list *l,int p,int q);
int merge(list *l,int p,int q,int r);
#endif

int main(void)
{	
	srand(time(NULL));
	list *first;
	list *search;
	first = (list *)malloc(sizeof(list *));
	first->index = 0;//rand()%1000000+1;
	first->next = NULL;
	
	unsigned long int i=1;

	//insert and sort
	while(i!=10000){
		list *new;
		new = (list *)malloc(sizeof(list *));
		new->index = i;//rand()%1000000+1;
		new->next = NULL;

		search = first;
		list *_next;
		if(first->next!=NULL)
			_next = search->next;
		while(search!=NULL){
			if(search->next==NULL){
				link(max(search,new),min(search,new));
				break;
			}
			if(re(search,max(search,new))&&re(_next,min(_next,new))){
				link(search,new);
				link(new,_next);
				break;
			}
			if(re(new,max(new,search))){
				link(new,search);
				break;
			}
			search = search->next;
			_next = _next->next;
		}
		first = max(search,new);
		i++;
	}
#ifdef test
		i=0;
		search = first;
		while(search!=NULL){
			printf("%d\n",search->index);
			search = search->next;
			printf("i: %d\n",i++);
		}
#endif

#ifdef finish
	//use swap
	while(1){
		while(first->next!=NULL){
			
		}
			
	}
#endif
}

#ifdef finish
int merge_sort(list *l;int p,int r){
	if(p<r){
		int q = (p+r)/2;
		merge_sort(l,p,q);
		merge_sort(l,q+1,r);
		merge(l,p,q,r);
	}

}

int merge(list *l,int p,int q,int r){
	int n1 = q-p+1;
	int n2 = r-q;

	

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

