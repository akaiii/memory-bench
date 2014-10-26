#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//#define test2
//#define test
#define swap
#define merge

#ifdef random
#define max(a,b) \
	a->num>b->num?a:b

#define min(a,b) \
	a->num<b->num?a:b
#endif

#define limit 999999999999999

typedef struct list{
	unsigned long int index;
	unsigned long int num;
	struct list *next;
}list;

//inline void link(list *a,list *b){a->next = b;}
//inline void revision(list *a)
//	{while(a!=NULL){a->index+=1;a=a->next;}}
//inline int re(list *a,list *b){return (a==b)?1:0;}
inline list * find_list(unsigned long int a,list *b)
	{while(b->index!=a)b=b->next;
	return b;}

#ifdef merge
void merge_sort(list *,unsigned long int,unsigned long int,int);
void merge_(list *,unsigned long int,unsigned long int,unsigned long int,int);
#endif

int main(void)
{
	int j;

	unsigned long int num = 0;

	unsigned long int temp = num;
	
	unsigned long int increase=1;	//increase memory
	
	srand(time(NULL));
	list *first;
	list *prev;
	list *tail;
	list *search;
	//for(j=0;j<100;j++)
		first = (list *)malloc(8388608);
	first->index = 0;
	first->num = num;
	first->next = NULL;
	prev = first;
	tail = first;	

	//insert and sort
	while(increase!=100000){
		list *new;
		new = (list *)malloc(8388608);
		new->index = ++num;
		new->num = new->index;
		new->next = first;
		first = new;
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
		merge_sort(first,0,tail->index,1);
		merge_sort(first,0,tail->index,0);
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
void merge_sort(list *l,unsigned long int p,unsigned long int r,int x){
	if(p<r){
		unsigned long int q = (unsigned long int)((p+r)/2);
		merge_sort(l,p,q,x);
		merge_sort(l,q+1,r,x);
		merge_(l,p,q,r,x);
	}
}

void merge_(list *l,unsigned long int p,unsigned long int q,unsigned long int r,int x){
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
		if(x){
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
		else{
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
}
#endif


