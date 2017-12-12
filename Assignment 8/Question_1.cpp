#include <iostream>
#include <cmath>
#include <fstream>
#include <cstdlib>
#include <iomanip>

using namespace std;

const int POINTS_HORIZONTAL = 2400/100 + 1;
const int POINTS_VERTICAL = 4900/100 + 1;
/*
Divide total distance by distance travelled per coordinate (point)
then add 1 to include the 0 (initial) point
*/

void read_in_elevations (ifstream & elevations_file,
 							int elevations[POINTS_VERTICAL][POINTS_HORIZONTAL])
{
	for (int index_vertical = 0; index_vertical < POINTS_VERTICAL; index_vertical++)
	{
		for (int index_horizontal = 0; index_horizontal < POINTS_HORIZONTAL; index_horizontal++)
		{
			elevations_file >> elevations [index_vertical][index_horizontal];
		}
	}
}
void read_in_geocache (ifstream & geocache_file,
 							bool cache[POINTS_VERTICAL][POINTS_HORIZONTAL])
{
	for (int index_vertical = 0; index_vertical < POINTS_VERTICAL; index_vertical++)
	{
		for (int index_horizontal = 0; index_horizontal < POINTS_HORIZONTAL; index_horizontal++)
		{
			geocache_file >> cache [index_vertical][index_horizontal];
		}
	}
}

double energy_required(int elevations[POINTS_VERTICAL][POINTS_HORIZONTAL],
		int start_point_x, int start_point_y, int end_point_x, int end_point_y)
{
	int start_elevation = elevations[start_point_y][start_point_x];
	int end_elevation = elevations[end_point_y][end_point_x];
	double plane_energy = 100*sqrt(pow(end_point_x - start_point_x,2) +
								pow(end_point_y - start_point_y,2));
	//uses distance equation, and letting energy be proportional to energy
	double vertical_energy = fabs(7*(start_elevation - end_elevation));
	double total_energy = plane_energy + vertical_energy;
	return total_energy;
}

bool next_geocache (int elevations [POINTS_VERTICAL][POINTS_HORIZONTAL],
bool cache [POINTS_VERTICAL][POINTS_HORIZONTAL],
	int current_x, int current_y, int & end_point_x, int & end_point_y)
{
	int min_point_x = 0, min_point_y = 0;
	end_point_y = 0;
	// can I do end_point_x = end_point_y = 0;
	int	min_energy = 100000;
	//assume no energy larger than 10000
	while(end_point_y < POINTS_VERTICAL)
	{
		end_point_x = 0;
		while (end_point_x < POINTS_HORIZONTAL)
		{
			if (cache[end_point_y][end_point_x])
			{
				if (energy_required(elevations, current_x
					, current_y, end_point_x, end_point_y) < min_energy)
					{
						min_energy = energy_required(elevations,
						current_x, current_y, end_point_x, end_point_y);
						min_point_x = end_point_x;
						min_point_y = end_point_y;
					}
			}
			end_point_x++;
		}
		end_point_y++;
	}
	end_point_x = min_point_x;
	end_point_y = min_point_y;
	cache [end_point_y][end_point_x] = 0;
	if (min_point_x == 0 && min_point_y == 0)
		return 0;
	return 1;
}

int number_of_caches(bool cache [POINTS_VERTICAL][POINTS_HORIZONTAL])
{
	int point_x = 0, point_y = 0, sum_cache = 0;
	while (point_y < POINTS_VERTICAL)
	{
		point_x = 0;
		while (point_x < POINTS_HORIZONTAL)
		{
			if (cache [point_y][point_x])
				sum_cache++;
			point_x++;
		}
		point_y++;
	}
	return sum_cache;
}

int optimal_path (int elevations [POINTS_VERTICAL][POINTS_HORIZONTAL],
					bool cache [POINTS_VERTICAL][POINTS_HORIZONTAL],
					int path [2][100])
{
	int initial_cache = number_of_caches(cache);
	int current_x = 0, current_y = 0, path_x = 0, path_y = 0, path_point = 0;

	do
	{
		if (path_point == 0)
		{
			path[0][path_point] = path_x;
			path[1][path_point] = path_y;
			path_point++;
		}
		//for initial point
		next_geocache(elevations, cache, current_x, current_y, path_x, path_y);
		current_x = path_x;
		current_y = path_y;
		path[0][path_point] = path_x;
		path[1][path_point] = path_y;
		path_point++;
	}	while (number_of_caches(cache) && (!(path_x == 0) || !(path_y == 0)));
	return initial_cache;
}

path_to_file (ofstream & path_file, int path [2][100])
{
	int output_count = 0;
	do
	{
		path_file << "(" << path[0][output_count] << ","
				<< path[1][output_count] << ")" << endl;
				output_count++;
	}while (path[0][output_count] || path[1][output_count]);
}

int main()
{
	ifstream elevation_file("elevations.txt");
	ifstream cache_file("caches.txt");
	ofstream path_file("path.txt");
	if (!cache_file || !elevation_file)
	{
		cout << "Unable to find file" << endl;
		return EXIT_FAILURE;
	}
	int elevations [POINTS_VERTICAL][POINTS_HORIZONTAL] = {0};
	int path [2][100] = {0};
	//assume there will be less than 100 geocaches
	bool caches [POINTS_VERTICAL][POINTS_HORIZONTAL] = {0};
	read_in_elevations (elevation_file, elevations);
	read_in_geocache (cache_file, caches);
	int current_x = 0, current_y = 0, end_point_x = 0, end_point_y = 0;
	optimal_path (elevations, caches, path);
	path_to_file (path_file, path);

	elevation_file.close();
	cache_file.close();
	path_file.close();
	return EXIT_SUCCESS;	
}
