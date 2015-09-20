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
#include<utility>

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
		int minDepth(TreeNode* root)
		{
			if(root==NULL)
				return 0;

			int result=pow(16,sizeof(int))-1;
			stack<pair<TreeNode*,int> >s;
			s.push(make_pair(root,1));
			while(!s.empty())
			{
				TreeNode* node=s.top().first;
				int depth=s.top().second;
				s.pop();

				if(node->left==NULL&&node->right==NULL)
					result=min(result,depth);

				if(node->left&&result>depth)
					s.push(make_pair(node->left,depth+1));

				if(node->right&&result>depth)
					s.push(make_pair(node->right,depth+1));

			}
			return result;

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
