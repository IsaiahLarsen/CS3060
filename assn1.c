/*
Isaiah Larsen
CS3060-601 Fall 2018
#1
I promise that this source code file has, in its entirety,
been written by myself and by no other person or persons.
If at any time an exact copy of this source code is found
to be used by another person in this term, I understand
that both myself and the student that submitted the
copy will receive a zero on this assignment.
*/

#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE  10

int main(int argc, char *argv[]){

	int nums[MAXSIZE];
	int answer = 0;
	FILE *fptr = stdin;
	int i = 0;
	printf("This program will read or recieve numbers and multiply 3 at a time\n");
	//read from file
	if(argc > 1){
		fptr = fopen(argv[1], "r");

		if(fptr == NULL){
			perror("Problem opening file: ");
			return -1;
		}

		while(fscanf(fptr, "%d%d%d", &nums[i],&nums[i+1],&nums[i+2]) == 3)
		{
			answer = nums[i] * nums[i+1] * nums[i+2];
			printf("Answer: %d * %d * %d = %d\n",nums[i],nums[i+1],nums[i+2],answer);
			i = 0;
		}//end of reading while loop
	//read stdin
	}else{
		while(scanf("%d%d%d", &nums[i],&nums[i+1],&nums[i+2]) == 3){
			answer = nums[i] * nums[i+1] * nums[i+2];
			printf("Answer: %d * %d * %d = %d\n", nums[i], nums[i+1], nums[i+2], answer);
			i = 0;
		}
	}
	return 0;
}//end main

