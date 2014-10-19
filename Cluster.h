#include <bits/stdc++.h>
#include "Point.h"

using namespace std;

/**
 *
 *
 *
 * */

class Cluster {
protected:
    string filename; 
    int dimension;   
    int num_cluster; 
    vector<Point> means;
	vector<int> point_count;
	bool convergence;
public:
    Cluster(string,int,int,vector<Point>);
	Cluster(string,int,int);
	vector<Point> get_means();
	int get_dimension();
	int get_num_cluster();
	vector<int> get_point_count();
    void print();
	bool converged();
    void check_converged(Cluster);
	double get_cost();
    void iterate();
	int belongs_to(Point);
	void update(int,Point);
	void finalize();
};
