#include <stdio.h>
#include <stdlib.h>

int main(){
	long T;
	long tn = 1;
	scanf("%ld", &T);
	while(tn <= T){
		double T1,T2,t1,t2;
		scanf("%lf %lf %lf %lf", &T1, &T2, &t1, &t2);
		double answerA, answerB;
		double answerT;
		double totalarea;

		totalarea = (T1 * T2);
		
		if(T2 > T1){
			//answer = (T1*T1 - ((T1-t1)*(T1-t2)))/(T1*T1);
			//A arrives first.
			answerA = (((T1-t1)/T1) * t1/T2) + (t1/T1 * ((T2-T1) + t1)/T2);
			
			//B arrives first.
			answerB = (T1/T2 * t1/T1);

			answerT = answerA + answerB;
		}

		else if(T1 > T2){
			//answer = (T2*T2 - ((T2-t1)*(T2-t2)))/(T2*T2);
			//A arrives first.
			answerA = (T2/T1 * t2/T2);

			//B arrives first.
			answerB = (((T2-t2)/T2) * t2/T1) + (t2/T2 * ((T1-T2) + t2)/T1);

			answerT = answerA + answerB;
		}

		else{
			answerT = (totalarea - ((T1-t1)*(T2-t2)))/(totalarea);
		}

		printf("%.6f\n", answerT);
		tn++;
	}

	return 0;
}