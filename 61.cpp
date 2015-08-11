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
		void merge(int A[],int m,int B[],int n)
		{
			int ia=m-1,ib=n-1,icur=m+n-1;
			while(ia>=0&&ib>=0)
			{
				A[icur--]=A[ia]>B[ib]?A[ia--]:B[ib--];

			}
			while(ib>=0)
			{
				A[icur--]=B[ib--];
			}
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
	int b[]={4,6,8,1};
	sort(a,a+sizeof(b)/sizeof(int));
	sort(b,b+sizeof(b)/sizeof(int));
	Solution s;
	size_t q=sizeof(b)/sizeof(int);
	s.merge(a,q,b,q);
	q*=2;
	while(q--)
	{
		cout<<a[2*sizeof(b)/sizeof(int)-1-q];
		cout<<" "<<2*sizeof(b)/sizeof(int)-1-q<<endl;
	}

	return 0;
}
