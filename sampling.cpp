#include <bits/stdc++.h>
#include <random>
//#include "point.h"
#include "sampling.h"

using namespace std;

/*
class sampling
{
public:
	sampling(string x,int k);
	vector<point> generate();
	~sampling();

protected:
	ifstream file;
	int centers;
	 data
};

*/


sampling::sampling(string x, int k) {
    centers =k;
    file.open(x.c_str());
}

sampling::~sampling() {
    file.close();
    //destroy(sampling);
}

/*
vector<point> sampling::generate() {
	int remaining = centers;

	vector<point> current_set;

	if(remaining ==0)
		return {}; //raise error

	// choose first center

    string line;
    vector<double> probabilities;

    while(getline(file,line)) {
    	probabilities.push_back(1.0);
    }

    random_device rd;
    mt19937 gen(rd());
    discrete_distribution<> d(probabilities.begin(), probabilities.end());

    int chosen = d(gen);

    int temp=0;

    file.clear();
    file.seekg(0, ios_base::beg);

    while(getline(file,line)) {
    	if(temp==chosen) {
    		stringstream ss(line);
    		vector<int> p;

    		while(ss>>temp) {
    			p.push_back(temp);
    		}
    		point p1(p);
    		current_set.push_back(p1);
    		break;
    	} else {
    		temp++;
    	}
    }

    remaining--;

    while(remaining--) {
		file.clear();
    	file.seekg(0, ios_base::beg);

    	probabilities.clear();

    	while(getline(file,line)) {

    		stringstream ss(line);
    		vector<int> p;

    		while(ss>>temp) {
    			p.push_back(temp);
    		}
    		point p1(p);

    		double min_dist = p1.dist(current_set[0]);
    		for(int i=1;i<current_set.size();i++) {
    			double local_dist = p1.dist(current_set[i]);
    			min_dist = min(min_dist,local_dist);
    		}
    		probabilities.push_back(min_dist);
    	}

    	discrete_distribution<> distribution(probabilities.begin(), probabilities.end());

    	chosen = distribution(gen);

    	temp=0;

   		file.clear();
   		file.seekg(0, ios_base::beg);

	    while(getline(file,line)) {
	    	if(temp==chosen) {
	    		stringstream ss(line);
	    		vector<int> p;

	    		while(ss>>temp) {
	    			p.push_back(temp);
	    		}
	    		point p1(p);
	    		current_set.push_back(p1);
	    		break;
	    	} else {
	    		temp++;
	    	}
	    }

    }


    return current_set;
}
*/

vector<point> sampling::generate2(vector<point> points) {

    srand(time(NULL));

    set<int> ans;

    int remaining = centers;

    vector<point> current_set;

    if(points.size()==0) {
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
            ans.insert(chosen);

        }

        set<int>::iterator it=ans.begin();

        int temp =0;

        file.clear();
        file.seekg(0, ios_base::beg);

        while(getline(file,line)) {
            if(temp== (*it)) {
                stringstream ss(line);
                vector<int> p;

                while(ss>>temp) {
                    p.push_back(temp);
                }
                point p1(p);
                current_set.push_back(p1);
                it++;
                if(it==ans.end()) break;
            } else {
                temp++;
            }
        }

    } else {
        //sample with probabilities equal to min distance

        string line;
        vector<double> probabilities;

        while(getline(file,line)) {

            stringstream ss(line);
            vector<int> p;
            int temp;
            while(ss>>temp) {
                p.push_back(temp);
            }
            point p1(p);

            double min_dist = p1.dist(points[0]);
            for(int i=1; i<points.size(); i++) {
                double local_dist = p1.dist(points[i]);
                min_dist = min(min_dist,local_dist);
            }
            probabilities.push_back(min_dist);
        }


        random_device rd;
        mt19937 gen(rd());
        discrete_distribution<> d(probabilities.begin(), probabilities.end());

        while(ans.size()<remaining) {
            int chosen = d(gen);
            ans.insert(chosen);
        }

        set<int>::iterator it=ans.begin();

        int temp =0;

        file.clear();
        file.seekg(0, ios_base::beg);

        while(getline(file,line)) {
            if(temp== (*it)) {
                stringstream ss(line);
                vector<int> p;

                while(ss>>temp) {
                    p.push_back(temp);
                }
                point p1(p);
                current_set.push_back(p1);
                it++;
                if(it==ans.end()) break;
            } else {
                temp++;
            }
        }

    }

    return current_set;
}


/*
int main() {

	srand(time(NULL));
	string filename = "in.txt";
	int k =2;

    vector<point> jk;

	for(int i=0;i<5;i++) {
		cout<<"Sampling for "<<i+1<<"th time"<<endl;

		sampling s(filename,k);
		jk = s.generate2(jk);

		for(int i=0;i<jk.size();i++) {
			jk[i].print();
		}
	}

	return 0;

}
*/