#include <bits/stdc++.h>
#include "Point.h"
using namespace std;
class Heuristic{
public:
    Point h1_center(vector<Point> sampled_set,int m);
private:
	vector<Point> h1_subset(vector<Point> sampled_set, int m);
};
