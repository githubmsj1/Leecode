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
		int trap(int a[],int n)
		{
			stack<pair<int,int> >s;
			int water=0;
			for(int i=1;i<n;i++)
			{	
				int height=0;
				while(!s.empty())
				{
					int bar=s.top().first;
					int pos=s.top().second;
					water+=(min(bar,a[i])-height)*(i-pos-1);
					height=bar;
					if(a[i]<bar)
						break;
					else
						s.pop();

				}
				s.push(make_pair(a[i],i));
			}
			return water;
		}
		
		int trap1(int a[],int n)
		{
			int max=0;
			for(int i=0;i<n;i++)
				if(a[i]>a[max])
					max=i;

			int water=0;
			
			for(int i=0,peak=0;i<max;i++)
			{
				if(a[i]>peak)
					peak=a[i];
				else
					water+=peak-a[i];
			}

			for(int i=n-1,top=0;i>max;i--)
			{
				if(a[i]>top)
					top=a[i];
				else
					water+=top-a[i];

			}

			return water;

		}
			
};



int main()
{
	int src[]={0,1,0,2,1,0,1,3,2,1,2,1};
	int src1[]={1,0,0,1};
	//vector<int>srcv(src,src+sizeof(src)/sizeof(int));
	Solution s;
	cout<<s.trap1(src1,sizeof(src1)/sizeof(int))<<endl;
	return 0;
}
