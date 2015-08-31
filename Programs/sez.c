#include <stdio.h>
#include <stdlib.h>

typedef struct nodes{
	long long no;
	long long status;
	struct nodes* next;
} node;

typedef struct AdjLists{
	struct nodes *head;
}AdjList;

AdjList* array;
int* stat;
long long max;
long long x,y;


void not_include(long long n,long long index){
	stat[index] = 0;
}

void is_include(long long n, long long index){	
	AdjList that;
	that = array[index];
	node* this;
	this = that.head;
	if(stat[index] == 0){
		x += 1;
		stat[index] = 1;
	}
	while(this->next != NULL){
		if(stat[this->no] != -1){
			stat[this->no] = -1;
			y++;
		}
		this = this->next;
	}
}

void bruteforce(long long n,long long index){
	for(; index <= n; index++){		
		if(stat[index] != -1){
			is_include(n,index);
			if((x-y) > max){
				max = (x-y);
			}
			not_include(n,index);
			if((x-y) > max){
				max = (x-y);
			}
		}
	}
}


int main(){
	long long n,m;
	scanf("%lld %lld", &n, &m);
	array = (AdjList*) malloc(sizeof(AdjList)*(n+1));
	stat =  (int*) malloc(sizeof(int)*(n+1));
	long long index;
	long long left,right;
	for(index = 1; index <= n; index++){
		
		node* newnode = (node*)malloc(sizeof(node));
		newnode->no = index;
		newnode->status = 0;
		newnode->next = NULL;
		array[index].head = newnode;
		stat[index] = 0;
	}

	for(index = 0; index < m; index++){
		scanf("%lld %lld", &left, &right);
		node* newnode = (node*) malloc(sizeof(node));
		newnode->no = right;
		newnode->next = array[left].head;
		array[left].head = newnode;

		node* newnode2 = (node*) malloc(sizeof(node));
		newnode2->no = left;
		newnode2->next = array[right].head;
		array[right].head = newnode2;
		
	}

	max = 0;
	x = 0;
	y = 0;
	bruteforce(n,1);
	printf("%lld\n", max);
	return 0;
	
}