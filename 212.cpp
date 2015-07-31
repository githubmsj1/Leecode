#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>

using namespace std;
class Solution1{
public:
	int removeDuplicates(int A[],int n)
	{
		if(n==0)return 0;
		int occur=1;
		int index=0;
		for(int i=0;i<n;i++)
		{
			if(A[index]==A[i])
			{
				if(occur<2)
				{
					A[++index]=A[i];
					occur++;
				}
			}
			else
			{
				A[++index]=A[i];
				occur=1;
			}
		}
		return index+1;

	}
};

class Solution2
{
	public:
	int removeDuplicates(int A[],int n)
	{
		int index=0;
		for(int i=0;i<n;i++)
		{
			if(i>0&&i<n-1&&A[i]==A[i-1]&&A[i]==A[i+1])
			continue;
			A[index++]=A[i];
		}
		return index;
	}
};

int main()
{
	int a[]={1,1,2,2,2,3,3,4,5,6};
	Solution2 s;
	s.removeDuplicates(a,sizeof(a)/sizeof(int));
	for(int i=0;i<sizeof(a)/sizeof(int);i++)
	{
		cout<<a[i]<<endl;
	}

	return 0;
}

