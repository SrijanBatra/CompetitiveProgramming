#include<stdio.h>
#include<stdlib.h>
#include<math.h>

double circles[20000000];

int main(){
	long long T;
	long long tn = 1;
	scanf("%lld", &T);
	long long No, P, M, B, N;
	double Ro1, Ro2, Ro3, Ro4;
	scanf("%lld %lld %lld %lld", &No, &P, &M, &B);
	scanf("%lf %lf %lf %lf", &Ro1, &Ro2, &Ro3, &Ro4);
	double radius;
	double R1, R2, R3;
	double inner;
	double a,b,c,x,y,sum;
	double coefa, coefb;
	circles[1] = Ro1;
	circles[2] = Ro2;
	circles[3] = Ro3;
	circles[4] = Ro4;
	N = No;
	
	//radius = Ro4;
	
	a = (-1/Ro1);
	
	b = (1/Ro2);

	

	double answer = 0;

	while(tn <= T){
		No = N;
		N = (P * No) % M + B;
		//N = 6;
		x = (1/Ro4);

		c = (1/Ro3);
		
		if(circles[N] != 0){
			radius = circles[N];
		}
		else{
			long long circleno = 5;
			while(circleno <= N){
				y = c;
				c = x;
				coefa = (a + b + c);
				sum =  2 * coefa;
				x = sum - y;

				radius = 1/x;
				circles[N] = radius;
				circleno++;
			}
		}

		answer += radius;
		tn++;
	}

	printf("%f\n", answer);
	return 0;
}