#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<iterator>
#include<set>
//#include<tr1/unordered_map>

using namespace std;
class Solution
{
	public:
		void nextPermutation(vector<int> &num )
		{
			next_permutation(num.begin(),num.end());
		}

		template<typename BidiIt>
		bool next_permutation(BidiIt first,BidiIt last)
		{
			const reverse_iterator<BidiIt> rfirst=(reverse_iterator<BidiIt>)last;
			const reverse_iterator<BidiIt> rlast=(reverse_iterator<BidiIt>)first;
		
		
			reverse_iterator<BidiIt>pivot=rfirst+1;

			while(pivot!=rlast&&!(*pivot<*(pivot-1)))
			{
				pivot++;

			}

			if(pivot==rlast)
			{
				reverse(rfirst,rlast);
				return false;
			}

			reverse_iterator<BidiIt>change=find_if(rfirst,pivot,bind1st(less<int>(),*pivot));
			swap(*change,*pivot);
			reverse(rfirst,pivot);
			return true;
		}
		

};



int main()
{
	int src[]={1,1,5};
	vector<int>srcv(src,src+sizeof(src)/sizeof(int));
	Solution s;
	int p=1;
	while(p--)
	{
	s.nextPermutation(srcv);
	for(vector<int>::iterator i=srcv.begin();i<srcv.end();i++)
	{
		cout<<*i<<" ";
	}
	cout<<endl;
	}
	return 0;
}
