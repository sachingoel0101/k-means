int main(void) {
    vector<double> tmp1,tmp2,tmp3,tmp4,tmp5;
	tmp1.push_back(5.25);
	tmp1.push_back(5.13);
	tmp2.push_back(5.0);
	tmp2.push_back(2.0);
	tmp3.push_back(2.8);
	tmp3.push_back(2.4);
	tmp4.push_back(1.5);
	tmp4.push_back(6.5);
	tmp5.push_back(3.5);
	tmp5.push_back(5);
	vector<Point> p;
	p.push_back(tmp1);
	p.push_back(tmp2);
	p.push_back(tmp3);
	p.push_back(tmp4);
	p.push_back(tmp5);
	Cluster c("a.txt",2,5,p);
	c.print();
	while(!c.converged()){
		try{
			c.iterate();
			c.print();
			cout<<'\n';
		} catch(...){
			cout<<"Exception"<<endl;
		}
	}
}
