//
//  main.cpp
//  3110_Assignment1
//
//  Created by Jonathan Sanchez on 2/16/20.
//  Copyright © 2020 Jonathan Sanchez. All rights reserved.
//

#include <iostream>
#include <sstream>
#include <fstream>
#include <array>
#include "mergeSort.hpp"
using namespace std;

int main()
{
    string line;
    int amountOfNumbers;
    int numOfLines = 0;
    
    ifstream myfile ("data1.txt");
    ofstream outFile;
    outFile.open("out1.txt"); 
    if (myfile.is_open())
     {
       while ( getline (myfile,line))
       {
           amountOfNumbers = 0;
           double arr[500];
           stringstream ss(line);
           int value;
           numOfLines++;
           
           while (ss>>value)
           {
               arr[amountOfNumbers++] = value;
           }
	   cout << endl;
         cout << "Line " << numOfLines << ": "<< line << endl;
           
           merge_sort(arr, 0, amountOfNumbers-1);

           outFile << "\nSorted Line " << numOfLines << ": ";
           cout<<"\nSorted Line " << numOfLines << ": ";
           for (int i = 0; i < amountOfNumbers; i++)
           {
               outFile << arr[i] << ", ";
               cout<< arr[i]<<", ";
           }

	   cout << endl;
       }
       myfile.close();
     }
     else cout << "Unable to open file";
    
    //outFile.open("out1.txt");
}
