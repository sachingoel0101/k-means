#include <bits/stdc++.h>
using namespace std;
class Point {
public:
    void print();
    int get_dimension();
    double dist(Point &p);
    Point(vector<double> v);
	Point(string line);
	Point operator+(Point &p1, Point &p2);
	Point operator/(Point &p,int i);
protected:
    vector<double> point;
    int dimension;
};
