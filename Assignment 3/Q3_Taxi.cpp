//Brendan Johnston and Noah Gillespie-Friesen
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <fstream>
#include <iomanip>
using namespace std;

int main()
{
	double distance = 0 , customer_cost = 0  , total_cost = 0 , x = 0 , y = 0 ,
	total_distance = 0 , a = 0, b = 0 , longest_trip = 0, cheapest_trip = 50;
	//longest_trip initialised lower than first trip distance
	//cheapest_trip initialised higher than first trip customer_cost
	int z = 1;
	//x indicates the x coordinates and y indicates the y coordinates
	int stops = 0, i = 0;
	bool return_trip = 0;
	//bool is acceptable because return_trip is always 1 or 0
	ifstream fin("taxi.txt");
	ofstream fout("report.txt");
	fout << fixed << setprecision (2);
	if (!fin)
	{
		cout << "Unable to find file";
		return EXIT_FAILURE;
	}
	fout << "Trips" << setw(14) << "Return" << setw(12) << "Stops" << setw(16) 
	<< "Distance (km)" << setw(12) << "Cost ($)" << setw(20) 
	<< "Total Distance (km)" << setw(18) << "Total Cost ($)" << endl;
	while (fin >> return_trip)
	//above line ensures that below are per customer codes
		{
			
			fin >> stops;
			customer_cost = 0;
			customer_cost += stops*11;
			distance = 0;
			i=0 , a = 0 , b = 0;
			while (stops > i)
			{	
				fin >> x >> y;
				distance += sqrt(pow(x-a,2)+pow(y-b,2));
				//assuming distances are given in km
				i++;
				a = x , b = y;
			}
			if (return_trip == 1)
			{
				distance += sqrt(pow(x,2)+pow(y,2));
			}
			if (distance > longest_trip)
				longest_trip = distance;
			customer_cost += distance*2.7;
			if (customer_cost < cheapest_trip)
				cheapest_trip = customer_cost;
			total_distance += distance;
			total_cost += customer_cost;
			int e = 0;
			if (z>=10)
				e = 1;
			/*  e value is used for spacing so that everything is not shifted
				when two digit numbers are introduced */
			if ((z<6)|| (z%5 == 0))
			{
			fout << z << setw(14-e) << return_trip << setw(14) << stops 
			<< setw(14) << distance << setw(14) << customer_cost  
			<< setw(14) << total_distance << setw(22) 
			<< total_cost << endl;
			}
			z++;
		}
		fout << "\nThe cumulative distance travelled for all of August is " 
		<< total_distance << "km\nThe cumulative amount collected from all"
		" customers for all of August is $" << total_cost << "\nThe length of "
		"the longest trip is " << longest_trip << "km\nThe price of the cheapest"
		" trip is $" << cheapest_trip << endl;
		fin.close();
		fout.close();
	return EXIT_SUCCESS;
}
