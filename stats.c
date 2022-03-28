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
 * @file <Add File Name> 
 * @brief <Add Brief Description Here >
 *
 * <Add Extended Description Here>
 *
 * @author <Add FirsName LastName>
 * @date <Add date >
 *
 */



#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  






  /* Other Variable Declarations Go Here */
  unsigned int ar_lenght, mininum_value, maximum_value, *p_max, *p_min;
  float mean_value, median_value, *p_mean, *p_med;
  unsigned char *p_array;

  
  ar_lenght = sizeof(test);
  p_array= &test;
  p_max = &maximum_value;
  p_min = &mininum_value;
  p_mean = &mean_value;
  p_med = &median_value;


  /* Statistics and Printing Functions Go Here */
  print_array(p_array,ar_lenght);
  sort_array(p_array,ar_lenght);
  find_minimum(p_array, ar_lenght,p_min);
  find_maximum(p_array, ar_lenght,p_max);
  find_mean(p_array, ar_lenght,p_mean);
  find_median(p_array, ar_lenght,p_med);
  print_statistic(p_max,p_min,p_med,p_mean);

}


/* Add other Implementation File Code Here */

/***************************************************************
            FUNCTION SORT_ARRAY() DESCRIPTION        

    THIS FUNCTION ORDER ARRAY FROM SMALLER TO BIGGER VALUE

 ****************************************************************/

void sort_array(unsigned char *ar, unsigned int lenght ){

  unsigned int i, j, min;
  
  for (i = 0; i < lenght - 1; i++){
    min = i;

    for (j = i + 1; j < lenght; j++){
      if (ar[j] < ar[min]) {
       min = j;
      }
		}
  

        int tmp = ar[i];
        ar[i] = ar[min];
        ar[min] = tmp;
  }

  printf("Ordinate Array is: ");

  for(int k = 0; k < SIZE; k++){
    printf("%d ",ar[k]);}
  }

/***************************************************************
               FUNCTION FIND_MINIMUM() DESCRIPTION         

      THIS FUNCTION RETURNS THE MINIMUM VALUE IN ARRAY

 ****************************************************************/

void find_minimum(unsigned char *ar, unsigned int lenght, unsigned int *val){
  unsigned int i, min ;
  for(i = 0; i < lenght; i++ ){
    if(i == 0) min = ar[i];
    if(ar[i] < min) min = ar[i];
  }
  *val = min;
  
  
}

/***************************************************************
               FUNCTION FIND_MAXIMUM() DESCRIPTION         

      THIS FUNCTION RETURNS THE MAXIMUM VALUE IN ARRAY  

 ****************************************************************/

void find_maximum(unsigned char *ar, unsigned int lenght, unsigned int *val){
  unsigned int i, max ;
  for(i = 0; i < lenght; i++ ){
    if(i == 0) max = ar[i];
    if(ar[i] > max) max = ar[i];
  }
  
  *val = max;
  
}

/***************************************************************
               FUNCTION FIND_MEAN() DESCRIPTION         

      THIS FUNCTION RETURNS THE MEAN VALUE IN ARRAY  

 ****************************************************************/

void find_mean(unsigned char *ar, unsigned int lenght, float *val){
  unsigned int i, count;
  float mean;
  for(i = 0; i < lenght; i++ ){
      mean = mean + ar[i];
      count++;
  }
  mean = mean/40;
  *val = mean;
  
  
}

/***************************************************************
               FUNCTION FIND_MEDIAN() DESCRIPTION         

      THIS FUNCTION RETURNS THE MEDIAN VALUE IN ARRAY  

 ****************************************************************/
void find_median(unsigned char *ar, unsigned int lenght, float *val){

  float median, tmp;
  tmp = ar[lenght/2] + ar[(lenght/2)+1];
  median = tmp/2;
  *val = median;
  
  
}


/***************************************************************
               FUNCTION PRINT_STATISTIC() DESCRIPTION         

      THIS FUNCTION PRINT ALL STATISTIC OF ARRAY

 ****************************************************************/
void print_statistic(unsigned int *max, unsigned int *min, float *med, float *mean){

  printf("\nMinimum Value in Array is: ");
  printf("%d\n",*min);
  printf("Maximum Value in Array is: ");
  printf("%d\n",*max);
  printf("Median Value in Array is: ");
  printf("%f\n",*med);
  printf("Mean Value in Array is: ");
  printf("%f\n",*mean);

}


/***************************************************************
               FUNCTION PRINT_ARRAY() DESCRIPTION         

      THIS FUNCTION PRINT THE ARRAY

 ****************************************************************/
void print_array(unsigned char *ar, unsigned int lenght){

  printf("Original Array is: ");

    for(int k = 0; k < lenght; k++){
      printf("%d ",ar[k]);}
      printf("\n");
    

}
