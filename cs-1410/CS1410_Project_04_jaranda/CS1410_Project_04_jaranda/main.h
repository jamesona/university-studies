#pragma once

#include "Employee.h"

#include <iostream>
#include <iomanip>
#include <string>

// Function Name: printCheck
// Purpose: Prints itemized paycheck for employee
// Parameters: Employee employee
// Returns: none
// Pre-conditions: none
// Post-conditions: none
void printCheck(Employee employee);

// Function Name: centerText
// Purpose: Centers input text using pad characters
// Parameters: int width, string str, char fill
// Returns: string text
// Pre-conditions: none
// Post-conditions: none
std::string centerText(int width, const std::string& str, char fill);