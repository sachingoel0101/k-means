#include <bits/stdc++.h>
#include "Sampling.h"
using namespace std;

Sampling::Sampling(string __file, int __N) {
    N =__N;
    file.open(__file.c_str());
}

Sampling::~Sampling() {
    file.close();
}

vector<Point> Sampling::generate2(vector<Point> centers) {
    srand(time(NULL));
    vector<int> ans;
    int remaining = N;
    vector<Point> current_set;
    if(centers.size()==0) {
        //sample uniformly
        string line;
        vector<double> probabilities;
        while(getline(file,line)) {
            probabilities.push_back(1.0);
        }
        random_device rd;
        mt19937 gen(rd());
        discrete_distribution<> d(probabilities.begin(), probabilities.end());
        while(ans.size()<remaining) {
            int chosen = d(gen);
            ans.push_back(chosen);
        }
		//sort the choosen points
		sort(ans.begin(),ans.end());
        vector<int>::iterator it=ans.begin();
        int temp =0;
        file.clear();
        file.seekg(0, ios_base::beg);
		getline(file,line);
        while(true) {
			if(file.eof()) break;
            if(temp== (*it)) {
                Point p1(line);
                current_set.push_back(p1);
                it++;
                if(it==ans.end()) break;
            } else {
				getline(file,line);
                temp++;
            }
        }
    } else {
        //sample with probabilities equal to min distance
        string line;
        vector<double> probabilities;
        while(getline(file,line)) {
            Point p1(line);
            double min_dist = p1.dist(centers[0]);
            for(int i=1; i< centers.size(); i++) {
                double local_dist = p1.dist(centers[i]);
                min_dist = min(min_dist,local_dist);
            }
            probabilities.push_back(min_dist);
        }
        random_device rd;
        mt19937 gen(rd());
        discrete_distribution<> d(probabilities.begin(), probabilities.end());
        while(ans.size()<remaining) {
            int chosen = d(gen);
            ans.push_back(chosen);
        }
		sort(ans.begin(),ans.end());
        vector<int>::iterator it=ans.begin();
        int temp =0;
        file.clear();
        file.seekg(0, ios_base::beg);
		getline(file,line);
        while(true) {
			if(file.eof()) break;
            if(temp== (*it)) {
                Point p1(line);
                current_set.push_back(p1);
                it++;
                if(it==ans.end()) break;
            } else {
				getline(file,line);
                temp++;
            }
        }
    }
    return current_set;
}
