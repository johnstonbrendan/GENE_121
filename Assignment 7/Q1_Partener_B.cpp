#include <cstdlib>
#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

const int MAXSIZE = 100;
//assume program will deal with no more than 100 people
int read_add_remove(ifstream&file_name, bool staff_or_not[], string name[])
// is it okay if paramter is a main variable?? like name
{
	int people_in_file = 0;
	bool y_n_staff = 0;
	string birth_name = " ";
	if (staff_or_not[0] == 1)
	//meanning is the remove file
	{
		while (people_in_file<50 && file_name>>y_n_staff>>birth_name)
		{
			staff_or_not[people_in_file] = y_n_staff;
			name[people_in_file] = birth_name;
			people_in_file++;
		}
	}
	else
	//is the add file
	{
		while (people_in_file<MAXSIZE && file_name>>y_n_staff>>birth_name)
		{
			staff_or_not[people_in_file+50] = y_n_staff;
			name[people_in_file+50] = birth_name;
			//+50 so these values don't mess with previous array values
			people_in_file++;
		}
	}
	return people_in_file;
}

void free_up_space (string name_array_value)
/*since freeing up a spot means that the person in the spot is no longer there
	we can just make the space with an empty value*/
{
	name_array_value = "";
}
bool assign_space (bool staff_or_not[], string name [], 
					bool staff_value, string individual)
{
	//assume function e will be called first_free_space
	int free_space = first_free_space (staff_or_not, name);
	//assume that if all spaces are taken then free_space returns 51
	if (free_space == 51)
	return false;
	else
	{
		//double check the free_space -1 values are correct
		staff_or_not[free_space - 1] = staff_value;
		name [free_space - 1] = name;
		return true;
	}
}

int main()
{
	ifstream add("parking_add.txt");
	ifstream remove("parking_remove.txt");
	ifstream current("parking_current.txt");
	ofstream fout("parking_updated.txt")
	if (!add || !remove || !current)
	return EXIT_FAILURE;
	bool staff[MAXSIZE] = {0}, staff_remove[50] = {1};
	//requires the initial values to be different for function read_add_remove
	string name[MAXSIZE] = {""}, name_remove[50] = {""};
	//use "" to represent empty spot and 50 is the max for parking spots
	int parking_spot[50], people_add = 0, people_remove = 0;
	//do we even need parking spot
	people_current(staff,name);
	people_add = read_add_remove(add,staff,name);
	people_remove = read_add_remove(remove,staff_remove,name_remove);
	for (int removed = 0; removed < people_remove; removed++)
	//removes people who need to be removed
	{
		int spot_check = 0;
		while (name_remove[removed] != name[spot_check])
		spot_check++;
		free_up_space (name[spot_check]);
	}
	
	//don't need to use function e becasue it is intertwined into funcion f
	int added = 0;
	bool full = 0;
	while(added < people_add && !full)
		{
			if (staff[added+52]==1)
			{
				if(!assign_space(staff[],name[],staff[added+52],name[added+52]))
				full = 1;
			}
			added++;
		}
	//assigns the staff a space until can no longer be done or no more staff
	added = 0;
	bool full=0;
	//assume function e assigns students spaces higer from 25
	while(added < people_add && !full)
	{
		if(!assign_space(staff[],name[],staff[added+52],name[added+52]))
		full = 1;
		added++;
	}
	//assume that function h is able to output without needing a parking array
	output_data (staff[],name[])
	add.close();
	remove.close();
	current.close();
	fout.close();

	return 0;
}


