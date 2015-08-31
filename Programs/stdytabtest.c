
#include <stdlib.h>
#include <math.h>
#include <stdio.h>


long long combinations[2000 + 10][2000 + 10];	//addressing: (row,sum)
long long permutations[2000 + 10];
long long permutations2[4000 + 10][4000 + 10];

long long nCr(int n, int k) {
   long long answer;
   answer = permutations2[n-1][k] + permutations2[n-1][k-1];
   if(answer > 1000000000){
   		answer -= 1000000000;
   }
   return answer;
  
}

void calpermutations(int n, int r){
	//ans = ((s + m - 1) choose (s))
	int nd;
    nd = n;
    n = n + r - 1;
    r = nd;
    if(r > n / 2) r = n - r; // because C(n, r) == C(n, n - r)
    long long ans = 1;
    int i;

    for(i = 1; i <= r; i++) {
        ans *= n - r + i;
        ans /= i;
    }
	permutations[nd] = ans;
}

int main(){
	int n,m;	
	scanf("%d %d", &n, &m);
	int index;
	permutations[0] = 1;
	for(index = 0; index <= m; index ++){
		calpermutations(index, m);
		
	}
	permutations2[0][0] = 1;
	permutations2[1][0] = 1;
	int i,j;
	for(i = 2; i <= 4000; i++){
		permutations2[i][0] = 1;
		for(j = 1; j <= i; j ++){
			permutations2[i][j] = nCr(i, j);
		}
	}

	printf("\n%lld\n",permutations[8]);
	printf("\n%lld\n",permutations2[57][8]);
	return 0;
}


