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
		TreeNode* buildTree(vector<int>& inorder,vector<int>&postorder)
		{
			return buildTree(inorder.begin(),inorder.end(),postorder.begin(),postorder.end());

		}

		template<typename Itr>
		TreeNode* buildTree(Itr in_first,Itr in_last,Itr post_first,Itr post_last)
		{
			if(in_first==in_last)return NULL;
			if(post_first==post_last)return NULL;

			TreeNode* root=new TreeNode(*(post_last-1));
			
			Itr in_root_post=find(in_first,in_last,*(post_last-1));
			int left_size=distance(in_first,in_root_post);
			Itr post_left_last=post_first+left_size;

			root->left=buildTree(in_first,in_root_post,post_first,post_left_last);
			root->right=buildTree(in_root_post+1,in_last,post_left_last,post_last-1);
			return root;
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
	int array[]={4,2,5,1,6,3};
	int array1[]={4,5,2,6,3,1};
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
	
	vector<int>inorder(array,array+sizeof(array)/sizeof(int));
	vector<int>postorder(array1,array1+sizeof(array1)/sizeof(int));


	Solution s;
	
	TreeNode *result=s.buildTree(inorder,postorder);
	cout<<result->left->val<<endl;
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
