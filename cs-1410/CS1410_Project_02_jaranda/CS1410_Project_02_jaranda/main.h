#pragma once
#include "Prompt.h"
#include <string>

// Function Name: main
// Purpose: main function scope
// Parameters: none
// Returns: none
// Pre-conditions: none
// Post-conditions: none
int main();

// Function Name: calculateGrades
// Purpose: Get a letter grade from a score
// Parameters: int score, int iteration
// Returns: string grade
// Pre-conditions: none
// Post-conditions: none
std::string calculateGrades(int score, int iteration);