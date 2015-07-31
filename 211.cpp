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

		int index=0;
		for(int i=0;i<n;i++)
		{
			if(A[index]!=A[i])
			A[++index]=A[i];
		}
		return index+1;
	}
};

class Solution2{
public:  
	int removeDuplicates(int A[],int n)
	{
		return distance(A,unique(A,A+n));
	}

};

class Solution3{
public:
	int removeDuplicates(int A[],int n)
	{
		return removeDuplicates(A,A+n,A)-A;
	}

	template<typename InIt,typename OutIt>
	OutIt removeDuplicates(InIt first,InIt last,OutIt output)
	{
		while(first!=last)
		{
			*output++=*first;
			first=find_if(first,last,bind1st(not_equal_to<int>(),*first));
		}
		return output;
	}
};
int main()
{
	int a[]={1,1,2,2,3,3,4,5,6};
	Solution3 s;
	s.removeDuplicates(a,sizeof(a)/sizeof(int));
	for(int i=0;i<sizeof(a)/sizeof(int);i++)
	{
		cout<<a[i]<<endl;
	}

	return 0;
}

