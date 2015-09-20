#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<iterator>
#include<set>
#include<stack>
#include<math.h>
#include<list>
#include<map>
#include<queue>

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
		int serchInsert(int A[],int n,int target)
		{
			return lower_bound(A,A+n,target)-A;
		}

		template<typename ITR,typename T>
		ITR lower_bound(ITR first,ITR last,T value)
		{
			while(first!=last)
			{
				ITR mid=first+(last-first)/2;
				if(value>*mid)first=++mid;
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
	int a[]={1,3,5,7,8,9,11,12,17,18,19};
	string start("hit");
	string end=("cog");
	string dict1[]={"hot","dot","dog","lot","log"};


	//s.ladderLength(start,end,dict);
	Solution s;
	cout<<s.serchInsert(a,sizeof(a)/sizeof(int),6)<<endl;
	return 0;
}
