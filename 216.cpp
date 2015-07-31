#include<iostream>
#include<map>
#include<vector>
//#include<tr1/unordered_map>

using namespace std;
class Solution
{
	public:
		int longestConsecutive(vector<int>num)
		{
			map<int,bool>used;
			for(vector<int>::iterator i=num.begin();i!=num.end();i++) used[*i]=false;

			int longest=0;
			for(vector<int>::iterator i=num.begin();i!=num.end();i++)
			{
				if(used[*i]==true)
				continue;
				
				int length=1;
				
				used[*i]=true;
				
				for(int j=*i+1;used.find(j)!=used.end();++j)
				{	
					used[j]=true;
					++length;
				}
				
				for(int j=*i-1;used.find(j)!=used.end();--j)
				{
					used[j]=true;
					++length;
				}
				
				longest=max(longest,length);
			}

			return longest;


		}
		
};


int main()
{
	Solution s1;
	int a[]={1,2,3,6,7,8,10,11};
	vector<int> a1(a,a+sizeof(a)/sizeof(int));
	cout<<s1.longestConsecutive(a1)<<endl;
	return 0;
}
