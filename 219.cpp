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
		vector<vector<int> >fourSum(vector<int> &num,int target)
		{
			if(num.size()<4)return vector<vector<int> >();
			sort(num.begin(),num.end());

			map<int,vector<pair<int,int> > >cache;
			for(size_t a=0;a<num.size()-3;a++)
				for(size_t b=a+1;b<num.size()-2;b++)
				{
					cache[num[a]+num[b]].push_back(pair<int,int>(a,b));
				}
			
			set<vector<int> >result;

			for(size_t c=2;c<num.size()-1;c++)
			{
				for(size_t d=c+1;d<num.size();d++)
				{
					const int key=target-num[c]-num[d];
					if(cache.find(key)!=cache.end())
					{
						for(size_t k=0;k<cache[key].size();k++)
						{
							if(c<=cache[key][k].second) continue;
							int temp[]={num[cache[key][k].first],num[cache[key][k].second],num[c],num[d]};
							result.insert(vector<int>(temp,temp+sizeof(temp)/sizeof(int)));
						}
					}
				}
			}
			return vector<vector<int> >(result.begin(),result.end());
				
		}
};


int main()
{
	int src[]={1,0,-1,0,-2,2};
	vector<int>srcv(src,src+sizeof(src)/sizeof(int));
	Solution s;
	vector<vector<int> >r=s.fourSum(srcv,0);
	for(int i=0;i<r.size();i++)
	{
		for(int j=0;j<r[i].size();j++)
		{
			cout<<r[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
