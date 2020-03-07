#include <iostream>
#include "Queue.h"
#include "Utility.h"
using namespace std;


void introduction();

int separate_input(Queue& test_queue1, Queue& test_queue2);
char compare_queues(int no_of_colons, Queue& test_queue1, Queue& test_queue2);

int main()
{
	Queue test_queue1;
	Queue test_queue2;
	int no_of_colons;
	char output;
	char end_game;


	introduction();


	do // keep playing until player wants to quit
	{
		no_of_colons = separate_input(test_queue1, test_queue2);
		output = compare_queues(no_of_colons, test_queue1, test_queue2);

		cout << output << endl;

		do
		{
			cout << "Do you wanna keep checking? [Y/N]: ";
			cin >> end_game;
			cout << endl;
		} while (end_game != 'Y' && end_game != 'y' && end_game != 'N' && end_game != 'n');


	} while (end_game == 'Y' || end_game == 'y');

}

int separate_input(Queue& test_queue1, Queue& test_queue2) {
	
	string input;
	int no_of_colons = 0;

	do { //do this atlest once, but continue doing this if there is more than 1 colons
		if (no_of_colons != 2) // if there is not 2 colons
			cout << "Enter strings separating it with one colon ':'." << endl
			<< "Input: ";
		else //else reset the no_of_colons to 0
			no_of_colons = 0;

		cin >> input;

		for (int i = 0; i < input.length(); i++) { 
			if (no_of_colons == 0) { //if there is no colons
				if (input.at(i) != ':')
					test_queue1.append(input.at(i)); //add the char to the queue
				else { //else reset the no_of_colons to 1
					no_of_colons = 1;
				}
			}
			else { //if there is a colon
				if (input.at(i) != ':')
					test_queue2.append(input.at(i)); //add the char to the another string
				else { //else reset the no_of_colons to 2, later it will get reseted again to 0 and makes player to enter a new string
					no_of_colons = 2; 
					cout << "Provided string has more than one ':' in it, please provide a string with the correct format." << endl << "INPUT - ";
					break;
				}
			}
		}

	} while (no_of_colons > 1);

	return no_of_colons; //return int 
}

char compare_queues(int no_of_colons, Queue& test_queue1, Queue& test_queue2)
{
	Queue_entry Q1, Q2;
	char output;

	int size1 = test_queue1.size();
	int size2 = test_queue2.size();

	if (no_of_colons == 0) //if string doesn't have colon, print 'N'
		output = 'N';
	else {
		if (size1 == size2) { //if strings has the same length
			for (int i = 0; i < size1; i++) {
				test_queue1.retrieve(Q1); //take the value to Q1
				test_queue2.retrieve(Q2);

				if (Q1 == Q2) { //if they are completely same, print 'S'
					output = 'S';
				}
				else { //else --> they are different, print 'D'
					output = 'D'; 
					break;
				}

				test_queue1.serve(); //remove the first char, so on next round it will show the next char
				test_queue2.serve();
			}
		}
		if (size1 > size2) //if left is longer, print 'L'
			output = 'L';
		if (size1 < size2)
			output = 'R'; //if right is longer, print 'R'

	}
	for (int i = 0; i < size1; i++) { //clear both queues
		test_queue1.serve();
	}
	for (int i = 0; i < size2; i++) {
		test_queue2.serve();
	}

	return output; //return char
}

void introduction()
{
	cout << "This program will compare your strings. Possible outputs are: " << endl;

	cout << "N        No colon on the line." << endl
		<< "L        The left part is longer than the right." << endl
		<< "R        The right part is longer than the left." << endl
		<< "D        The left and right parts have the same length but are different." << endl
		<< "S        The left and right parts are exactly the same." << endl << endl;

}