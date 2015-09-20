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
		int minDepth(const TreeNode *root)
		{
			return minDepth(root,false);
		}

	private:
		static int minDepth(const TreeNode *root,bool hasbrother)
		{
			if(!root)return hasbrother?9999:0;
			
			return 1+min(minDepth(root->left,root->right!=NULL),minDepth(root->right,root->left!=NULL));
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
	//node1->right=new TreeNode(1);
	node1->left->left=new TreeNode(1);


	//s.ladderLength(start,end,dict);
	Solution s;
	cout<<s.minDepth(node1)<<endl;
	return 0;
}
