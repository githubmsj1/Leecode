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
		vector<int> preorderTraversal(TreeNode *root)
		{
			vector<int> result;
			TreeNode *cur,*prev;

			cur=root;
			while(cur!=NULL)
			{
				if(cur->left==NULL)
				{
					result.push_back(cur->val);
					cur=cur->right;
				}
				else
				{
					TreeNode *node=cur->left;
					while(node->right!=NULL&&node->right!=cur)
					{
						node=node->right;
					}

					if(node->right==NULL)
					{
						result.push_back(cur->val);
						node->right=cur;
						cur=cur->left;
					}
					else
					{
						node->right=NULL;
						cur=cur->right;
					}
				}
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
	int a[]={1,2,3,4};
	int b[]={7,8,9,0};
	
	int size1=sizeof(a)/sizeof(int);
	TreeNode *input,*root1;
	
	input=new TreeNode(a[0]);
	root1=input;
	input->left=new TreeNode(a[1]);
	input->right=new TreeNode(a[2]);
	input=input->right;
	input->right=new TreeNode(a[3]);
	
	Solution s;
	vector<int> output=s.preorderTraversal(root1);
	
	size_t qw=output.size();
	while(qw--)
	{
		cout<<output[output.size()-1-qw]<<endl;
	}
	//count=size1;
	//count=size1;
	//la=hla;lb=hlb;
	//while(count--)
	//{
	//	cout<<la->val<<endl;
	//	la=la->next;
	//}
	
	//ListNode<int>* a=new ListNode<int>(2);
	//vector<vector<int> >srcv(sizeof(src)/sizeof(src[0]),vector<int>(sizeof(src[0])/sizeof(int)));
	

	//for(size_t i=0;i<srcv.size();i++)
	//{
	//	for(size_t j=0;j<srcv[0].size();j++)
	//	{
	//		srcv[i][j]=src[i][j];
	//	}
	//}
	

	return 0;
}
