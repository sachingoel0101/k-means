#include <bits/stdc++.h>
#include "cluster.h"
using namespace std;

cluster::cluster(string __filename,int __dimension, int __num_cluster, vector<Point> __means) {
    filename=__filename;
    dimension=__dimension;
    num_cluster=__num_cluster;
    means=__means;
}
void cluster::print() {
    for(int i=0; i<num_cluster; i++)
        means[i].print();
}
bool cluster::converged(cluster &old_cluster) {
    if(old_cluster.dimension!=dimension) exit(-1);
	else{
		for(int i=0;i<num_cluster;i++)
			if(means[i].dist(&old_cluster.means[i])>1e-6) return false;
		return true;
	}
}
void cluster::iterate() {
	ifstream data(filename);
	for(string line; getline(data,line);){
		
	}
}

int main(void) {
    return 0;
}
