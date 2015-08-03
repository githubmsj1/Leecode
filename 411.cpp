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
		bool isValid(string const& s)
		{
			string left="([{";
			string right=")]}";
			stack<char>stk;

			for(int i=0;i<s.size();i++)
			{
				if(left.find(s[i])!=string::npos)
				{
					stk.push(s[i]);
				}
				else if(!stk.empty()&&stk.top()==left[right.find(s[i])])
				{
					stk.pop();
				}
				else
				{
					return false;
				}
			}
			return stk.empty();
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
	
	Solution s;
	cout<<s.isValid("([])")<<endl;
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
