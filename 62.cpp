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
		ListNode *mergeTwoLists(ListNode *l1,ListNode *l2)
		{
			ListNode head(-1);

			for(ListNode*p=&head;l1!=NULL||l2!=NULL;p=p->next)
			{
				int val1=l1==NULL?124*sizeof(int):l1->val;
				int val2=l2==NULL?124*sizeof(int):l2->val;
				if(val1<=val2)
				{
					p->next=l1;
					l1=l1->next;
				}
				else
				{
					p->next=l2;
					l2=l2->next;
				}
			}
			return head.next;
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
	TreeNode* node1=new TreeNode(2);
	node1->left=new TreeNode(1);
	node1->left->left=new TreeNode(1);

	ListNode *list1=new ListNode(2);
	list1->next=new ListNode(4);
	list1->next->next=new ListNode(7);
	list1->next->next->next=new ListNode(8);
	list1->next->next->next->next=new ListNode(9);

	
	ListNode *list2=new ListNode(1);
	list2->next=new ListNode(3);
	list2->next->next=new ListNode(6);
	//s.ladderLength(start,end,dict);
	Solution s;

	ListNode *list3=s.mergeTwoLists(list1,list2);

	while(list3!=NULL)
	{
		cout<<list3->val<<endl;
		list3=list3->next;
	}
	return 0;
}
