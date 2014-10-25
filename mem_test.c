#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//#define test2
//#define test
#define swap
#define merge

#define max(a,b) \
	a->num>b->num?a:b

#define min(a,b) \
	a->num<b->num?a:b

#define limit 999999999999999

typedef struct list{
	unsigned long int index;
	unsigned long int num;
	struct list *next;
}list;

inline void link(list *a,list *b){a->next = b;}
inline void revision(list *a)
	{while(a!=NULL){a->index+=1;a=a->next;}}
inline int re(list *a,list *b){return (a==b)?1:0;}
inline list * find_list(unsigned long int a,list *b)
	{while(b->index!=a)b=b->next;
	return b;}

#ifdef merge
void merge_sort(list *,unsigned long int,unsigned long int);
void merge_(list *,unsigned long int,unsigned long int,unsigned long int);
#endif

int main(void)
{
	int j;

	unsigned long int num = 0;
	
	unsigned long int increase=1;	//increase memory
	
	srand(time(NULL));
	list *first;
	list *prev;
	list *tail;
	list *search;
	//for(j=0;j<10000;j++)
		first = (list *)malloc(100000);
	first->index = 0;
	first->num = num;
	first->next = NULL;
	prev = first;
	tail = first;	

	//insert and sort
	while(increase!=50000){
		list *new;
	//	list *_test;
		//for(j=0;j<10000;j++)
		new = (list *)malloc(100000);
		new->index = 0;
		new->num = ++num;
		new->next = NULL;

	//	_test = new;
		
		search = first;
	//	list *_next;
/*		if(first->next!=NULL)
			_next = search->next;

*/	//	unsigned long int index=0;
	//	while(search!=NULL){
		//	if(re(new,max(new,search))){
				link(new,search);
				revision(search);
				first = new;
	//			break;
		//	}
/*			else if(search->next==NULL){
				new->index = (re(new,min(new,search)))+index;
				if(first->next!=NULL)
					link(prev,max(search,new));
				link(max(search,new),min(search,new));

				if(re(new,max(new,search)))
					revision(search);
				tail = min(new,search);
				break;
			}
			else if(re(search,max(search,new))&&re(_next,min(_next,new))){
				link(search,new);
				link(new,_next);
				new->index+=index;
				revision(new);
				break;
			}
			index++;
			prev = search;
			search = search->next;
			_next = _next->next;*/
	//	}
		/*if(first->next==NULL)
			first = max(search,new) ; */
		increase++;
#ifdef test1
		printf("new: %lu num: %lu\n",_test->index,_test->num);

#endif
	}
#ifdef test2
		printf("======================================================\n\n\n");
		search = first;
		while(search!=NULL){
			printf("num: %lu\n",search->num);
			//if(search->index!=search->index-1)
			//	printf("error: \n");
	//		printf("index: %lu\n",search->index);
			search = search->next;
		}
	//	printf("tail: %lu\n",tail->index);
//	while(1){}
#endif

#ifdef swap
	int i = 0 ;
	//use swap
	while(1){
		merge_sort(first,0,tail->index);

#ifdef test2
		printf("======================================================\n\n\n");
		search = first;
		while(search!=NULL){
			printf("num: %lu\n",search->num);
		//	printf("index: %lu\n",search->index);
			search = search->next;
		}
		//printf("tail: %lu\n",tail->index);
#endif
	i++;
	}
#endif
}

#ifdef merge
void merge_sort(list *l,unsigned long int p,unsigned long int r){
	if(p<r){
		unsigned long int q = (unsigned long int)((p+r)/2);
		merge_sort(l,p,q);
		merge_sort(l,q+1,r);
		merge_(l,p,q,r);
	}
}

void merge_(list *l,unsigned long int p,unsigned long int q,unsigned long int r){
	list *first = l;
	list *temp;
	unsigned long int n1 = q-p+1;
	unsigned long int n2 = r-q;
	
	unsigned long int L[n1+1];
	unsigned long int R[n2+1];

	unsigned long int i,j,k;
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
			temp->num = R[j];
			first = l;
			j++;
		}
	}
}
#endif


