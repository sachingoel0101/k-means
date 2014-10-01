#include <bits/stdc++.h>
#include <random>
#include "Point.h"

using namespace std;

class sampling
{
public:
    sampling(string x,int k);
    //vector<point> generate();
    vector<Point> generate2(vector<Point> points);
    ~sampling();

protected:
    ifstream file;
    int centers;
    /* data */
};
