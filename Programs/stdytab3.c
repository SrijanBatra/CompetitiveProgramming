#include<stdio.h>
#include<stdlib.h>

long long combinations[2000 + 10][2000 + 10];	//addressing: (row,sum)
long long permutations[2000 + 10];
long long permutationssums[2000 + 10];
long long permutations2[4000 + 10][4000 + 10];

long long nCr(int n, int k) {
   long long answer;
   answer = permutations2[n-1][k] + permutations2[n-1][k-1];
   if(answer > 1000000000){
   		answer -= 1000000000;
   }
   return answer;
  
}

void calpermutations(){
	permutations2[0][0] = 1;
	permutations2[1][0] = 1;
	permutations2[1][1] = 1;
	int i,j;
	for(i = 2; i <= 4000; i++){
		permutations2[i][0] = 1;
		for(j = 1; j <= i; j ++){
			permutations2[i][j] = nCr(i, j);
		}
	}	
}

/*
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
*/

int main(){
	int T;
	int tn = 1;
	scanf("%d", &T);
	
	calpermutations();

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

		/*
		for(index = 0; index <= m; index ++){
			calpermutations(index, m);
			
		}
		*/

		permutationssums[0] = 1;
		combinations[1][0] = 1;
		for(index = 1; index <= m; index ++){
			permutationssums[index] = permutations2[index+m-1][index] + permutationssums[index-1];
			//permutationssums[index] = permutations[index] + permutationssums[index-1];
			if(permutationssums[index] > 1000000000){
				permutationssums[index] -= 1000000000;
			}
			combinations[1][index] = permutationssums[index];
		}

		int tmpsum;
		int tmprowno = 2;
		for(tmprowno = 2; tmprowno <= n; tmprowno++){
			combinations[tmprowno][0] = 1;
			for(tmpsum = 1; tmpsum <= m; tmpsum++){
				combinations[tmprowno][tmpsum] = ((permutations2[tmpsum+m-1][tmpsum] * (combinations[tmprowno-1][tmpsum]))%1000000000 + combinations[tmprowno][tmpsum-1] + combinations[tmprowno][tmpsum])%1000000000;
				//combinations[tmprowno][tmpsum] += (permutations[tmpsum] * combinations[tmprowno-1][tmpsum]) + combinations[tmprowno][tmpsum-1];
			}
		}

		long long answer = combinations[n][m];
		if(answer < 0){
			answer = answer + (1000000000);
		}
		printf("%lld\n", answer);
		tn++;
	}

	return 0;
}