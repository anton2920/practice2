/*
	Simple version of 5 exercise.
	Lagrange polynomial:
	wikipedia: https://en.wikipedia.org/wiki/Lagrange_polynomial
*/


#include <iostream>
#include <string>
#include <vector>
#include <sstream>


struct Point
{
	float x;
	float y;
};

std::string to_string_with_precision(const float a_value, const int n = 2);
std::string lagrange_polynomial(std::vector<Point>& points);
void getPoints(std::vector<Point>& points);


int main()
{
	std::vector<Point> points;
	getPoints(points);

	std::cout << '\n';
	std::cout << "Lagrange polynomial: \n";
	std::cout << lagrange_polynomial(points);


	std::cout << "\n\n";
	return 0;
}

void getPoints(std::vector<Point>& points)
{
	int number_of_points;

	do
	{
		std::cout << "Enter number of points: ";
		std::cin >> number_of_points;
	} while (number_of_points < 1);

	for (int i = 0; i < number_of_points; ++i)
	{
		float x, y;
		std::cout << "Enter (x;y) : ";

		bool correct(true);
		std::cin >> x >> y;
		for (auto& point : points)
		{
			if (point.x == x)
			{
				correct = false;
				std::cout << "All x must be difference!\n";
				--i;
				break;
			}
		}
		if (correct)
			points.push_back({ x,y });
	}

	std::cout << '\n'
		<< "list of points:\n";

	for (auto& point : points)
		std::cout << "(" << point.x << ";" << point.y << ")\n";
}

std::string lagrange_polynomial(std::vector<Point>& points)
{
	std::string lagr_poly = "";
	std::string numerator = "";
	//std::string denominator = "";
	float denominator = 1;
	std::string l = "";
	for (int i = 0; i < points.size(); ++i)
	{
		denominator = 1;
		numerator = to_string_with_precision(points[i].y);
		for (int j = 0; j < points.size(); ++j)
		{
			if (j == i)
				continue;
			else
			{
				numerator = numerator + "(x - (" + to_string_with_precision(points[j].x) + "))";
				denominator = denominator * (points[i].x - points[j].x);
			}
		}

		l = numerator + "/(" + to_string_with_precision(denominator) + ")";

		if (i == 0)
			lagr_poly = l;
		else
			lagr_poly += " + " + l;
	}

	return lagr_poly;
}

std::string to_string_with_precision(const float a_value, const int n)
{
	std::ostringstream out;
	out.precision(n);
	out << std::fixed << a_value;
	return out.str();
}
