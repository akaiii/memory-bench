#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//#define test
#define swap
#define merge

#define max(a,b) \
	a->num>b->num?a:b

#define min(a,b) \
	a->num<b->num?a:b

#define limit sizeof(unsigned long int)

typedef struct list{
	unsigned long int index;
	unsigned long int num;
	struct list *next;
}list;

inline void link(list *a,list *b){a->next = b;}
inline int re(list *a,list *b){return (a==b)?1:0;}
inline unsigned long int find_list(unsigned long int a,list *b)\
	{while(b->index!=a)b=b->next;return b->index;}

#ifdef merge
void merge_sort(list *,unsigned long int,unsigned long int);
void merge_(list *,unsigned long int,unsigned long int,unsigned long int);
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
			printf("%lu\n",search->num);
			search = search->next;
		}
#endif

#ifdef swap
	//use swap
	while(1){
		merge_sort(first,0,tail->index);	
	}
#endif
}

#ifdef merge
void merge_sort(list *l,unsigned long int p,unsigned long int r){
	if(p<r){
		unsigned long int q = (p+r)/2;
		merge_sort(l,p,q);
		merge_sort(l,q+1,r);
		merge_(l,p,q,r);
	}
}

void merge_(list *l,unsigned long int p,unsigned long int q,unsigned long int r){
	list *first = l;
	unsigned long int n1 = q-p+1;
	unsigned long int n2 = r-q;
	
	unsigned long int L[n1+1];
	unsigned long int R[n2+1];

	unsigned long int i,j,k;
	for(i=1;i<=n1;i++)
		L[i] = find_list(p+i-1,first);

	for(j=1;j<=n2;j++)
		R[j] = find_list(q+j,first);

	j=1;
	i=1;

	first = l;
	for(k=p;k<=r;k++){
		if(L[i]<R[j]){
			find_list(k,first);
			first->index = L[i];
			first = l;
			i++;
		}
		else{
			find_list(k,first);
			first->index = R[i];
			first = l;
			j++;
		}
	}
}
#endif


