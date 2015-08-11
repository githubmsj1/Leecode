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

struct UndirectedGraphNode
{
	int label;
	vector<UndirectedGraphNode*>neighbors;
	UndirectedGraphNode(int x):label(x){};
};
class Solution
{
	public:
		UndirectedGraphNode* clone(UndirectedGraphNode *node,map<UndirectedGraphNode *,UndirectedGraphNode *>copied)
		{
			if(copied.find(node)!=copied.end()) return copied[node];
			UndirectedGraphNode *new_node=new UndirectedGraphNode(node->label);
			copied[node]=new_node;
			for(int i=0;i<node->neighbors.size();i++)
			{
				new_node->neighbors.push_back(clone(node->neighbors[i],copied));
			}
			return new_node;

		}
		UndirectedGraphNode* clone1(UndirectedGraphNode *node)
		{
			if(node==NULL)return NULL;
			map<UndirectedGraphNode*,UndirectedGraphNode*> copied;
			queue<UndirectedGraphNode*>q;
			q.push(node);
			copied[node]=new UndirectedGraphNode(node->label);
			while(!q.empty())
			{
				UndirectedGraphNode *cur=q.front();
				q.pop();
				for(int i=0;i<cur->neighbors.size();i++)
				{
					if(copied.find(cur->neighbors[i])!=copied.end())
					{
						copied[cur]->neighbors.push_back(copied[cur->neighbors[i]]);
					}
					else
					{
						UndirectedGraphNode* new_node=new UndirectedGraphNode(cur->neighbors[i]->label);
						copied[cur->neighbors[i]]=new_node;
						copied[cur]->neighbors.push_back(new_node);
						q.push(cur->neighbors[i]);
					}
				}
			}
			return copied[node];
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
	UndirectedGraphNode* node0=new UndirectedGraphNode(0);
	UndirectedGraphNode* node1=new UndirectedGraphNode(1);
	UndirectedGraphNode* node2=new UndirectedGraphNode(2);
	
	node1->neighbors.push_back(node0);
	node1->neighbors.push_back(node2);
	node0->neighbors.push_back(node1);
	node0->neighbors.push_back(node2);
	node2->neighbors.push_back(node0);
	node2->neighbors.push_back(node1);
	node2->neighbors.push_back(node2);
	
	map<UndirectedGraphNode*,UndirectedGraphNode*>q;

	Solution s;
	UndirectedGraphNode* q1=s.clone(node0,q);
	//UndirectedGraphNode* q1=s.clone1(node0);

	cout<<q1->neighbors[0]->neighbors[1]->label<<endl;
	return 0;
}
