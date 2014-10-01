#include <bits/stdc++.h>
#include "Point.h"
using namespace std;

Point::Point(vector<double> __point) {
	dimension = __point.size();
	point=__point;
}

void Point::print() {
	for (vector<double>::iterator it = point.begin() ; it != point.end(); ++it)
		cout << *it<< ' ';
	cout << '\n';
}

int Point::get_dimension() {
	return dimension;
}

double Point::dist(Point &p) {
	if(p.point.size()==0) {
		return -1;
	} else {
		if(p.get_dimension() != dimension) {
			return -1;
		} else {
			double temp =0.0;
			for(int i=0; i<dimension; i++) 
				temp += (p.point[i]-point[i])*(p.point[i]-point[i]);
			temp = sqrt(temp);
			return temp;
		}
	}
}

double Point::coordinate(int index){
	if(index>=dimension) exit(-1);
	else return point[index];
}

/**int main() {

	vector<double> temp1,temp2;
	double x;
	for(int i=0;i<2;i++) {
		cin>>x;
		temp1.push_back(x);
	}
	Point p1(temp1);
	p1.print();
	for(int i=0;i<2;i++) {
		cin>>x;
		temp2.push_back(x);
	}
	Point p2(temp2);
	p2.print();
	cout<<p1.dist(p2)<<endl;
	return 0;
}
*/
