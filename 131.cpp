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
		int minimumTotal(vector<vector<int> >& triangle )
		{
			for(int i=triangle.size()-2;i>=0;i--)
				for(int j=0;j<=i;j++)
				{
					triangle[i][j]+=min(triangle[i+1][j],triangle[i+1][j+1]);
				}
				
			return triangle[0][0];
		}

};



int main()
{
	int src1[][3]=
	{
	{9,9,0},
	{1,0,5},
	{2,5,6}
	};
	
	int a[]={2};
	int b[]={3,4};
	int c[]={6,5,7};
	int d[]={4,1,8,3};
	vector<vector<int> >triangle;
	triangle.push_back(vector<int>(a,a+sizeof(a)/sizeof(int)));
	triangle.push_back(vector<int>(b,b+sizeof(b)/sizeof(int)));
	triangle.push_back(vector<int>(c,c+sizeof(c)/sizeof(int)));
	triangle.push_back(vector<int>(d,d+sizeof(d)/sizeof(int)));

	Solution s;
	cout<<s.minimumTotal(triangle)<<endl;

	return 0;
}

