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
		int largestRectangleArea(vector<int>&height)
		{
			stack<int>s;
			height.push_back(0);
			int result=0;
			for(int i=0;i<height.size();)
			{
				if(s.empty()||height[i]>height[s.top()])
					s.push(i++);
				else
				{
					int tmp=s.top();
					s.pop();
					result=max(result,height[tmp]*(s.empty()?i:i-s.top()-1));
				}


			}
			return result;

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
	
	
	Solution s;
	
	vector<int>prices(array,array+sizeof(array)/sizeof(int));
	cout<<s.largestRectangleArea(va)<<endl;
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
