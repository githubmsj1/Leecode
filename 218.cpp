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
		int threeSumCloest(vector<int>& num,int target)
		{
			int result=0;
			int min_gap=65535;

			sort(num.begin(),num.end());

			for(vector<int>::iterator a=num.begin();a<num.end()-2;a++)
			{
				vector<int>::iterator b=a+1;
				vector<int>::iterator c=num.end()-1;
				while(b<c)
				{
					const int sum=*a+*b+*c;
					const int gap=abs(sum-target);

					if(gap<min_gap)
					{
						result=sum;
						min_gap=gap;
					}

					if(sum<target) ++b;
					else --c;


					
				}
			}
			return result;
		}
		
};


int main()
{
	int src[]={-1,2,1,-4};
	vector<int>srcv(src,src+sizeof(src)/sizeof(int));
	Solution s;
	cout<<s.threeSumCloest(srcv,-5)<<endl;;
	return 0;
}
