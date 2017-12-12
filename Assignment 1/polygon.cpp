// Brendan Johnston
#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

int main()
{   
    int side_length = 0;

    cout << "Enter the length of each side (in cm): ";
    cin >> side_length;

    cout << "The area of a square of side length " << side_length
         << " is " << pow(side_length,2) << "cm^2" << endl;
    cout << "The volume of a cube of side length " << side_length
         << " is " << pow(side_length, 3) << "cm^3" << endl;
    cout << "The area of a pentagon of side length " << side_length << " is " 
		 <<  pow(side_length,2) * 0.25 * sqrt(25 + 10 * sqrt(5))
		 << "cm^3" << endl;
	
    return EXIT_SUCCESS;
}

/*
Enter the length of each side (in cm): 8
The area of a square of side length 8 is 64cm^2
The volume of a cube of side length 8 is 512cm^3
The area of a pentagon of side length 8 is 110.111cm^3

--------------------------------
Process exited after 5.611 seconds with return value 0
Press any key to continue . . .
*/

/*Why does this happen
Enter the length of each side (in cm): sqrt(64)
The area of a square of side length 0 is 0cm^2
The volume of a cube of side length 0 is 0cm^3
The area of a pentagon of side length 0 is 0cm^3

--------------------------------
Process exited after 6.514 seconds with return value 0
Press any key to continue . . .

*/

