#include <bits/stdc++.h>
#include <random>
#include "point.h"

using namespace std;

class sampling
{
public:
    sampling(string x,int k);
    //vector<point> generate();
    vector<point> generate2(vector<point> points);
    ~sampling();

protected:
    ifstream file;
    int centers;
    /* data */
};