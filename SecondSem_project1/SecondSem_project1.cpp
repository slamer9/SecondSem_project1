// SecondSem_project1.cpp : Defines the entry point for the console application.
// Author Duncan Reeves, CP2, C++

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;


double CalcMarTax(unsigned int income)
{
	unsigned int toSubtract;
	double taxRate;
	unsigned int toAdd;
	double tax;

	if (income <= 1726)
	{
		toSubtract = 0;
		taxRate = 0.022;
		toAdd = 0;
	}
	else if (income <= 5176)
	{
		toSubtract = 1726;
		taxRate = 0.033;
		toAdd = 40;
	}
	else if (income <= 8626)
	{
		toSubtract = 5176;
		taxRate = 0.062;
		toAdd = 175;
	}
	else if (income > 8626)
	{
		toSubtract = 8626;
		taxRate = 0.075;
		toAdd = 390;
	}

	tax = ((income - toSubtract)* taxRate) + toAdd;
	return tax;
}
double CalcSingTax(unsigned int income) 
{
	unsigned int toSubtract;
	double taxRate;
	unsigned int toAdd;
	double tax;

	if (income <= 863)
	{
		toSubtract = 0;
		taxRate = 0.022;
		toAdd = 0;
	}
	else if(income <= 2588)
	{
		toSubtract = 863;
		taxRate = 0.033;
		toAdd = 25;
	}
	else if (income <= 4313)
	{
		toSubtract = 2588;
		taxRate = 0.062;
		toAdd = 85;
	}
	else if (income > 4313)
	{
		toSubtract = 4313;
		taxRate = 0.075;
		toAdd = 181;
	}

	tax = ((income - toSubtract)* taxRate) + toAdd;
	return tax;
}

double CalculateTax(int income)
{
	string garbageString;
	char married;
	bool validMS = false;
	double tax;


	cout << "Are you filing married/jointly, or single/seperate? [Enter an M or S]  ";
	while (validMS == false)
	{
		if (cin >> married)
		{

			if (married == 'M' || married == 'm')
			{
				validMS = true;
				cout << endl << "You are filing married." << endl;
				tax = CalcMarTax(income);
			}
			else
				if (married == 'S' || married == 's')
				{
					validMS = true;
					cout << endl << "You are filing single." << endl;
					tax = CalcSingTax(income);
				}
				else 
				{
					cout << "Error, enter an 'M or an 'S'" << endl;
				}
		}
		else
		{
			cout << "Error, enter an 'M' character or an 'S' charatcter" << endl;
			cin.clear();
			cin >> garbageString;
		}
	}
	return tax;
}


int main()
{
	string garbageString;
	unsigned int taxableIncome;
	bool goodInput = false;
	double tax;
	bool doAgain = false;
	char doAnother;

	do
	{
		cout << "Enter your taxable income.  ";
		while (goodInput == false)
		{
			if (cin >> taxableIncome)
			{
				goodInput = true;
			}
			else
			{
				cout << "Error, could not read input.  Enter a positive, real number in decimal form." << endl;
				cin.clear();
				cin >> garbageString;
			}
		}

		tax = CalculateTax(taxableIncome);
		cout << "And your taxable income is $" << taxableIncome << endl <<
			"So your income tax will be $" << tax << endl;

		cout << endl << "Do you want to do another calculation? ";
		while (goodInput)
		{
			if (cin >> doAnother)
			{
				if (doAnother == 'Y' || doAnother == 'y')
				{
					goodInput = false;
					doAgain = true;
				}else
					if (doAnother == 'N' || doAnother == 'n')
					{
						goodInput = false;
						doAgain = false;
						cout << "Bye." << endl;
						//return 0;
					}
					else
					{
						cout << "Error, enter a [Y] or an [N]." << endl;
						cin.clear();
					}
			}
			else
			{
				cout << "Error, enter a [Y] or an [N]." << endl;
				cin.clear();
				cin >> garbageString;
			}
		}
	} while (doAgain == true);


    return 0;
}