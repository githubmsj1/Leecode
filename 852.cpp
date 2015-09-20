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
		vector<vector<int> >combine(int n,int k)
		{
			vector<vector<int> >result;
			vector<int>path;
			dfs(n,k,1,0,path,result);
			return result;
		}
	private:
		static void dfs(int n,int k,int start,int cur,vector<int> &path,vector<vector<int> >&result)
		{
			if(cur==k)
				result.push_back(path);
			for(int i=start;i<=n;i++)
			{
				path.push_back(i);
				dfs(n,k,i+1,cur+1,path,result);
				path.pop_back();
			}
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
	int a[]={1,2,3};
	Solution s;
	vector<vector<int> >result=s.combine(4,2);

	for(int i=0;i<result.size();i++)
	{
		for(int j=0;j<result[0].size();j++)
		{
			cout<<result[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
