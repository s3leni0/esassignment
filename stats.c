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

  unsigned int ar_lenght = sizeof(test);

  unsigned char *point;
  point = &test;


  sort_array(point,ar_lenght);

  find_minimum(point, ar_lenght);
  find_maximum(point, ar_lenght);
  find_mean(point, ar_lenght);
  find_median(point, ar_lenght);


  /* Other Variable Declarations Go Here */
  /* Statistics and Printing Functions Go Here */

}


/* Add other Implementation File Code Here */

/***************************************************************
                       FUNCTION DESCRIPTION        



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

void find_minimum(unsigned char *ar, unsigned int lenght){
  unsigned int i, min ;
  for(i = 0; i < lenght; i++ ){
    if(i == 0) min = ar[i];
    if(ar[i] < min) min = ar[i];
  }
  printf("\n Minimum Number is: %d", min);
  
}

void find_maximum(unsigned char *ar, unsigned int lenght){
  unsigned int i, max ;
  for(i = 0; i < lenght; i++ ){
    if(i == 0) max = ar[i];
    if(ar[i] > max) max = ar[i];
  }
  printf("\n Maximum Number is: %d", max);
  
}



void find_mean(unsigned char *ar, unsigned int lenght){
  unsigned int i, count;
  float mean;
  for(i = 0; i < lenght; i++ ){
      mean = mean + ar[i];
      count++;
  }
  mean = mean/40;
  printf("\n Mean Number is: %f", mean);
  
}


void find_median(unsigned char *ar, unsigned int lenght){

  float median, tmp;
  tmp = ar[lenght/2] + ar[(lenght/2)+1];
  median = tmp/2;
  printf("\n Median Number is: %f", median);
  
}