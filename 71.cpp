#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<iterator>
#include<set>
#include<stack>
#include<math.h>
#include<list>

//#include<tr1/unordered_map>

using namespace std;
template<class type>
class ListNode1
{
	public:
		ListNode1(type _value)
		{
			value=_value;
			next=NULL;
			prev=NULL;
		}

		type value;
		ListNode1<type>* next;
		ListNode1<type>* prev;
};
struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int x):val(x),next(NULL){}
};

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x):val(x),left(NULL),right(NULL){}
};
class Solution
{
	public:
		vector<int>searchRange(int A[],int n,int target)
		{
			int *lr =lower(A,A+n,target);
			int *up =upper(A,A+n,target);
			
			if(lr==A+n||*lr!=target)
			{
				int a[]={1,-1};
				return vector<int>(a,a+2);
			}
			else
			{
				int a[]={distance(A,lr),distance(A,up-1)};
				return vector<int>(a,a+2);
			}

		}

		template<typename Forward,typename T>
		Forward lower(Forward first,Forward last,T value)
		{
			while(first!=last)
			{
				Forward mid=first+distance(first,last)/2;
				if(value>*mid)first=++mid;
				else last=mid;
			}
			return first;
		}
		template<typename Forward,typename T>
		Forward upper(Forward first,Forward last,T value)
		{
			while(first!=last)
			{
				Forward mid=first+distance(first,last)/2;
				if(value>=*mid)first=++mid;
				else last=mid;
			}
			return first;
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
	int a[20]={51,12,3,5};
	int b[]={2,9,3,4,6,8,1,7,10,5,5};
	sort(a,a+sizeof(b)/sizeof(int));
	sort(b,b+sizeof(b)/sizeof(int));
	Solution s;
	size_t q=sizeof(b)/sizeof(int);

	vector<int>w=s.searchRange(b,q,5);
	cout<<w[0]<<","<<w[1]<<endl;
	return 0;
}
