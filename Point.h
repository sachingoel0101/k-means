#include <bits/stdc++.h>
using namespace std;
class Point {
public:
    void print();
    int get_dimension();
    double dist(Point &p);
	double coordinate(int index);
    Point(vector<double> v);
protected:
    vector<double> point;
    int dimension;
};
