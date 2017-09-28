#include<algorithm>

using namespace std

void enterGrade(string msg, int grade)
{
	do
	{
		cout << msg;
		cin >> grade;
		if (grade <= MAXGRADE && grade >= MINGRADE)
			good = true;
		else
		{
			cout << "Please enter a value between 0 & 100...\n";
			good = false;
		}
	} while (good == false);
}

int main()
{
	const int MAXGRADE 100;
	const int MINGRADE 0;
	
	vector<int> hmwrkGrades;
	int grades, gradeMT1, gradeMT2, gradeFinal, i, hmwrkMedian;
	bool good;

	cout << "Please enter exam grades: \n\n";

	enterGrade("Please enter the first midterm grade: \n", gradeMT1);

	cin.clear();
}

