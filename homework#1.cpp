// ConsoleApplication8.cpp : Defines the entry point for the console application.
/*Clarisse Ilibagiza Umulisa With the Help of Dr Donald Simon
September 12th 2019
program name:homework#1
Program to print states and its corresponding city in alphabetic order
Variable declaration:
stcity[]:array that stores states and cities
citstates:string used to input states and cities
*p:pointer to the stcity array
prev:string to store cities
sub:string to store states
*/

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;
// function of sorting string of state and city
void insertSort(string* low, string* high) {
	for (string *p = low + 1; p <= high; p++) {
		string t = *p, *q = p;
		while (q > low && *(q - 1) > t) {
			*q = *(q - 1);
			q--;
		}
		*q = t;
   }
}

int main() {
	string stcity[100];
	string citstates;
	string *p = stcity;
	string prev, sub;
	//entering the states and cities
	cout << "Enter city and corresponding state: \n";
	while (getline(cin, citstates)) {
		//find the delimiter
		int s = citstates.find(',');
		//splitting into state and city
		sub = citstates.substr(s + 1);
		prev = citstates.substr(0, s);
		//combining in a format of states then city
		*p = sub + "," + prev;
		p++;
	}
	//calling the sorting function
	insertSort(stcity, p - 1);
	//Initialising the previous state stored
	string last = "";
	 
	//output
	for (string *q = stcity; q < p; q++) {
		//find the deliminiter
		int a = q->find(',');
		//split into state and city
		prev = q->substr(a + 1);
		sub = q->substr(0, a);
		//checking if 2 cities are the same
		
			if (last == sub)
				cout << ',' << prev;
			else
				cout <<endl << sub << ":" << prev;
			last = sub;
		}
	}

