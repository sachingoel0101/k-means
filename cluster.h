#include <bits/stdc++.h>
#include "point.h"
using namespace std;
class cluster {
protected:
    string filename; // data set for the problem
    int dimension;     // d
    int num_cluster;   // k
    point* means;     // k cluster means
public:
    cluster(string, int, int, point*);
    void print(void);
    bool converged(cluster* old_cluster);       // convergence criteria
    void iterate(void);       // update cluster means by lloyd's
    point* cluster_means(void);  // returns means
};
