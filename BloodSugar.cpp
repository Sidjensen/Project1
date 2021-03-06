// BloodSugar.cpp : Defines the entry point for the console application.
// Sidney Jensen
// 10/26/18
// COSC 2030
// got help for passing arrays into a function from: 
//http://www.ntu.edu.sg/home/ehchua/programming/cpp/cp4_pointerreference.html

#include "stdafx.h"
#include "LinkedList.h"
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::getline;


string weekSum(List *weekNum, int day);
int weekMax(List *weekNum, int day);
int weekMin(List *weekNum, int day);
int weekCount(const List *weekNum, int day);
int weekDelta(const List *weekNum, int day);

int main()
{
	// creates linked lists for each day
	List zero, one, two, three, four, five, six, seven, eight, nine, ten, eleven, twelve, thirteen;

	// arrays of linked lists for each week
	List week1[7] = { zero, one, two, three, four, five, six };
	List week2[7] = { seven, eight, nine, ten, eleven, twelve, thirteen };

	// for the input, and to change to numbers
	string input;
	int temp = 0;

	// to keep track of what day/ week currently on
	int day = 0;
	int week = 1;

	// To keep program running until done
	bool end = false;

	while (end == false)
	{
		cout << "Welcome to your blood sugar collector.\n Today is day " << day << " of week " << week
			<< "\nPlease enter your blood sugar levels, or enter D for a daliy summary, W for a weekly summary, or N for the next day.\n Or type E to exit" 
			<< endl;

		getline(cin, input);

		if (input == "D")
		{
			if (week == 1)
			{
				cout << "todays current sum: " << week1[day].sum() << endl;// calls the function to get the sum for the current day, below are similar
				cout << "todays current max: " << week1[day].max() << endl;
				cout << "todays current min: " << week1[day].min() << endl;
				cout << "todays current count of Blood Sugar readings: " << week1[day].size() << endl;
			}
			else if (week == 2)
			{
				cout << "todays current sum: " << week2[day].sum() << endl;
				cout << "todays current max: " << week2[day].max() << endl;
				cout << "todays current min: " << week2[day].min() << endl;
				cout << "todays current count of Blood Sugar readings: " << week2[day].size() << endl;
			}
		}
		else if (input == "W")
		{
			// get current week
			if (week == 1)
			{
				cout << "this week's current sum: " << weekSum(week1, day) << endl;
				cout << "this week's current max: " << weekMax(week1, day) << endl;
				cout << "this week's current min: " << weekMin(week1, day) << endl;
				cout << "this week's current count of Blood Sugar readings: " << weekCount(week1, day) << endl;
				cout << "this week's current greatest day-to-day delta: " << weekDelta(week1, day) << endl;
			}
			else if (week == 2)
			{
				//call whatever to get data
				cout << "this week's current sum: " << weekSum(week2, day) << endl;
				cout << "this week's current max: " << weekMax(week2, day) << endl;
				cout << "this week's current min: " << weekMin(week2, day) << endl;
				cout << "this week's current count of Blood Sugar readings: " << weekCount(week2, day) << endl;
				cout << "this week's current greatest day-to-day delta: " << weekDelta(week2, day) << endl;
			}
		}
		else if (input == "N")
		{
			if (day == 6)
			{
				if (week == 1)
				{
					week = 2;
					day = 0;
				}
				else
				{
					cout << "End of two weeks, can no longer go to the next day.\n" << endl;
				}
			}
			else
			{
				day += 1;
			}
		}
		else if (input == "E")
		{
			end = true;
		}
		else
		{
			// turn string into a number;
			temp = atoi(input.c_str()); // got  this line from http://www.cplusplus.com/forum/general/13135/
			if (temp > 0)
			{
				//if 0 or neg, goes back to begining of statment
				if (week == 1)
				{
					week1[day].insertAsFirst(temp);
				}
				else
				{
					week2[day].insertAsFirst(temp);
				}
			}
		}
	}
    return 0;
}

string weekSum(List *weekNum, int day)
{
	string sumAndRemainder;
	int over = 0;
	int sum = 0;
	int size = day + 1;
	for (int i = 0; i < size; i++)
	{
		sum += weekNum[i].sum(); // figure out how to pass array into function
		if (sum < 0)
		{
			sum = sum - 2147483647;// takes sum back to the begining.
			over += 1;// counts number of times it overflows
		}
	}
	sumAndRemainder = "2,147,483,647 * " + std::to_string(over) + " + " + std::to_string(sum);
	return sumAndRemainder;
}

int weekMax(List *weekNum, int day)
{
	int max = 0;
	int size = day + 1;
	for (int i = 0; i < size; i++)
	{
		if (weekNum[i].max() > max)
		{
			max = weekNum[i].max();
		}
	}
	return max;
}

int weekMin(List *weekNum, int day)
{
	int min = 2147483647;//every possible int is below this, so should be able to get correct min.
	int size = day + 1;
	for (int i = 0; i < size; i++)
	{
		if (weekNum[i].min() < min)
			{
				min = weekNum[i].min();
			}
	}
	return min;
}

int weekCount(const List *weekNum, int day)
{
	int size = 0;
	int dayNum = day + 1;
	for (int i = 0; i < dayNum; i++)
	{
		size += weekNum[i].size();
	}
	return size;
}

int weekDelta(const List *weekNum, int day)
{
	int delta = 0;
	int tempVal = 0;
	int size = day + 1;
	if (day != 0)
	{
		for (int i = 1; i < size; i++) // can't calucate tempVal if i = 0, so excluding it.
		{
			tempVal = weekNum[i].size() - weekNum[i - 1].size();
			//Calcuate the bigest delta, comparing sizes of the sizes
			if (tempVal > delta)
			{
				delta = tempVal;
			}
		}
	}
	return delta;
}
