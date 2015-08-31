#include<stdio.h>
#ifdef WIN32
#define INT64 "%I64d\n"
#else
#define INT64 "%lld\n"
#endif
int main(){
	double T, S, q;
	scanf("%lf %lf %lf", &T, &S, &q);
	long long repeat = 0;
	double played = S;
	if(S < T){
		while(played < T){
			played = q * played;
			repeat++;
		}
		printf("%d", (int)repeat);
	}
	else
		printf("0\n");


	return 0;
}