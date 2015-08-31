#include<stdio.h>
#include<stdlib.h>


int main(){
	long long T;
	scanf("%lld",&T);
	long long tn = 1;	
	long long n;
	long long minx[100000 + 10];
	long long maxx[100000 + 10];
	long long miny[100000 + 10];
	long long maxy[100000 + 10];

	long long index = 0;
	long long j = 0;
	while(tn <= T){
		scanf("%lld", &n);
		long long answer[100000 + 10];
		for(index = 0; index < n; index++){
			answer[index] = 0;
			long long vertices;
			scanf("%lld", &vertices);			
			long long x;
			long long y;
			long long tmaxx, tminx;
			long long tmaxy, tminy;
			scanf("%lld %lld", &x, &y);
			tmaxx = x; tminx = x;
			tmaxy = y; tminy = y;
			for(j = 1;j < vertices; j++){
				scanf("%lld %lld", &x, &y);
				if(x > tmaxx) tmaxx = x;
				else if(x < tminx) tminx = x;

				if(y > tmaxy) tmaxy = y;
				else if(y < tminy) tminy = y;
			}
			minx[index] = tminx;
			maxx[index] = tmaxx;
			miny[index] = tminy;
			maxy[index] = tmaxy;
		}

		for(index = 0; index < n; index++){
			for(j = index;j < n; j++){
				if(minx[index] < minx[j]){
					if(maxx[index] > maxx[j]){
						if(miny[index] < miny[j] && maxy[index] > maxy[j]){
							answer[index]++;
						}
					}
					
				}
				else if(minx[j] < minx[index]){
					if(maxx[j] > maxx[index]){
						if(miny[j] < miny[index] && maxy[j] > maxy[index]){
							answer[j]++;
						}
					}
				}
			}
		}

		for(index = 0; index < n; index++){
			printf("%lld ", answer[index]);
		}
		printf("\n");
		tn++;
	}


	return 0;
}