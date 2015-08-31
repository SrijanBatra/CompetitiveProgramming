#include<stdio.h>
#include<stdlib.h>

long long combinations[2000 + 10][2000 + 10];
long long permutations[2000 + 10];
/*
long long C(int n, int r) {
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

    return ans;
}
*/
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

long long lookup(int sum, int row){
	
}

int main(){
	int T;
	int tn = 1;
	scanf("%d", &T);

	while(tn <= T){
		int n,m;	
		scanf("%d %d", &n, &m);
		int index;
		permutations[0] = 1;
		
		int i = 0,j = 0;
		for(i = 0;i <= n;i++){
			for(j = 0;j <= m;j++){
				combinations[i][j] = 0;
			}
		}

		for(index = 0; index <= m; index ++){
			calpermutations(index, m);
		}

		long long answer = 0;
		for(index = 0; index <= m; index++){
			answer += lookup(index,m);
		}
		printf("%lld\n", answer);
		tn++;
	}

	return 0;
}