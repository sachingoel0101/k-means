#include <bits/stdc++.h>
#include "Heuristic.h"

using namespace std;

Point Heuristic::h1_center(vector<Point> sampled_set, int m) {
	vector<Point> subset=h1_subset(sampled_set,m);
	int dim=sampled_set[0].get_dimension();
	vector<double> tmp;
	for(int i=0;i<dim;i++) tmp.push_back(0);
	Point ret(tmp);
	for(int i=0;i<subset.size();i++)
		ret.add_point(subset[i]);
	ret.divide_int(subset.size());
	return ret;
}


vector<Point> Heuristic::h1_subset(vector<Point> sampled_set, int m) {

	int n=sampled_set.size();
    vector<vector<pair<double,int> > > matrix(n);

    for(int i=0; i<n; i++) {
        matrix[i].resize(n);
        for(int j=0; j<n; j++) {
            matrix[i][j] = make_pair(0,j);
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            double local_dist = sampled_set[i].dist(sampled_set[j]);
            matrix[i][j].first = local_dist;
            matrix[j][i].first = local_dist;
        }
    }

    for(int i=0; i<n; i++) {
        sort(matrix[i].begin(), matrix[i].end());
    }
    vector<pair<int,int> > ranks(n);
    for(int i=0; i<n; i++)
        ranks[i]=make_pair(0,i);

    for(int i=0; i<n; i++) {
        int limit = min(10,n-1);

        for(int j=0; j<=limit; j++) {
            ranks[matrix[i][j].second].first++;
        }
    }

    reverse_sort(ranks.begin(),ranks.end());
	vector<Point> to_ret(m);

	for(int i=0;i<m;i++) {
		to_ret[i] = sampled_set[ranks[i].second];
	}
	return to_ret;
}
