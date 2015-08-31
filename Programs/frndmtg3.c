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

		
		double side1, side2, side3, side4;
		
		if(t1 >= T1){
			side1 = 0;
		}
		else
			side1 = T1 - t1;

		if(t2 >= T1){
			side2 = 0;
		}
		else
			side2 = T1 - t2;

		if(t1 >= T2){
			side3 = 0;
		}
		else
			side3 = T2 - t1;

		if(t2 >= T2){
			side4 = 0;
		}
		else
			side4 = T2 - t2;

		totalarea = ((T1) * (T2));

		if(T2 > T1){
			if(T1 + t1 <= T2){
				//totalarea = (T1 + t1) * T1;
				answer = ((T1*(T1+t1) - (((side2)*(side2)/2) + (T1*T1/2))) )/(totalarea);
			}
			else{
				answer = ( (T1*T2 - (( ((side2) * (side2))/2 ) + ( ((side3) * (side3))/2 ))) )/(totalarea);	
			}
		}
		
		else if(T1 > T2){
			if(T2 + t2 <= T1){
				//totalarea = (T2 + t2) * T2;
				answer = ((T2*(T2+t2) - (((side3)*(side3)/2) + (T2*T2/2))) )/(totalarea);
			}
			else{
				answer = ( (T1*T2 - (( ((side3) * (side3))/2 ) + ( ((side2) * (side2))/2 ))) )/(totalarea);	
			}
		}
		
		else{
			
			answer = (T1*T2 - ( (side2)*(side2)/2 + (side3)*(side3)/2 ))/(totalarea);
		}
		
		/*
		if(totalarea == 0 && t1 == 0 && t2 == 0){
			answer = 1.000000; 
		}
		if(totalarea == 0 && (t1 != 0 || t2 != 0)){
			answer = 0.000000;
		}
		*/
		

		if(answer > 1.000000){
			printf("1.000000\n");
		}
		else{
			printf("%.6f\n", answer);
		}
		tn++;
	}

	return 0;
}