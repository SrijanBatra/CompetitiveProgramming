#include <stdlib.h>
#include <stdio.h>

long long B[10000000 + 10];

long long A[10000000 + 10];
long long Quality[10000000 + 10];
long long powers[10000000 + 10];
long long sum;
long long prod;

struct pairs {
    long long value;
    long long death;
};

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
        powers[index] = (powers[index - 1] * val)%m;
    }
}



void minwindow(long long *in, long long *out, long long n, long long k)
{
    long long i;
    struct pairs * ring;
    struct pairs * minpair;
    struct pairs * end;
    struct pairs * last;

    ring = malloc(k * sizeof *ring);
    if (!ring) exit(EXIT_FAILURE);
    end  = ring + k;
    last = ring;
    minpair = ring;
    minpair->value = in[1];
    minpair->death = k;
    out[1] = in[1];

    for (i=2;i <= n;i++) {
        if (minpair->death == i) {
            minpair++;
            if (minpair >= end) minpair = ring;
        }
        if (in[i] <= minpair->value) {
            minpair->value = in[i];
            minpair->death = i+k;
            last = minpair;
        } else {
            while (last->value >= in[i]) {
                if (last == ring) last = end;
                --last;
            }
            ++last;
            if (last == end) last = ring;
            last->value = in[i];
            last->death = i+k;
        }
        out[i] = minpair->value;
        //printf("%lld %lld\n", out[i], minpair->death);

    }
    //printf("\n");
    free(ring);
}


int main(){
    long long N, K, Q;
    long long a,b,c,d,e,f,r,s,t,m;
    long long L1,La,Lc,Lm,D1,Da,Dc,Dm;
    long long L,R;  //range pointers for ingredients;
    A[0] = 0;
    scanf("%lld %lld %lld",&N,&K,&Q);
    scanf("%lld %lld %lld %lld %lld %lld %lld %lld %lld %lld %lld", &a,&b,&c,&d,&e,&f,&r,&s,&t,&m,&A[1]);
    scanf("%lld %lld %lld %lld %lld %lld %lld %lld", &L1,&La,&Lc,&Lm,&D1,&Da,&Dc,&Dm);
    
    long long x;

    calPower(t,N,s);
    long long prevm;
    long long prevms;
    for(x = 2; x <= N; x++){
        //precompute A[1] and t^        
        prevm = A[x-1];
        prevms = (prevm * prevm);
        if(powers[x] <= r) {
            
            A[x] = (((a)*prevms) + (((b)*prevm) + c))%m;
        }
        else{
            //A[x] = (d*A[x-1]*A[x-1] + e*A[x-1] + f)%m;
            A[x] = (((d)*prevms) + (((e)*prevm) + f))%m;
        }
    }

    long long index;
    minwindow(A,B,N,K);
    for(index = 1; index <= Q; index++){
        L1 = (((La) * (L1)) + Lc) %Lm;
        D1 = (((Da) * (D1)) + Dc) %Dm;
        L = L1 + 1;
        R = min(L + K - 1 + D1, N);     //make min(){}
        //Quality[index] = calTaste(L,R);
        Quality[index] = min(B[L+K-1], B[R]);
        //Quality[index] = B[R];
    }

    cal_Sum(Q);
    cal_Prod(Q);

    printf("%lld %lld\n", sum, prod);

    return 0;

/*
The ascending minima algorithm has been taken from:http://richardhartersworld.com/cri/2001/slidingmin.html.
*/
}
