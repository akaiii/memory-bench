#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define test
#define swap
#define merge

#define max(a,b) \
	a->num>b->num?a:b

#define min(a,b) \
	a->num<b->num?a:b

#define limit 999999999999999

typedef struct list{
	long int index;
	long int num;
	struct list *next;
}list;

inline void link(list *a,list *b){a->next = b;}
inline void revision(list *a,long int b)
	{while(a!=NULL){a->index+=1;a=a->next;}}
inline int re(list *a,list *b){return (a==b)?1:0;}
inline list * find_list(long int a,list *b)
	{while(b->index!=a)b=b->next;
	return b;}

#ifdef merge
void merge_sort(list *,long int,long int);
void merge_(list *,long int,long int,long int);
#endif

int main(void)
{
	
	long int increase=1;	//increase memory
	
	srand(time(NULL));
	list *first;
	list *prev;
	list *tail;
	list *search;
	first = (list *)malloc(sizeof(list *));
	first->index = 0;
	first->num = rand()%10000+1;
	first->next = NULL;
	prev = first;
	tail = first;	

	//insert and sort
	while(increase!=1000000000000000){
		list *new;
		new = (list *)malloc(sizeof(list *));
		new->index = 0;
		new->num = rand()%10000+1;
		new->next = NULL;

		search = first;
		list *_next;
		if(first->next!=NULL)
			_next = search->next;

		long int index=0;
		while(search!=NULL){
			if(search->next==NULL){
				//list *temp = max(new,search);
				new->index = (re(new,min(new,search)))+index;
				link(max(prev,new),max(search,new));
				link(max(search,new),min(search,new));

				if(re(new,max(new,search)))
					revision(search,0);
				tail = min(new,search);
				break;
			}
			if(re(search,max(search,new))&&re(_next,min(_next,new))){
				link(search,new);
				link(new,_next);
				new->index+=index;
				revision(new,0);
				break;
			}
			if(re(new,max(new,search))){
				first = new;
				revision(search,0);
				link(new,search);
				break;
			}
			index++;
			prev = search;
			search = search->next;
			_next = _next->next;
		}
		if(first->next==NULL)
			first = max(search,new) ; 
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
	int i = 0 ;
	//use swap
	while(i!=1){
		merge_sort(first,0,tail->index);

#ifdef test
		search = first;
		while(search!=NULL){
			printf("num: %lu\n",search->num);
			printf("index: %lu\n",search->index);
			search = search->next;
		}
		printf("tail: %lu\n",tail->index);
#endif
	i++;
	}
#endif
}

#ifdef merge
void merge_sort(list *l,long int p,long int r){
	if(p<r){
		long int q = (long int)((p+r)/2);
		merge_sort(l,p,q);
		merge_sort(l,q+1,r);
		merge_(l,p,q,r);
	}
}

void merge_(list *l,long int p,long int q,long int r){
	list *first = l;
	list *temp;
	long int n1 = q-p+1;
	long int n2 = r-q;
	
	long int L[n1+1];
	long int R[n2+1];

	long int i,j,k;
	for(i=1;i<=n1;i++){
		temp = find_list(p+i-1,first);
		L[i-1] = temp->num;
	}

	first = l;
	for(j=1;j<=n2;j++)
	{
		temp = find_list(q+j,first);
		R[j-1] = temp->num;
	}

	L[n1] = limit;
	R[n2] = limit;

	j=0;
	i=0;

	first = l;
	for(k=p;k<=r;k++){
		if(L[i]<=R[j]){
			temp = find_list(k,first);
			temp->num = L[i];
			first = l;
			i++;
		}
		else{
			temp = find_list(k,first);
			temp->num = R[i];
			first = l;
			j++;
		}
	}
}
#endif


