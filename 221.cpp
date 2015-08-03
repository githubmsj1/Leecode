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
class Solution
{
	public:
		ListNode* addTwoNumbers(ListNode *l1,ListNode *l2)
		{
			ListNode head(-1);
			int carry=0;

			ListNode* prev=&head;
			
			for(ListNode *pa=l1,*pb=l2;
			pa!=NULL||pb!=NULL;
			pa=pa==NULL?NULL:pa->next,
			pb=pb==NULL?NULL:pb->next,
			prev=prev->next)
			{
				const int ai=pa==NULL?0:pa->val;
				const int bi=pb==NULL?0:pb->val;
				const int value=(ai+bi+carry)%10;
				carry=(ai+bi+carry)/10;
				prev->next=new ListNode(value);
			}

			if(carry>0)
			{
				prev->next=new ListNode(carry);
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
	int a[]={1,2,3,4};
	int b[]={7,8,9,0};
	
	ListNode *la=new ListNode(0),*lb=new ListNode(0);
	ListNode *hla=la,*hlb=lb;
	la->val=a[0];lb->val=b[0];
	int size1=sizeof(a)/sizeof(int),count=size1;
	count--;
	while(count--)
	{
		la->next=new ListNode(a[size1-1-count]);
		lb->next=new ListNode(b[size1-1-count]);
		la=la->next;
		lb=lb->next;
	}
	Solution s;
	ListNode *result=s.addTwoNumbers(hla,hlb);
	
	while(1)
	{
		cout<<result->val<<endl;
		if(result->next!=NULL)
			result=result->next;
		else
			break;
	}
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
