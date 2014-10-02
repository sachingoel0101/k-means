#include <bits/stdc++.h>
#include "Point.h"
using namespace std;
class Cluster {
protected:
    string filename; // data set for the problem
    int dimension;     // d
    int num_cluster;   // k
    vector<Point> means;     // k cluster means
	vector<int> point_count; // points in each cluster
	bool convergence;
public:
    Cluster(string,int,int,vector<Point>);
	Cluster(string,int,int);  // all zero values initialized
	vector<Point> get_means();
	int get_dimension();
	int get_num_cluster();
	vector<int> get_point_count();
    void print();
	bool converged();
    void check_converged(Cluster); // convergence criteria
    void iterate();       // update cluster means by lloyd's
	int belongs_to(Point);  // which cluster the point p belongs to
	void update(int,Point); // add p to cluster index and update counts
	void finalize(); // divide the means by point counts
};
