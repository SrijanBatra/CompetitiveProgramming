#include<stdio.h>
#include<stdlib.h>

long long combinations[2000 + 10][2000 + 10];	//addressing: (row,sum)
long long permutations[2000 + 10];
long long permutationssums[2000 + 10];

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
        ans = ((ans%1000000000) * ((n - r + i)%1000000000))%1000000000;
        ans /= i;
    }
	permutations[nd] = ans;
}
/*
void calpermutations(int n, int k) {
    int nd;
    nd = n;
    n = n + k - 1;
    k = nd;
    
    long long r = 1;
    long long d;
    for (d = 1; d <= k; ++d) {
        r *= n--;
        r /= d;
    }
    //return r;
    permutations[nd] = r;
}
*/
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

		permutationssums[0] = 1;
		combinations[1][0] = 1;
		for(index = 1; index <= m; index ++){
			permutationssums[index] = permutations[index] + permutationssums[index-1];
			combinations[1][index] = permutationssums[index];
		}

		int tmpsum;
		int tmprowno = 2;
		for(tmprowno = 2; tmprowno <= n; tmprowno++){
			combinations[tmprowno][0] = 1;
			for(tmpsum = 1; tmpsum <= m; tmpsum++){
				combinations[tmprowno][tmpsum] = ((combinations[tmprowno][tmpsum]%1000000000 + (permutations[tmpsum]%1000000000 * combinations[tmprowno-1][tmpsum]%1000000000)%1000000000)%1000000000 + combinations[tmprowno][tmpsum-1]%1000000000)%1000000000;
			}
		}

		long long answer = combinations[n][m]%1000000000;
		if(answer < 0){
			answer = answer + (1000000000);
		}
		printf("%lld\n", answer);
		tn++;
	}

	return 0;
}