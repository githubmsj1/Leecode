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
		vector<vector<string> >solveNQueens(int n)
		{
			this->columns=vector<int>(n,0);
			this->principal_diagonals=vector<int>(2*n,0);
			this->counter_diagonals=vector<int>(2*n,0);

			vector<vector<string> >result;
			vector<int>C(n,0);
			dfs(0,C,result);
			return result;
		}
			

	
		void print1(vector<vector<string> >result)
		{
			for(int i=0;i<result.size();i++)
			{
				for(int j=0;j<result[0].size();j++)
				{
					cout<<result[i][j]<<endl;
				}
				cout<<"~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
			}
		}
	private:
		vector<int> columns;
		vector<int> principal_diagonals;
		vector<int> counter_diagonals;

		void dfs(int row,vector<int>&C,vector<vector<string> >&result)
		{
			const int N=C.size();
			if(row==N)
			{
				vector<string> solution;
				for(int i=0;i<N;i++)
				{
					string s(N,'.');
					for(int j=0;j<N;j++)
					{
						if(j==C[i])
							s[j]='Q';
					}
					solution.push_back(s);
				}
				result.push_back(solution);
				return;
			}

			for(int j=0;j<N;j++)
			{
				const bool ok=columns[j]==0&&principal_diagonals[row+j]==0&&counter_diagonals[row-j+N]==0;
				if(ok)
				{
					C[row]=j;
					columns[j]=principal_diagonals[row+j]=counter_diagonals[row-j+N]=1;
					dfs(row+1,C,result);
					
					columns[j]=principal_diagonals[row+j]=counter_diagonals[row-j+N]=0;
				}
			}
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
	
	

	vector <int>va(a,a+sizeof(a)/sizeof(int));
	//s.ladderLength(start,end,dict);
	
	
	Solution s;
	s.print1(s.solveNQueens(4));
	
	
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
