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
		vector<vector<string> > partition(string s)
		{
			vector<vector<string> > result;
			vector<string>output;
			DFS(s,0,output,result);
			return result;
		}

		void DFS(string &s,int start,vector<string>& output,vector<vector<string> >&result)
		{
			if(start==s.size())
			{
				result.push_back(output);
				return;
			}

			for(int i=start;i<s.size();i++)
			{
				if(isPalindrome(s,start,i))
				{
					output.push_back(s.substr(start,i-start+1));
					DFS(s,i+1,output,result);
					output.pop_back();//current
				}
			}
		}
		bool isPalindrome(string &s,int start,int end)
		{
			while(start<end)
			{
				if(s[start]!=s[end])return false;
				start++;
				end--;
			}
			return true;
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
	
	Solution s;
	vector<vector<string> >result=s.partition(str);
	int count=result.size();
	while(count--)
	{
		int count1=result[count].size();
		while(count1--)
			cout<<result[count][count1]<<" ";
		cout<<endl;
	}
	//s.ladderLength(start,end,dict);
	return 0;
}
