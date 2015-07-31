#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<iterator>
//#include<tr1/unordered_map>

using namespace std;
class Solution
{
	public:
		vector<vector<int> > threeSum(vector<int>& num)
		{
			vector<vector<int> >result;
			if(num.size()<3)return result;
			sort(num.begin(),num.end());
			const int target =0;

			vector<int>::iterator last=num.end();
			
			int oldi,oldj;
			for(vector<int>::iterator a=num.begin();a<last-2;a++)
			{
				if(a==num.begin()||(*a)!=oldi)
				{
					for(vector<int>::iterator b=a+1;b<last-1;b++)
					{

						if(b==a+1||(*b)!=oldj)
						{
							const int c=target-*a-*b;
							if(binary_search(b+1,last,c))
							{
								int temp[]={*a,*b,c};
								vector<int>tempv(temp,temp+3);
								result.push_back(tempv);
							}
							oldj=*b;
						}

					}

					oldi=*a;
				}
			}
			return result;
		}
		
};


int main()
{
	int src[]={-1,0,1,2,-1,-4};
	vector<int>srcv(src,src+sizeof(src)/sizeof(int));
	Solution s;
	vector<vector<int> >result=s.threeSum(srcv);
	for(vector<vector<int > >::iterator i=result.begin();i<result.end();i++)
	{
		for(vector<int>::iterator j=(*i).begin();j<(*i).end();j++)
		{
			cout<<*j<<" ";
		}
		cout<<endl;

	}
	return 0;
}
