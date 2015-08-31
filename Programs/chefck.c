#include<stdio.h>
#include<stdlib.h>


long long A[10000000 + 10];
long long Quality[10000000 + 10];
long long powers[10000000 + 10];
long long sum;
long long prod;

#define M (1000000000 + 7)

void cal_Sum(long long Q){
	long long index;
	sum = 0;
	for(index = 1; index <= Q; index++){
		sum = (sum + Quality[index]);
	}
}

void cal_Prod(long long Q){
	long long index;
	prod = 1;
	for(index = 1; index <= Q;index++){
		prod = (prod%M * Quality[index]%M)%M;
	}	
}

long long min(long long no1, long long no2){
	if(no1 < no2)
		return no1;
	else
		return no2;
}


void calPower(long long val,long long power,long long m){
	long long index;
	powers[1] = val;
	for(index = 2; index <= power; index ++){
		powers[index] = (powers[index - 1]%m * val%m)%m;
	}
}


long long calTaste(long long L, long long R){
	long long index;
	long long minimum;
	minimum = A[L];
	for(index = L + 1; index <= R; index++){
		if(A[index] < minimum){
			minimum = A[index];
		}
	}
	return minimum;
}

int main(){
	long long N, K, Q;
	long long a,b,c,d,e,f,r,s,t,m;
	long long L1,La,Lc,Lm,D1,Da,Dc,Dm;
	long long L,R;	//range pointers for ingredients;
	A[0] = 0;
	scanf("%lld %lld %lld",&N,&K,&Q);
	scanf("%lld %lld %lld %lld %lld %lld %lld %lld %lld %lld %lld", &a,&b,&c,&d,&e,&f,&r,&s,&t,&m,&A[1]);
	scanf("%lld %lld %lld %lld %lld %lld %lld %lld", &L1,&La,&Lc,&Lm,&D1,&Da,&Dc,&Dm);
	
	long long x;

	calPower(t,N,s);
	for(x = 2; x <= N; x++){
		//precompute A[1] and t^
		long long prevm;
		long long prevms;
		prevm = A[x-1]%m;
		prevms = (prevm * prevm)%m;
		if(powers[x] <= r) {
			
			A[x] = (((a%m)*prevms)%m + (((b%m)*prevm)%m + c%m)%m)%m;
		}
		else{
			//A[x] = (d*A[x-1]*A[x-1] + e*A[x-1] + f)%m;
			A[x] = (((d%m)*prevms)%m + (((e%m)*prevm)%m + f%m)%m)%m;
		}
	}

	long long index;
	for(index = 1; index <= Q; index++){
		L1 = (((La%Lm) * (L1%Lm))%Lm + Lc%Lm) %Lm;
		D1 = (((Da%Dm) * (D1%Dm))%Dm + Dc%Dm) %Dm;
		L = L1 + 1;
		R = min(L + K - 1 + D1, N);		//make min(){}
		Quality[index] = calTaste(L,R);
	}

	cal_Sum(Q);
	cal_Prod(Q);

	printf("%lld %lld\n", sum, prod);

	return 0;
}