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
#include<sstream>

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

ListNode* array2List(int a[],int n)
{
	
	ListNode *head=new ListNode(a[0]);
	ListNode *ptr=head;
	for(int i=1;i<n;i++)
	{
		ptr->next=new ListNode(a[i]);
		ptr=ptr->next;
	}
	return head;
}
void printList(ListNode *head)
{
	ListNode *temp=head;
	while(temp!=NULL)
	{
		cout<<temp->val<<" ";
		temp=temp->next;
	}
	cout<<endl;
}
class Solution
{
	public:
		int evalRPN(vector<string>&tokens)
		{
			int x,y;
			string token=tokens.back();
			tokens.pop_back();
			if(is_operator(token))
			{
				cout<<token<<endl;
				y=evalRPN(tokens);
				x=evalRPN(tokens);
				switch (token[0])
				{
					case '+':x+=y;
					break;
					case '-':x-=y;
					break;
					case '*':x*=y;
					break;
					default:x/=y;
					break;
				}
			}
			else
			{
				
				istringstream stream1;
				stream1.str(token);
				stream1>>x;
			}
			return x;
		}
		private:
			bool is_operator(const string &op)
			{
				return op.size()==1&&string("+-*/").find(op)!=string::npos;
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
	int array[]={-7,2,-1,5,-4,-8,9,5};
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
	string stra[]={"4","13","5","/","+"};
	vector<string>istr(stra,stra+sizeof(stra)/sizeof(string));
	cout<<s.evalRPN(istr)<<endl;
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
