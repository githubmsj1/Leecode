#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<iterator>
#include<set>
#include<stack>
//#include<tr1/unordered_map>

using namespace std;
class Solution
{
	public:
		void rotate(vector<vector<int> >& matrix)
		{
			const int n=matrix.size();

			for(int i=0;i<n;i++)
			{
				for(int j=0;j<n-i;j++)
				{
					swap(matrix[i][j],matrix[n-1-j][n-1-i]);
				}
			}

			for(int i=0;i<n/2;i++)
			{
				for(int j=0;j<n;j++)
				{
					swap(matrix[i][j],matrix[n-1-i][j]);
				}
			}
		}
			
};



int main()
{
	int src[]={0,1,0,2,1,0,1,3,2,1,2,1};
	int src1[]={1,0,0,1};
	//vector<int>srcv(src,src+sizeof(src)/sizeof(int));
	int matrix[][3]=
	{
	{1,2,3},
	{4,5,6},
	{7,8,9}
	};
	
	//cout<<sizeof(matrix)/sizeof(matrix[0])<<endl;
	Solution s;
	vector<vector<int> >v;
	for(int i=0;i<sizeof(matrix)/sizeof(matrix[0]);i++)
		v.push_back(vector<int>(matrix[i],matrix[i]+sizeof(matrix[i])/sizeof(int)));	
	s.rotate(v);

	for(int i=0;i<v.size();i++)
	{
		for(int j=0;j<v[i].size();j++)
		{
			cout<<v[i][j]<<" ";
		}
		cout<<endl;	
	}


	return 0;
}
