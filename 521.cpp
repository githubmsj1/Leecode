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
		TreeNode* buildTree(vector<int>& preorder,vector<int>& inorder)
		{
			return buildTree(preorder.begin(),preorder.end(),inorder.begin(),inorder.end());
		}

		template<typename Itr>
		TreeNode* buildTree(Itr pre_first,Itr pre_last,Itr in_first,Itr in_last)
		{
			if(pre_first==pre_last)return (TreeNode*)NULL;
			if(in_first==in_last)return (TreeNode*)NULL;

			TreeNode *root=new TreeNode(*pre_first);

			Itr inRootPos=find(in_first,in_last,*pre_first);
			size_t leftSize=distance(in_first,inRootPos);

			root->left=buildTree(pre_first+1,pre_first+leftSize+1,in_first,in_first+leftSize);
			root->right=buildTree(pre_first+leftSize+1,pre_last,inRootPos+1,in_last);
			
			return root;
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
	
	int preo[]={5,2,1,4,3,6,8,7,9,11,10};
	int ino[]={1,2,3,4,5,6,7,8,9,10,11};
	vector<int>preov(preo,preo+sizeof(preo)/sizeof(int));
	vector<int>inov(ino,ino+sizeof(ino)/sizeof(int));
	Solution s;
	TreeNode *ptr=s.buildTree(preov,inov);
	ptr=ptr->left->right->left;
	cout<<ptr->val<<endl;


	//int size1=sizeof(a)/sizeof(int);
	//TreeNode *input,*root1;
	//
	//input=new TreeNode(a[0]);
	//root1=input;
	//input->left=new TreeNode(a[1]);
	//input->right=new TreeNode(a[2]);
	//input=input->right;
	//input->right=new TreeNode(a[3]);
	//
	//Solution s;
	//vector<int> output=s.preorderTraversal(root1);
	//
	//size_t qw=output.size();
	//while(qw--)
	//{
	//	cout<<output[output.size()-1-qw]<<endl;
	//}
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
