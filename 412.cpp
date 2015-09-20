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
		int longestValidParentheses(string s)
		{
			int max_len=0,last=-1;
			stack<int>lefts;

			for(int i=0;i<s.size();i++)
			{
				if(s[i]=='(')
				{
					lefts.push(i);
				}
				else
				{
					if(lefts.empty())
					{
						last=i;
					}
					else
					{
						lefts.pop();
						if(lefts.empty())
						{
							max_len=max(max_len,i-last);

						}
						else
						{
							max_len=max_len=max(max_len,i-lefts.top());
						}
					}
				}
			}
			return max_len;
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


	//s.ladderLength(start,end,dict);
	Solution s;
	cout<<s.longestValidParentheses("(()))())()()())()())(")<<endl;
	return 0;
}
