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
	int calc = 0;
	int divisibleThree;
	char ch;
	int index = 0;
	printf("This program will read or recieve numbers and multiply 3 at a time\n");
	// if no arguments are passed wait for user input
	if(argc < 2){
		printf("Please enter in some numbers(crtld to stop): \n ");
		//loop to read input
		while(scanf("%15d",&nums[index]) == 1)
		{
			if(index >= MAXSIZE - 1)
			{
				printf("To many nums bro!... calculating what you have entered.\n");
				break;
			}else{
				index++;
			}
		}

		divisibleThree = index % 3;
		if(divisibleThree > 0)
		{
			index-=divisibleThree;
		}

		for(int i = 0; i < index; i+=3)
		{
			answer = nums[i] + nums[i+1] + nums[i+2];
			printf("Answer: %d + %d + %d = %d\n",nums[i],nums[i+1],nums[i+2],answer);
			calc++;
		}
		printf("Number of calculations: %d\n",calc);
	}else{
		FILE *fptr;
		fptr = fopen(argv[1], "r");
		if(fptr == NULL){
			printf("Cannot open file.");
			exit(0);
		}
		ch = fgetc(fptr);
		while(ch != EOF)
		{
			printf("%c", ch);
			ch = fgetc(fptr);
		}
		fclose(fptr);
	}//end else
	return 0;
}//main