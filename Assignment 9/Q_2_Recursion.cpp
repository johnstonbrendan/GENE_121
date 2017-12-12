#include <iostream>
#include <cstdlib>

using namespace std;

int Guess (int max, int min, int & guess_number, 
							int & max_guesses, char answer)
{
	int current_guess = (max+min)/2;	
	cout << "Try" << endl; //debug

	if(guess_number == max_guesses)
	{
		return -1;
	}
	guess_number++;
	cout << "Is the numnber " << current_guess << endl
		<< "Input character 'Y'(Yes), 'H' (Higher), or 'L' (Lower)" << endl;
	if (guess_number + 1 == max_guesses && answer == 'H') // something like this so that when close use the alternatign guessses (ALSO SEE BELOW)
	{
		current_guess++;
	}
	if (guess_number + 1 == max_guesses && answer == 'L') //NEED TO ADD SOMETHING SO THAT DEPENDING ON USER INPUT IT GOES UP OR DOWN
	{
		current_guess--;
	}
	answer = 0;
	cin >> answer;
//	if (max-min && 'H')
//	{
//		return current_guess + 1;
//	}

	if (answer == 'Y')
	{
		return current_guess;
	}
	if (answer == 'H')
	{
		return Guess(max, current_guess, guess_number, 
					max_guesses, answer);
	}
	if (answer == 'L')
	{
		return Guess(current_guess, min, guess_number,
					 max_guesses, answer);
	}
}

int main()
{
	int max = 0, min = 0, guess_number = 0, previous_guess = 0;
	cout << "Please give me a maximum integer less than or equal 2147483647" 
		<< endl;
	cin >> max;
	cout << "Please give me a minimum integer larger than or equal –2147483648" 
		<< endl;
	cin >> min;
	int max_guesses = (max + min)/2 + 1, guess = -1;
	if ((max + min)%2)
	{
		max_guesses = (max + min)/2 + 2; //2 = ((10*(max + min)/2)%10)/5 + 1 GET RID OF THIS IF IT WORKSSSSW
	}
	
	char answer = 0;
	guess = Guess(max, min, guess_number, max_guesses, answer);
	if (guess == -1 || guess > max || guess < min)
	{
		cout << "Please don't lie to me\nIt's really not that hard to read" 
		" your mind.\nHumans are just worse computers anyways.\n";
		cout << "guess,,, debug is: " << guess << endl; //DEBUG
	}
	else
	{
		cout << "So your final number was " << guess << endl
			<< "I can't believe I got it in " << guess_number << " attempt(s)!"
			<< "\nThanks for choosing a nice number and have a great day\n";
	}
	main();
}

//DO I NEED TO IMPLEMENT SO IT DOESN'T GUESS THE SAME NUMBER TWICE AND TO DO SO EITHER
// BY ACTUALLY CHECKING OR BY ESTABLISHING MINIMUM NUMBER USING ODD AND EVEN FOR GUESS NUMBERS
