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
 * @file <stats.h> 
 * @brief <Header file for the stats.c program>
 *
 * <The stats.h header file includes declarations and documentation
    for the functions from the stats.c file.Function declarations 
    for all required functions except main are provided. With each declaration 
    comments with a description of the function, the inputs, and return value
    have been provided>
 *
 * @author <Vijey Adhithya>
 * @date <23.5.20>
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/* Add Your Declarations and Function Comments here */ 

/**
 * @brief <Add Brief Description of Function Here>
 *
 * <Add Extended Description Here>
 *
 * @param <Add InputName> <add description here>
 * @param <Add InputName> <add description here>
 * @param <Add InputName> <add description here>
 * @param <Add InputName> <add description here>
 *
 * @return <Add Return Informaiton here>
 */

float find_mean(unsigned char *data,int size);
/*@brief <Finds mean of an array of floats>
  
  This function takes an unsigned char array and size of the array 
  as input parameters and returns a floating point number.

  @param unsigned char array pointer
  @param integer size of the array

  @return float mean of the array
*/

float find_maximum(unsigned char *data,int size);
/*@brief <finds maximum of an array of floats>
  
  This function takes a float array and size of the array
  as arguments and returns the maximum value as a float

  @param float array pointer
  @param interger size of the array

  @return float maximum of the array

*/

float find_minimum(unsigned char *data,int size);
/*@brief <finds minimum of an array of floats>
  
  This function takes a float array and size of the array
  as arguments and returns the minimum value as a float

  @param float array pointer
  @param interger size of the array

  @return float minimum of the array

*/


float find_median(unsigned char *data,int size);
/*@brief <finds maximum of an array of floats>
  
  This function takes a float array and size of the array
  as arguments and returns the median as a float

  @param float array pointer
  @param interger size of the array

  @return float median of the array

*/


void print_array(unsigned char *data,int size);
/*@brief <prints given array>
  
  This function takes a float array and size of the array
  as arguments and prints the array

  @param float array pointer
  @param interger size of the array

  @return void

*/

void sort_array(unsigned char *data,int size);
/*@brief <sorts given array>
  
  This function takes a float array and size of the array
  as arguments and sorts the array

  @param float array pointer
  @param interger size of the array

  @return void

*/


void print_statistics(unsigned char *data,int size);
/*@brief <prints statistics of given array>
  
  A function that prints the statistics of an array including minimum, maximum,
  mean, and median.

  @param unsigned char array pointer
  @param interger size of the array

  @return void

*/



#endif /* __STATS_H__ */
