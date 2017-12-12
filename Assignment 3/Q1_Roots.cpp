//Brendan Johnston and Noah Gillespie-Friesen
#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

int main()
{
	double x = -5;
	const double TOL = 0.0001;
	//just using brute force by checking then incrementing until success
	while (fabs(3*pow(x,5) + 11*pow(x,4) + 12*pow(x,3) -7*x + 5 ) >= TOL)
		x = x + 0.00001;
	//increment x by a smaller than tolerance value otherwise root is missed
	cout << x;
	return EXIT_SUCCESS;
	
}


/*
-2.09928
--------------------------------
Process exited after 0.1832 seconds with return value 0
Press any key to continue . . .
*/

