#include <bits/stdc++.h>
#include "point.h"
#include "sampling.h"

using namespace std;

class centers
{
public:
    centers(string x, int y,int z,int a);
    //~centers();
    vector<point> produce();

protected:
    string filename;
    int k;
    int n;
    int m;

private:
    point get_centre(vector<point> candidates);
};

centers::centers(string x,int y,int z, int a) {
    filename =x;
    k=y;
    n=z;
    m=a;
}


vector<point> centers::produce() {
    vector<point> ret;

    for(int i=0; i<k; i++) {

        sampling s(filename,n);

        vector<point> jk = s.generate2(ret);

        point to_add = get_centre(jk);
        ret.push_back(to_add);
    }

    return ret;
}


point centers::get_centre(vector<point> candidates) {

    //choose top m candidates

    vector<vector<pair<double,int> > > matrix(n);

    for(int i=0; i<n; i++) {
        matrix[i].resize(n);
        for(int j=0; j<n; j++) {
            matrix[i][j] = make_pair(0,j);
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            double local_dist = candidates[i].dist(candidates[j]);

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

    //choose top-m points according to rank now

    //TODO :
    //dekh yaar samajh nhi aa raha ya toh mean lele sab points ka fir sab points ko double me convert kar le ya fir middle wala find kar inka
    // middle wala in the sense jisse baaki sab ka distance ka sum minimum ho

    //choose the centroid

    int dim = candidates[i].size();

    vector<int> ans(dim);

    for(int i=0; i<dim; i++)
        ans[i]=0;
    //I don't know
}

