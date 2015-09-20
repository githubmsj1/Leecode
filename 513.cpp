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

ListNode* array2List(int a[],int n)
{
	
	ListNode *head=new ListNode(a[0]);
	ListNode *ptr=head;
	for(int i=1;i<n;i++)
	{
		ptr->next=new ListNode(a[i]);
		ptr=ptr->next;
	}
	return head;
}
void printList(ListNode *head)
{
	ListNode *temp=head;
	while(temp!=NULL)
	{
		cout<<temp->val<<" ";
		temp=temp->next;
	}
	cout<<endl;
}
class Solution
{
	public:
		vector<int>postorderTraversal(TreeNode *root)
		{
			vector<int>result;
			TreeNode dummy(-1);
			TreeNode *cur,*prev=NULL;

			dummy.left=root;
			cur=&dummy;
			while(cur!=NULL)
			{
				if(cur->left==NULL)
				{
					prev=cur;
					cur=cur->right;
				}
				else
				{
					TreeNode *node=cur->left;
					while(node->right!=NULL&&node->right!=cur)
						node=node->right;

					if(node->right==NULL)
					{
						node->right=cur;
						prev=cur;
						cur=cur->left;
					}
					else
					{
						visit(cur->left,prev,result);
						prev->right=NULL;
						prev=cur;
						cur=cur->right;
					}
				}
			}
			return result;
		}
	private:
		static void reverse(TreeNode *from,TreeNode *to)
		{
			TreeNode *x=from,*y=from->right,*z;
			if(from==to)return;
			while(x!=to)
			{
				z=y->right;
				y->right=x;
				x=y;
				y=z;
			}
		}

		static void visit(TreeNode *from,TreeNode *to,vector<int>&result)
		{
			TreeNode *p=to;
			reverse(from,to);
			while(true)
			{
				result.push_back(p->val);
				if(p==from)
					break;
				p=p->right;
			}
			reverse(to,from);
		}
};



int main()
{
	int src[][3]=
	{
	{0,9,0},
	{1,0,5},
	{2,5,6}
	};
	int array[]={2,1,5,6,2,3};
	char a[]="XXXX";
	char b[]="XOOX";
	char c[]="XXXX";
	char d[]="XOXX";

	vector<vector<char> >input;
	input.push_back(vector<char>(a,a+sizeof(int)));
	input.push_back(vector<char>(b,b+sizeof(int)));
	input.push_back(vector<char>(c,c+sizeof(int)));
	input.push_back(vector<char>(d,d+sizeof(int)));
	
	string start("hit");
	string end=("cog");
	string dict1[]={"hot","dot","dog","lot","log"};
	
	

	vector <int>va(array,array+sizeof(array)/sizeof(int));
	//s.ladderLength(start,end,dict);
	
	TreeNode *head=new TreeNode(1);
	head->right=new TreeNode(2);
	head->right->left=new TreeNode(3);
	Solution s;
	
	vector<int>prices(array,array+sizeof(array)/sizeof(int));
	vector<int> output=s.postorderTraversal(head);
	for(int i=0;i<output.size();i++)
	{
		cout<<output[i]<<" ";
	}
	cout<<endl;
	//s.solve(input);
	//vector<vector<char> >::iterator i=input.begin();
	//while(i!=input.end())
	//{
	//	vector<char>::iterator j=(*i).begin();
	//	while(j!=(*i).end())
	//	{
	//		cout<<*j<<" ";
	//		j++;
	//	}
	//	i++;
	//	cout<<endl;
	//}
	return 0;
}
