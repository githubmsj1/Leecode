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
		vector<vector<int> >subsets(vector<int> &S)
		{
			sort(S.begin(),S.begin());
			vector<vector<int> > result;
			vector<int> path;

			subsets(S,path,0,result);
			return result;
		}
		
	private:
		static void subsets(const vector<int> &S,vector<int> &path,int step,vector<vector<int> >&result)
		{
			if(step==S.size())
			{
				result.push_back(path);
				return;
			}

			subsets(S,path,step+1,result);

			path.push_back(S[step]);
			subsets(S,path,step+1,result);
			path.pop_back();
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
	string start("hit");
	string end=("cog");
	string dict1[]={"hot","dot","dog","lot","log"};

	vector <int>va(a,a+sizeof(a)/sizeof(int));
	//s.ladderLength(start,end,dict);
	Solution s;
	vector<vector<int> > vb=s.subsets(va);
	vector<vector<int> >::iterator i=vb.begin();
	while(i!=vb.end())
	{
		vector<int>::iterator j=(*i).begin();
		while(j!=(*i).end())
		{
			cout<<*j<<" ";
			j++;
		}
		i++;
		cout<<endl;
	}
	return 0;
}
