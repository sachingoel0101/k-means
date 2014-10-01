#include <bits/stdc++.h>
#include "Cluster.h"
using namespace std;

Cluster::Cluster(string __filename,int __dimension, int __num_cluster, vector<Point> __means) {
    filename=__filename;
    dimension=__dimension;
    num_cluster=__num_cluster;
    means=__means;
	for(int i=0;i<num_cluster;i++) point_count.push_back(1);
}

Cluster: Cluster(string __filename, int __dimension, int __num_cluster){
	filename=__filename;
	dimension=__dimension;
	num_cluster=__num_cluster;
	for(int i=0;i<num_cluster;i++) point_count.push_back(0);
	vector<double> tmp;
	for(int i=0;i<dimension;i++) tmp.push_back(0);
	for(int i=0;i<num_cluster;i++) means.push_back(tmp);
}
void Cluster::print() {
    for(int i=0; i<num_cluster; i++)
        means[i].print();
}
bool Cluster::converged(Cluster &old_cluster) {
    if(old_cluster.dimension!=dimension) exit(-1);
	else{
		for(int i=0;i<num_cluster;i++)
			if(means[i].dist(&old_cluster.means[i])>1e-6) return false;
		return true;
	}
}
void Cluster::iterate() {
	ifstream data(filename);
	Cluster new_cluster(filename,dimension,num_cluster);
	for(string line; getline(data,line);){
		Point tmp(line);
		new_cluster.update(belongs_to(&tmp),&tmp);
	}
	new_cluster.finalize();
}

int Cluster::belongs_to(Point &p){
	int index=0;
	double min_dist=DBL_MAX;
	for(int i=0;i<num_cluster;i++){
		if(means[i].dist(&p)<min_dist){
			index=i; min_dist=means[i].dist(&p);
		}
	}
	return index;
}

void Cluster::update(int index,Point &p){
	point_count[index]=point_count[index]+1;
	means[index]=means[index]+p;
}

void Cluster:finalize(){
	for(int i=0;i<num_cluster;i++)
		means[i]=means[i]/point_count[i];
}
int main(void) {
    return 0;
}
