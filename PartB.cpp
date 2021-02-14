//
//  PartB.cpp
//  3110_Assignment1
//
//  Created by Jonathan Sanchez on 2/17/20.
//  Copyright © 2020 Jonathan Sanchez. All rights reserved.
//
#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
#include "mergeSort.hpp"

void merge_sort(double *arr, int low, int high)
{
    int mid;
    if (low < high){
        //divide the array at middle and sort using merge sort
        mid=(low+high)/2;
        if (high-low <= 8) {
            insertion_sort(arr, high);
        }
        else
        {
        merge_sort(arr,low,mid);
        merge_sort(arr,mid+1,high);
        //merge sorted arrays
        merge(arr,low,high,mid);
        }
    }
}
void merge(double *arr, int low, int high, int mid)
{
    int i, j, k, c[500];
    i = low;
    k = low;
    j = mid + 1;
    while (i <= mid && j <= high) {
        if (arr[i] < arr[j]) {
            c[k] = arr[i];
            k++;
            i++;
        }
        else  {
            c[k] = arr[j];
            k++;
            j++;
        }
    }
    while (i <= mid) {
        c[k] = arr[i];
        k++;
        i++;
    }
    while (j <= high) {
        c[k] = arr[j];
        k++;
        j++;
    }
    for (i = low; i < k; i++)  {
        arr[i] = c[i];
    }
}
void insertion_sort(double *arr, int amountOfNumbers) //passing in an array and array size.
{
   int i, key, j;
     for (i = 1; i <= amountOfNumbers; i++)
     {
         key = arr[i];
         j = i - 1;
   
         /* Move elements of arr[0..i-1], that are
         greater than key, to one position ahead
         of their current position */
         while (j >= 0 && arr[j] > key)
         {
             arr[j + 1] = arr[j];
             j = j - 1;
         }
         arr[j + 1] = key;
     }
    
}
