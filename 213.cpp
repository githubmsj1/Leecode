#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>

using namespace std;
class Solution
{
	public:
		int search(int A[],int n,int target)
		{	
			int first=0;
			int last=n;

			while(first!=last)
			{
				int mid=(first+last-1)/2;
				if(A[mid]==target)
				return mid;

				if(A[first]<=A[mid])
				{
					if(target<A[mid]&&target>=A[first])
					last=mid;
					else
					{
						first=mid+1;
					}
				}
				else
				{
					if(target>A[mid]&&target<A[last-1])
					first=mid+1;
					else
					last=mid;
				}
			}
			return -1;
		}
};

int main()
{
	int a[]={7,8,9,2,3};
	Solution s;
	cout<<s.search(a,sizeof(a)/sizeof(int),3)<<endl;


	return 0;
}

