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
		int canCompleteCircuit(const vector<int> gas,const vector<int> cost)
		{
			int sum=0;
			int total=0;
			int j=-1;

			for(int i=0;i<gas.size();i++)
			{
				sum+=gas[i]-cost[i];
				total+=gas[i]-cost[i];

				if(sum<0)
				{
					sum=0;
					j=i;
				}
			}
			return total>=0?j+1:-1;
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
	
	int gas[]={4,5,6,8,7,9};vector<int>gasv(gas,gas+sizeof(gas)/sizeof(int));
	int cost[sizeof(gas)/sizeof(int)]={1,6,6,15,2,1};vector<int>costv(cost,cost+gasv.size());
	//cout<<sizeof(matrix)/sizeof(matrix[0])<<endl;
	Solution s;
	
	int g=costv.size();
	while(g--)
	{
		cout<<costv[costv.size()-1-g]<<" ";
	}
	cout<<endl;
	cout<<s.canCompleteCircuit(gasv,costv)<<endl;
	return 0;
}
