#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
#define black 1
#define blue 2
#define red 3
#define green 4
#define yellow 5
#define orange 6
*/

int main(){
	long T;
	scanf("%ld", &T);
	long tn = 1;
	//front back left right top bottom
	int array[7];
	int ret;
	char string[10];

	while(tn <= T){
		int sides = 1;

		for(sides = 1;sides <= 6;sides++){
			scanf("%s", string);
			if((ret = strcmp(string, "black")) == 0){
				array[sides] = 1;
			}
			else if((ret = strcmp(string, "blue")) == 0){
				array[sides] = 2;
			}
			else if((ret = strcmp(string, "red")) == 0){
				array[sides] = 3;
			}
			else if((ret = strcmp(string, "green")) == 0){
				array[sides] = 4;
			}
			else if((ret = strcmp(string, "yellow")) == 0){
				array[sides] = 5;
			}
			else if((ret = strcmp(string, "orange")) == 0){
				array[sides] = 6;
			}
		}
		int answer = 0;
		//for three adj either front or back or both involved.
		//front
		
		if(array[3] == array[1] || array[4] == array[1]){ //left or right
			if(array[5] == array[1] || array[6] == array[1])
				answer = 1;
		}	
		

		//back
		if(array[3] == array[2] || array[4] == array[2]){ //left or right
			if(array[5] == array[2] || array[6] == array[2])
				answer = 1;
		}
		if(answer == 1)
			printf("YES\n");
		else
			printf("NO\n");
		tn++;
	}

	return 0;
}