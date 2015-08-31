#include <stdio.h>
#include <stdlib.h>

int main(){
	long T;
	long tn = 1;
	scanf("%ld", &T);
	while(tn <= T){
		double T1,T2,t1,t2;
		scanf("%lf %lf %lf %lf", &T1, &T2, &t1, &t2);
		double answer;
		double totalarea;

		totalarea = (T1 * T2);
		
		if(T2 >= T1){
			if(T1 + t1 <= T2){
				answer = ((T1*T1 - ((T1-t2)*(T1-t2)/2) - ((T1-t1)*(T1-t1)/2)) + (t1*t1)/2)/(totalarea);
			}
			else{
				answer = ( (totalarea - (( ((T1-t2) * (T1-t2))/2 ) + ( ((T2-t1) * (T2-t1))/2 ))) )/(totalarea);	
			}
		}
		
		else if(T1 > T2){
			if(T2 + t2 <= T1){
				answer = ((T2*T2 - (((T2-t1)*(T2-t1)/2) + ((T2-t2)*(T2-t2)/2))) + ((t2*t2)/2))/(totalarea);
			}
			else{
				answer = ( (totalarea - (( ((T2-t1) * (T2-t1))/2 ) + ( ((T1-t2) * (T1-t2))/2 ))) )/(totalarea);	
			}

		}
		
		else{
			
			answer = (totalarea - ( (T1-t2)*(T1-t2)/2 + (T2-t1)*(T2-t1)/2 ))/(totalarea);
		}
		
		printf("%.6f\n", answer);
		tn++;
	}

	return 0;
}