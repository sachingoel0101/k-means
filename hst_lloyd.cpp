#include <bits/stdc++.h>
#include "Cluster.h"
#include "Sampling.h"
#include "Heuristic.h"

using namespace std;

int main(int argc,char* argv[]) {
	Sampling sampler(argv[1]);
	vector<Point> p;
	int numcluster=stoi(argv[2]);
	int n_val=stoi(argv[3]);
	int m_val=stoi(argv[4]);
	Heuristic h;
	for(int i=0;i<numcluster;i++){
		p.push_back(h.h1_center(sampler.d2_sample(p,n_val),m_val));
	}
	vector<double> costs;
	Cluster c1(argv[1],p);
	costs.push_back(c1.get_cost());
	c1.print();
	Cluster c2=c1.iterate();
	costs.push_back(c2.get_cost());
	//c2.print();
	int iter=1;
	while((c1.get_cost()-c2.get_cost())/c1.get_cost() > 0.0001){
		//c2.print();
		c1=c2;
		c2=c1.iterate();
		costs.push_back(c2.get_cost());
		iter++;
	}
	cout<<iter<<endl;
	for(vector<double>::iterator it=costs.begin();it!=costs.end();++it)
		cout<<*it<<',';
	cout<<'\n';
	return 0;
}
