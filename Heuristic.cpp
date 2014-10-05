#include <bits/stdc++.h>
#include "Heuristic.h"

using namespace std;

Point Heuristic::h1_center(vector<Point> sampled_set) {
	vector<Point> subset=h1_subset(sampled_set);
	int dim=sampled_set[0].size();
	vector<double> tmp;
	for(int i=0;i<dim;i++) tmp.push_back(0);
	Point ret(tmp);
	for(int i=0;i<subset.size();i++)
		ret.add(subset[i]);
	ret.divide(subset.size());
	return ret;
}


vector<Point> Heuristic::h1_subset(vector<Point> sampled_set) {

    //choose top m candidates
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

    //counting only top-10 ranks
    for(int i=0; i<n; i++) {
        int limit = min(10,n-1);

        for(int j=1; j<=limit; j++) {
            ranks[matrix[i][j].second].first++;
        }
    }

    sort(ranks.begin(),ranks.end());

    int dim = candidates[i].size();
    vector<int> ans(dim);
    for(int i=0; i<dim; i++)
        ans[i]=0;
}
