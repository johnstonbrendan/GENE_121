//Brendan Johnston and Kimath Kaai
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <fstream>
using namespace std;

int main()
{
	const double TOL_LENGTH = 7 , TOL_ANGLE = 0.5;
	//TOL_LENGTH is in mm and TOL_ANGLE is in mm
	ifstream fin("stones.txt");
	ofstream fout("shapes.txt");
	if(!fin)
	{
		cout << "Unable to find file";
		return EXIT_FAILURE;
	}
	int shapes = 0;
	string stone_type = "";
	fin >> shapes;
	double a,b,c = 0; 
	cout << "There are " << shapes << " shapes.";
	for (int i = 0; i < shapes; i++ )
	{
		fin >> a >> b >> c;
		if (fabs(a-b) < TOL_LENGTH)
		{
			if (fabs(90 - c) < TOL_ANGLE)
				stone_type = "Square";
			else
				stone_type = "Rhombus";
			
		}
		else if (fabs(90 - c) < TOL_ANGLE)
			stone_type = "Rectangle";
			else
			stone_type = "Parallelogram";
		fout << a << "cm " << b << "cm " << c << "° " << stone_type << "\n";
		
	}
	fin.close();
	fout.close();
	
	return EXIT_SUCCESS;
}


