#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<iterator>
#include<set>
//#include<tr1/unordered_map>

using namespace std;
class Solution
{
	public:
		int removeElement(int A[],int n,int elem)
		{
			return distance(A,remove(A,A+n,elem));
		}
};


int main()
{
	int src[]={1,0,-1,0,-2,2};
	//vector<int>srcv(src,src+sizeof(src)/sizeof(int));
	
	Solution s;
	cout<<s.removeElement(src,sizeof(src)/sizeof(int),1)<<endl;
	cout<<sizeof(src)/sizeof(int)<<endl;
	return 0;
}
