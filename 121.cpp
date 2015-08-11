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
		bool canJump(int A[],int n)
		{
			int reach=0;
			for(int i=0;i<=reach&&reach<n;i++)
			{
				reach=max(reach,i+A[i]);
			}
			return reach>=(n-1);
		}

};



int main()
{
	int src1[][3]=
	{
	{9,9,0},
	{1,0,5},
	{2,5,6}
	};
	string start("hit");
	string end=("cog");
	string dict1[]={"hot","dot","dog","lot","log"};
	string str="aab";
	
	int src[]={3,2,1,1,4};
	Solution s;
	cout<<s.canJump(src,sizeof(src)/sizeof(int))-true<<endl;

	return 0;
}
