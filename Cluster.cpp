#include <bits/stdc++.h>
#include "Cluster.h"

using namespace std;

Cluster::Cluster(string __filename,int __dimension, int __num_cluster, vector<Point> __means) {
    filename=__filename;
    dimension=__dimension;
    num_cluster=__num_cluster;
    means=__means;
	convergence=false;
	for(int i=0;i<num_cluster;i++) point_count.push_back(0);
}

Cluster::Cluster(string __filename, int __dimension, int __num_cluster){
	filename=__filename;
	dimension=__dimension;
	num_cluster=__num_cluster;
	convergence=false;
	for(int i=0;i<num_cluster;i++) point_count.push_back(0);
	vector<double> tmp;
	for(int i=0;i<dimension;i++) tmp.push_back(0);
	for(int i=0;i<num_cluster;i++) means.push_back(tmp);
}

vector<Point> Cluster::get_means(){
	return means;
}

int Cluster::get_dimension(){
	return dimension;
}

int Cluster::get_num_cluster(){
	return num_cluster;
}
vector<int> Cluster::get_point_count(){
	return point_count;
}


void Cluster::print() {
    for(int i=0; i<num_cluster; i++){
        means[i].print();
	}
	cout<<"Point counts:\n";
	for(int i=0;i<num_cluster;i++){
		cout<<point_count[i]<<' ';
	}
	cout<<'\n';
}

bool Cluster::converged(){
	return convergence;
}

void Cluster::check_converged(Cluster new_cluster) {
    if(new_cluster.get_dimension()!=dimension) throw 1;
	else if(new_cluster.get_num_cluster()!=num_cluster) throw 2;
	else{
		convergence=true;
		vector<Point> tmp_means=new_cluster.get_means();
		for(int i=0;i<num_cluster;i++){
			if(means[i].dist(tmp_means[i])>1e-6){
				convergence=false;
				break;
			}
		}
	}
}

void Cluster::iterate() {
	ifstream data;
	data.open(filename.c_str());
	Cluster new_cluster(filename,dimension,num_cluster);
	for(string line; getline(data,line);){
		Point tmp(line);
		new_cluster.update(belongs_to(tmp),tmp);
	}
	data.close();
	new_cluster.finalize();
	check_converged(new_cluster);
	means=new_cluster.get_means();
	point_count=new_cluster.get_point_count();
}

int Cluster::belongs_to(Point p){
	int index=0;
	double min_dist=DBL_MAX;
	for(int i=0;i<num_cluster;i++){
		if(means[i].dist(p)<min_dist){
			index=i; min_dist=means[i].dist(p);
		}
	}
	return index;
}

void Cluster::update(int index,Point p){
	point_count[index]=point_count[index]+1;
	means[index].add_point(p);
}

void Cluster::finalize(){
	for(int i=0;i<num_cluster;i++)
		if(point_count[i]!=0) means[i].divide_int(point_count[i]);
}
