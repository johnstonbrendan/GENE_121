#include <cstdlib>
#include <cmath>
#include <iostream>
using namespace std;

void swap(float&a, float&b)
{
	float OG_a = a;
	a = b;
	b = OG_a;
}
bool sort_three_numbers(float&num_1,float&num_2,float&num_3)
{
	if (num_1 > num_2 && num_1>num_3 && num_2>num_3)
	return true;
	if (num_1<num_2)
		swap(num_1,num_2);
	if (num_2<num_3)
		swap(num_2,num_3);
	if(num_1<num_2)
		swap(num_1,num_2);
	return false;
}

int main()
{
	float num_1 = 0, num_2 = 0, num_3 = 0;
	cout << "Give me 3 number please\n";
	cin >> num_1 >> num_2 >> num_3;
	if(sort_three_numbers(num_1,num_2,num_3))
		cout << "It's already sorted, I didn't have to do anything\n"
			 << "<3" << endl;
	cout << num_1 << " " << num_2 << " " << num_3;
	return EXIT_SUCCESS;
}
