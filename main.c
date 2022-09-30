#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


int sumOfElAfterFirstNegative(int * array, int size){
	int sum = 0;
	int flag = 0;
	for(int i = 0 ; i < size ; i++){
		if(flag == 0){
			if(array[i] < 0){
				flag = 1;
			}
		} else {
			sum+= abs(array[i]);
		}
	}
	return sum;	
}

int countMoreThanAvg(int * array, int size, int avg){
	int count = 0;
	for(int i = 0 ; i < size ; i++){
		if(array[i] > avg){
			count++;
		}
	}
	return count;
}

int calculateAvg(int * array, int size){
	int sum = 0;
	for(int i = 0 ; i < size ; i++){
		sum+= array[i];
	}
	return sum / size;
}

void printArray(int * array, int size){
		for(int i = 0 ; i < size ; i++){
		printf("%d ", array[i]);
	}
}

void generateArray(int * array, int size){
		for(int i = 0 ; i < size ; i++){
		array[i] = (rand() % 100) - 50;
	}
}

int main(int argc, char *argv[]) {
	srand(time(NULL));
	int size = 5;
	int * array = calloc(size,sizeof(int));
	
	generateArray(array,size);
	printArray(array,size);
	
	int avg = calculateAvg(array,size);
	printf("\nAvg = %d", avg);
	
	printf("\nCount of more than avg = %d", countMoreThanAvg(array,size,avg));
	
	printf("\nSum of elements after first negative = %d", sumOfElAfterFirstNegative(array,size));
	
	free(array);
	
	return 0;
}