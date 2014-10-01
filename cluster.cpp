#include <bits/stdc++.h>
#include "cluster.h"
using namespace std;

cluster::cluster(string __filename,int __dimension, int __num_cluster, point* __means) {
    filename=__filename;
    dimension=__dimension;
    num_cluster=__num_cluster;
    means=__means;
}
void cluster::print() {
    for(int i=0; i<num_cluster; i++)
        (means+i)->print();
}
bool cluster::converged(cluster* old_cluster) {
    return true;
}
void cluster::iterate() {

}
point* cluster::cluster_means() {
    return means;
}

int main(void) {
    vector<int> a,b;
    a.push_back(1);
    a.push_back(2);
    b.push_back(3);
    b.push_back(4);
    point* yay=new point[2] {a,b};
    cluster tmp("a",2,2,yay);
    tmp.print();
    return 0;
}
