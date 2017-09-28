// Author: Jameson Aranda
// Assignment: Project_02
// Instructor: Craig Sharp
// Class: CS 1410 -- 002
// Date Written: 2/5/2017 4:53:48 PM
// Description: 

// I declare that the following code was written by me or provided
// by the instructor for this project. I understand that copying source
// code from any other source constitutes cheating, and that I will receive 
// a zero on this project if I am found in violation of this policy.

#include "stdafx.h"
#include "Prompt.h"
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>

using namespace std;

const string GRADE_LETTERS[] = { "A", "A-", "B+", "B", "B-", "C+", "C", "C-", "D+", "D", "D-" };
const int GRADE_STEP = 20, MAX_TOTAL = 400, MAX_SCORE = 100, TWO = 2;

string calculateGrades(int score, int iteration = 0)
{
	int max = MAX_TOTAL - (GRADE_STEP * iteration),
		min = max + 1 - GRADE_STEP;

	if (iteration > sizeof(GRADE_LETTERS) / sizeof(*GRADE_LETTERS) - 1)
	{
		return "Fail";
	}

	if (score < min)
	{
		return calculateGrades(score, ++iteration);
	}
	else if (score >= min && score <= max)
	{
		return GRADE_LETTERS[iteration];
	}	
};

int main()
{
	int inputBuffer, median, gradesLength, total,
		firstMidterm = Prompt::getInt("Enter first midterm score: ", 0, MAX_SCORE),
		secondMidterm = Prompt::getInt("Enter second midterm score: ", 0, MAX_SCORE),
		finalExam = Prompt::getInt("Enter final exam score: ", 0, MAX_SCORE);

	vector<int> grades;
	cout << "Enter grades separated by return key. Press Ctrl+Z to stop." << endl;
	cin.clear();
	cin.ignore();

	while (cin >> inputBuffer)
	{
		grades.push_back(inputBuffer);
	};

	sort(grades.begin(), grades.end());

	gradesLength = grades.size();

	cout << "You entered " << gradesLength << " scores." << endl;

	if (gradesLength == 1)
	{
		median = grades[0];
	} 
	else if (gradesLength % TWO == 0)
	{
		median = (grades[gradesLength / TWO] + grades[gradesLength / TWO - 1]) / TWO;
	}
	else {
		median = grades[gradesLength / TWO];
	};

	total = firstMidterm + secondMidterm + finalExam + median;

	cout << "The final grade is: " << calculateGrades(total) << " (" << total << "/" << MAX_TOTAL << ")" << endl;

	cout << "Press any key to exit." << endl;

	cin.clear();
	cin.get();
	return 0;
}

