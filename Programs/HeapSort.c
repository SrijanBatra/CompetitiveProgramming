#include<stdio.h>
#include<stdlib.h>

/* i/2--> node, 2i --> left, 2i + 1 --> right. */

void heapify(int *array, int i, int n){
int child;
int temp;

for(temp = array[i]; 2*i+1 < n; i = child){
	child = 2*i;
	if(child != n-1 && array[child + 1] > array[child])
		child ++;
	if(temp < array[child])
		array[i] = array[child];
	else
		break;
	}
	array[i] = temp;
}


/*int max_heap()*/

int main(){
int *array; 
int i = 0,n,temp;
printf("\nenter no of elements\n");
scanf("%d",&n);
printf("\nenter elements to sort.\n");
array = (int*)malloc(sizeof(int) * n);
while(i < n){
	scanf("%d",&array[i]);
	i += 1;
	}
for(i = n/2; i >=0; i--){
	heapify(array,i,n);
	}
i = 0;
/*while(i<n){
	printf("\n%d\n",array[i]);
	i += 1;
	}*/
for(i = n-1; i>0; i--){
	temp = array[0];
	array[0] = array[i];
	array[i] = temp;
	heapify(array, 0, i);
	}
while(i<n){
	printf("\n%d\n",array[i]);
	i += 1;
	}
return 0;
}
/*retrieve the elements for sorting*/
