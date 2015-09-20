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
		int candy(vector<int> &ratings)
		{
			const int n=ratings.size();
			int result=n;
			vector<int>increment(n);

			for(int i=1,inc=1;i<n;i++)
			{
				if(ratings[i]>ratings[i-1])
					increment[i]=max(inc++,increment[i]);
				else
					inc=1;
			}

			for(int i=n-2,inc=1;i>=0;i--)
			{
				if(ratings[i]>ratings[i+1])
					increment[i]=max(inc++,increment[i]);
				else
					inc=1;
			}

			for(int i=0;i<n;i++)
				result+=increment[i];
				
			
			return result;
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
	int array[]={4,1};
	char a[]="1110";
	char b[]="0111";
	char c[]="0110";
	char d[]="0000";

	vector<vector<char> >input;
	input.push_back(vector<char>(a,a+sizeof(a)/sizeof(char)));
	input.push_back(vector<char>(b,b+sizeof(b)/sizeof(char)));
	input.push_back(vector<char>(c,c+sizeof(c)/sizeof(char)));
	input.push_back(vector<char>(d,d+sizeof(d)/sizeof(char)));
	
	string start("hit");
	string end=("cog");
	string dict1[]={"hot","dot","dog","lot","log"};
	
	

	//vector <int>va(a,a+sizeof(a)/sizeof(int));
	//s.ladderLength(start,end,dict);
	
	
	Solution s;
	
	
	vector<int>ratings(array,array+sizeof(array)/sizeof(int));
	cout<<s.candy(ratings)<<endl;
	//vector<int>prices(array,array+sizeof(array)/sizeof(int));
	//s.solve(input);
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
