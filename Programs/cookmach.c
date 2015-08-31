#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
	int T;
	int tn = 1;
	scanf("%d", &T);
	double A, B;
	double q;
	while(tn <= T){
		long long operations = 0;
		scanf("%lf %lf", &A, &B);
		while(A != B){
			q = B/A;
			if(fmod(q,2) == 0){
				//operation 2
				A = B;
				operations += log(q)/log(2);
			}
			else{
				//operation 1
				if(fmod(A,2) == 0){
					A /= 2;
				}
				else{
					A = (A-1)/2;
				}
				operations += 1;			
			}
		}
		printf("%lld\n", operations);
		tn++;
	}

	return 0;
}
