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
		ListNode *reverseBetween(ListNode *head,int m,int n)
		{
			ListNode dummy(-1);
			dummy.next=head;

			ListNode *prev_m,*prev=&dummy;
			for(int i=1;i<=n;i++)
			{
				if(i==m)prev_m=prev;

				if(i>m&&i<=n)
				{
					prev->next=head->next;
					head->next=prev_m->next;
					prev_m->next=head;
					head=prev;

				}

				prev=head;
				head=head->next;
			}

			return dummy.next;
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
	string start("hit");
	string end=("cog");
	string dict1[]={"hot","dot","dog","lot","log"};
	
	ListNode *node=new ListNode(1);
	ListNode *head=node;

	for(int i=2;i<=10;i++)
	{
		node->next=new ListNode(i);
		node=node->next;
	}

	
	node=head;
	for(int i=1;i<=10;i++)
	{
		cout<<node->val<<" ";
		node=node->next;
	}
	cout<<endl;




	set<string>dict(dict1,dict1+sizeof(dict1)/sizeof(string));
	
	Solution s;
	s.reverseBetween(head,3,7);
	
	
	node=head;
	for(int i=1;i<=10;i++)
	{
		cout<<node->val<<" ";
		node=node->next;
	}
	cout<<endl;

	//s.ladderLength(start,end,dict);
	return 0;
}
