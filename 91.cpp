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
		int ladderLength(string start,string end,const set<string> &dict)
		{
			if(start.size()!=end.size())return 0;
			if(start.empty()||end.empty())return 0;

			queue<string>next,current;
			set<string>visited;
			map<string,string>father;

			int level=0;
			bool found=false;

			current.push(start);
			while(!current.empty()&&!found)
			{
				++level;
				while(!current.empty()&&!found)
				{
					const string str (current.front());current.pop();
					for(size_t i=0;i<str.size();++i)
					{
						string new_word(str);
						for(char c='a';c<='z';c++)
						{
							if(c==new_word[i]) continue;
							swap(c,new_word[i]);
							if(new_word==end)
							{
								found=true;
								father[new_word]=str;
								break;
							}

							if(dict.count(new_word)>0&&!visited.count(new_word))
							{
								next.push(new_word);
								visited.insert(new_word);
								father[new_word]=str;
							}
							swap(c,new_word[i]);
						}

					}
				}
				swap(next,current);
			}
			if(found)return level+1;
			else return 0;
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
	
	set<string>dict(dict1,dict1+sizeof(dict1)/sizeof(string));
	
	Solution s;
	cout<<s.ladderLength(start,end,dict);
	
	//s.ladderLength(start,end,dict);
	return 0;
}
