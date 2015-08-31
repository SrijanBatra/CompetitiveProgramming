#include<stdio.h>
#include<stdlib.h>

int array[100000 + 10];

int minimum_and_sum(int length){
//return (sum-min) + 2
	int index = 1;
	int sum = array[0];
	int min = array[0];
	int answer = 0;
	while(index < length){
		if(array[index] < min){
			min = array[index];
		}
		sum += array[index];
		index++;
	}
	if(min < 2) answer = -1;
	else answer = sum - min + 2;
	return answer;
}

int main(){
	int T;
	int tn = 1;
	scanf("%d",&T);
	int max;
	int i = 0;	
	while(tn <= T){
		int no_of_ingredients;
		scanf("%d",&no_of_ingredients);
		i = 0;
		while(i < no_of_ingredients){
			scanf("%d", &array[i]);
			i += 1;
		}

		max = minimum_and_sum(no_of_ingredients);
		printf("%d\n",max);
		tn ++;
	}

	return 0;
}