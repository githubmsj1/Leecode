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
		string getPermutation(int n,int k)
		{
			string s(n,'0');
			for(int i=0;i<n;++i)
			{
				s[i]+=i+1;
			}
			return kth_permutation(s,k);
		}
	private:
		int factorial(int n)
		{
			int result=1;
			for(int i=1;i<=n;i++)
				result*=i;
			return result;
		}

		template<typename Sequence>
		Sequence kth_permutation(const Sequence &seq,int k)
		{
			const int n=seq.size();
			Sequence S(seq);
			Sequence result;

			int base=factorial(n-1);
			k--;

			for(int i=n-1;i>0;k%=base,base/=i,i--)
			{
				typename Sequence::iterator pos=S.begin()+k/base;
				result.push_back(*pos);
				S.erase(pos);
			}

			result.push_back(S[0]);
			return result;

		}


};



int main()
{
	int src[]={1,1,5};
	vector<int>srcv(src,src+sizeof(src)/sizeof(int));
	Solution s;
	cout<<s.getPermutation(5,2)<<endl;

	//for(vector<int>::iterator i=srcv.begin();i<srcv.end();i++)
	//{
	//	cout<<*i<<" ";
	//}
	//}
	return 0;
}
