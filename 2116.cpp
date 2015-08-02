#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<iterator>
#include<set>
#include<stack>
//#include<tr1/unordered_map>

using namespace std;
class Solution
{
	public:
		vector<int>pulsOne(vector<int>& digits)
		{
			add(digits,1);
			return digits;
		}
	private:
		
		void add(vector<int>&digits,int digit)
		{
			int carry=digit;
			for(vector<int>::reverse_iterator i=digits.rbegin();i<digits.rend();i++)
			{
				*i+=carry;
				carry=*i/10;
				*i%=10;
			}
			if(carry>0)digits.insert(digits.begin(),1);
		}
			
};



int main()
{
	int src[]={9,9,9,9};
	vector<int>srcv(src,src+sizeof(src)/sizeof(int));
	
	//cout<<sizeof(matrix)/sizeof(matrix[0])<<endl;
	Solution s;
	s.pulsOne(srcv);
	for(int i=0;i<srcv.size();i++)
	{
		cout<<srcv[i];
	}
	cout<<endl;


	return 0;
}
