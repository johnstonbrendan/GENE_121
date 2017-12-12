//Brendan Johnston
#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

int main()
{
	int pizzas;
	double radius = 17.0;
	// radius in cm
	
	cout << "You've decided to host a most excellent pizza party \n"
		"Please tell me how many pizzas you will order? \n";
	
	cin >> pizzas;
	int students;
	
	cout << "Boy what a great number \n"
		 "How  many lucky students will be having these pizzas? \n";
	
	cin >> students;
	if (students == 0)
		cout << "That's quite the turn out";
	else
	{
	
	double SA_per_student = pow(radius,2)*M_PI*pizzas/students;
	
	cout << "For some reason my purpose was to calculate the surface area \n"
		 "of pizza consumed by each student while assuming all students ate \n"
		 "the same amount each, however this is never the case because there \n"
		 "are always those people who try to get more than others and always \n"
		 "choose the bigger slices, when here I am, choosing the smaller \n"
		 "slice so that next time I can have a larger slice, \n"
		 "and by that time all the large slices are gone... \n"
		 "But contemplating this assumption is not my purpose \n"
		 "so here is your silly number " << SA_per_student << "cm^2" << endl;
	}
	
	return EXIT_SUCCESS;
	
	
	
}

/*
CASE 1
You've decided to host a most excellent pizza party
Please tell me how many pizzas you will order?
22
Boy what a great number
How  many lucky students will be having these pizzas?
11
For some reason my purpose was to calculate the surface area
of pizza consumed by each student while assuming all students ate
the same amount each, however this is never the case because there
are always those people who try to get more than others and always
choose the bigger slices, when here I am, choosing the smaller
slice so that next time I can have a larger slice,
and by that time all the large slices are gone...
But contemplating this assumption is not my purpose
so here is your silly number 1815.84cm^2

--------------------------------
Process exited after 9.214 seconds with return value 0
Press any key to continue . . .

*/

/*
CASE 2
You've decided to host a most excellent pizza party
Please tell me how many pizzas you will order?
5
Boy what a great number
How  many lucky students will be having these pizzas?
9
For some reason my purpose was to calculate the surface area
of pizza consumed by each student while assuming all students ate
the same amount each, however this is never the case because there
are always those people who try to get more than others and always
choose the bigger slices, when here I am, choosing the smaller
slice so that next time I can have a larger slice,
and by that time all the large slices are gone...
But contemplating this assumption is not my purpose
so here is your silly number 504.4cm^2

--------------------------------
Process exited after 26.63 seconds with return value 0
Press any key to continue . . .
*/

/*
CASE 3
You've decided to host a most excellent pizza party
Please tell me how many pizzas you will order?
6
Boy what a great number
How  many lucky students will be having these pizzas?
0
That's quite the turn out
--------------------------------
Process exited after 5.993 seconds with return value 0
Press any key to continue . . .
*/


