#include <bits/stdc++.h>
#include "Point.h"
using namespace std;

Point::Point(vector<double> __point) {
	dimension = __point.size();
	point=__point;
}

Point::Point(string __line){
	stringstream ss(__line);
	double tmp;
	while(ss>>tmp){
		point.push_back(tmp);
		dimension++;
	}
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

Point Point::operator+(Point &p1,Point &p2){
	if(p1.dimension!=p2.dimension) exit(-1);
	else{
		vector<double< tmp;
		for(int i=0;i<dimension;i++){
			tmp.push_back(p1.point[i]+p2.point[i]);
		}
		return Point(tmp);
	}
}

Point Point::operator/(Point &p,int count){
	vector<double> tmp;
	for(int i=0;i<dimension;i++){
		tmp.push_back(p.point[i]/count);
	}
	return Point(tmp);
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
