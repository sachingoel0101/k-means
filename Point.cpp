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
	dimension=0;
	while(ss>>tmp){
		point.push_back(tmp);
		dimension++;
	}
}

void Point::print() {
	cout<<"Data:";
	for (vector<double>::iterator it=point.begin();it!=point.end();++it){
		cout << *it<< ' ';
	}
	cout << "Dimension:"<<dimension<<"\n";
}

int Point::get_dimension() {
	return dimension;
}

vector<double> Point::get_coordinates(){
	return point;
}

double Point::dist(Point p) {
	if(p.get_dimension() != dimension) {
		throw 1;
	} else {
		double temp =0.0;
		vector<double> p_point=p.get_coordinates();
		for(int i=0; i<dimension; i++) 
			temp += (p_point[i]-point[i])*(p_point[i]-point[i]);
		temp = sqrt(temp);
		return temp;
	}
}

void Point::add_point(Point p){
	if(p.get_dimension()!=dimension) throw 1;
	else{
		vector<double> tmp=p.get_coordinates();
		for(int i=0;i<dimension;i++){
			point[i]+=tmp[i];
		}
	}
}

void Point::divide_int(int count){
	for(int i=0;i<dimension;i++)
		point[i]/=count;
}

/**
int main() {
	vector<double> temp1,temp2;
	temp1.push_back(10);
	temp1.push_back(12.5);
	temp2.push_back(3);
	temp2.push_back(1.5);
	Point p1(temp1);
	Point p2(temp2);
	string line="2.3 5.6 7.8";
	Point p3(line);
	p1.print();p2.print();p3.print();
	cout<<p1.dist(p2)<<endl;
	p1.add_point(p2);
	p1.print();
	p1.add_point(p3);
	p1.print();
	return 0;
}
*/
