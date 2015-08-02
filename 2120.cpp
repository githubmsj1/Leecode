#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<iterator>
#include<set>
#include<stack>
#include<math.h>
//#include<tr1/unordered_map>

using namespace std;
class Solution
{
	public:
		void setZeros(vector<vector<int> > &matrix)
		{
			const size_t m=matrix.size();
			const size_t n=matrix[0].size();

			bool row_has_zero=false;
			bool col_has_zero=false;

			for(size_t i=0;i<n;i++)
			{
				if(matrix[0][i]==0)
				{
					row_has_zero=true;
					break;
				}
			}

			for(size_t i=0;i<m;i++)
			{
				if(matrix[i][0]==0)
				{
					col_has_zero=true;
					break;
				}
			}

			for(size_t i=1;i<m;i++)
				for(size_t j=1;j<n;j++)
				{
					if(matrix[i][j]==0)
					{
						matrix[i][0]=0;
						matrix[0][j]=0;
					}
				}

			for(size_t i=1;i<m;i++)
				for(size_t j=0;j<n;j++)
				{
					if(matrix[i][0]==0||matrix[0][j]==0)
					{
						matrix[i][j]=0;
					}
				}

			if(row_has_zero)
			{
				fill(&(matrix[0][0]),&(matrix[0][0])+matrix[0].size(),0);
			}

			if(col_has_zero)
			{
				for(size_t i=0;i<m;i++)
				{
					matrix[i][0]=0;
				}
			}

		}

		void print1(vector<vector<int> > src)
		{
			for(size_t i=0;i<src.size();i++)
			{
				for(size_t j=0;j<src[0].size();j++)
				{
					cout<<src[i][j]<<" ";
				}
				cout<<endl;
			}		
		}
			
};



int main()
{
	int src[][3]=
	{
	{9,9,0},
	{1,0,5},
	{2,5,6}
	};

	vector<vector<int> >srcv(sizeof(src)/sizeof(src[0]),vector<int>(sizeof(src[0])/sizeof(int)));
	

	for(size_t i=0;i<srcv.size();i++)
	{
		for(size_t j=0;j<srcv[0].size();j++)
		{
			srcv[i][j]=src[i][j];
		}
	}
	
	//cout<<sizeof(matrix)/sizeof(matrix[0])<<endl;
	Solution s;
	s.print1(srcv);
	
	s.setZeros(srcv);
	cout<<endl;
	s.print1(srcv);

	return 0;
}
