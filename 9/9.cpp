//#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>

#define EPS 0.000001

using namespace std;

class Point
{
public:
	int x, y;
	Point(int x = 0, int y = 0)
	{
		this->x = x; this->y = y;
	}
	double len2() const { return x * x + y * y; }
};

Point operator+ (Point a, Point b)
{
	return Point(a.x + b.x, a.y + b.y);
}

Point operator- (Point a, Point b)
{
	return Point(a.x - b.x, a.y - b.y);
}

double PolarAngle(Point p)
{
	return atan2(1.0*p.y, 1.0*p.x);
}

int f(Point a, Point b)
{
	if (fabs(PolarAngle(a) - PolarAngle(b)) < EPS)
		return a.len2() < b.len2();
	return PolarAngle(a) < PolarAngle(b);
}

vector<Point> v, hull;
int i, n, cur, a, b;
double p;

int TurnLeft(Point a, Point b, Point c)
{
	Point p = b - a, q = c - b;
	return p.x * q.y > q.x * p.y;
}

int main(void)
{
	do
	{
		printf("Enter number of points: ");
		scanf("%d", &n);
	} while (n < 1);
	for (i = 0; i < n; i++)
	{
		printf("Enter (x;y) : ");
		scanf("%d %d", &a, &b);
		v.push_back(Point(a, b));
	}
	for (i = 1; i < n; i++)
	{
		if (v[i].x < v[0].x) swap(v[i], v[0]);
		if ((v[i].x == v[0].x) && (v[i].y < v[0].y)) swap(v[i], v[0]);
	}
	sort(v.begin() + 1, v.end(), f);  v.push_back(v[0]); n++;
	for (cur = 1, i = 2; i < n; i++)
	{
		while ((cur > 0) && !TurnLeft(v[cur - 1], v[cur], v[i])) cur--;
		v[++cur] = v[i];
	}

	for (i = 0; i < cur; i++)
		p += sqrt(1.0*(v[i + 1] - v[i]).len2());


	printf("%.1lf\n", p);

	return 0;
}
