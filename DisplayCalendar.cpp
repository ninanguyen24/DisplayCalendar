/*Nina Nguyen
Program 1: Display Calendar
April 10, 2017
CS 212
*/

/*(Display calendars) Write a program that prompts the user to enter the year
and first day of the year and displays the calendar table for the year on the console.
For example, if the user entered the year 2013 and 2 for Tuesday, January 1, 2013,
your program should display the calendar for each month in the year, as follows:

Liang, Y. Daniel. Introduction to Programming with C++ (Page 198). Pearson Education. Kindle Edition. */

#include <string>
#include <iomanip>
#include <iostream>
using namespace std;

//function prototypes;
int daysInTheMonth(int year, int month);
bool isLeapYear(int year);
string printMonthName(int month);
void printCalendar(int month[], int year, int startDay, int size);
int daysInTheMonth(int year, int month);


int main() {
	int month[12] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };//Instead of a string, i used int for the array
	int arraySize = sizeof(month) / sizeof(month[0]);//get size of array for month
	string daysOfTheWeek[7] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };

	cout << "What year do you want the calendar to display? " << endl;
	int year;
	cin >> year;

	cout << "What is the first day of the year? (0 for Sunday, 1 for Monday, 2 for Tuesday..."
		"6 for Saturday) " << endl;
	int startDay;
	cin >> startDay;

	printCalendar(month, year, startDay, arraySize);

}


void printCalendar(int month[], int year, int startDay, int size) {
	for (int i = 0; i < size; i++) {//get the right array length

		cout << "   " << printMonthName(month[i]) << " " << year << "   " << endl;
		cout << "------------------------------------------" << endl;
		cout << " Sun Mon Tue Wed Thu Fri Sat" << endl;

		if (month[0] == 1) {
			for (int x = 0; x < startDay; x++) { //Prints spaces according to startdate
				cout << "    ";
			}
		}
		else {
			//something to make the calendar align correctly????
		}
		int numberOfDays = daysInTheMonth(year, month[i]);
		for (int j = 1; j <= daysInTheMonth(year, month[i]); j++) {//less than or equal to get the right # of days

			cout << setw(4) << j;
			if ((j + startDay) % 7 == 0) {
				cout << endl;
			}

		}
		cout << endl;
		cout << endl;
	}
}




string printMonthName(int month) {
	switch (month) {
	case 1: return "January";
		break;
	case 2: return "February";
		break;
	case 3: return "March";
		break;
	case 4: return "April";
		break;
	case 5: return "May";
		break;
	case 6: return "June";
		break;
	case 7: return "July";
		break;
	case 8: return "August";
		break;
	case 9: return "September";
		break;
	case 10: return "October";
		break;
	case 11: return "November";
		break;
	case 12: return "December";
		break;
	}
}

int daysInTheMonth(int year, int month) {

	if (month == 4 || month == 6 || month == 9 || month == 11) {
		return 30;
	}
	else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
		return 31;
	}
	else { // Month == 2
		if (!isLeapYear(year)) {
			return 28;
		}
		else {
			return 29;
		}
	}
	return 0;
}

bool isLeapYear(int year) {
	return year % 400 == 0 || (year % 4 == 0 && year % 100 != 0);
}


