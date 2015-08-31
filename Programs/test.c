#include<stdio.h>
#include<stdlib.h>
#include <math.h>
int main(){
	int T;
	int tn = 1;
	scanf("%d", &T);
	double A, B;
	double q;
	scanf("%lf %lf", &A, &B);
	q = B/A;
	printf("q = %f\n", q);
	if((fmod(q,2)) == 0){
	//operation 2
		printf("divisible\n");
	}
	else
		printf("\n");

	return 0;
}