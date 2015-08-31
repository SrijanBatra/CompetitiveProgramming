#include<stdio.h>
#include<stdlib.h>
#include<math.h>

double circles[20];

double a,b,c,d;

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
	double x,y,sum;
	double coefa, coefb;
	circles[1] = Ro1;
	circles[2] = Ro2;
	circles[3] = Ro3;
	circles[4] = Ro4;
	N = No;
	
	//radius = Ro4;
	
	a = (-1/Ro1);
	
	b = (1/Ro2);

	c = (1/Ro3);

	d = (1/Ro4);		

	double answer = 0;
	long long diff;
	while(tn <= T){
		No = N;
		N = (P * No) % M + B;
		//N = 6;
		
		
		if(N <= 5){
			if(N == 5){
				x = 2 * (a + b + d) - c;

				radius = 1/x;
			}
			else
				radius = circles[N];
		}
		else{	
			
			x = (((N-4)*(N-4) + (N-4)) * (a + b)) + ((N-3) * d) - ((N-4) * c);
			radius = 1/x;
		
		}

		answer += radius;
		tn++;
	}

	printf("%f\n", answer);
	return 0;
}