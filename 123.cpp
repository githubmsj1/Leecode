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
		int maxProfit(vector<int>&prices)
		{
			if(prices.size()<2)return 0;
			int profit=0;
			int cur_min=prices[0];

			for(int i=1;i<prices.size();i++)
			{
				profit=max(profit,prices[i]-cur_min);
				cur_min=min(cur_min,prices[i]);
			}
			return profit;
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
	int array[]={7,2,3,5,4,8,9,5};
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
	
	vector<int>prices(array,array+sizeof(array)/sizeof(int));
	cout<<s.maxProfit(prices)<<endl;
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
