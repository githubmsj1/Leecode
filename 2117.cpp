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
		int climbStairs(int n)
		{
			int prev=0,cur=1;

			for(int i=1;i<=n;i++)
			{
				int tmp=cur;
				cur+=prev;
				prev=tmp;
			}
			return cur;
			
		}
		
		int climbStairs1(int n)
		{
			double s=sqrt(5);
			return floor((pow((1+s)/2,n+1)+pow((1-s)/2,n+1))/s+0.5);
		}
			
};



int main()
{
	int src[]={9,9,9,9};
	vector<int>srcv(src,src+sizeof(src)/sizeof(int));
	
	//cout<<sizeof(matrix)/sizeof(matrix[0])<<endl;
	Solution s;
	cout<<s.climbStairs1(4)<<endl;
	//s.pulsOne(srcv);
	//for(int i=0;i<srcv.size();i++)
	//{
	//	cout<<srcv[i];
	//}
	//cout<<endl;


	return 0;
}
