#include <bits/stdc++.h>
using namespace std;
class Point {
public:
    void print();
    int get_dimension();
	vector<double> get_coordinates();
    double dist(Point);
	void add_point(Point);
	void divide_int(int);
	Point(vector<double>);
	Point(string);
protected:
    vector<double> point;
    int dimension;
};
