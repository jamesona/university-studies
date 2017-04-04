#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

// Function Name: mySort
// Purpose: sort an array of integers
// Parameters: int[] nums, int nelems, int begin
// Returns: none
// Pre-conditions: a populated array is required
// Post-conditions: the array is sorted in ascending order
void mySort(int* nums, int nelems, int begin);

// Function Name: hiloLogic
// Purpose: perform recursive logic for the hilo function
// Parameters: int lower, int upper
// Returns: none
// Pre-conditions: none
// Post-conditions: none
void hiloLogic(int lower, int upper);


// Function Name: hilo
// Purpose: a guessing game based on lambda calculus
// Parameters: int size
// Returns: none
// Pre-conditions: none
// Post-conditions: none
void hilo(int size);