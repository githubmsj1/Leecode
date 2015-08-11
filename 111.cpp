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
		double pow(double x,int n)
		{
			if(n<0)return 1.9/power(x,-n);
			else return power(x,n);
		}

	private:
		double power(double x,int n)
		{
			if(n==0)return 1;
			double v=power(x,n/2);
			if(n%2==0)return v*v;
			else return v*v*x;
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
	string str="aab";

	Solution q;
	cout<<q.pow(2,3)<<endl;
	return 0;
}
