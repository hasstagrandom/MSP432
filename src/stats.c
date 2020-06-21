/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file <Main program file for stats> 
 * @brief <Program to calculate various statistics for an array>
 *
 * <
 *The following functions have been defined:
 *
 *main() - The main entry point for your program
  print_statistics() - A function that prints the statistics of an array including minimum, maximum, mean, and median.
  print_array() - Given an array of data and a length, prints the array to the screen
  find_median() - Given an array of data and a length, returns the median value
  find_mean() - Given an array of data and a length, returns the mean
  find_maximum() - Given an array of data and a length, returns the maximum
  find_minimum() - Given an array of data and a length, returns the minimum
  sort_array() - Given an array of data and a length, sorts the array from largest to smallest.
  (The zeroth Element should be the largest value, and the last element (n-1) should be the smallest value. )>
 *
 * @author <BS VIJEY ADHITHYA>
 * @date <23.5.20>
 *
 */



#include <stdio.h>
#include "stats.h"
#include "platform.h"

/* Size of the Data Set */
#define SIZE (40)

/*
void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  // Other Variable Declarations Go Here 

  // Statistics and Printing Functions Go Here 
  print_array(test,SIZE);
  print_statistics(test,SIZE);
  print_array(test,SIZE);

}

 Add other Implementation File Code Here 

*/




float find_maximum(unsigned char *data,int size){
	float max=data[0];
	for(int i =0;i<size;i++){
		if((float)data[i]>max){
			max=data[i];
		}
	}
	return max;
}


float find_minimum(unsigned char *data,int size){
	float min=data[0];
	for(int i =0;i<size;i++){
		if((float)data[i]<min){
			min=data[i];
		}
	}
	return min;
}

float find_mean(unsigned char* data,int size){
	float total=0.0;
	for(int i=0;i<size;i++){
		total+=(float)data[i];
	}
	if (size!=0){
		return total/size;
	}
	else{
		return 0;
	}
}

void sort_array(unsigned char* data,int size){
	for(int i =0;i<size;i++){
		for(int j=i;j<size;j++){
			if (((int)data[j])>((int)data[i])){
				char temp=data[i];
				data[i]=data[j];
				data[j]=temp;
			}
			
		}
	}
}

float find_median(unsigned char* data,int size){
	sort_array(data,size);
	if (size%2==0){

		return (float)data[size/2];
	
	}else{
		return ((float)data[size/2]+(float)data[(size/2)+1])/2;
	}
}
void print_array(unsigned char* data,int size){
	for(int i =0;i<size;i++){
		
#ifdef VERBOSE
		PRINTF("%d ",data[i]);

#endif
	}
	
}

void print_statistics(unsigned char* data,int size){
	PRINTF("Mean:%.2f,Median:%.2f,min:%.2f,max:%.2f\n",find_mean(data,size),find_median(data,size),find_minimum(data,size),find_maximum(data,size));
}




