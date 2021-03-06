#include <bits/stdc++.h>
#include "Point.h"

using namespace std;

#ifndef CLUSTER_H
#define CLUSTER_H

/**
 *
 * scale_cluster divides all cluster means by the corresponding values in the argument vector
 * get_cost assigns the voronoi partitions and then calculates cost based on euclidean distance
 *
 * */
class Cluster {
protected:
    string filename; 
    int dimension;   
    int num_cluster; 
    vector<Point> means;
public:
    Cluster(string,vector<Point>);
	Cluster(void);
	vector<Point> get_means();
	int get_dimension();
	int get_num_cluster();
    void print();
	double get_cost();
    Cluster iterate();
	int belongs_to(Point);
	void scale_cluster(vector<int>);
};

#endif
