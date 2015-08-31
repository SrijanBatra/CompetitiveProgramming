#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<limits.h>

long long A[10000000 + 10];
long long Quality[10000000 + 10];
long long powers[10000000 + 10];
long long sum;
long long prod;

#define M (1000000000 + 7)

// A utility function to get minimum of two numbers
long long minVal(long long x, long long y) { return (x < y)? x: y; }
 
// A utility function to get the middle index from corner indexes.
long long getMid(long long s, long long e) {  return s + (e -s)/2;  }
 
/*  A recursive function to get the minimum value in a given range of array
    indexes. The following are parameters for this function.
 
    st    --> Pointer to segment tree
    index --> Index of current node in the segment tree. Initially 0 is
             passed as root is always at index 0
    ss & se  --> Starting and ending indexes of the segment represented by
                 current node, i.e., st[index]
    qs & qe  --> Starting and ending indexes of query range */
long long RMQUtil(long long *st, long long ss, long long se, long long qs, long long qe, long long index)
{
    // If segment of this node is a part of given range, then return the
    // min of the segment
    if (qs <= ss && qe >= se)
        return st[index];
 
    // If segment of this node is outside the given range
    if (se < qs || ss > qe)
        return INT_MAX;
 
    // If a part of this segment overlaps with the given range
    long long mid = getMid(ss, se);
    return minVal(RMQUtil(st, ss, mid, qs, qe, 2*index+1),
                  RMQUtil(st, mid+1, se, qs, qe, 2*index+2));
}
 
// Return minimum of elements in range from index qs (quey start) to
// qe (query end).  It mainly uses RMQUtil()
long long RMQ(long long *st, long long n, long long qs, long long qe)
{
    /*
    // Check for erroneous input values
    if (qs <= 1 || qe > n || qs > qe)
    {
        printf("Invalid Input");
        return -1;
    }
    */
    return RMQUtil(st, 0, n-1, qs, qe, 0);
}
 
// A recursive function that constructs Segment Tree for array[ss..se].
// si is index of current node in segment tree st
long long constructSTUtil( long long ss, long long se, long long *st, long long si)
{
    // If there is one element in array, store it in current node of
    // segment tree and return
    if (ss == se)
    {
        st[si] = A[ss];
        return A[ss];
    }
 
    // If there are more than one elements, then recur for left and
    // right subtrees and store the minimum of two values in this node
    long long mid = getMid(ss, se);
    st[si] =  minVal(constructSTUtil(ss, mid, st, si*2+1),
                     constructSTUtil(mid+1, se, st, si*2+2));
    return st[si];
}
 
/* Function to construct segment tree from given array. This function
   allocates memory for segment tree and calls constructSTUtil() to
   fill the allocated memory */
long long *constructST(long long n)
{
    // Allocate memory for segment tree
    long long x = (long long)(ceil(log2(n))); //Height of segment tree
    long long max_size = 2*(long long)pow(2, x) - 1; //Maximum size of segment tree
    long long *st;
    st = (long long *)malloc(sizeof(long long)* max_size);
 
    // Fill the allocated memory st
    constructSTUtil(1, n, st, 0);
 
    // Return the constructed segment tree
    return st;
}

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
    long long L,R;  //range pointers for ingredients;
    //A[0] = 0;
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

    long long *st = constructST(N); 
    
    long long index;
    for(index = 1; index <= Q; index++){
        L1 = (((La%Lm) * (L1%Lm))%Lm + Lc%Lm) %Lm;
        D1 = (((Da%Dm) * (D1%Dm))%Dm + Dc%Dm) %Dm;
        L = L1 + 1;
        R = min(L + K - 1 + D1, N);     //make min(){}
        //Quality[index] = calTaste(L,R);
        Quality[index] = RMQ(st, N, L-1, R-1);
    }

    cal_Sum(Q);
    cal_Prod(Q);

    printf("%lld %lld\n", sum, prod);

    return 0;
}

/*
used the implementation of segment trees with help from this website:
http://www.geeksforgeeks.org/segment-tree-set-1-range-minimum-query/
*/