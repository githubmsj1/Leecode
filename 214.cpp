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
				int mid=(first+last)/2;
				if(A[mid]==target)
					return mid;
				if(A[first]<A[mid])
				{
					if(target>=A[first]&&target<A[mid])
						last=mid;
					else
						first=mid+1;
				}
				else if(A[first]>A[mid])
				{
					if(target<=A[last-1]&&target>A[mid])
						first=mid+1;
					else
						last=mid;
				}
				else
					first++;
			}
			return -1;
		}
};

int main()
{
	int a[]={7,8,9,2,3,7,7};
	Solution s;
	cout<<s.search(a,sizeof(a)/sizeof(int),3)<<endl;


	return 0;
}

