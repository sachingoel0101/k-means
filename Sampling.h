#include <bits/stdc++.h>
#include <random>
#include "Point.h"
using namespace std;
class Sampling
{
public:
    Sampling(string,int);
    vector<Point> generate2(vector<Point>);
    ~Sampling();
protected:
    ifstream file;
    int N;
};
