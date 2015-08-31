#include<stdio.h>
#include<stdlib.h>

long long array[200000 + 10];
long long values[200000 + 10];
long long values2[200000 + 10];
//mod 1000000007

void query1(long long start, long long end){
	long long index;
	for(index = start; index <= end; index ++){
		array[index] = array[index] + values[index - start + 1];
		if(array[index] > 1000000007){
			array[index] -= 1000000007;
		}
	}
}

long long query2(long long start, long long end){
	long long index;
	long long answer = 0;
	for(index = start; index <= end; index++){
		answer = answer + array[index];
		if(answer > 1000000007){
			answer -= 1000000007;
		}
	}

	return answer;
}

void initialize(long long N){
	long long index;
	values[0] = 1;
	values[1] = 2;
	values[2] = 6;
	values2[1] = 2;
	values2[2] = 4;
	for(index = 3; index <= N; index ++){
		values2[index] = values2[index-1] + 2;
	}
	for(index = 3; index <= N; index ++){
		values[index] = values[index - 1] + values2[index];
		if(values[index] > 1000000007){
			values[index] = values[index] - 1000000007;
		}
	}
}


int main(){
	long long N,Q;

	scanf("%lld %lld", &N, &Q);
	long long index;
	long long answer;
	for(index = 1; index <= N; index ++){
		array[index] = 0;
	}

	initialize(N);

	long long type, start, end;
	for(index = 1; index <= Q; index ++){
		scanf("%lld %lld %lld", &type, &start, &end);
		if(type == 1){
			query1(start, end);
		}
		else if(type == 2){
			answer = query2(start, end);
			printf("%lld\n", answer);
		}
	}

	return 0;
}