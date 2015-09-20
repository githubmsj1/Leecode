#include<iostream>
#include<fstream>
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
		ListNode *removeNthFromEnd(ListNode *head,int n)
		{
			ListNode dummy(-1);
			dummy.next=head;
			ListNode *p=&dummy,*q=&dummy;
			
			for(int i=0;i<n;i++)
				q=q->next;
			while(q->next)
			{
				p=p->next;
				q=q->next;
			}

			ListNode *tmp=p->next;
			p->next=p->next->next;
			delete tmp;
			return dummy.next;
		}	
};

class Graph
{
	public:
		Graph(int _V)
		{
			V=_V;
			E=0;
			for(int i=0;i<V;i++)
			{
				adj.push_back(set<int>());
			}

		}
		Graph(char* file)
		{
			ifstream in(file);
			if(!in.is_open())
			{
				cout<<"file can't be opened"<<endl;
			}
			in>>V;
			in>>E;
			
			for(int i=0;i<V;i++)
			{
				adj.push_back(set<int>());
			}
			
			while(!in.eof())
			{
				int v1,v2;
				in>>v1;
				in>>v2;
				
				cout<<v1<<" "<<v2<<endl;
				addEdge(v1,v2);
			}
			

		}
		int getV(){return V;}
		int getE(){return E;}
		void addEdge(int v,int w)
		{
			
			adj[v].insert(w);
			adj[w].insert(v);
			E++;
		}
		void printG()
		{
			for(int i=0;i<adj.size();i++)
			{
				set<int>::iterator j;
				j=adj[i].begin();
				cout<<i<<": ";
				while(j!=adj[i].end())
				{
					cout<<*j<<" ";
					j++;
				}
					cout<<endl;
			}
		}

	private:
		int V;
		int E;
		vector<set<int> >adj;
		
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
	char file[]="txt";
	Graph s1(file);
	cout<<"---------------------"<<endl;
	s1.printG();

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
