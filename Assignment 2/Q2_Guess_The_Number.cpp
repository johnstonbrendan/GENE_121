//Brendan Johnston and Kimath Kaai
#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

int main()
{
	int guess = 4;
	int i = 2;
	string answer_1 = "" , answer_2 = "";
	cout << "Choose a integer between 1 and 7 (inclusive) \n" ;
	//assume user will type one of the options
	while (i != 10 && i != -1)
	{
	cout << "My guess is " << guess << 
	"\nIs this guess that's correct, too high, or too low?\n";
	//assume user will type one of the options
	//options are "that's correct, too high, too low
	cin >> answer_1 >> answer_2;
	//used to allow for spaces
	if (answer_2 == "correct")
	{
		i=11;
		cout << "Gotcha";
	}
	else if (answer_2 == "low")
		guess += i;
	else if (answer_2 == "high")
		guess -= i;
	i--;
	}
	if (i!=10)
	cout << "You were lying this entire time, your number was not"
	<< " an integer between 1 and 7 (inclusive), I'm hurt :(";
	return EXIT_SUCCESS;
}

