#include <bits/stdc++.h>
#include "Cluster.h"
#include "Sampling.h"

using namespace std;

int main(void) {
	Sampling sampler("data/a.txt");
	vector<Point> p=sampler.uniform_sample(5);
	vector<double> costs;
	Cluster c1("data/a.txt",p);
	costs.push_back(c1.get_cost());
	c1.print();
	Cluster c2=c1.iterate();
	costs.push_back(c2.get_cost());
	c2.print();
	int iter=1;
	while(c1.get_cost()-c2.get_cost()>0.000001){
		c2.print();
		c1=c2;
		c2=c1.iterate();
		costs.push_back(c2.get_cost());
		iter++;
	}
	cout<<iter<<endl;
	for(vector<double>::iterator it=costs.begin();it!=costs.end();++it)
		cout<<*it<<'\n';
	return 0;
}
