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
		void solve(vector<vector<char> >&board)
		{
			if(board.size()==0)return;

			const int m=board.size();
			const int n=board[0].size();
			for(int i=0;i<n;i++)
			{
				bfs(board,0,i);
				bfs(board,m-1,i);				
			}

			for(int j=1;j<m-1;j++)
			{
				bfs(board,j,0);
				bfs(board,j,n-1);
			}

			for(int i=0;i<n;i++)
			{
				for(int j=0;j<m;j++)
				{
					if(board[i][j]=='O')
						board[i][j]='X';
					else if(board[i][j]=='+')
						board[i][j]='O';
				}
			}
		}

	private:
		void bfs(vector<vector<char> >&board,int i,int j)
		{
			queue<int>q;
			visit(board,i,j,q);
			while(!q.empty())
			{
				int cur=q.front();q.pop();
				int x=cur/board[0].size();
				int y=cur/board[0].size();


				visit(board,x-1,y,q);
				visit(board,x,y-1,q);
				visit(board,x+1,y,q);
				visit(board,x,y+1,q);

			}

		}

		void visit(vector<vector<char> >&board,int i,int j,queue<int >&q)
		{
			const int m=board.size();
			const int n=board[0].size();
			if(i<0||i>=m||j<0||j>=n||board[i][j]!='O')
			{
				return;
			}
			board[i][j]='+';
			q.push(i*n+i);
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
	s.solve(input);
	vector<vector<char> >::iterator i=input.begin();
	while(i!=input.end())
	{
		vector<char>::iterator j=(*i).begin();
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
