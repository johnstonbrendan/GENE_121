//Brendan Johnston
#include <cmath>
#include <fstream>
#include "ccc_win.h"

using namespace std;

	int ccc_win_main()
	{
		int flower_num = cwin.get_int("How many flowers do you want?");
		//assume that the user inputs a positive integer
		for (int flowers_d = 0; flowers_d < flower_num; flowers_d++)
	{
		Point origin = cwin.get_mouse("Click where you want the flower");
		Circle circle_origin(origin,1);
		float x_origin = origin.get_x();
		float y_origin = origin.get_y();
		float stem_end_y = origin.get_y() - 5;
		Line stem(Point(x_origin, y_origin), Point(x_origin , stem_end_y));
		Line stem_petal_1(Point(x_origin,stem_end_y + 2.5),
			Point(x_origin + 1, stem_end_y + 3.0));
		Line stem_petal_2(Point(x_origin,stem_end_y + 2.1),
			Point(x_origin - 1, stem_end_y + 3.0));
		Line stem_petal_3(Point(x_origin,stem_end_y + 1.3),
			Point(x_origin - 1, stem_end_y + 1.8));
		Line stem_petal_4(Point(x_origin,stem_end_y + 1.1),
			Point(x_origin + 1, stem_end_y + 1.8));
		cwin << circle_origin << stem << stem_petal_1 << stem_petal_2
				<< stem_petal_3 << stem_petal_4;
		float petals = 25;
		Point new_centre = origin;
		for (int d_petals = 0; d_petals < petals; d_petals++)
	//works like a polar array where the circle and line are the object arrayed
		{
			new_centre = Point(1.5*cos((2*M_PI*d_petals)/petals)+x_origin
							,1.5*sin((2*M_PI*d_petals)/petals)+y_origin);
			Point b_petal_line(1.7*cos((2*M_PI*d_petals)/petals)+x_origin
							,1.7*sin((2*M_PI*d_petals)/petals)+y_origin);
							//1.7 choosen for asthetic
			Point e_petal_line(2*cos((2*M_PI*d_petals)/petals)+x_origin
							,2*sin((2*M_PI*d_petals)/petals)+y_origin);
			Circle inside(origin, 1*d_petals/(petals));
						
			cwin << Circle(new_centre,0.5) << Line(b_petal_line,e_petal_line)
				 << inside;
		}
	}
}
