#include <stdio.h>

typedef struct items{
	int value;
	int sno;
}item;

item array[100000 + 10];

static int cmpfunc (const void * a, const void * b)
{
    if( (*(item *)a).value - (*(item *)b).value < 0 )
        return -1;
    if( (*(item *)a).value - (*(item *)b).value > 0 )
        return 1;
    if( (*(item *)a).value - (*(item *)b).value == 0 )
        return 0;
}

static int cmpfunc2 (const void * a, const void * b)
{
    if( (*(item *)a).sno - (*(item *)b).sno < 0 )
        return -1;
    if( (*(item *)a).sno - (*(item *)b).sno > 0 )
        return 1;
    if( (*(item *)a).sno - (*(item *)b).sno == 0 )
        return 0;
}

int main(){
	int n;
	scanf("%d", &n);
	int index = 0;
	for(index = 0; index < n; index ++){
		scanf("%d", &array[index].value);
		array[index].sno = index + 1;
	}

	//qsort(array,n,sizeof(item),cmpfunc);

	for(index = 0; index < n;index++){
		if(array[index].value <= n){
			item temp;
			temp = array[array[index].value-1];
			array[array[index].value-1] = array[index];
			array[index] = temp;
		}
		
	}
	for(index = 0; index < n; index ++){
		array[index].value = index + 1;
	}

	qsort(array,n,sizeof(item),cmpfunc2);

	for(index = 0; index < n;index++){
		printf("%d ", array[index].value);
	}
	printf("\n");
	
	return 0;
}