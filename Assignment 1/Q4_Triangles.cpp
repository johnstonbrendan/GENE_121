//Brendan Johnston
#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

int main ()
{
	cout << "Please give me 3 sides (in ascending order) to a triangle \n";
	double side_1 , side_2 , side_3;
	
	// I assume that the user is real numbers,  (no letters or complex numbers)
	cin >> side_1 >> side_2 >> side_3;
	// To avoid negative numbers I take the absolute value every time
	
	side_1 = abs(side_1);
	side_2 = abs(side_2);
	side_3 = abs(side_3);
	
	//if statement for side legth that is 0
	if (side_1 == 0 || side_2 == 0 || side_3 == 0)
		cout << "What type of triangle is this??? \n";
	

	//Now to use Law of Cosines
	double angle_1 , angle_2 , angle_3;
	/*
	angle_1 is opposite to side_1, angle_2 is opposite to side_2 ...
	*/
	
	angle_1 = acos((pow(side_1,2) - pow(side_2,2) - pow(side_3,2))
			  /(-2*side_2*side_3))*(180/M_PI);
	angle_2= acos((pow(side_2,2) - pow(side_1,2) - pow(side_3,2))
			  /(-2*side_1*side_3))*(180/M_PI);
	angle_3= acos((pow(side_3,2) - pow(side_1,2) - pow(side_2,2))
			  /(-2*side_1*side_2))*(180/M_PI);
			  
	cout << "Angles according to Law of Cosines: " << angle_1 << " " << 
		angle_2 << " " << angle_3 << endl;
		
	/*Now to use Law of Sines, But I have to get at least one angle first
	I'll keep the below angles in degrees first then change it later
	*/
	angle_1 = (asin((pow(side_1,2) - pow(side_2,2) - pow(side_3,2))
			  /(-2*side_2*side_3))-M_PI/2);
	//sin(M_PI/2-angle) = cos(angle)
	angle_2 = asin(side_2*sin(angle_1)/side_1);
	angle_3 = asin(side_3*sin(angle_1)/side_1);
	angle_1 = angle_1 * (-180/M_PI);
	angle_2 = angle_2 * (-180/M_PI);
	angle_3 = angle_3 * (-180/M_PI);
	cout << "Angles according to Law of Sines: " 
		 << angle_1 << " " << angle_2 << " " << angle_3 << endl;
	
	
	
	//Now to find area, s is perimeter divided by 2
	double s = (side_1 + side_2 + side_3)/2;
	
	double area = sqrt(s*(s-side_1)*(s-side_2)*(s-side_3));
	
	cout << "This is the area " << area << "cm^2" << endl;
	
	return EXIT_SUCCESS;
}

/*
CASE 1
Please give me 3 sides (in ascending order) to a triangle
3 4 5
Angles according to Law of Cosines: 36.8699 53.1301 90
Angles according to Law of Sines: 36.8699 53.1301 90
This is the area 6cm^2

--------------------------------
Process exited after 4.549 seconds with return value 0
Press any key to continue . . .
*/

/*
CASE 2
Please give me 3 sides (in ascending order) to a triangle
13 13 24.021
Angles according to Law of Cosines: 22.4992 22.4992 135.002
Angles according to Law of Sines: 22.4992 22.4992 44.9985
This is the area 59.7489cm^2

--------------------------------
Process exited after 7.056 seconds with return value 0
Press any key to continue . . .
*/
/* 
The difference in angles beetween law of cosine and law of sines can be seen
in CASE 2 where the third angle for law of cosines was 135.002, and 44.9985
for using the law of sines.
The difference for these values would be the potential for the ambigious case
to arrise. Since you can use the sin law using just an angle side and side, 
the ambigious case can arise where there are two possible triangles with 
different angles which can be made using the specified angle and 2 sides. 
Thus in CASE 2 when outputting a angle it used a different angle versus with 
the cosine law.
*/
