#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define test
//#define swap
//#define merge

#define max(a,b) \
	a->num>b->num?a:b

#define min(a,b) \
	a->num<b->num?a:b

#define limit sizeof(long int)

typedef struct list{
	long int index;
	long int num;
	struct list *next;
}list;

inline void link(list *a,list *b){a->next = b;}
inline int re(list *a,list *b){return (a==b)?1:0;}
inline long int find_list(long int a,list *b)
	{while(b->index!=a)b=b->next;
	return b->num;}

#ifdef merge
void merge_sort(list *,long int,long int);
void merge_(list *,long int,long int,long int);
#endif

int main(void)
{
	
	long int increase=1;	//increase memory
	long int num=0;
	
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
	while(increase!=10){
		list *new;
		new = (list *)malloc(sizeof(list *));
		new->index = 0;
		new->num = rand()%1000000+1;
		new->next = NULL;

		search = first;
		list *_next;
		if(first->next!=NULL)
			_next = search->next;

		long int index=0;
		while(search!=NULL){
			if(search->next==NULL){
				new->index = re(new,min(new,search))+index;
				link(max(search,new),min(search,new));
				tail = min(new,search);
				break;
			}
			if(re(search,max(search,new))&&re(_next,min(_next,new))){
				new->index = index;
				link(search,new);
				link(new,_next);
				break;
			}
			if(re(new,max(new,search))){
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
			printf("num: %lu\n",search->num);
			printf("index: %lu\n",search->index);
			search = search->next;
		}
		printf("tail: %lu\n",tail->index);
#endif

#ifdef swap
	//use swap
	while(1){
		merge_sort(first,0,tail->index);	
	}
#endif
}

#ifdef merge
void merge_sort(list *l,long int p,long int r){
	if(p<r){
		long int q = (p+r)/2;
		merge_sort(l,p,q);
		merge_sort(l,q+1,r);
		merge_(l,p,q,r);
	}
}

void merge_(list *l,long int p,long int q,long int r){
	list *first = l;
	long int n1 = q-p+1;
	long int n2 = r-q;
	
	long int L[n1+1];
	long int R[n2+1];

	long int i,j,k;
	for(i=1;i<=n1;i++)
		L[i] = find_list(p+i-1,first);

	for(j=1;j<=n2;j++)
		R[j] = find_list(q+j,first);

	L[n1+1] = limit;
	R[n2+1] = limit;

	j=1;
	i=1;

	first = l;
	for(k=p;k<=r;k++){
		if(L[i]<R[j]){
			find_list(k,first);
			first->num = L[i];
			first = l;
			i++;
		}
		else{
			find_list(k,first);
			first->num = R[i];
			first = l;
			j++;
		}
	}
}
#endif


