#include <bits/stdc++.h>

using namespace std;

/**
 *
 * the vector point stores all the coordinates
 * dist return euclidean distance
 * add_point adds the coordinates to "this"
 * divide_int scales coordinates of "this"
 *
 * */

class Point {
public:
	Point(vector<double>);
	Point(string);
    void print();
    int get_dimension();
	vector<double> get_coordinates();
    double dist(Point);
	void add_point(Point);
	void divide_int(int);
protected:
    vector<double> point;
    int dimension;
};
