//Noah Gillespie-Friesen and Brendan Johnston
#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

int main()
{
	int time = 0, hour = 0 , minute = 0 , dminute = 0;
	//dmintue stands for difference in minutes
	
	do
	//use a do while loop so that the user enters a value to be checked
{
	cout << "What is your first time?" << endl;
	cin >> time;
	hour = time/100;
	minute = time%100;
}
	while (hour>=24 || hour<0 || minute <0 || minute >= 60);
//assume that for times like 24:00 that the user will input 00:00
//assume for minutes such as 60, user will input 00
//assume that users will input times with 4 digits
	dminute = hour*60 + minute;
	
	do
{
	cout << "What is your second time?" << endl;
	cin >> time;
	hour = time/100;
	minute = time%100;
}
	while (hour>=24 || hour<0 || minute < 0 || minute >= 60);

	dminute -= hour*60 + minute;
	if (abs(dminute) == 1)
	//had to write case for 1 otherwise output would say 1 minutes
	{
	cout << "There is only 1 tiny minute between your two times, \n"
	"use your time wisely";
	}
	else if (dminute == 0)
	cout << "There is no time left between the two times";
	else
	cout << "There are " << abs(dminute) << " minutes between your two times.";
	//use abs because time between will be more easily understood if positive
	return EXIT_SUCCESS;
}
/* Case 1
What is your first time?
0060
What is your first time?
0000
What is your second time?
2400
What is your second time?
2359
There are 1439 minutes between your two times.
--------------------------------
Process exited after 31.09 seconds with return value 0
Press any key to continue . . .

Case 2
What is your first time?
2200
What is your second time?
2200
There is no time left between the two times
--------------------------------
Process exited after 15.97 seconds with return value 0
Press any key to continue . . .

Case 3
What is your first time?
0012
What is your second time?
0011
There is only 1 tiny minute between your two times,
use your time wisely
--------------------------------
Process exited after 3.862 seconds with return value 0
Press any key to continue . . .
*/
