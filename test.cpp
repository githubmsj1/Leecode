#include<iostream>
#include<vector>
#include<set>
using namespace std;

int main()
{
	int q[]={1,2,3};
	//set<vector<int> >a;
	//a.insert(vector<int>{1,2,3});
	vector<int>a(q,q+3);
	//q[0]=9;
	reverse_iterator<vector<int>::iterator > i=(vector<int>::reverse_iterator)a.end();

	cout<<*(i+1)<<endl;
	return 0;
}
