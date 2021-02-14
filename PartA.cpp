//
//  PartA.cpp
//  3110_Assignment1
//
//  Created by Jonathan Sanchez on 2/17/20.
//  Copyright © 2020 Jonathan Sanchez. All rights reserved.
//
#include <iostream>
#include <stdio.h>
using namespace std;
#include "mergeSort.hpp"

void merge_sort(double *arr, int low, int high)
{
    int mid;
    if (low < high){
        //divide the array at middle and sort using merge sort
        mid=(low+high)/2;
        merge_sort(arr,low,mid);
        merge_sort(arr,mid+1,high);
        //merge sorted arrays
        merge(arr,low,high,mid);
        
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
